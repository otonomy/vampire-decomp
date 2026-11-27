// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101bc4f0 size=0x122
#include "vgui2__TreeView.h"
#include "vgui2__TreeViewSubPanel.h"
struct TVScrollBarV : public vgui2::Panel { TVScrollBarV *sub_101beb90(vgui2::Panel *parent, const char *name, int vertical); };
vgui2::TreeView::TreeView(vgui2::Panel *parent, const char *name) : vgui2::Panel(parent, name)
{
	char *c = (char *)this;
	*(int *)(c + 0x60) = 0x14;
	*(int *)(c + 0x6c) = 0;
	*(int *)(c + 0x9c) = 0;
	*(int *)(c + 0x68) = 0;
	*(char *)(c + 0x64) = 0;
	*(int *)(c + 0x70) = 0;
	*(int *)(c + 0x74) = 0;
	void *mem0 = vgui2::Panel::operator new(0x58);
	vgui2::TreeViewSubPanel *sp = new (mem0) vgui2::TreeViewSubPanel(this);
	*(vgui2::TreeViewSubPanel **)(c + 0xa0) = sp;
	sp->vfunc21(1);
	(*(vgui2::TreeViewSubPanel **)(c + 0xa0))->sub_101a9890(0, 0);
	void *mem = vgui2::Panel::operator new(0x70);
	TVScrollBarV *hb = mem ? ((TVScrollBarV *)mem)->sub_101beb90(this, "HorizScrollBar", 0) : 0;
	*(TVScrollBarV **)(c + 0x58) = hb;
	hb->vfunc41((int)this);
	(*(TVScrollBarV **)(c + 0x58))->vfunc21(0);
	mem = vgui2::Panel::operator new(0x70);
	TVScrollBarV *vb = mem ? ((TVScrollBarV *)mem)->sub_101beb90(this, "VertScrollBar", 1) : 0;
	*(TVScrollBarV **)(c + 0x5c) = vb;
	vb->vfunc21(0);
	(*(TVScrollBarV **)(c + 0x5c))->vfunc41((int)this);
}
// END FUNCTION

// FUNCTION: 0x101bc700 size=0x1e
#include "vgui2__TreeView.h"

// VC6 writes vgui2::TreeView's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::TreeView *pcd_emit_101bc700(const vgui2::TreeView &other) { return new vgui2::TreeView(other); }

// TARGET: ??_GTreeView@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101bc7f0 size=0x62
#include "vgui2__TreeView.h"

int sub_101ac8d0();

struct VSurface
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
	virtual int v63(int);
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
	virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
	virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
	virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
	virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
	virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
	virtual void v132(int);
};

struct ITreeNode
{
	char m_pad00[0x64];
	VSurface *m_p64;
	char m_pad68[0x74 - 0x68];
	ITreeNode **m_pChildren;
	char m_pad78[0x80 - 0x78];
	int m_nChildren;
	void sub_101bc860(int font);
};

// TARGET: vfunc114
void vgui2::TreeView::vfunc114(int font)
{
	if (!font)
		return;
	m_i74 = font;
	m_unk5c[1] = ((VSurface *)sub_101ac8d0())->v63(font) + 2;
	ITreeNode *root = (ITreeNode *)m_unk5c[4];
	if (!root)
		return;
	root->m_p64->v132(font);
	for (int i = 0; i < root->m_nChildren; i++)
		root->m_pChildren[i]->sub_101bc860(font);
}
// END FUNCTION

// FUNCTION: 0x101bc8c0 size=0x28c
#include "vgui2__TreeView.h"
#include "vgui2__TextImage.h"
#include "vgui2__TextEntry.h"

struct KV_101bc8c0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10();
	virtual const char *GetString(const char *key, const char *def);
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void v17();
	virtual KV_101bc8c0 *MakeCopy();
	virtual void v19(); virtual void v20();
	virtual void deleteThis();
};

struct ImgView_101bc8c0 { virtual void v0(); virtual void SetPos(int x, int y); };

struct UtlMem { void sub_101be2e0(int, int); };
struct ListElem_101bc8c0 { vgui2::Panel *m_Element; int m_Previous; int m_Next; };
struct CUtlLinkedList12 { int sub_101be410(int); void sub_101be340(int, int); ListElem_101bc8c0 *m_pMemory; };
struct UtlVec8 { void sub_101be2a0(int, int); };
void sub_101be320(vgui2::Panel **dst, vgui2::Panel *const *src);
struct CUtlVector4
{
	void sub_101be160(int, vgui2::Panel *const &);
	void sub_101be210(int);
	vgui2::Panel **m_pMemory; int m_nAlloc; int m_nGrow; int m_Size; vgui2::Panel **m_pElements;

