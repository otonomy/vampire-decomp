// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010e540 size=0x1e
#include "CHudMessage.h"

// VC6 writes CHudMessage's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudMessage *pcd_emit_1010e540(const CHudMessage &other) { return new CHudMessage(other); }

// TARGET: ??_GCHudMessage@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1010e560 size=0x35
#include "CHudMessage.h"
namespace lifted {
extern char g_1010e4c0;
extern char g_1010e4f0;
extern char g_10281d54;
extern char g_102bec5c;
extern int g_104a57d4;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual int f7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual int f29(int, int); };
}
void CHudMessage::vfunc1()
{
    ((lifted::V *)lifted::g_104a57d4)->f29((int)&lifted::g_10281d54, (int)&lifted::g_1010e4c0);
    ((lifted::V *)lifted::g_104a57d4)->f29((int)&lifted::g_102bec5c, (int)&lifted::g_1010e4f0);
    ((lifted::V *)this)->f7();
}
// END FUNCTION

// FUNCTION: 0x1010e5a0 size=0x2f
#include "CHudMessage.h"
namespace lifted {
extern char g_102bec68;
extern char g_102bec74;
extern char g_104cfe38;
struct C100f11d0 { int sub_100f11d0(int); };
}
void CHudMessage::vfunc2()
{
    int t0 = ((lifted::C100f11d0 *)((int)&lifted::g_104cfe38))->sub_100f11d0((int)&lifted::g_102bec74);
    *(int *)((char *)this + 0xe4) = t0;
    int t1 = ((lifted::C100f11d0 *)((int)&lifted::g_104cfe38))->sub_100f11d0((int)&lifted::g_102bec68);
    *(int *)((char *)this + 0xe0) = t1;
}
// END FUNCTION

// FUNCTION: 0x1010e5d0 size=0x2d
#include "CHudMessage.h"
#include <string.h>
struct XHM { char u0[0x10]; int a[16]; int b[16]; char u1[0xd4 - 0x90]; int m_d4; int m_d8; char m_dc; };
// TARGET: CHudMessage::vfunc7
void CHudMessage::vfunc7()
{
	XHM *p = (XHM *)this;
	memset(p->a, 0, sizeof(p->a));
	memset(p->b, 0, sizeof(p->b));
	p->m_d4 = 0;
	p->m_d8 = 0;
	p->m_dc = 0;
}
// END FUNCTION

// FUNCTION: 0x1010ed40 size=0x2af
#include "CHudMessage.h"
#include <string.h>

typedef struct client_textmessage_s
{
	int effect;
	unsigned char r1, g1, b1, a1;
	unsigned char r2, g2, b2, a2;
	float x;
	float y;
	float fadein;
	float fadeout;
	float holdtime;
	float fxtime;
	const char *pName;
	const char *pMessage;
} client_textmessage_t;

extern float g_104cfe3c;
int sub_100ccdc0(int sprite);
int sub_100ccde0(int sprite);
void sub_100ccd10(int x, int y, int sprite, int r, int g, int b);

void CHudMessage::vfunc5(float fTime)
{
	int i, drawn;
	client_textmessage_t *pMessage;
	float endTime;

	drawn = 0;

	if (m_gameTitleTime > 0)
	{
		float localTime = g_104cfe3c - m_gameTitleTime;
		float brightness;

		if (m_gameTitleTime > g_104cfe3c)
			m_gameTitleTime = g_104cfe3c;

		if (localTime > (m_pGameTitle->fadein + m_pGameTitle->holdtime + m_pGameTitle->fadeout))
			m_gameTitleTime = 0;
		else
		{
			brightness = sub_1010e600(m_pGameTitle->fadein, m_pGameTitle->fadeout, m_pGameTitle->holdtime, localTime);

			int halfWidth = sub_100ccdc0(m_HUD_title_half);
			int fullWidth = halfWidth + sub_100ccdc0(m_HUD_title_life);
			int fullHeight = sub_100ccde0(m_HUD_title_half);

			int x = sub_1010e6a0(m_pGameTitle->x, fullWidth, fullWidth);
			int y = sub_1010e740(m_pGameTitle->y, fullHeight);

			sub_100ccd10(x, y, m_HUD_title_half, m_pGameTitle->r1 * brightness, m_pGameTitle->g1 * brightness, m_pGameTitle->b1 * brightness);
			sub_100ccd10(x + halfWidth, y, m_HUD_title_life, m_pGameTitle->r1 * brightness, m_pGameTitle->g1 * brightness, m_pGameTitle->b1 * brightness);

			drawn = 1;
		}
	}

	for (i = 0; i < 16; i++)
	{
		if (m_pMessages[i])
		{
			if (m_startTime[i] > g_104cfe3c)
				m_startTime[i] = g_104cfe3c + m_time - m_startTime[i] + 0.2;
		}
	}

	for (i = 0; i < 16; i++)
	{
		if (m_pMessages[i])
		{
			pMessage = m_pMessages[i];

			switch (pMessage->effect)
			{
			case 0:
			case 1:
				endTime = m_startTime[i] + pMessage->fadein + pMessage->fadeout + pMessage->holdtime;
				break;
			case 2:
				endTime = m_startTime[i] + (pMessage->fadein * strlen(pMessage->pMessage)) + pMessage->fadeout + pMessage->holdtime;
				break;
			default:
				endTime = 0;
				break;
			}

			if (fTime <= endTime)
			{
				float messageTime = fTime - m_startTime[i];
				sub_1010eb20(pMessage, messageTime);
				drawn++;
			}
			else
			{
				m_pMessages[i] = NULL;
			}
		}
	}

	*(int *)&m_time = *(int *)&g_104cfe3c;
	if (!drawn)
		m_bHaveMessage = false;
}
// END FUNCTION
