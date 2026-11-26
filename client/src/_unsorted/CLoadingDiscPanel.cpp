// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101670d0 size=0x351
#include "CLoadingDiscPanel.h"
#include "vgui2__TextEntry.h"

extern "C" __declspec(dllimport) void Msg(const char *pMsg, ...);

int sub_100cd0f0();
int sub_100cd100();
const char *sub_1018c870(const char *);

struct ISchemeMgrView
{
	virtual void v0();
	virtual int LoadSchemeFromFile(const char *file);
};
ISchemeMgrView *sub_101ac8c0();

struct ISurfaceView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26();
	virtual void DrawSetTextureFile(int id, const char *name, int hardwareFilter);
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void DrawGetTextureSize(int id, int &wide, int &tall);
	virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
	virtual void v37();
	virtual int CreateNewTextureID(int procedural);
};
ISurfaceView *sub_101ac8d0();

struct SColor
{
	int raw;
	SColor() {}
};

struct ISchemeView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int GetFont(const char *name);
	virtual void v5();
	virtual SColor GetColor(const char *name);
};

struct Color
{
	unsigned char r, g, b, a;
	Color(int _r, int _g, int _b, int _a) { r = _r; g = _g; b = _b; a = _a; }
};

struct PanelSetScheme
{
	void sub_101aa230(int scheme);
};

struct TextEntryCtor
{
	vgui2::TextEntry *sub_101acaa0(vgui2::Panel *parent, const char *name);
};

#define FIELD(off) (*(int *)((char *)this + (off)))

CLoadingDiscPanel::CLoadingDiscPanel(vgui2::Panel *parent)
	: vgui2::Panel(parent, "CLoadingDiscPanel")
{
	int scheme = sub_101ac8c0()->LoadSchemeFromFile("Resource/VampireScheme.res");
	if (!scheme)
		Msg("Error loading '%s'\n", "Resource/VampireScheme.res");
	((PanelSetScheme *)(void *)this)->sub_101aa230(scheme);
	sub_101a99f0(0);
	vfunc54(0);
	Color col(0, 0, 0, 255);
	vfunc51(*(int *)&col);
	vfunc63(0);
	FIELD(0x88) = 0xff;

	FIELD(0x58) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x64) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x70) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x7c) = sub_101ac8d0()->CreateNewTextureID(0);
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x58), "interface/TipInfoScreen/LoadingBar_Empty", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x58), FIELD(0x5c), FIELD(0x60));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x64), "interface/TipInfoScreen/LoadingBar_Full", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x64), FIELD(0x68), FIELD(0x6c));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x70), "interface/TipInfoScreen/Background_Default", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x70), FIELD(0x74), FIELD(0x78));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x7c), "interface/TipInfoScreen/Overlay_Info", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x7c), FIELD(0x80), FIELD(0x84));

	sub_101a98f0(sub_100cd100(), sub_100cd0f0());
	sub_101a9890(0, 0);

	ISchemeView *pScheme = (ISchemeView *)sub_101ac830();
	FIELD(0x98) = pScheme->GetFont(sub_1018c870("PercolatorSmall"));
	FIELD(0x9c) = pScheme->GetFont(sub_1018c870("Dlg_Base"));

	void *mem = vgui2::Panel::operator new(0x128);
	vgui2::TextEntry *pText = mem ? ((TextEntryCtor *)mem)->sub_101acaa0(this, "TxtHelp") : 0;
	*(vgui2::TextEntry **)((char *)this + 0x94) = pText;
	pText->vfunc132(FIELD(0x98));
	pText->vfunc107("");
	pText->vfunc51(pScheme->GetColor("TitleText").raw);
	pText->vfunc50(pScheme->GetColor("GhostControlBG").raw);
	pText->sub_101a9950((int)(217.0 * (sub_100cd100() / 1024.0)),
		(int)(191.0 * (sub_100cd0f0() / 768.0)),
		(int)(595.0 * (sub_100cd100() / 1024.0)),
		(int)(323.0 * (sub_100cd0f0() / 768.0)));
	pText->vfunc138(1);
	pText->vfunc140(0);
	pText->vfunc134(0);
	pText->vfunc62(0);
}
// END FUNCTION

// FUNCTION: 0x10167430 size=0x1e
#include "CLoadingDiscPanel.h"

// VC6 writes CLoadingDiscPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CLoadingDiscPanel *pcd_emit_10167430(const CLoadingDiscPanel &other) { return new CLoadingDiscPanel(other); }

// TARGET: ??_GCLoadingDiscPanel@@UAEPAXI@Z
// END FUNCTION