	vgui2::Panel *&Element(int i) { return m_pMemory[i]; }
	int Count() const { return m_Size; }
	int InsertBefore(int elem, vgui2::Panel *const &src)
	{
		sub_101be210(1);
		((UtlVec8 *)this)->sub_101be2a0(elem, 1);
		sub_101be320(&Element(elem), &src);
		return elem;
	}
	void AddToTail(vgui2::Panel *const &src) { sub_101be160(m_Size, src); }
};
struct TreeNode_101bc860 { void sub_101bc860(int font); };
struct CUnknown101bcca0 { void *sub_101bcca0(void *parent, const char *name); };
struct CUnknown101bcb50 { void *sub_101bcb50(void *parent, const char *name); };
extern char vt_10252cb4[];

typedef bool (*TreeSortFunc_101bc8c0)(KV_101bc8c0 *a, KV_101bc8c0 *b);

#define TN_DATA(n) (*(KV_101bc8c0 **)((char *)(n) + 0x58))
#define TN_INDEX(n) (*(int *)((char *)(n) + 0x5c))
#define TN_PARENT(n) (*(vgui2::Panel **)((char *)(n) + 0x60))
#define TN_TEXT(n) (*(vgui2::TextEntry **)((char *)(n) + 0x64))
#define TN_EXPAND(n) (*(vgui2::TextImage **)((char *)(n) + 0x68))
#define TN_IMAGE(n) (*(vgui2::Panel **)((char *)(n) + 0x6c))
#define TN_BEXPAND(n) (*(bool *)((char *)(n) + 0x70))
#define TN_CHILDREN(n) (*(CUtlVector4 *)((char *)(n) + 0x74))
#define TN_VIEW(n) (*(vgui2::Panel **)((char *)(n) + 0x88))

#define TV_ROOT (*(vgui2::Panel **)((char *)this + 0x6c))
#define TV_SORT(t) (*(TreeSortFunc_101bc8c0 *)((char *)(t) + 0x70))
#define TV_FONT (*(int *)((char *)this + 0x74))
#define TV_LIST (*(CUtlLinkedList12 *)((char *)this + 0x78))
#define TV_SUBPANEL (*(vgui2::Panel **)((char *)this + 0xa0))

static inline void TreeNode_AddChild(vgui2::Panel *parent, vgui2::Panel *node)
{
	if (TV_SORT(TN_VIEW(parent)))
	{
		int i;
		for (i = 0; i < TN_CHILDREN(parent).Count(); i++)
		{
			vgui2::Panel **children = TN_CHILDREN(parent).m_pMemory;
			if (TV_SORT(TN_VIEW(parent))(TN_DATA(node), TN_DATA(children[i])))
				break;
		}
		if (i != TN_CHILDREN(parent).Count())
		{
			TN_CHILDREN(parent).InsertBefore(i, node);
			return;
		}
	}
	TN_CHILDREN(parent).AddToTail(node);
}

