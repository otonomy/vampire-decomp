// CUtlRBTree148: Source's CUtlRBTree with 0x94-byte nodes (8-byte links first), element array pointer at +4.
#pragma once

class CUtlRBTree148
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
		char m_Data[0x94 - 8];
	};

	int m_unk0;
	Node_t *m_pElements;
	int m_unk8;	// 0x08: the allocation count of the node memory
	int m_unkC;	// 0x0c: its grow size
	unsigned short m_Root;	// 0x10

	static unsigned short InvalidIndex() { return 0xffff; }

	const Links_t &Links(unsigned short i) const
	{
		static Links_t s_Sentinel = { InvalidIndex(), InvalidIndex(), InvalidIndex(), 1 };
		return i != InvalidIndex() ? m_pElements[i].m_Links : s_Sentinel;
	}

	bool sub_100cfc00(unsigned short i) const;	// "CUtlRBTree::IsRightChild"
	bool sub_100cf230(unsigned short i) const;	// "CUtlRBTree::IsLeftChild"
	Links_t &sub_100ce920(unsigned short i);	// "CUtlRBTree::Links" (out of line, with the sentinel static)
	void sub_100cfa20(unsigned short elem);	// "CUtlRBTree::RotateLeft"
	void sub_100cf4e0(unsigned short elem);	// "CUtlRBTree::InsertRebalance"
	unsigned short Parent(unsigned short i) { return sub_100ce920(i).m_Parent; }
	unsigned short LeftChild(unsigned short i) { return sub_100ce920(i).m_Left; }
	unsigned short RightChild(unsigned short i) { return sub_100ce920(i).m_Right; }
	unsigned short Color(unsigned short i) { return sub_100ce920(i).m_Tag; }
	void SetParent(unsigned short i, unsigned short v) { m_pElements[i].m_Links.m_Parent = v; }
	void SetLeftChild(unsigned short i, unsigned short v) { m_pElements[i].m_Links.m_Left = v; }
	void SetRightChild(unsigned short i, unsigned short v) { m_pElements[i].m_Links.m_Right = v; }
	void SetColor(unsigned short i, unsigned short v) { m_pElements[i].m_Links.m_Tag = v; }
	void RotLeft(unsigned short elem)
	{
		unsigned short rightchild = RightChild(elem);
		SetRightChild(elem, LeftChild(rightchild));
		if (LeftChild(rightchild) != InvalidIndex())
			SetParent(LeftChild(rightchild), elem);
		if (rightchild != InvalidIndex())
			SetParent(rightchild, Parent(elem));
		if (elem != m_Root) {
			if (sub_100cf230(elem))
				SetLeftChild(Parent(elem), rightchild);
			else
				SetRightChild(Parent(elem), rightchild);
		} else
			m_Root = rightchild;
		SetLeftChild(rightchild, elem);
		if (elem != InvalidIndex())
			SetParent(elem, rightchild);
	}
	void RotRight(unsigned short elem)
	{
		unsigned short leftchild = LeftChild(elem);
		SetLeftChild(elem, RightChild(leftchild));
		if (RightChild(leftchild) != InvalidIndex())
			SetParent(RightChild(leftchild), elem);
		if (leftchild != InvalidIndex())
			SetParent(leftchild, Parent(elem));
		if (elem != m_Root) {
			if (sub_100cfc00(elem))
				SetRightChild(Parent(elem), leftchild);
			else
				SetLeftChild(Parent(elem), leftchild);
		} else
			m_Root = leftchild;
		SetRightChild(leftchild, elem);
		if (elem != InvalidIndex())
			SetParent(elem, leftchild);
	}
};
