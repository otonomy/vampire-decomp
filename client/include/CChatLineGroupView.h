// CChatLineGroupView: a chat-like panel holding 6 line panels at +0x68 (stand-in view for hud_chat.cpp).
#pragma once
class CChatLineView
{
public:
	virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
	virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9();
	virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
	virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
	virtual void vf20(); virtual void vf21();
	virtual bool IsVisible();
};

class CChatLineGroupView
{
public:
	int m_unk00; int m_unk04; int m_unk08; int m_unk0c;
	int m_unk10; int m_unk14; int m_unk18; int m_unk1c;
	int m_unk20; int m_unk24; int m_unk28; int m_unk2c;
	int m_unk30; int m_unk34; int m_unk38; int m_unk3c;
	int m_unk40; int m_unk44; int m_unk48; int m_unk4c;
	int m_unk50; int m_unk54; int m_unk58; int m_unk5c;
	int m_unk60; int m_unk64;
	CChatLineView *m_pLines[6];	// +0x68
	bool m_b80;
	bool m_b81;
	void sub_100f2510();
	int sub_100f1ee0(int width, const char *text, int len);
	void sub_100f2060(int a, int b, int c, char *str);
};