namespace vgui2
{
int TreeView::vfunc107(void *pData, int parentItemIndex)
{
	Panel *pTreeNode = (Panel *)Panel::operator new(0x8c);
	if (pTreeNode)
	{
		Panel *node = pTreeNode;
		node->sub_101a9480(TV_SUBPANEL);
		CUtlVector4 &ch = TN_CHILDREN(node);
		((UtlMem *)&ch)->sub_101be2e0(0, 0);
		ch.m_Size = 0;
		ch.m_pElements = ch.m_pMemory;
		*(void **)node = vt_10252cb4;
		TN_DATA(node) = 0;
		TN_VIEW(node) = this;
		TN_INDEX(node) = -1;

		TN_EXPAND(node) = new TextImage("+", node->sub_101aa220());
		((ImgView_101bc8c0 *)TN_EXPAND(node))->SetPos(3, 3);

		void *mem = Panel::operator new(0x60);
		TN_IMAGE(node) = (Panel *)(mem ? ((CUnknown101bcca0 *)mem)->sub_101bcca0(node, "TreeImage") : 0);
		TN_IMAGE(node)->sub_101a9890(0x14, 3);

		mem = Panel::operator new(0x128);
		TN_TEXT(node) = (TextEntry *)(mem ? ((CUnknown101bcb50 *)mem)->sub_101bcb50(node, "TreeNode") : 0);
		TN_TEXT(node)->vfunc138(0);
		TN_TEXT(node)->vfunc134(0);
		TN_TEXT(node)->sub_101a9890(0x28, 0);
		TN_BEXPAND(node) = false;
	}
	else
		pTreeNode = 0;

	// m_NodeList.AddToTail(pTreeNode)
	int idx = TV_LIST.sub_101be410(0);
	TV_LIST.sub_101be340(-1, idx);
	Panel **elem = &TV_LIST.m_pMemory[idx].m_Element;
	if (elem)
		*elem = pTreeNode;
	TN_INDEX(pTreeNode) = idx;

	// SetKVData(data)
	if (TN_DATA(pTreeNode))
		TN_DATA(pTreeNode)->deleteThis();
	KV_101bc8c0 *data = (KV_101bc8c0 *)pData;
	TN_DATA(pTreeNode) = data->MakeCopy();
	const char *text = data->GetString("Text", "");
	TN_TEXT(pTreeNode)->vfunc107(text);
	TN_TEXT(pTreeNode)->sub_101b1790();
	pTreeNode->vfunc57(0, 0);

	if (TV_FONT)
	{
		int font = TV_FONT;
		TN_TEXT(pTreeNode)->vfunc132(font);
		for (int i = 0; i < TN_CHILDREN(pTreeNode).m_Size; i++)
			((TreeNode_101bc860 *)TN_CHILDREN(pTreeNode).m_pMemory[i])->sub_101bc860(font);
	}

	if (parentItemIndex == -1)
	{
		TV_ROOT = pTreeNode;
		TN_PARENT(pTreeNode) = 0;
	}
	else
	{
		TN_PARENT(pTreeNode) = TV_LIST.m_pMemory[parentItemIndex].m_Element;
		TreeNode_AddChild(TN_PARENT(pTreeNode), pTreeNode);
	}
	return TN_INDEX(pTreeNode);
}
}
// END FUNCTION

// FUNCTION: 0x101bd3d0 size=0x7
#include "vgui2__TreeView.h"
int vgui2::TreeView::vfunc108()
{
    return *(int *)((char *)this + 0x90);
}
// END FUNCTION

// FUNCTION: 0x101bd420 size=0xf
#include "vgui2__TreeView.h"
int vgui2::TreeView::vfunc110()
{
    if ((*(int *)((char *)this + 0x9c)) == 0) {
        return *(int *)((char *)this + 0x9c);
    }
    return *(int *)((char *)(*(int *)((char *)this + 0x9c)) + 0x58);
}
// END FUNCTION

// FUNCTION: 0x101bd430 size=0x19b
#include "vgui2__TreeView.h"
#include "utlvector.h"

struct TreeNode_101bd430
{
	virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
	virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
	virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
	virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual ~TreeNode_101bd430();

	char m_pad04[0x58];
	int m_ItemIndex;                       // 0x5c
	TreeNode_101bd430 *m_pParent;          // 0x60
	char m_pad64[0x10];
	CUtlVector<TreeNode_101bd430 *> m_Children; // 0x74

	int GetChildrenCount() { return m_Children.Count(); }
};

template <class T, class I = unsigned short>
class CUtlLinkedList_101bd430
{
public:
	struct ListElem_t
	{
		T m_Element;
		I m_Previous;
		I m_Next;
	};

	CUtlMemory<ListElem_t> m_Memory;
	I m_Head;
	I m_Tail;
	I m_FirstFree;
	I m_ElementCount;
	I m_TotalElements;
	ListElem_t *m_pElements;

	static inline I InvalidIndex() { return (I)~0; }

	ListElem_t &InternalElement(I i) { return m_Memory[i]; }
	ListElem_t const &InternalElement(I i) const { return m_Memory[i]; }

	inline T &Element(I i) { return m_Memory[i].m_Element; }
	inline T &operator[](I i) { return m_Memory[i].m_Element; }

	inline I Previous(I i) const { return InternalElement(i).m_Previous; }

	inline bool IsValidIndex(I i) const
	{
		return (i < m_TotalElements) && (i >= 0) &&
			((m_Memory[i].m_Previous != i) || (m_Memory[i].m_Next == i));
	}

