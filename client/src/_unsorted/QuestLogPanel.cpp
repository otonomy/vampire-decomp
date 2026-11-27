// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10188050 size=0x1e
#include "QuestLogPanel.h"

// VC6 writes QuestLogPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
QuestLogPanel *pcd_emit_10188050(const QuestLogPanel &other) { return new QuestLogPanel(other); }

// TARGET: ??_GQuestLogPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10188430 size=0x14a
#include "QuestLogPanel.h"

char *sub_10170f60();
int sub_100cd100();
int sub_100cd0f0();
struct SchemeView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void *v3(const char *); };

#define XRES(x) (int)((x) * (sub_100cd100() * 0.0009765625))
#define YRESD(y) ((y) * (sub_100cd0f0() * 0.0013020833333333333))
#define YRES(y) (int)YRESD(y)

// TARGET: ??0QuestLogPanel@@QAE@XZ
QuestLogPanel::QuestLogPanel()
{
	char *p = sub_10170f60();
	sub_101a9ff0((int)(p ? p + 0x10 : 0));
	sub_10189990(0);
	PropertyPage::vfunc39(0);
	int x = XRES(0.0);
	int y = YRES(90.0);
	int w = sub_100cd100() - x * 2;
	int h = (int)((double)(sub_100cd0f0() - y * 2) - YRESD(90.0) * 2);
	sub_101a9950(x, y, w, h);
	unsigned char c[4];
	c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0xaf;
	PropertyPage::vfunc50(*(int *)c);
	PropertyPage::vfunc54(2);
	sub_101aa0a0(0x3e8);
	sub_101aafb0(((SchemeView *)sub_101ac830())->v3("ToolTipBorder"));
	PropertyPage::vfunc62(0);
	PropertyPage::vfunc63(0);
	sub_10188730();
	QuestLogPanel::vfunc101();
}
// END FUNCTION

// FUNCTION: 0x10188580 size=0x10
#include "QuestLogPanel.h"
namespace lifted {
struct C10189130 { int sub_10189130(); };
struct C101ab2f0 { int sub_101ab2f0(); };
}
void QuestLogPanel::vfunc101()
{
    ((lifted::C101ab2f0 *)this)->sub_101ab2f0();
    ((lifted::C10189130 *)this)->sub_10189130();
}
// END FUNCTION

// FUNCTION: 0x10189380 size=0x9e
#include "C_BasePlayer.h"
#include "QuestLogPanel.h"
#include "CHud.h"
#include "CharEditPanel.h"
extern "C" int _strcmpi(const char *, const char *);
extern "C" char *strstr(const char *, const char *);
extern "C" int atoi(const char *);
extern CHud g_104cfe38;
struct QLView { void sub_10189600(); };
void QuestLogPanel::vfunc78(int command)
{
	if (C_BasePlayer::GetLocalPlayer()) {
		const char *pszCommand = (const char *)command;
		if (!_strcmpi(pszCommand, "refresh")) {
			((QLView *)this)->sub_10189600();
			return;
		}
		if (strstr(pszCommand, "QB") == pszCommand) {
			sub_101892d0(atoi(pszCommand + 2) - 1);
			return;
		}
		if (!_strcmpi(pszCommand, "accept")) {
			CharEditPanel *pPanel = (CharEditPanel *)g_104cfe38.sub_100f0ed0("CharEditPanel");
			pPanel->sub_101733d0(false);
			return;
		}
		PropertyPage::vfunc78(command);
	}
}
// END FUNCTION

// FUNCTION: 0x10189420 size=0x3
#include "QuestLogPanel.h"
void QuestLogPanel::vfunc124(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101895b0 size=0x6
#include "QuestLogPanel.h"
namespace lifted {
extern char g_102d3808;
}
int QuestLogPanel::vfunc102()
{
    return (int)&lifted::g_102d3808;
}
// END FUNCTION

// FUNCTION: 0x101895c0 size=0x3
#include "QuestLogPanel.h"
void QuestLogPanel::vfunc125(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101895e0 size=0x1
#include "QuestLogPanel.h"
void QuestLogPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x10189960 size=0x21
#include "QuestLogPanel.h"
int sub_1016a6b0();
void QuestLogPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x10189a10 size=0xe
#include "QuestLogPanel.h"
namespace lifted {
extern int g_104a57d4;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(); };
}
void QuestLogPanel::vfunc3()
{
    ((lifted::V *)lifted::g_104a57d4)->f57();
}
// END FUNCTION
