// vgui2::FocusNavGroup: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once

struct PanelX;
class CUnknown101ac6b0
{
public:
    int m_h;
    CUnknown101ac6b0() { m_h = -1; }
    PanelX *sub_101ac6b0(PanelX *);
};
namespace vgui2
{
class Panel;
class FocusNavGroup
{
public:
    FocusNavGroup(vgui2::Panel *);
    int m_unk4;
    vgui2::Panel *m_pPanel;
    CUnknown101ac6b0 m_hCurrent;
    bool m_bFlag;	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots FocusNavGroup adds to its base's vtable: 0-8, vfuncK at slot K
    virtual Panel *vfunc0();
    virtual void vfunc1(vgui2::Panel *p);
    virtual int vfunc2();
    virtual int vfunc3(int);
    virtual void vfunc4(vgui2::Panel *);
    virtual void vfunc5();
    virtual int vfunc6();
    virtual int vfunc7();
    virtual bool vfunc8(char);
};
}