	inline bool IsInList(I i) const
	{
		return (i < m_TotalElements) && (i >= 0) && (Previous(i) != i);
	}

	void Unlink(I elem)
	{
		if (IsInList(elem))
		{
			ListElem_t *pBase = m_Memory.Base();
			ListElem_t *pOldElem = &pBase[elem];

			if (pOldElem->m_Previous != InvalidIndex())
			{
				pBase[pOldElem->m_Previous].m_Next = pOldElem->m_Next;
			}
			else
			{
				m_Head = pOldElem->m_Next;
			}

			if (pOldElem->m_Next != InvalidIndex())
			{
				pBase[pOldElem->m_Next].m_Previous = pOldElem->m_Previous;
			}
			else
			{
				m_Tail = pOldElem->m_Previous;
			}

			pOldElem->m_Previous = pOldElem->m_Next = elem;
			--m_ElementCount;
		}
	}

	void Free(I elem)
	{
		Unlink(elem);
		ListElem_t &internalElem = InternalElement(elem);
		Destruct(&internalElem.m_Element);
		internalElem.m_Next = m_FirstFree;
		m_FirstFree = elem;
	}

	void Remove(I elem)
	{
		Free(elem);
	}
};

struct TreeViewLayout_101bd430
{
	char m_pad[0x78];
	CUtlLinkedList_101bd430<TreeNode_101bd430 *, int> m_NodeList;
};

#define m_NodeList (((TreeViewLayout_101bd430 *)this)->m_NodeList)

// TARGET: vgui2::TreeView::vfunc111
void vgui2::TreeView::vfunc111(int itemIndex, bool bPromoteChildren)
{
	if (!m_NodeList.IsValidIndex(itemIndex))
		return;

	TreeNode_101bd430 *pNode = m_NodeList[itemIndex];
	TreeNode_101bd430 *pParent = pNode->m_pParent;

	if (bPromoteChildren && pParent)
	{
		int i;
		for (i = 0; i < pNode->GetChildrenCount(); i++)
		{
			TreeNode_101bd430 *pChild = pNode->m_Children[i];
			pChild->m_pParent = pParent;
		}
	}
	else
	{
		int i;
		for (i = 0; i < pNode->GetChildrenCount(); i++)
		{
			TreeNode_101bd430 *pDeleteChild = pNode->m_Children[i];
			vfunc111(pDeleteChild->m_ItemIndex, false);
		}
	}

	if (pParent)
	{
		pParent->m_Children.FindAndRemove(pNode);
	}

	m_NodeList.Remove(itemIndex);
	delete pNode;
}
// END FUNCTION

// FUNCTION: 0x101bd5d0 size=0x9e
#include "vgui2__TreeView.h"
#include "CUtlLinkedList12.h"
struct TVView112 { char pad0[0x6c]; int m6c; char pad1[0x78 - 0x70]; CUtlLinkedList12 m_list; };
void vgui2::TreeView::vfunc112()
{
	TVView112 *v = (TVView112 *)this;
	for (int i = 0; i < v->m_list.m_NumAlloced; i++) {
		if (v->m_list.IsValidIndex(i)) {
			vgui2::Panel *p = (vgui2::Panel *)v->m_list.m_pMemory[i].m_pData;
			if (p) delete p;
		}
	}
	if (v->m_list.m_NumAlloced) {
		int prev = -1;
		for (int i = v->m_list.m_NumAlloced - 1; i >= 0; i--) {
			v->m_list.m_pMemory[i].m_Next = prev;
			v->m_list.m_pMemory[i].m_Previous = i;
			prev = i;
		}
		v->m_list.m_FirstFree = 0;
		v->m_list.m_Head = -1;
		v->m_list.m_Tail = -1;
		v->m_list.m_ElementCount = 0;
	}
	v->m6c = 0;
}
// END FUNCTION

