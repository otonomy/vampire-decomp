// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10171040 size=0x59
#include "CLabelHeader.h"
#pragma warning(disable: 4716)
struct ColorV
{
	unsigned char c[4];
	ColorV(int r, int g, int b, int a) { c[0] = r; c[1] = g; c[2] = b; c[3] = a; }
};
struct TgtV2 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void f3(int); };
struct TgtV { void *vt; char pad[0x1c]; TgtV2 *m_p20; };
typedef vgui2::Label BaseClass;
// TARGET: CLabelHeader::vfunc74
int CLabelHeader::vfunc74(int pScheme)
{
	BaseClass::vfunc74(pScheme);
	TgtV *p = *(TgtV **)((char *)this + 0xb8);
	ColorV c(255, 170, 0, 0);
	p->m_p20->f3(*(int *)&c);
	ColorV d(0, 0, 0, 0);
	vfunc50(*(int *)&d);
}
// END FUNCTION

// FUNCTION: 0x101710a0 size=0xb4
#include "CLabelHeader.h"

struct ITextImgLocal
{
	virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
	virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
	virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
	virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
	virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
	virtual void u24(); virtual void u25(); virtual void u26();
	virtual void SetText(const char *text);
	virtual void u28(); virtual void u29(); virtual void u30();
	virtual unsigned long GetFont();
};

struct CDualImgLocal
{
	char pad0[0x1c];
	ITextImgLocal *m_pImages[2];
	ITextImgLocal *GetImage(int idx) { return m_pImages[idx]; }
};

struct ISurfaceLocal
{
	virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
	virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
	virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
	virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
	virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
	virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
	virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
	virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
	virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
	virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43();
	virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
	virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51();
	virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55();
	virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59();
	virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63();
	virtual void GetCharABCwide(unsigned long font, int ch, int &a, int &b, int &c);
};

extern ISurfaceLocal *sub_101ac8d0();
extern int sub_100cd100();

// TARGET: CLabelHeader::vfunc138
void CLabelHeader::vfunc138(int textBufferLen, const char *text)
{
	CDualImgLocal *&dualImage = *(CDualImgLocal **)((char *)this + 0xb8);
	int &gap = *(int *)((char *)this + 0xc0);

	dualImage->GetImage(0)->SetText(text);

	unsigned long font = dualImage->GetImage(0)->GetFont();
	gap = 0;
	for (const char *ch = text; *ch != 0; ch++)
	{
		int a, b, c;
		sub_101ac8d0()->GetCharABCwide(font, *ch, a, b, c);
		gap += (a + b + c);
	}

	gap += (sub_100cd100() / 640.0) * 5.0;
}
// END FUNCTION

// FUNCTION: 0x10171160 size=0x105
#include "CLabelHeader.h"
#include <ctype.h>
extern "C" unsigned int strlen(const char *);
#pragma intrinsic(strlen)
extern int sub_100cd100();
struct TextObj_10171160
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26();
	virtual void SetText(const char *text);
	virtual void v28(); virtual void v29(); virtual void v30();
	virtual int GetFont();
};
struct Holder_10171160
{
	char m_pad[0x1c];
	TextObj_10171160 *m_pText;
};
struct Surface_10171160
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void GetCharABCwide(int font, int ch, int *a, int *b, int *c);
};
extern Surface_10171160 *sub_101ac8d0();
#define XSCALE_10171160(x) ((int)((x) * ((float)sub_100cd100() / 640.0)))
void CLabelHeader::vfunc108(const char *pText)
{
	int a, b, c;
	char buf[0x200];
	const char *s = pText;
	char *d = buf;
	while ((*d++ = *s++) != 0)
		;
	int len = strlen(buf);
	while (len && isspace(buf[--len]))
	{
		buf[len] = 0;
		if (!len)
			break;
	}
	(*(Holder_10171160 **)((char *)this + 0xb8))->m_pText->SetText(buf);
	int font = (*(Holder_10171160 **)((char *)this + 0xb8))->m_pText->GetFont();
	*(int *)((char *)this + 0xc0) = 0;
	for (char *p = buf; *p; p++)
	{
		sub_101ac8d0()->GetCharABCwide(font, *p, &a, &b, &c);
		*(int *)((char *)this + 0xc0) += a + b + c;
	}
	double k = sub_100cd100() * 0.0015625;
	*(int *)((char *)this + 0xc0) = (int)(k * 5.0 + *(int *)((char *)this + 0xc0));
}
// END FUNCTION

// FUNCTION: 0x10171320 size=0xe
#include "CLabelHeader.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual int f30(); };
}
void CLabelHeader::vfunc118()
{
    ((lifted::V *)(*(int *)((char *)(*(int *)((char *)this + 0xb8)) + 0x1c)))->f30();
}
// END FUNCTION

// FUNCTION: 0x10171330 size=0x37
#include "CLabelHeader.h"
// TARGET: ??_GCLabelHeader@@UAEPAXI@Z
CLabelHeader *pcd_emit_10171330() { return new CLabelHeader(0, 0, 0); }
// END FUNCTION
