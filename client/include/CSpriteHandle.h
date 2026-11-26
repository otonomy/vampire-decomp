// CSpriteHandle: the object the engine's sprite lookup returns (hand-made from 0x10081cd0, 0x10136f80, 0x10136f90)
#pragma once
class CSpriteHandle
{
public:
	int m_unk00;
	int m_unk04;
	int m_unk08;
	void *m_pMaterial;	// 0x0c
	void *m_unk10;
	void *m_unk14;
	int m_nOrientation;	// 0x18 (sub_10136fc0)
	int m_unk1c;
	int m_unk20;
	int m_unk24;
	float m_flUp;	// 0x28
	float m_flDown;	// 0x2c
	float m_flLeft;	// 0x30
	float m_flRight;	// 0x34
	int sub_10136fc0();	// GetOrientation
	float GetUp() const { return m_flUp; }
	float GetDown() const { return m_flDown; }
	float GetLeft() const { return m_flLeft; }
	float GetRight() const { return m_flRight; }
	void sub_10136f80(float);
	void sub_10136f90(int);
};