// FUNCTION: 0x101bd670 size=0x9a
#include "vgui2__TreeView.h"
#include "CUtlLinkedList12.h"
#include "vgui2__TextEntry.h"
#define D8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct Dat101bd670 {
	D8(a) virtual void b0(); virtual void b1(); virtual void b2();
	virtual const char *v11(const char *key, const char *def);
	virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5();
	virtual int v18();
};
struct Lbl101bd670 {
	D8(a) D8(b) D8(c) D8(d) D8(e) D8(f) D8(g) D8(h) D8(i) D8(j) D8(k) D8(l) D8(m)
	virtual void n0(); virtual void n1(); virtual void n2();
	virtual void s107(const char *);
};
struct Rel101bd670 { D8(a) D8(b) virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void v21(); };
struct Node101bd670 {
	D8(a) D8(b) D8(c) D8(d) D8(e) D8(f) D8(g)
	virtual void h0();
	virtual int v57(int, int);
	char pad[0x54]; Rel101bd670 *m58; int pad2; int pad3; Lbl101bd670 *m64;
};
struct TVV101bd670 {
	char pad0[0x78];
	CUtlLinkedList12 m_list;
	Node101bd670 *Get(int i) { return (Node101bd670 *)m_list.m_pMemory[i].m_pData; }
	bool Valid(int i) { return m_list.IsValidIndex(i); }
};
bool vgui2::TreeView::vfunc113(int idx, int data)
{
	TVV101bd670 *v = (TVV101bd670 *)this;
	if (!v->Valid(idx))
		return 0;
	Node101bd670 *n = v->Get(idx);
	if (n->m58) n->m58->v21();
	Dat101bd670 *d = (Dat101bd670 *)data;
	n->m58 = (Rel101bd670 *)d->v18();
	const char *t = d->v11("Text", "");
	n->m64->s107(t);
	((vgui2::TextEntry *)n->m64)->sub_101b1790();
	n->v57(0, 0);
	vfunc57(0, 0);
	return 1;
}
// END FUNCTION

// FUNCTION: 0x101bd710 size=0x5f
#include "vgui2__TreeView.h"
namespace vgui2 {
// TARGET: vgui2::TreeView::vfunc115
void TreeView::vfunc115(int p, char b)
{
	if (m_pTree68)
	{
		if (m_bTree64)
			delete m_pTree68;
	}
	m_pTree68 = (CUtlVectorDel4 *)p;
	m_bTree64 = b;
}
}
// END FUNCTION

