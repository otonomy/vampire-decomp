// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017c950 size=0x1e
#include "VHButton.h"

// VC6 writes VHButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VHButton *pcd_emit_1017c950(const VHButton &other) { return new VHButton(other); }

// TARGET: ??_GVHButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017c980 size=0x5f
#include "VHButton.h"

struct HBtnColor { unsigned char r, g, b, a; };
struct HBtnView { char m_pad[0xfc]; bool m_bFC; };

// TARGET: VHButton::vfunc74
int VHButton::vfunc74(int pScheme)
{
	HBtnColor c;
	Button::vfunc74(pScheme);
	if (((HBtnView *)this)->m_bFC)
	{
		c.r = 0x7d; c.g = 0xa7; c.b = 0xd9; c.a = 0xff;
		return vfunc51(*(int *)&c);
	}
	c.r = 0xff; c.g = 0xff; c.b = 0xff; c.a = 0xff;
	return vfunc51(*(int *)&c);
}
// END FUNCTION

// FUNCTION: 0x1017c9e0 size=0x423
#include "VHButton.h"
#include "C_BasePlayer.h"
#include <stdlib.h>
#include <string.h>

void __cdecl sub_1007db20();
void **sub_1017ce10();

struct CStatBlock_1017c9e0
{
    int m_a, m_b, m_c, m_d;

    int GetType() const { return m_a; }
    int GetStat() const { return m_b; }
    void *sub_101613a0(const char *pszName);
    bool sub_10160660();
    void sub_101608a0(const char *pszName);
    bool sub_101613e0(const CStatBlock_1017c9e0 *pOther);
};

struct CStatLabel_1017c9e0
{
    void sub_1017d310(char bHighlight);
};

struct CStatRow_1017c9e0
{
    CStatLabel_1017c9e0 *m_pLabel;
    int m_pad[8];
};

struct CStatGroup_1017c9e0
{
    char m_pad[0x3c];
    CStatRow_1017c9e0 *m_pRows;

    int sub_1017f870(int statId);
    void HighlightRow(int idx, char bHighlight)
    {
        m_pRows[idx].m_pLabel->sub_1017d310(bHighlight);
    }
};

struct CStatsPanel_1017c9e0
{
    char m_pad[0x1f0];
    int m_n1f0;
    void sub_10182100(vgui2::Button *arg);
    void sub_10181960();
    void sub_10181a30();
    void sub_101820f0(int arg);
};

struct CVFeat_1017c9e0
{
    int m_id;
    char m_pad04[0x18];
    int m_nBlocks;
    CStatBlock_1017c9e0 *m_pBlocks;
    char m_pad24[0x14];

    void *sub_1014ada0(int id);
    int sub_1014b3b0(C_BasePlayer *pPlayer);
};

extern int g_105e8138;
extern CVFeat_1017c9e0 **g_105e813c;
extern unsigned char g_10680f34;
extern CVFeat_1017c9e0 g_10680f40;

extern int g_105fb600[];
extern int g_105fb640[];
extern CStatsPanel_1017c9e0 *g_105fb6e4;
extern CStatGroup_1017c9e0 *g_105fb6e8;
extern CStatGroup_1017c9e0 *g_105fb6ec;
extern CStatGroup_1017c9e0 *g_105fb6f0;

inline CVFeat_1017c9e0 *FindFeat_1017c9e0(int id)
{
    for (int i = 0; i < g_105e8138; i++)
    {
        if (g_105e813c[i]->m_id == id)
            return g_105e813c[i];
    }
    if (!(g_10680f34 & 1))
    {
        g_10680f34 |= 1;
        g_10680f40.sub_1014ada0(-1);
        atexit(sub_1007db20);
    }
    return &g_10680f40;
}

#define VHB_F0(p) (*(int *)((char *)(p) + 0xf0))
#define VHB_F4(p) (*(int *)((char *)(p) + 0xf4))
#define VHB_F8(p) (*(vgui2::Button **)((char *)(p) + 0xf8))

