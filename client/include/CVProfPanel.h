// CVProfPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "vgui2__Panel.h"

class CVProfPanel;
// Builds CVProfPanel's two member panels in place: the title Label at +0x6c and the "Hierarchy" view at +0x124.
// vgui2__Panel.h declares Panel as 0x170 bytes (the game's is 0x58), so these members cannot be declared at their
// offsets yet; this empty member runs their constructors where the game's member initialisation does.
struct CVProfPanelMembers
{
	CVProfPanelMembers(CVProfPanel *p);
};
struct CVProfTreeView	// the "Hierarchy" control at +0x124 (constructor 0x101bc4f0)
{
	void sub_101bc4f0(vgui2::Panel *parent, const char *name);
};
extern char g_102de300[];

class CVProfPanel : public CHudElement, public vgui2::Panel
{
public:
	virtual ~CVProfPanel();
	CVProfPanel(const char *pElementName);
	CVProfPanelMembers m_members;
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
	virtual int vfunc74(int scheme);	// ApplySchemeSettings: the title label at +0x6c, the tree view at +0x124 (vgui2::Panel is 0x5c bytes in the game; the header's Panel is larger, hence the casts)
	bool CHudElement_vfunc9();	// as in CHudHistoryResource (transplant)
	void sub_1018dda0(void *kv, void *node, int parent);
	void sub_1018dba0();
};

#include "vgui2__Label.h"
namespace vgui2 {
inline void CVProfPanel_BuildMembers(CVProfPanel *p)
{
	((Label *)((char *)p + 0x6c))->Label::Label((Panel *)p, "TitleLabel", g_102de300);
	((CVProfTreeView *)((char *)p + 0x124))->sub_101bc4f0((Panel *)p, "Hierarchy");
}
}
inline CVProfPanelMembers::CVProfPanelMembers(CVProfPanel *p)
{
	vgui2::CVProfPanel_BuildMembers(p);
}