// FUNCTION: 0x101bd780 size=0x89
#include "vgui2__TreeView.h"
struct TVNode { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void RequestFocus(int); };
struct TVEntry { TVNode *m_pData; int m_Previous; int m_Next; };
struct KVx { KVx *sub_101b56c0(const char *, const char *, int); };
extern void *sub_101b6840(int);
struct TVList {
	TVEntry *m_pMemory; int m_u4[(0x94 - 0x7c) / 4]; int m_NumAlloced;
	bool IsValidIndex(int i) const { return (i < m_NumAlloced) && (i >= 0) && ((m_pMemory[i].m_Previous != i) || (m_pMemory[i].m_Next == i)); }
	TVEntry &Element(int i) { return m_pMemory[i]; }
};
struct TVView { char pad[0x78]; TVList m_list; int m_u98; TVNode *m_pSel; };
void vgui2::TreeView::vfunc116(int itemIndex)
{
	TVView *t = (TVView *)this;
	if (!t->m_list.IsValidIndex(itemIndex))
		return;
	t->m_pSel = t->m_list.Element(itemIndex).m_pData;
	t->m_pSel->RequestFocus(0);
	vfunc121(itemIndex);
	KVx *p = (KVx *)sub_101b6840(0x1c);
	vfunc43(p ? p->sub_101b56c0("TreeViewItemSelected", "itemIndex", itemIndex) : 0);
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101bd810 size=0x12
#include "vgui2__TreeView.h"
int vgui2::TreeView::vfunc117()
{
    if ((*(int *)((char *)this + 0x9c)) != 0) {
        return *(int *)((char *)(*(int *)((char *)this + 0x9c)) + 0x5c);
    }
    return -1;
}
// END FUNCTION

// FUNCTION: 0x101bd830 size=0x32
#include "vgui2__TreeView.h"
struct TVNode { int a; int b; int c; };
struct TVView { char pad[0x78]; TVNode *m_nodes; char pad2[0x94 - 0x7c]; int m_count; };
// TARGET: vgui2::TreeView::vfunc118
int vgui2::TreeView::vfunc118(int i)
{
    TVView *v = (TVView *)this;
    if (i < v->m_count && i >= 0) {
        TVNode &n = v->m_nodes[i];
        if (n.b != i || n.c == i)
            return 1;
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101bd870 size=0x7
#include "vgui2__TreeView.h"
int vgui2::TreeView::vfunc119()
{
    return *(int *)((char *)this + 0x94);
}
// END FUNCTION

// FUNCTION: 0x101bd880 size=0xc6
#include "vgui2__TreeView.h"
#include "CUtlLinkedList12.h"
struct TVLabelView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26();
	virtual void v27(const char *psz);
};
struct TVNodeView
{
	char m_pad0[0x5c];
	int m_n5c;
	TVNodeView *m_pParent;	// 0x60
	char m_pad64[4];
	TVLabelView *m_pLabel;	// 0x68
	char m_pad6c[4];
	char m_b70;
	char m_pad71[0x88 - 0x71];
	vgui2::TreeView *m_pTree;	// 0x88
};
struct TVListView
{
	char m_pad0[0x78];
	CUtlLinkedList12 m_list;
};
void vgui2::TreeView::vfunc120(int i, bool bFlag)
{
	TVListView *v = (TVListView *)this;
	if (!v->m_list.IsValidIndex(i))
		return;
	TVNodeView *pNode = (TVNodeView *)v->m_list.m_pMemory[i].m_pData;
	pNode->m_b70 = bFlag;
	if (bFlag) {
		pNode->m_pLabel->v27("-");
	} else {
		pNode->m_pLabel->v27("+");
		int nSel = pNode->m_pTree->vfunc117();
		if (nSel != -1) {
			TVListView *t = (TVListView *)pNode->m_pTree;
			TVNodeView *p = ((TVNodeView *)t->m_list.m_pMemory[nSel].m_pData)->m_pParent;
			while (p) {
				if (p == pNode) {
					pNode->m_pTree->vfunc116(pNode->m_n5c);
					break;
				}
				p = p->m_pParent;
			}
		}
	}
	pNode->m_pTree->vfunc57(0, 0);
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101bd950 size=0x27
#define V10(n) virtual void a##n##0(); virtual void a##n##1(); virtual void a##n##2(); virtual void a##n##3(); virtual void a##n##4(); virtual void a##n##5(); virtual void a##n##6(); virtual void a##n##7(); virtual void a##n##8(); virtual void a##n##9();
struct VBar { V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
 virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6();
 virtual int s107(int); virtual int s108(); };
struct VTree { char pad[0x5c]; VBar *m_pBar; int sub_101bd950(int a); };
// TARGET: ?sub_101bd950@VTree@@QAEHH@Z
int VTree::sub_101bd950(int a) { a = m_pBar->s108() - a * 3; return m_pBar->s107(a); }
// END FUNCTION

// FUNCTION: 0x101bd980 size=0x2d
#include "vgui2__TreeView.h"
namespace lifted {
struct C101aa090 { int sub_101aa090(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::TreeView::vfunc11(int a0, int a1)
{
    ((lifted::C101aa090 *)this)->sub_101aa090(a0, a1);
    ((lifted::V *)this)->f57(0, 0);
    ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101be080 size=0x5e
#include "vgui2__TreeView.h"

class Color_101be080 {
public:
	int m_v;
	Color_101be080() {}
	Color_101be080(const Color_101be080 &o) { m_v = o.m_v; }
};

struct ISchemeV_101be080 {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual void *GetBorder(const char *name);
	virtual void v4();
	virtual Color_101be080 GetColorDef(const char *name, int def);
	virtual Color_101be080 GetColor(const char *name);
};

struct PanelBaseV_101be080 {
	void sub_101ab490(int pScheme);
};

int vgui2::TreeView::vfunc74(int pScheme)
{
	((PanelBaseV_101be080 *)this)->sub_101ab490(pScheme);

	ISchemeV_101be080 *s = (ISchemeV_101be080 *)pScheme;
	vfunc60(s->GetBorder("ButtonDepressedBorder"));
	return vfunc50(s->GetColorDef("ListBgColor", s->GetColor("WindowDisabledBgColor").m_v).m_v);
}
// END FUNCTION

// FUNCTION: 0x101be0e0 size=0x17
#include "vgui2__TreeView.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::TreeView::vfunc122()
{
    ((lifted::V *)this)->f57(0, 0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101be150 size=0x6
#include "vgui2__TreeView.h"
namespace lifted {
extern char g_102d95c0;
}
int vgui2::TreeView::vfunc102()
{
    return (int)&lifted::g_102d95c0;
}
// END FUNCTION