void VHButton::vfunc85()
{
    VHButton *self = this;
    Button::vfunc85();
    int nArg = -1;
    const char *cmd = vfunc18();
    if (cmd[0] == 'f' && cmd[1] == ' ')
    {
        int id = g_105fb600[atoi(cmd + 2)];
        CStatBlock_1017c9e0 *pBlocks = FindFeat_1017c9e0(id)->m_pBlocks;
        C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
        if (pPlayer && FindFeat_1017c9e0(id)->sub_1014b3b0(pPlayer) > 0)
        {
            for (int i = 0; i < 2; i++)
            {
                int stat = pBlocks[i].GetStat();
                int idx;
                switch (pBlocks[i].GetType())
                {
                case 0:
                    idx = g_105fb6e8->sub_1017f870(stat);
                    if (idx != -1)
                        g_105fb6e8->HighlightRow(idx, 1);
                    break;
                case 1:
                    idx = g_105fb6ec->sub_1017f870(stat);
                    if (idx != -1)
                        g_105fb6ec->HighlightRow(idx, 1);
                    break;
                case 2:
                    idx = g_105fb6f0->sub_1017f870(stat);
                    if (idx != -1)
                        g_105fb6f0->HighlightRow(idx, 1);
                    break;
                }
            }
        }
        self->vfunc150();
    }
    else if (cmd[0] == 'H' && cmd[1] == ' ')
    {
        if (g_105fb6e4)
            g_105fb6e4->sub_10181960();
    }
    else if (cmd[0] == 'M' && cmd[1] == ' ')
    {
        if (g_105fb6e4)
            g_105fb6e4->sub_10181a30();
    }
    else
    {
        CStatBlock_1017c9e0 block;
        block.sub_101613a0(cmd);
        if (block.sub_10160660())
        {
            const char *p = strrchr(cmd, ' ');
            if (p)
                block.sub_101608a0(p + 1);
        }
        CStatLabel_1017c9e0 **pLabels = (CStatLabel_1017c9e0 **)sub_1017ce10();
        nArg = VHB_F0(this);
        if (pLabels)
        {
            C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
            if (pPlayer)
            {
                for (int j = 0; j < 0x17; j++)
                {
                    CStatBlock_1017c9e0 *pBlock = FindFeat_1017c9e0(j)->m_pBlocks;
                    char bFound = 0;
                    if (FindFeat_1017c9e0(j)->sub_1014b3b0(pPlayer) > 0)
                    {
                        for (int k = 0; k < FindFeat_1017c9e0(j)->m_nBlocks; k++)
                        {
                            if (pBlock[k].sub_101613e0(&block))
                            {
                                bFound = 1;
                                break;
                            }
                        }
                    }
                    int lab = g_105fb640[j];
                    if (lab != -1 && lab >= 0 && lab < 16)
                        pLabels[lab]->sub_1017d310(bFound);
                }
            }
        }
    }

    if ((g_105fb6e4->m_n1f0 != VHB_F4(self) && VHB_F4(self) != 0) || nArg > 0)
    {
        if (VHB_F8(self))
        {
            g_105fb6e4->sub_101820f0(nArg);
            VHB_F8(self)->vfunc150();
            g_105fb6e4->sub_10182100(VHB_F8(self));
        }
    }
}
// END FUNCTION

// FUNCTION: 0x1017ce20 size=0x295
#include "VHButton.h"
#include <stdlib.h>
#include <string.h>

void __cdecl sub_1007db20();
int sub_1017ce10();

struct CStatBlock_1017ce20
{
	int m_a, m_b, m_c, m_d;

	int GetType() const { return m_a; }
	int GetStat() const { return m_b; }
	void *sub_101613a0(const char *pszName);
	bool sub_10160660();
	void sub_101608a0(const char *pszName);
	bool sub_101613e0(const CStatBlock_1017ce20 *pOther);
};

struct CStatLabel_1017ce20
{
	void sub_1017d310(char bHighlight);
};

struct CStatRow_1017ce20
{
	CStatLabel_1017ce20 *m_pLabel;
	int m_pad[8];
};

struct CStatGroup_1017ce20
{
	char m_pad[0x3c];
	CStatRow_1017ce20 *m_pRows;

