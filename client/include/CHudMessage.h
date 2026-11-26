// CHudMessage: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "CHudElement.h"

class CHudMessage : public CHudElement
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CHudMessage's own function
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc5(float fTime);
    virtual void vfunc7();
    virtual bool vfunc9();
    float sub_1010e600(float fadein, float fadeout, float hold, float localTime);
    int sub_1010e6a0(float f, int width, int totalWidth);
    int sub_1010e740(float f, int totalHeight);
    void sub_1010e7f0();
    void sub_1010e9b0();
    void sub_1010eb20(struct client_textmessage_s *pMessage, float time);

    struct client_textmessage_s *m_pMessages[16];
    float m_startTime[16];
    struct client_textmessage_s *m_pMessage;
    float m_time;
    int m_x;
    int m_y;
    int m_totalWidth;
    int m_totalHeight;
    int m_width;
    int m_lines;
    int m_lineLength;
    int m_length;
    int m_r;
    int m_g;
    int m_b;
    int m_text;
    int m_fadeBlend;
    float m_charTime;
    int m_unkd0;
    float m_gameTitleTime;
    struct client_textmessage_s *m_pGameTitle;
    bool m_bHaveMessage;
    int m_HUD_title_life;
    int m_HUD_title_half;
};
