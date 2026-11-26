// CHudManagerPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IHudManagerPanel.h"
namespace vgui2 { class Panel; }

struct HudChildNode
{
	class IManagedHudElement *m_pElement;	// 0x00
	HudChildNode *m_pNext;					// 0x04
};
struct HudChild_t
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(bool);
	void sub_10057840(int, int, int);
	void sub_100578a0(int, int, int);
	void sub_10057900(int, int, int);
	void sub_10057960(int, int, int);
	char m_pad4[0x16c];
	HudChildNode *m_pNodes;	// 0x170
};
class CHudManagerPanel : public IHudManagerPanel
{
public:
	HudChild_t *m_pChild;
	int m_nCount;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots CHudManagerPanel adds to its base's vtable: 0-38, vfuncK at slot K
	virtual void vfunc0(vgui2::Panel *parent);
	virtual void vfunc1();
	virtual bool vfunc2(int);
	virtual int vfunc3();
	virtual int vfunc4();
	virtual int vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual ~CHudManagerPanel();
	virtual int vfunc9();
	virtual int vfunc10();
	virtual int vfunc11();
	virtual int vfunc12();
	virtual int vfunc13();
	virtual int vfunc14();
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual int vfunc18();
	virtual int vfunc19();
	virtual int vfunc20();
	virtual int vfunc21();
	virtual int vfunc22();
	virtual int vfunc23();
	virtual int vfunc24();
	virtual int vfunc25();
	virtual int vfunc26();
	virtual int vfunc27();
	virtual int vfunc28();
	virtual void vfunc29();
	virtual void vfunc30();
	virtual void vfunc31();
	virtual void vfunc32();
	virtual void vfunc33();
	virtual void vfunc34();
	virtual void vfunc35();
	virtual void vfunc36();
	virtual void vfunc37();
	virtual void vfunc38();
};