	int sub_1017f870(int statId);
	void HighlightRow(int idx, char bHighlight)
	{
		m_pRows[idx].m_pLabel->sub_1017d310(bHighlight);
	}
};

struct CStatsPanel_1017ce20
{
	void sub_10182100(int arg);
};

struct CVFeat_1017ce20
{
	int m_id;
	char m_pad04[0x18];
	int m_nBlocks;
	CStatBlock_1017ce20 *m_pBlocks;
	char m_pad24[0x14];

	void *sub_1014ada0(int id);
};

extern int g_105e8138;
extern CVFeat_1017ce20 **g_105e813c;
extern unsigned char g_10680f34;
extern CVFeat_1017ce20 g_10680f40;

extern int g_105fb600[];
extern int g_105fb640[];
extern CStatsPanel_1017ce20 *g_105fb6e4;
extern CStatGroup_1017ce20 *g_105fb6e8;
extern CStatGroup_1017ce20 *g_105fb6ec;
extern CStatGroup_1017ce20 *g_105fb6f0;

inline CVFeat_1017ce20 *FindFeat_1017ce20(int id)
{
	for (int i = 0; i < g_105e8138; i++)
	{
		if (g_105e813c[i]->m_id == id)
			return g_105e813c[i];
	}
	if (!(g_10680f34 & 1))
	{
		g_10680f34 |= 1;
		g_10680f40.sub_1014ada0(-1);
		atexit(sub_1007db20);
	}
	return &g_10680f40;
}

// TARGET: VHButton::vfunc86
void VHButton::vfunc86()
{
	typedef vgui2::Button BaseClass;
	BaseClass::vfunc86();

	if (!g_105fb6e4)
		return;

	g_105fb6e4->sub_10182100(0);

	const char *pszName = vfunc18();
	if (pszName[0] == 'f' && pszName[1] == ' ')
	{
		CStatBlock_1017ce20 *pBlocks = FindFeat_1017ce20(g_105fb600[atoi(pszName + 2)])->m_pBlocks;
		for (int i = 0; i < 2; i++)
		{
			int idx;
			switch (pBlocks[i].GetType())
			{
			case 0:
				idx = g_105fb6e8->sub_1017f870(pBlocks[i].GetStat());
				if (idx != -1)
					g_105fb6e8->HighlightRow(idx, 0);
				break;
			case 1:
				idx = g_105fb6ec->sub_1017f870(pBlocks[i].GetStat());
				if (idx != -1)
					g_105fb6ec->HighlightRow(idx, 0);
				break;
			case 2:
				idx = g_105fb6f0->sub_1017f870(pBlocks[i].GetStat());
				if (idx != -1)
					g_105fb6f0->HighlightRow(idx, 0);
				break;
			}
		}
	}
	else
	{
		CStatBlock_1017ce20 block;
		block.sub_101613a0(pszName);
		if (block.sub_10160660())
		{
			const char *pSpace = strrchr(pszName, ' ');
			if (pSpace)
				block.sub_101608a0(pSpace + 1);
		}

		CStatLabel_1017ce20 **pFeatLabels = (CStatLabel_1017ce20 **)sub_1017ce10();
		if (!pFeatLabels)
			return;

		for (int i = 0; i < 16; i++)
		{
			CStatBlock_1017ce20 *pBlocks = FindFeat_1017ce20(i)->m_pBlocks;
			for (int j = 0; j < FindFeat_1017ce20(i)->m_nBlocks; j++)
			{
				if (pBlocks[j].sub_101613e0(&block))
				{
					int labelIdx = g_105fb640[i];
					if (labelIdx >= 0 && labelIdx < 16)
						pFeatLabels[labelIdx]->sub_1017d310(0);
					break;
				}
			}
		}
	}
}
// END FUNCTION

// FUNCTION: 0x1017d0c0 size=0x4e
#include "VHButton.h"

extern void sub_1017c680(const char *);

void VHButton::vfunc143(char state)
{
	bool bWasArmed = vfunc144();
	Button::vfunc143(state);
	if (vfunc144() != bWasArmed)
	{
		sub_1017c680(vfunc144() ? "interface/bubble_click_on.wav" : "interface/bubble_click_off.wav");
	}
}
// END FUNCTION
