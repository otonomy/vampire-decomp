// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1013d930 size=0x37f
#include "utlrbtree.h"

struct CRBTree12Entry_10194f30
{
	int m_n0;
};

typedef void (CUtlRBTree<CRBTree12Entry_10194f30, unsigned short>::*LinkToParentFn_1013d930)(unsigned short, unsigned short, bool);

// TARGET: ?LinkToParent@?$CUtlRBTree@UCRBTree12Entry_10194f30@@G@@QAEXGG_N@Z
LinkToParentFn_1013d930 pcd_emit_1013d930()
{
	return &CUtlRBTree<CRBTree12Entry_10194f30, unsigned short>::LinkToParent;
}
// END FUNCTION

// FUNCTION: 0x1013dcb0 size=0x58
#include "utlrbtree.h"

struct CRBTree12Entry_10194f30 { int m_unk0; };

template<>
const CUtlRBTree<CRBTree12Entry_10194f30, unsigned short>::Links_t &
CUtlRBTree<CRBTree12Entry_10194f30, unsigned short>::Links(unsigned short i) const
{
	static Links_t s_Sentinel = { InvalidIndex(), InvalidIndex(), InvalidIndex(), BLACK };
	return (i != InvalidIndex()) ? *(Links_t *)&m_Elements[i] : *(Links_t *)&s_Sentinel;
}
// END FUNCTION

// FUNCTION: 0x1013de80 size=0x1bc
#include "utlrbtree.h"
#include "CUtlRBTree12.h"

struct CRBTree12Entry_10194f30 { int m_unk0; };

typedef CUtlRBTree12At<0x105e74e0> RBT_1013de80;

// TARGET: ?RotateLeft@?$CUtlRBTree@UCRBTree12Entry_10194f30@@G@@QAEXG@Z
template <>
void CUtlRBTree<CRBTree12Entry_10194f30, unsigned short>::RotateLeft(unsigned short elem)
{
	RBT_1013de80 *t = (RBT_1013de80 *)this;
	unsigned short rightchild = sub_1013dcb0(elem).m_Right;
	unsigned short rcLeft = sub_1013dcb0(rightchild).m_Left;
	m_Elements.m_pMemory[elem].m_Right = rcLeft;
	if (sub_1013dcb0(rightchild).m_Left != InvalidIndex())
	{
		unsigned short l = sub_1013dcb0(rightchild).m_Left;
		m_Elements.m_pMemory[l].m_Parent = elem;
	}
	if (rightchild != InvalidIndex())
	{
		unsigned short p = sub_1013dcb0(elem).m_Parent;
		m_Elements.m_pMemory[rightchild].m_Parent = p;
	}
	if (elem != m_Root)
	{
		unsigned short parent = sub_1013dcb0(elem).m_Parent;
		if (t->Links(parent).m_Left == elem)
			m_Elements.m_pMemory[t->Links(elem).m_Parent].m_Left = rightchild;
		else
			m_Elements.m_pMemory[t->Links(elem).m_Parent].m_Right = rightchild;
	}
	else
		m_Root = rightchild;
	m_Elements.m_pMemory[rightchild].m_Left = elem;
	if (elem != InvalidIndex())
		m_Elements.m_pMemory[elem].m_Parent = rightchild;
}
// END FUNCTION
