// C_TempEntsSystem: declared by pcdecomp transplant for 0x100c6420 from IParticleEffect (0x10004e30);
// only what matched code needs, as plain members.
#pragma once

class C_TempEntsSystem
{
public:
	void *m_pVtable;
	int m_unk04;
	bool m_bSuppressEvent;
	char m_pad09[7];
	int m_nSuppressCount;

	bool CanPredict() const
	{
		if ( m_nSuppressCount > 0 )
			return false;
		return !m_bSuppressEvent;
	}
	void vfunc6(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19);
	void vfunc8(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17);
	void vfunc11(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17);
	void vfunc10(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16);
	void vfunc23(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15);
	void vfunc24(int filter, int a1, int a2, int a3, int a4, int a5, int a6);
	void vfunc27(int filter, int a1, int a2, int a3, int a4, int a5, int a6);
	void vfunc40(int filter, int a1, int a2, int a3, int a4, int a5, int a6);
	void vfunc17(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
	void vfunc18(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
	void vfunc37(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
	void vfunc32(int, int, int, int, int, int);
	void vfunc35(int, int, int, int, int, int);
	void vfunc42(int, int, int, int, int, int);
	void vfunc13(int, int, int, int, int, int, int, int, int);
	void vfunc14(int, int, class Vector *, class Vector *, int, int, int, int, int);
	void vfunc21(void *filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);
	void * vfunc0(char);
	void vfunc31(int filter, int delay, int pos, int dir, int extra);
	void vfunc28(int filter, int delay, int pos, int dir, int extra);
	void vfunc29(int filter, int delay, int pos);
	void vfunc2(int filter, int delay, int pos, int dir, int extra);
	void vfunc36(int filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
	void vfunc30(int filter, int delay, int pos, int dir);
	void vfunc5(int filter, int delay, int pos, int dir);	// as in C_TempEntsSystem (transplant)
	void vfunc9(void *filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18);
	void vfunc12(int filter, int delay, int pos, int dir);	// as in C_TempEntsSystem (transplant)
	void vfunc22(int filter, int delay, int pos, int dir);	// as in C_TempEntsSystem (transplant)
	void vfunc33(int filter, int delay, int pos, int dir);
	void vfunc34(int filter, int delay, int pos, int dir, int extra, int extra2);	// as in C_TempEntsSystem (transplant)
	void vfunc38(int filter, int delay, int pos, int dir);	// as in C_TempEntsSystem (transplant)
	void vfunc41(int filter, int delay, int pos, int dir);	// as in C_TempEntsSystem (transplant)
	void vfunc43(int filter, int a, int b, int c, int d, int e);
	void vfunc15(int, int, int, int, int, int, int, int, int, int);
	void vfunc20(int, int, int, int, int, int, int, int, int, int);
	void vfunc16(int filter, int delay, int pos, int dir, int extra);	// as in C_TempEntsSystem (transplant)
	void vfunc39(int filter, int delay, int pos, int dir, int extra);	// as in C_TempEntsSystem (transplant)
	void vfunc7(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17);	// as in C_TempEntsSystem (transplant)
};
