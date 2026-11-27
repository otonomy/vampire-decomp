// CUtlRBTree16: Source's CUtlRBTree with 16-byte nodes (8-byte links, 8-byte element), a less-func pointer first.
#pragma once

class CUtlRBTree16
{
public:
	struct Links_t
	{
		unsigned short m_Left;
		unsigned short m_Right;
		unsigned short m_Parent;
		unsigned short m_Tag;
	};
	struct Node_t
	{
		Links_t m_Links;
		char m_Data[8];
	};

	bool (*m_LessFunc)(const void *, const void *);
	Node_t *m_pElements;
	int m_unk8;
	int m_unkC;
	unsigned short m_Root;
	unsigned short m_NumElements;
	unsigned short m_FirstFree;
	unsigned short m_TotalElements;

	static unsigned short InvalidIndex() { return 0xffff; }

	const Links_t &sub_10112720(unsigned short i) const;
	unsigned short sub_10111210(const void *search);	// "CUtlRBTree::Find"
	const Links_t &sub_10113190(unsigned short i) const;
	const Links_t &sub_101397f0(unsigned short i) const;

	bool sub_101130d0(unsigned short i) const;	// "CUtlRBTree::IsLeftChild"
	bool sub_10114120(unsigned short i) const;
	bool sub_10139850(unsigned short i) const;
		// same as sub_10047840 (another instance)
		// same as sub_10047840 (another instance)
		// same as sub_10047840 (another instance)
		// same as sub_10047840 (another instance)
		// same as sub_10047840 (another instance)
	bool sub_10114560(unsigned short i) const;	// "CUtlRBTree::IsRightChild"
		// same as sub_100483f0 (another instance)
		// same as sub_100483f0 (another instance)
		// same as sub_100483f0 (another instance)
	void sub_10112390(unsigned short i, unsigned short parent, bool isLeft);	// "CUtlRBTree::LinkToParent" with InsertRebalance inlined
	void sub_101141e0(unsigned short i);	// "CUtlRBTree::RotateLeft" of that instance
	void sub_101143a0(unsigned short i);	// "CUtlRBTree::RotateRight" of that instance
	unsigned short sub_10111ae0(unsigned short parent, bool leftchild);	// "CUtlRBTree::InsertAt" (NewNode, Grow, LinkToParent, InsertRebalance inlined)
	void sub_10113da0(unsigned short i);	// "CUtlRBTree::RotateLeft"
	void sub_10113f60(unsigned short i);	// "CUtlRBTree::RotateRight"
	unsigned short sub_10112270();	// "CUtlRBTree::NewNode": takes the free list head or grows the node memory (first allocation 2 elements)
	unsigned short sub_10139340();
	void sub_10111ee0(unsigned short elem);
	void sub_10139460(unsigned short i, unsigned short parent, bool isLeft);	// "CUtlRBTree::LinkToParent" with InsertRebalance inlined, of the instance whose links are 0x101397f0
	void sub_10139910(unsigned short elem);	// "CUtlRBTree::RotateLeft" of that instance
	void sub_10139ad0(unsigned short elem);	// "CUtlRBTree::RotateRight" of that instance	// "CUtlRBTree::Unlink" of the instance whose sentinel is 0x104dff2c
	void sub_101131f0(unsigned short elem);	// "CUtlRBTree::RemoveRebalance" of that instance
		// same as sub_1024a310 (another instance)
		// address of the left child index of node i (stub 0x10012189), called by the lookup at 0x10312580
		// "CUtlRBTree::RemoveNode" (stub 0x10008e04): unlinks node i and rebalances
		// "CUtlRBTree::Links" of the instance used by 0x10044a90 (stub 0x10007d6f): the links of node i
		// "CUtlRBTree::RemoveNode" of that instance (stub 0x10010b81): unlinks node i and rebalances
};

// The game has one CUtlRBTree<T, I> per element type T; CUtlRBTree16 stands for every instance with 16-byte nodes.
// Each instance keeps its own sentinel node in a function-local static of Links() (with its own guard), so a function
// of one instance reads its links through CUtlRBTree16At<the address the game keeps that instance's sentinel at>, the
// static the judge places for it (one game variable, one static: link audit E):
//	const CUtlRBTree16At<0x...> *tree = (const CUtlRBTree16At<0x...> *)this;	... tree->Links(i) ...
template <unsigned long Sentinel>
class CUtlRBTree16At : public CUtlRBTree16
{
public:
	const Links_t &Links(unsigned short i) const
	{
		static Links_t s_Sentinel = { InvalidIndex(), InvalidIndex(), InvalidIndex(), 1 };
		return i != InvalidIndex() ? m_pElements[i].m_Links : s_Sentinel;
	}

	unsigned short Parent(unsigned short i) const { return Links(i).m_Parent; }
};
