// CUtlRBTree232: Source's CUtlRBTree with 232-byte nodes (int-indexed, 16-byte links, 216-byte element), a less-func pointer first.
#pragma once

class CUtlRBTree232
{
public:
	struct Links_t
	{
		int m_Left;
		int m_Right;
		int m_Parent;
		int m_Tag;
	};
	struct Node_t
	{
		Links_t m_Links;
		char m_Data[216];
	};

	bool (*m_LessFunc)(const void *, const void *);
	Node_t *m_pElements;	// 0x04
	int m_nAllocationCount;	// 0x08
	int m_nGrowSize;	// 0x0c
	int m_Root;	// 0x10
	int m_NumElements;	// 0x14
	int m_FirstFree;	// 0x18
	int m_TotalElements;	// 0x1c

	static int InvalidIndex() { return -1; }
	void sub_10133080(int elem);	// "CUtlRBTree::RotateRight" of the instance whose Links is sub_10131a70
	void sub_10132e80(int elem);
	void sub_10131f80(int elem);	// "CUtlRBTree::InsertRebalance"	// "CUtlRBTree::RotateLeft" of that instance
	void sub_101316c0(int i, int parent, bool isLeft);	// "CUtlRBTree::LinkToParent" with InsertRebalance inlined (called by InsertAt 0x10130c50)

	Node_t &ElementAt(int i) const { return m_pElements[i]; }

	void sub_10131140(const void *pInsert, int *pParent, bool *pLeftChild);	// "CUtlRBTree::FindInsertionPosition": walks down from the root with the less function, stores the last visited node in *pParent and whether the new element goes to its left in *pLeftChild
		// "CUtlRBTree::InsertAt": NewNode (free list head, else grows the node memory to hold one more node; the first allocation is 1 element), constructs the element (first word 0xffff, sound parameter record sub_101b30d0 at +0xc of the data), links it below parent (red, no children; the root when parent is -1), InsertRebalance, ++m_NumElements; returns the node index
		// "CUtlRBTree::LinkNode + InsertRebalance" body for this 232-byte-node instance (0x101b7450, ret 12): writes the new node's links (m_Left = m_Right = -1 at +0/+4, m_Parent = iParent at +8, red tag 0 at +0xc), links it as the left (bLeftChild) or right child of iParent, or as m_Root (+0x10) when iParent is -1, then runs the red-black fix-up loop (uncle test, RotateLeft/RotateRight, recolour) reading links through Links(); the root ends black. Uses m_pElements (+4), m_Root (+0x10) and CUtlRBTree<CSoundEmitterRecord,int>::RotateLeft (0x101b9250) / RotateRight (0x101b94d0).
	Links_t &sub_10131a70(int i);	// "CUtlRBTree::Links" (out of line, with the sentinel static; stub 0x10005c40)
		// "CUtlRBTree::InsertRebalance" (stub 0x10012d8c)
};

// The game has one CUtlRBTree<T, I> per element type T; CUtlRBTree232 stands for every instance with 232-byte nodes.
// Each instance keeps its own sentinel node in a function-local static of Links() (with its own guard), so a function
// of one instance reads its links through CUtlRBTree232At<the address the game keeps that instance's sentinel at>, the
// static the judge places for it (one game variable, one static: link audit E):
//	const CUtlRBTree232At<0x...> *tree = (const CUtlRBTree232At<0x...> *)this;	... tree->Links(i) ...
template <unsigned long Sentinel>
class CUtlRBTree232At : public CUtlRBTree232
{
public:
	const Links_t &Links(int i) const
	{
		static Links_t s_Sentinel = { InvalidIndex(), InvalidIndex(), InvalidIndex(), 1 };
		return i != InvalidIndex() ? m_pElements[i].m_Links : s_Sentinel;
	}
};
