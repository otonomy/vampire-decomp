// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101acaa0 size=0x2eb
#include "vgui2__TextEntry.h"
extern "C" void *memset(void *, int, unsigned int);
extern "C" __declspec(noreturn) void exit(int);
#pragma intrinsic(memset)

struct IScheme_v { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int GetFont(const char *name); };
struct ISchemeManager_v { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual IScheme_v *GetIScheme(int scheme); };
ISchemeManager_v *sub_101ac8c0();
struct VTE { void sub_101ad500(); };

struct DarInt
{
	int m_count, m_capacity; int *m_data;
	void AddToTail(int v)
	{
		int n = m_count + 1;
		if (n > m_capacity)
		{
			int cap = m_capacity;
			if (cap == 0) cap = 1;
			while (cap < n) cap *= 2;
			int *p = (int *)operator new(cap * sizeof(int));
			if (!p) exit(0);
			memset(p, 0, cap * sizeof(int));
			m_capacity = cap;
			for (int i = 0; i < m_count; i++) p[i] = m_data[i];
			operator delete(m_data);
			m_data = p;
		}
		m_data[m_count] = v;
		m_count++;
	}
};

struct SColor { unsigned char c[4]; SColor(int r, int g, int b, int a) { c[0] = r; c[1] = g; c[2] = b; c[3] = a; } };

#define F(T, o) (*(T *)((char *)this + (o)))

vgui2::TextEntry::TextEntry(Panel *parent, const char *name) : Panel(parent, name)
{
	F(int, 0x124) = sub_101ac8c0()->GetIScheme(sub_101aa220())->GetFont("Default");
	F(bool, 0x89) = false;
	F(bool, 0x8a) = false;
	F(bool, 0xb2) = false;
	F(int, 0x70) = 0;
	F(int, 0xd0) = 0;
	F(bool, 0xd4) = true;
	F(bool, 0x74) = false;
	F(bool, 0x75) = false;
	F(bool, 0xb1) = false;
	F(int, 0x98) = 400;
	F(bool, 0x8b) = false;
	F(bool, 0x8c) = false;
	F(bool, 0x8d) = false;
	F(int, 0xb4) = 0;
	F(bool, 0x100) = true;
	F(bool, 0xf4) = false;
	F(int, 0xac) = -1;
	F(int, 0xa8) = 0;
	F(bool, 0xf5) = false;
	F(bool, 0xf6) = false;
	F(int, 0xf8) = 0;
	F(int, 0x9c) = -1;
	F(int, 0xa0) = -1;
	F(int, 0xfc) = 0;
	((VTE *)this)->sub_101ad500();
	vfunc54(2);
	vfunc119();
	SColor fg(0, 0, 0, 0);
	vfunc51(*(int *)&fg);
	SColor bg(255, 255, 255, 0);
	vfunc50(*(int *)&bg);
	vfunc134(true);
	F(DarInt, 0x64).AddToTail(999999);
	F(int, 0x11c) = -1;
	F(int, 0x114) = 0;
	F(bool, 0x118) = false;
	F(bool, 0x11a) = false;
	F(int, 0x120) = 0;
}
// END FUNCTION

// FUNCTION: 0x101acd90 size=0x1e
#include "vgui2__TextEntry.h"

// VC6 writes vgui2::TextEntry's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::TextEntry *pcd_emit_101acd90(const vgui2::TextEntry &other) { return new vgui2::TextEntry(other); }

// TARGET: ??_GTextEntry@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101acdb0 size=0x4f
#include "vgui2__TextEntry.h"
namespace vgui2 {
TextEntry::~TextEntry()
{
	char *s = (char *)this;
	vgui2::Panel *a = *(vgui2::Panel **)(s + 0xfc);
	if (a)
		delete a;
	::operator delete(*(void **)(s + 0xe8));
	::operator delete(*(void **)(s + 0x80));
	::operator delete(*(void **)(s + 0x6c));
	::operator delete(*(void **)(s + 0x60));
}
}
// END FUNCTION

// FUNCTION: 0x101ace00 size=0xf9
struct Color {
	int c;
	Color() {}
};
struct IBorder;
struct IScheme {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual IBorder *GetBorder(const char *name);
	virtual void v4();
	virtual Color GetColor(const char *name);
	virtual Color GetColor(const char *name, Color def);
};
struct TEV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void SetBgColor(Color c);
	virtual void SetFgColor(Color c);
	virtual void v52();
	virtual Color GetFgColor();
	virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void SetBorder(IBorder *b);
	char pad[0xb8 - 4];
	Color m_cursor;
	Color m_disFg;
	Color m_disBg;
	Color m_selBg;
	Color m_selFg;
	void sub_101ab490(IScheme *);
	void sub_101ace00(IScheme *s);
};
// TARGET: TEV::sub_101ace00
void TEV::sub_101ace00(IScheme *s)
{
	sub_101ab490(s);
	SetFgColor(s->GetColor("WindowFgColor"));
	SetBgColor(s->GetColor("WindowBgColor"));
	m_cursor = s->GetColor("TextCursorColor");
	m_disFg = s->GetColor("WindowDisabledFgColor");
	m_disBg = s->GetColor("WindowDisabledBgColor");
	m_selFg = s->GetColor("SelectionFgColor", GetFgColor());
	m_selBg = s->GetColor("SelectionBgColor");
	SetBorder(s->GetBorder("ButtonDepressedBorder"));
}
// END FUNCTION

// FUNCTION: 0x101acf00 size=0xd
#include "vgui2__TextEntry.h"
int vgui2::TextEntry::vfunc137(int a0)
{
    *(int *)((char *)this + 0xc0) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101ad120 size=0x23f
#include "vgui2__TextEntry.h"

extern "C" size_t strlen(const char *);
#pragma intrinsic(strlen)
extern "C" void *memset(void *, int, size_t);
#pragma intrinsic(memset)
extern "C" __declspec(noreturn) void exit(int);

template <class T>
struct Dar_101ad120
{
	int _count;
	int _capacity;
	T *_data;

	void ensureCapacity(int wanted)
	{
		if (wanted <= _capacity)
			return;
		int newCapacity = _capacity;
		if (newCapacity == 0)
			newCapacity = 1;
		while (newCapacity < wanted)
			newCapacity *= 2;
		T *newData = new T[newCapacity];
		if (!newData)
			exit(0);
		memset(newData, 0, sizeof(T) * newCapacity);
		_capacity = newCapacity;
		for (int i = 0; i < _count; i++)
			newData[i] = _data[i];
		delete _data;
		_data = newData;
	}
	void addElement(T e)
	{
		ensureCapacity(_count + 1);
		_data[_count] = e;
		_count++;
	}
	void removeAll() { _count = 0; }
};

struct TEFields_101ad120
{
	char m_pad00[0x58];
	Dar_101ad120<char> m_TextStream;	// 0x58
	Dar_101ad120<int> m_LineBreaks;	// 0x64
	char m_pad70[0xb0 - 0x70];
	bool _dataChanged;	// 0xb0
	char m_padb1[0x114 - 0xb1];
	int _currentStartLine;	// 0x114
};

void vgui2::TextEntry::vfunc107(const char *text)
{
	TEFields_101ad120 *self = (TEFields_101ad120 *)this;
	int len = strlen(text);
	self->m_TextStream.removeAll();
	if (text)
	{
		self->m_TextStream.ensureCapacity(len);
		for (int i = 0; i < len; i++)
		{
			self->m_TextStream.addElement(text[i]);
			vfunc156(text[i], i);
		}
	}
	vfunc118();
	vfunc124();
	self->_dataChanged = false;
	self->_currentStartLine = 0;
	self->m_LineBreaks.removeAll();
	self->m_LineBreaks.addElement(999999);
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101ad360 size=0x192
#include "vgui2__TextEntry.h"

extern "C" __declspec(noreturn) void exit(int);
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

template <class T>
struct DarT
{
	int m_count;
	int m_capacity;
	T *m_data;

	void ensureCapacity(int want)
	{
		if (want <= m_capacity)
			return;
		int cap = m_capacity;
		if (cap == 0)
			cap = 1;
		while (cap < want)
			cap += cap;
		T *newData = new T[cap];
		if (!newData)
			exit(0);
		memset(newData, 0, cap * sizeof(T));
		m_capacity = cap;
		for (int i = 0; i < m_count; i++)
			newData[i] = m_data[i];
		delete[] m_data;
		m_data = newData;
	}
	void removeAll() { m_count = 0; }
	void addElement(T e)
	{
		ensureCapacity(m_count + 1);
		m_data[m_count] = e;
		m_count++;
	}
	void setElementAt(T e, int index)
	{
		ensureCapacity(index + 1);
		if (index < m_capacity)
		{
			if (index >= m_count)
			{
				for (int i = m_count; i < index; i++)
					m_data[i] = 0;
				if (index + 1 >= 0 && index + 1 <= m_capacity)
					m_count = index + 1;
			}
			m_data[index] = e;
		}
	}
};

#define F(type, off) (*(type *)((char *)this + (off)))

void vgui2::TextEntry::vfunc156(char ch, int index)
{
	if (ch == '\n' || ch == 0)
	{
		if (index != F(DarT<char>, 0x58).m_count)
		{
			F(int, 0x114) = 0;
			F(DarT<int>, 0x64).removeAll();
			F(DarT<int>, 0x64).addElement(999999);
		}
	}
	if (index < 0)
		return;
	F(DarT<char>, 0x58).setElementAt(ch, index);
	F(bool, 0xb0) = true;
}
// END FUNCTION

// FUNCTION: 0x101ad500 size=0x24
struct IFont { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); };
IFont *sub_101ac8e0();
struct VTE { char pad[0x88]; char m_b88; char pad2[0x94 - 0x89]; int m_i94; int m_i98; void sub_101ad500(); };
// TARGET: ?sub_101ad500@VTE@@QAEXXZ
void VTE::sub_101ad500() { m_b88 = 0; m_i94 = sub_101ac8e0()->v4() + m_i98; }
// END FUNCTION

// FUNCTION: 0x101ad530 size=0x12
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::TextEntry::vfunc133(char a0)
{
    *(char *)((char *)this + 0x89) = a0;
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101ad710 size=0x22f
#include "vgui2__TextEntry.h"

#define F(T, off) (*(T *)((char *)this + (off)))

struct SurfView_101ad710
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void SetCursor(int cursor); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int GetFontTall(int font);
};

template <class T> struct Dar_101ad710
{
	int m_count;
	int m_capacity;
	T *m_data;
	T Get(int i) { return (i >= 0 && i < m_count) ? m_data[i] : 0; }
};

extern SurfView_101ad710 *sub_101ac8d0();
int sub_101ad550(int font, char ch);

// TARGET: vgui2::TextEntry::vfunc160
int vgui2::TextEntry::vfunc160(int cx, int cy)
{
	F(char, 0x75) = 0;
	int fontTall = sub_101ac8d0()->GetFontTall(F(int, 0x124));
	int yStart = vfunc162();
	int x, y = yStart;
	F(int, 0xa4) = 0;
	int lineBreakIndexIndex = 0;
	x = 3;
	int startIndex = vfunc172(&lineBreakIndexIndex);
	if (F(char, 0x100))
	{
		if (F(char, 0x8b))
			vfunc166(startIndex);
	}
	if (F(char, 0x8b))
	{
		sub_101ac8d0()->SetCursor(F(int, 0x101));
		F(int, 0xa4) = F(int, 0x108);
		F(char, 0xd9) = F(char, 0x10c);
	}
	bool onRightLine = false;
	int i;
	for (i = startIndex; i < F(int, 0x58); i++)
	{
		char ch = F(Dar_101ad710<char>, 0x58).Get(i);
		if (vfunc164(ch, (int)&i, (int)&x, (int)&y))
			continue;
		if (F(char, 0x89))
			ch = '*';
		if (F(Dar_101ad710<int>, 0x64).Get(lineBreakIndexIndex) == i)
		{
			vfunc161(&x, &y);
			lineBreakIndexIndex++;
			if (onRightLine)
			{
				F(char, 0x75) = 1;
				return i;
			}
		}
		if (cy < yStart)
		{
			F(char, 0x75) = 1;
			onRightLine = true;
		}
		else if (cy >= y && cy < y + fontTall + 1)
		{
			onRightLine = true;
		}
		int wide = sub_101ad550(F(int, 0x124), ch);
		if (onRightLine)
		{
			if (cx <= sub_101ab130())
			{
				if (cx < F(int, 0xa4) + 3 || cy < yStart)
					break;
			}
			if (cx >= x && cx < x + wide)
			{
				if (cx < x + wide * 0.5)
					return i;
				return i + 1;
			}
		}
		x += wide;
	}
	return i;
}
// END FUNCTION

// FUNCTION: 0x101ada50 size=0x7d
#include "vgui2__TextEntry.h"
struct TE154Child {
	void sub_101a98c0(int *a, int *b);
	void sub_101a98f0(int a, int b);
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(int);
};
struct TE154Surf {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
	virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
	virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
	virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual int v63(int);
};
TE154Surf *sub_101ac8d0();
struct TE154View {
	char pad[0xe0];
	int m_nSize;
	int m_pad4;
	TE154Child **m_pData;
	int m_nCur;
	char pad2[0x124 - 0xf0];
	int m_nFont;
};
// TARGET: ?vfunc154@TextEntry@vgui2@@UAEXHH@Z
void vgui2::TextEntry::vfunc154(int a, int b)
{
	TE154View *v = (TE154View *)this;
	int idx = v->m_nCur;
	if (idx >= 0 && idx < v->m_nSize)
	{
		TE154Child *c = v->m_pData[idx];
		if (c)
		{
			int x, y;
			c->sub_101a98c0(&x, &y);
			int tall = sub_101ac8d0()->v63(v->m_nFont);
			c->sub_101a98f0(a - x, tall - y + b);
			c->v21(1);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101adad0 size=0x84
#include "vgui2__TextEntry.h"
struct ISurf155 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual void v7(); virtual void v8(); virtual void v9();
	virtual void SetColor(int c);
	virtual void v11();
	virtual void DrawFilledRect(int x0, int y0, int x1, int y1);
	virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
	virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
	virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
	virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
	virtual void v62();
	virtual int GetFontTall(int font);
};
ISurf155 *sub_101ac8d0();
namespace vgui2 {
// TARGET: vgui2::TextEntry::vfunc155
bool TextEntry::vfunc155(int a, int b)
{
	if (!m_b88)
	{
		int x, y;
		vfunc159(m_i70, &x, &y);
		sub_101ac8d0()->SetColor(m_n0b8);
		int h = sub_101ac8d0()->GetFontTall(*(int *)((char *)this + 0x124));
		sub_101ac8d0()->DrawFilledRect(x, y, x + 1, y + h);
		return true;
	}
	return false;
}
}
// END FUNCTION

// FUNCTION: 0x101adb60 size=0x621
#include "vgui2__TextEntry.h"

#define F(T, off) (*(T *)((char *)this + (off)))

template <class T> struct DarV
{
	int m_count;
	int m_capacity;
	T *m_data;
	T Get(int i) { if (i >= 0 && i < m_count) return m_data[i]; return 0; }
};

struct SurfV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void DrawSetColor(int col);
	virtual void DrawSetColorRGBA(int r, int g, int b, int a);
	virtual void DrawFilledRect(int x0, int y0, int x1, int y1);
	virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void DrawSetTextFont(int font);
	virtual void DrawSetTextColor(int col);
};
SurfV *sub_101ac8d0();
int sub_101ad550(int font, char ch);
struct TV { int sub_101ae190(int); };

#define TEXT F(DarV<char>, 0x58)
#define IMAGES F(DarV<vgui2::Panel *>, 0xe0)

void vgui2::TextEntry::vfunc97()
{
	int col;
	if (vfunc47())
	{
		int tmp;
		col = *(int *)vfunc52((int)&tmp);
	}
	else
		col = F(int, 0xc0);
	sub_101ac8d0()->DrawSetColor(col);
	int wide, tall;
	sub_101a9920(&wide, &tall);
	sub_101ac8d0()->DrawFilledRect(0, 0, wide, tall);
	sub_101ac8d0()->DrawSetTextFont(F(int, 0x124));
	if (vfunc47())
	{
		int tmp;
		col = *(int *)vfunc53((int)&tmp);
	}
	else
		col = F(int, 0xbc);
	sub_101ac8d0()->DrawSetTextColor(col);
	F(int, 0xd5) = col;
	F(int, 0xa4) = 0;
	F(char, 0xd9) = 0;
	for (int k = 0; k < IMAGES.m_count; k++)
		IMAGES.Get(k)->vfunc21(0);

	bool highlight = false;
	int lineBreakIndexIndex = 0;
	int startIndex = vfunc172(&lineBreakIndexIndex);
	F(int, 0xec) = ((TV *)this)->sub_101ae190(startIndex);
	if (F(char, 0x100) && F(char, 0x8b))
		vfunc166(startIndex);
	if (F(char, 0x8b))
	{
		sub_101ac8d0()->DrawSetTextColor(F(int, 0x101));
		F(int, 0xa4) = F(int, 0x108);
		highlight = F(bool, 0xd9) = F(bool, 0x10c);
	}

	int x = F(int, 0xa4) + 3;
	int y = vfunc162();
	if (!F(char, 0xb1) && !F(char, 0x8b) && !F(char, 0xd4))
	{
		int endIndex = TEXT.m_count;
		int pixels = 3;
		if ((!vfunc56() && vfunc135()) || !vfunc135())
		{
			for (int n = 0; n < TEXT.m_count; n++)
			{
				pixels += sub_101ad550(F(int, 0x124), TEXT.Get(n));
				if (pixels > F(int, 0xf8))
				{
					int dotsWidth = sub_101ad550(F(int, 0x124), '.') * 3;
					while (dotsWidth > 0 && n >= 0)
					{
						dotsWidth -= sub_101ad550(F(int, 0x124), TEXT.Get(n));
						n--;
					}
					endIndex = n + 1;
					break;
				}
			}
			if (TEXT.m_count - endIndex < 3 && TEXT.m_count - endIndex > 0)
				endIndex = TEXT.m_count - 3;
		}
		int i;
		for (i = startIndex; i < endIndex; i++)
		{
			char ch = TEXT.Get(i);
			if (F(char, 0x89))
				ch = '*';
			x += vfunc153(ch, F(int, 0x124), i, x, y);
		}
		if (endIndex < TEXT.m_count)
		{
			x += vfunc153('.', F(int, 0x124), i, x, y);
			i++;
			x += vfunc153('.', F(int, 0x124), i, x, y);
			i++;
			x += vfunc153('.', F(int, 0x124), i, x, y);
		}
	}
	else
	{
		for (int i = 0; i < startIndex; i++)
			vfunc164(TEXT.Get(i), (int)&i, (int)&x, (int)&y);
		for (int j = startIndex; j < TEXT.m_count; j++)
		{
			char ch = TEXT.Get(j);
			if (vfunc164(ch, (int)&j, (int)&x, (int)&y))
			{
				sub_101ac8d0()->DrawSetTextFont(F(int, 0x124));
				if (highlight != F(bool, 0xd9))
				{
					if (F(char, 0xd9))
					{
						vgui2::Panel *p = IMAGES.Get(++F(int, 0xec));
						if (p)
							p->sub_101a9890(x, y);
					}
					else
						vfunc154(x, y);
					highlight = F(bool, 0xd9);
				}
				continue;
			}
			if (F(char, 0x89))
				ch = '*';
			if (F(char, 0xb1) && F(DarV<int>, 0x64).Get(lineBreakIndexIndex) == j)
			{
				if (F(char, 0xd9))
					vfunc154(x, y);
				vfunc161(&x, &y);
				if (sub_101ae650(x, y))
					break;
				lineBreakIndexIndex++;
				if (F(char, 0xd9))
				{
					vgui2::Panel *p = IMAGES.Get(++F(int, 0xec));
					if (p)
						p->sub_101a9890(x, y);
				}
			}
			x += vfunc153(ch, F(int, 0x124), j, x, y);
		}
	}

	sub_101ac8d0()->DrawSetColorRGBA(50, 50, 50, 255);
	if (vfunc47() && vfunc135() && vfunc56())
	{
		sub_101ac8d0()->DrawSetColorRGBA(0, 0, 0, 255);
		vfunc155(x, y);
	}
}
// END FUNCTION

// FUNCTION: 0x101ae1e0 size=0xc1
#include "vgui2__TextEntry.h"
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
#define V16(n) V4(n##1) V4(n##2) V4(n##3) V4(n##4)
struct TV { int sub_101ae190(int n); };
struct PanelV53 {
    V16(a) V16(b) V16(c) V4(d) virtual void s52(); 
    virtual int *vfunc53(int *out);
};
struct TECharVec {
    int size;
    int m4;
    char *data;
    bool IsValid(int i) const { return i >= 0 && i < size; }
    char Get(int i) const { return data[i]; }
};
#define F(type, off) (*(type *)((char *)this + (off)))
// TARGET: vgui2::TextEntry::vfunc166
void vgui2::TextEntry::vfunc166(int count)
{
    {
        int tmp;
        F(int, 0x101) = *((PanelV53 *)this)->vfunc53(&tmp);
    }
    F(int, 0xa4) = 0;
    F(char, 0xd9) = 0;
    F(int, 0xec) = ((TV *)this)->sub_101ae190(count);
    char prev = 0;
    for (int i = 0; i < count; i++) {
        TECharVec *v = (TECharVec *)((char *)this + 0x58);
        if (v->IsValid(i) && v->Get(i) == 1) {
            int x, y;
            i = vfunc171(v, i, (int)&x, (int)&y);
            char cur = F(char, 0xd9);
            if (prev != cur) {
                if (cur)
                    F(int, 0xec)++;
                prev = cur;
            }
        }
    }
    F(int, 0x101) = F(int, 0xd5);
    F(int, 0x108) = F(int, 0xa4);
    F(char, 0x10c) = F(char, 0xd9);
    F(char, 0x100) = 0;
}
// END FUNCTION

// FUNCTION: 0x101ae2b0 size=0x35
#include "vgui2__TextEntry.h"
namespace lifted {
struct C101b18c0 { int sub_101b18c0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual int f149(); virtual int f150(); };
}
void vgui2::TextEntry::vfunc101()
{
    *(char *)((char *)this + 0x100) = 1;
    ((lifted::V *)this)->f149();
    ((lifted::C101b18c0 *)this)->sub_101b18c0();
    if ((*(char *)((char *)this + 0xb2)) != 0) {
        ((lifted::V *)this)->f150();
    }
    ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101ae2f0 size=0x19c
#include "vgui2__TextEntry.h"

struct TextBuf_101ae2f0
{
	int m_len;
	int m_unk4;
	const char *m_data;
	char Get(int i) const { return (i >= 0 && i < m_len) ? m_data[i] : 0; }
	unsigned char GetU(int i) const { unsigned char c; if (i >= 0 && i < m_len) c = m_data[i]; else c = 0; return c; }
};
struct ColorSink_101ae2f0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void vfunc18(int color);
};
ColorSink_101ae2f0 *sub_101ac8d0();

// TARGET: vgui2::TextEntry::vfunc171
int vgui2::TextEntry::vfunc171(void *pBuf, int pos, int pOut, int unused)
{
	TextBuf_101ae2f0 *buf = (TextBuf_101ae2f0 *)pBuf;
	char *self = (char *)this;
	pos++;
	char type = buf->Get(pos++);
	switch (type) {
	case 1: {
		int arr[4];
		for (int k = 0; k < 4; k++) {
			char ch = buf->Get(pos++);
			int v = ch;
			arr[k] = v;
			if (v < 0)
				arr[k] = v + 256;
		}
		unsigned char col[4];
		col[0] = (unsigned char)arr[0];
		col[1] = (unsigned char)arr[1];
		col[2] = (unsigned char)arr[2];
		col[3] = (unsigned char)arr[3];
		*(int *)(self + 0xd5) = *(int *)col;
		sub_101ac8d0()->vfunc18(*(int *)(self + 0xd5));
		break;
	}
	case 2: {
		char ch = buf->Get(pos++);
		int c = ch;
		int *p = (int *)pOut;
		if (p) {
			if (*p == *(int *)(self + 0xa4) + 3)
				*p = c + 3;
		}
		*(int *)(self + 0xa4) = c;
		break;
	}
	case 3:
		*(bool *)(self + 0xd9) = true;
		break;
	case 4:
		*(bool *)(self + 0xd9) = false;
		break;
	case 5: {
		int hi = buf->GetU(pos++) * 256;
		*(int *)(self + 0x124) = hi;
		*(int *)(self + 0x124) = hi | buf->GetU(pos++);
		break;
	}
	}
	return pos - 1;
}
// END FUNCTION

// FUNCTION: 0x101ae490 size=0x71
#include "vgui2__TextEntry.h"

void vgui2::TextEntry::sub_101ae490(int arg)
{
	if ( *(char *)((char *)this + 0x8b) )
	{
		unsigned char *p = (unsigned char *)&arg;
		vfunc120(1);
		vfunc120(1);
		vfunc120(*(int *)(p + 0));
		vfunc120(*(int *)(p + 1));
		vfunc120(*(int *)(p + 2));
		vfunc120(*(int *)(p + 3));
		vfunc57(0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101ae510 size=0x5d
#include "vgui2__TextEntry.h"

struct VTable57
{
	virtual void a00(); virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05(); virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09();
	virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
	virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29();
	virtual void a30(); virtual void a31(); virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35(); virtual void a36(); virtual void a37(); virtual void a38(); virtual void a39();
	virtual void a40(); virtual void a41(); virtual void a42(); virtual void a43(); virtual void a44(); virtual void a45(); virtual void a46(); virtual void a47(); virtual void a48(); virtual void a49();
	virtual void a50(); virtual void a51(); virtual void a52(); virtual void a53(); virtual void a54(); virtual void a55(); virtual void a56();
	virtual bool v57(int, int);
};

// TARGET: vgui2::TextEntry::vfunc146
bool vgui2::TextEntry::vfunc146(int index)
{
	bool bResult = *(bool *)((char *)this + 0x8b);
	if (bResult)
	{
		if (index < 0)
			index = 0;
		else if (index > 0xff)
			index = 0xff;
		vfunc120(1);
		vfunc120(2);
		vfunc120(index);
		bResult = ((VTable57 *)this)->v57(0, 0);
	}
	return bResult;
}
// END FUNCTION

// FUNCTION: 0x101ae5d0 size=0x1b
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual int f120(int); };
}
int vgui2::TextEntry::vfunc147()
{
    ((lifted::V *)this)->f120(1);
    return ((lifted::V *)this)->f120(3);
}
// END FUNCTION

// FUNCTION: 0x101ae5f0 size=0x1b
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual int f120(int); };
}
int vgui2::TextEntry::vfunc148()
{
    ((lifted::V *)this)->f120(1);
    return ((lifted::V *)this)->f120(4);
}
// END FUNCTION

// FUNCTION: 0x101ae610 size=0x35
#include "vgui2__TextEntry.h"
#define P8(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d(); virtual void n##e(); virtual void n##f(); virtual void n##g(); virtual void n##h();
struct ISurfaceView {
	P8(a) P8(b) P8(c) P8(d) P8(e) P8(f) P8(g)
	virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62();
	virtual int GetFontTall(int font);
};
ISurfaceView *sub_101ac8d0();
// TARGET: vgui2::TextEntry::vfunc161
void vgui2::TextEntry::vfunc161(int *x, int *y)
{
	*x = *(int *)((char *)this + 0xa4) + 3;
	*y += sub_101ac8d0()->GetFontTall(*(int *)((char *)this + 0x124)) + 1;
}
// END FUNCTION

// FUNCTION: 0x101aed20 size=0x1cb
#include "vgui2__TextEntry.h"
struct SurfV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int vfunc63(int font);
};
struct ScrollV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void vfunc6();
	virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
	virtual void vfunc46(int);
	virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void vfunc57(int, int);
	virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
	virtual void vfunc107(int);
	virtual int vfunc108();
	virtual void vfunc109(int, int);
	virtual void vfunc110(int);
	virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117();
	virtual void vfunc118(int);
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
};
SurfV *sub_101ac8d0();
#define CHILD (*(ScrollV **)((char *)this + 0xb4))
// TARGET: vgui2::TextEntry::vfunc150
void vgui2::TextEntry::vfunc150()
{
	if (CHILD)
	{
		int a, q, b, r, s, p;
		sub_101a9920(&a, &b);
		vfunc8((int)&p, (int)&q, (int)&r, (int)&s);
		a -= q;
		CHILD->sub_101a9890(a - 0x12, 0);
		CHILD->sub_101a98f0(0x12, b - r - s);
		int nLines = b / (sub_101ac8d0()->vfunc63(*(int *)((char *)this + 0x124)) + 1);
		int top = *(int *)((char *)this + 0x64);
		if (top <= nLines)
		{
			CHILD->vfunc46(0);
			CHILD->vfunc109(0, top);
			CHILD->vfunc110(top);
			CHILD->vfunc107(0);
		}
		else
		{
			CHILD->vfunc109(0, top);
			CHILD->vfunc110(nLines);
			CHILD->vfunc46(1);
			CHILD->vfunc118(1);
			int lo = CHILD->vfunc108();
			int hi = CHILD->vfunc108() + nLines;
			if (sub_101afbf0() < lo)
			{
				while (sub_101afbf0() < lo)
					lo--;
			}
			else if (sub_101afbf0() >= hi)
			{
				while (sub_101afbf0() >= hi)
					hi++;
				lo = hi - nLines;
			}
			CHILD->vfunc107(lo);
			CHILD->vfunc57(0, 0);
			CHILD->vfunc6();
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101aeef0 size=0x18
#include "vgui2__TextEntry.h"
namespace lifted {
int __stdcall sub_101ab220(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::TextEntry::vfunc46(int a0)
{
    lifted::sub_101ab220(a0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101aef10 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc138(char a0)
{
    *(char *)((char *)this + 0xb1) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101aef20 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc141(char a0)
{
    *(char *)((char *)this + 0xf4) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101aefc0 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc139(char a0)
{
    *(char *)((char *)this + 0x8b) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101aefd0 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc134(char a0)
{
    *(char *)((char *)this + 0x8a) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101af110 size=0x7
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc135()
{
    return *(bool *)((char *)this + 0x8a);
}
// END FUNCTION

// FUNCTION: 0x101af120 size=0x17
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual int f84(int, int); };
}
void vgui2::TextEntry::vfunc96()
{
    if ((*(char *)((char *)this + 0x8d)) != 0) {
        ((lifted::V *)this)->f84(0, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x101af140 size=0x8
#include "vgui2__TextEntry.h"
void vgui2::TextEntry::vfunc85()
{
    *(char *)((char *)this + 0x8d) = 0;
}
// END FUNCTION

// FUNCTION: 0x101af150 size=0x12
#include "vgui2__TextEntry.h"
void vgui2::TextEntry::vfunc86()
{
    if ((*(char *)((char *)this + 0x8c)) != 0) {
        *(char *)((char *)this + 0x8d) = 1;
    }
}
// END FUNCTION

// FUNCTION: 0x101af170 size=0x9d
#include "vgui2__TextEntry.h"
struct VInput101 { virtual void v0(); };
struct CUnknown101afee0 { void sub_101afee0(); };
#define T10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();
struct VI0 { T10(a) T10(b) T10(c) T10(d) T10(e) T10(f) T10(g) };
struct VIn : VI0 { virtual void h0(); virtual void h1(); virtual void GetCursorPos(int &x, int &y); };
int sub_101ac8d0();
void vgui2::TextEntry::vfunc84(int, int)
{
	if (!*(char *)((char *)this + 0x8c)) return;
	int x, y;
	((VIn *)sub_101ac8d0())->GetCursorPos(x, y);
	vfunc27(&x, &y);
	int r = vfunc160(x, y);
	m_i70 = r;
	if (!r) *((char *)this + 0x75) = 0;
	if (r == *(int *)((char *)this + 0xd0)) {
		if (r > 0) m_i70 = r - 1;
		((CUnknown101afee0 *)this)->sub_101afee0();
		m_i70 = *(int *)((char *)this + 0xd0);
	}
	if (m_i70 != *(int *)((char *)this + 0xa0)) {
		*(int *)((char *)this + 0xa0) = m_i70;
		vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101af2f0 size=0x50
#include "vgui2__TextEntry.h"
int sub_101ac8b0();

struct InputView { virtual void vfunc0(); virtual void vfunc1(int); };

void vgui2::TextEntry::vfunc89(int)
{
	*(char *)((char *)this + 0x8c) = 0;
	((InputView *)sub_101ac8b0())->vfunc1(0);
	int a, b;
	if (vfunc158((int)&b, (int)&a)) {
		if (a - b == 0)
			*(int *)((char *)this + 0x9c) = -1;
	}
}
// END FUNCTION

// FUNCTION: 0x101af340 size=0x7b
#include "vgui2__TextEntry.h"
extern "C" int isspace(int);
void vgui2::TextEntry::vfunc88(int a)
{
	if (a == 0) {
		vfunc87(0);
		vfunc115();
		int start = *(int *)((char *)this + 0x70);
		vfunc114();
		int end = *(int *)((char *)this + 0x70);
		int prev = end - 1;
		char c;
		if (prev >= 0 && prev < *(int *)((char *)this + 0x58))
			c = (*(char **)((char *)this + 0x60))[prev];
		else
			c = 0;
		if (isspace(c)) {
			end = prev;
			(*(int *)((char *)this + 0x70))--;
		}
		*(int *)((char *)this + 0x9c) = start;
		*(int *)((char *)this + 0xa0) = end;
		*((char *)this + 0x8c) = 1;
	}
}
// END FUNCTION

// FUNCTION: 0x101af3c0 size=0x8
#include "vgui2__TextEntry.h"
void vgui2::TextEntry::vfunc79()
{
    *(char *)((char *)this + 0x8c) = 0;
}
// END FUNCTION

// FUNCTION: 0x101af3d0 size=0x570
#include "vgui2__TextEntry.h"
#include "vgui2__KeyValues.h"

#define V4_101af3d0(a, b, c, d) virtual void v##a(); virtual void v##b(); virtual void v##c(); virtual void v##d();

struct IInput_101af3d0
{
	V4_101af3d0(0, 1, 2, 3) V4_101af3d0(4, 5, 6, 7) V4_101af3d0(8, 9, 10, 11)
	virtual bool IsKeyDown(int code);
};
IInput_101af3d0 *sub_101ac8b0();	// vgui2::input()

struct ISurface_101af3d0
{
	V4_101af3d0(0, 1, 2, 3) V4_101af3d0(4, 5, 6, 7) V4_101af3d0(8, 9, 10, 11) V4_101af3d0(12, 13, 14, 15)
	V4_101af3d0(16, 17, 18, 19) V4_101af3d0(20, 21, 22, 23) V4_101af3d0(24, 25, 26, 27) V4_101af3d0(28, 29, 30, 31)
	V4_101af3d0(32, 33, 34, 35) V4_101af3d0(36, 37, 38, 39) V4_101af3d0(40, 41, 42, 43) V4_101af3d0(44, 45, 46, 47)
	V4_101af3d0(48, 49, 50, 51) V4_101af3d0(52, 53, 54, 55) V4_101af3d0(56, 57, 58, 59)
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int GetFontTall(int font);
};
ISurface_101af3d0 *sub_101ac8d0();	// vgui2::surface()

// vgui2::ScrollBar's own slots 107..111 (ScrollBar.h keeps slot 107 as the slider forwarder's `int vfunc107()`)
struct ScrollBarView_101af3d0
{
	V4_101af3d0(0, 1, 2, 3) V4_101af3d0(4, 5, 6, 7) V4_101af3d0(8, 9, 10, 11) V4_101af3d0(12, 13, 14, 15)
	V4_101af3d0(16, 17, 18, 19) V4_101af3d0(20, 21, 22, 23) V4_101af3d0(24, 25, 26, 27) V4_101af3d0(28, 29, 30, 31)
	V4_101af3d0(32, 33, 34, 35) V4_101af3d0(36, 37, 38, 39) V4_101af3d0(40, 41, 42, 43) V4_101af3d0(44, 45, 46, 47)
	V4_101af3d0(48, 49, 50, 51) V4_101af3d0(52, 53, 54, 55) V4_101af3d0(56, 57, 58, 59) V4_101af3d0(60, 61, 62, 63)
	V4_101af3d0(64, 65, 66, 67) V4_101af3d0(68, 69, 70, 71) V4_101af3d0(72, 73, 74, 75) V4_101af3d0(76, 77, 78, 79)
	V4_101af3d0(80, 81, 82, 83) V4_101af3d0(84, 85, 86, 87) V4_101af3d0(88, 89, 90, 91) V4_101af3d0(92, 93, 94, 95)
	V4_101af3d0(96, 97, 98, 99) V4_101af3d0(100, 101, 102, 103)
	virtual void v104(); virtual void v105(); virtual void v106();
	virtual void SetValue(int value);	// 107
	virtual int GetValue();				// 108
	virtual void v109();
	virtual void v110();
	virtual int GetRangeWindow();		// 111
};

struct TEFields_101af3d0
{
	char m_pad00[0x70];
	int _cursorPos;					// 0x70
	bool _cursorIsAtEnd;			// 0x74
	bool _putCursorAtEnd;			// 0x75
	char m_pad76[0xa0 - 0x76];
	int m_nA0;						// 0xa0
	char m_padA4[0xb0 - 0xa4];
	bool m_bB0;						// 0xb0
	bool _multiline;				// 0xb1
	char m_padB2[2];
	ScrollBarView_101af3d0 *_vertScrollBar;	// 0xb4
	char m_padB8[0xf4 - 0xb8];
	bool _catchEnterKey;			// 0xf4
	char m_cF5;
	bool _sendNewLines;				// 0xf6
	char m_padF7[0x124 - 0xf7];
	int _font;						// 0x124
};

void vgui2::TextEntry::sub_101af3d0(int code)
{
	TEFields_101af3d0 *self = (TEFields_101af3d0 *)this;

	self->_cursorIsAtEnd = self->_putCursorAtEnd;
	self->_putCursorAtEnd = false;

	bool shift = (sub_101ac8b0()->IsKeyDown(0x4f) || sub_101ac8b0()->IsKeyDown(0x50));
	bool ctrl = (sub_101ac8b0()->IsKeyDown(0x53) || sub_101ac8b0()->IsKeyDown(0x54));
	bool alt = (sub_101ac8b0()->IsKeyDown(0x51) || sub_101ac8b0()->IsKeyDown(0x52));
	bool fallThrough = false;

	if (ctrl)
	{
		switch (code)
		{
		case 72:
		case 13:
			vfunc127();
			break;
		case 32:
			vfunc129();
			vfunc128();
			break;
		case 34:
			vfunc127();
			vfunc129();
			break;
		case 36:
			vfunc130();
			break;
		case 91:
			vfunc114();
			break;
		case 89:
			vfunc115();
			break;
		case 64:
			if (self->_multiline)
			{
				vfunc129();
				vfunc131();
				vfunc120('\n');
			}
			if (self->_sendNewLines)
			{
				vfunc43(new vgui2::KeyValues("TextNewLine"));
			}
			break;
		case 74:
			vfunc118();
			break;
		case 75:
			vfunc119();
			break;
		default:
			fallThrough = true;
			break;
		}
	}
	else if (alt)
	{
		fallThrough = true;
	}
	else
	{
		switch (code)
		{
		case 72:
			if (shift)
			{
				vfunc129();
				vfunc128();
			}
			else
			{
				fallThrough = true;
			}
			break;
		case 73:
			if (shift)
			{
				vfunc127();
				vfunc129();
			}
			else
			{
				vfunc123();
			}
			break;
		case 89:
			vfunc110();
			break;
		case 91:
			vfunc111();
			break;
		case 88:
			if (self->_multiline)
				vfunc112();
			else
				fallThrough = true;
			break;
		case 90:
			if (self->_multiline)
				vfunc113();
			else
				fallThrough = true;
			break;
		case 74:
			vfunc116();
			break;
		case 75:
			vfunc117();
			break;
		case 66:
			{
				int x0, x1;
				if (vfunc158((int)&x0, (int)&x1))
					vfunc129();
				else
					vfunc122();
			}
			break;
		case 64:
			if (self->_multiline && self->_catchEnterKey)
			{
				vfunc129();
				vfunc131();
				vfunc120('\n');
			}
			else
			{
				fallThrough = true;
			}
			if (self->_sendNewLines)
			{
				vfunc43(new vgui2::KeyValues("TextNewLine"));
			}
			break;
		case 76:
			{
				int val;
				if (self->_vertScrollBar)
					val = self->_vertScrollBar->GetValue();
				if (self->_multiline)
				{
					int displayLines = sub_101ab1a0() / (sub_101ac8d0()->GetFontTall(self->_font) + 1);
					for (int i = 0; i < displayLines; i++)
						vfunc112();
				}
				if (self->_vertScrollBar)
				{
					int window = self->_vertScrollBar->GetRangeWindow();
					int newval = self->_vertScrollBar->GetValue();
					int linesToMove = window - (val - newval);
					self->_vertScrollBar->SetValue(val - linesToMove - 1);
				}
			}
			break;
		case 77:
			{
				int val;
				if (self->_vertScrollBar)
					val = self->_vertScrollBar->GetValue();
				if (self->_multiline)
				{
					int displayLines = sub_101ab1a0() / (sub_101ac8d0()->GetFontTall(self->_font) + 1);
					for (int i = 0; i < displayLines; i++)
						vfunc113();
				}
				if (self->_vertScrollBar)
				{
					int window = self->_vertScrollBar->GetRangeWindow();
					int newval = self->_vertScrollBar->GetValue();
					int linesToMove = window - (newval - val);
					self->_vertScrollBar->SetValue(val + linesToMove + 1);
				}
			}
			break;
		case 67:
		case 79:
		case 80:
		case 70:
		case 92: case 93: case 94: case 95: case 96: case 97:
		case 98: case 99: case 100: case 101: case 102: case 103:
			fallThrough = true;
			break;
		default:
			return;
		}
	}

	self->m_nA0 = self->_cursorPos;
	if (self->m_bB0)
		vfunc157();

	if (fallThrough)
	{
		self->_putCursorAtEnd = self->_cursorIsAtEnd;
		this->Panel::sub_101aa6f0(code);
	}
}
// END FUNCTION

// FUNCTION: 0x101af940 size=0x89
#include "vgui2__TextEntry.h"
extern int (__cdecl *g_101e31cc)(int);
void vgui2::TextEntry::vfunc93(int code)
{
	char *p = (char *)this;
	p[0x74] = p[0x75];
	p[0x75] = 0;
	if (g_101e31cc(code & 0xffff))
	{
		if (!vfunc135())
		{
			sub_101aa720(code);
			return;
		}
		if ((short)code)
		{
			vfunc129();
			vfunc131();
			vfunc120(code);
		}
		*(int *)(p + 0xa0) = *(int *)(p + 0x70);
		if (p[0xb0])
			vfunc157();
	}
}
// END FUNCTION

// FUNCTION: 0x101afa20 size=0x40
#include "vgui2__TextEntry.h"
struct IUnk101ac8e0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int Get(); };
IUnk101ac8e0 *sub_101ac8e0();
void vgui2::TextEntry::vfunc95()
{
	int n = sub_101ac8e0()->Get();
	if (n > m_i94)
	{
		m_b88 = !m_b88;
		m_i94 = m_i98 + n;
		vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101afa60 size=0x53
#include "vgui2__TextEntry.h"

extern int sub_101ac8b0();

class IInputView_101afa60
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual bool vfunc12(int keyCode);
};

// TARGET: vgui2::TextEntry::vfunc165
void vgui2::TextEntry::vfunc165()
{
	if ( vfunc56() )
	{
		if ( ((IInputView_101afa60 *)sub_101ac8b0())->vfunc12(0x4f)
			|| ((IInputView_101afa60 *)sub_101ac8b0())->vfunc12(0x50) )
		{
			if ( *(int *)((char *)this + 0x9c) == -1 )
				*(int *)((char *)this + 0x9c) = *(int *)((char *)this + 0x70);
			return;
		}
	}
	*(int *)((char *)this + 0x9c) = -1;
}
// END FUNCTION

// FUNCTION: 0x101afac0 size=0xd
#include "vgui2__TextEntry.h"
int vgui2::TextEntry::vfunc143(int a0)
{
    *(int *)((char *)this + 0xac) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101afad0 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc144(char a0)
{
    *(char *)((char *)this + 0xf5) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101afae0 size=0xd
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc142(char a0)
{
    *(char *)((char *)this + 0xf6) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101afb30 size=0x4f
#include "vgui2__TextEntry.h"

struct VTextEntry_101afaf0 { bool sub_101afaf0(int); };
struct VTextEntry_101afee0 { void sub_101afee0(); };

int vgui2::TextEntry::vfunc110()
{
	vfunc165();
	int n = *(int *)((char *)this + 0x70);
	if (((VTextEntry_101afaf0 *)this)->sub_101afaf0(n))
	{
		if (!*(char *)((char *)this + 0x74))
			*(char *)((char *)this + 0x75) = 1;
	}
	if (!*(char *)((char *)this + 0x75) && n > 0)
	{
		n--;
		*(int *)((char *)this + 0x70) = n;
	}
	((VTextEntry_101afee0 *)this)->sub_101afee0();
	vfunc109();
	return vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101afb80 size=0x70
#include "vgui2__TextEntry.h"

struct TEView
{
	char pad0[0x58];
	int m_n58;	// 0x58
	char pad1[0x70 - 0x5c];
	int m_pos70;	// 0x70
	char m_b74;	// 0x74
	char m_b75;	// 0x75
	bool sub_101afaf0(int);
	void sub_101aff20();
};

int vgui2::TextEntry::vfunc111()
{
	TEView *v = (TEView *)this;
	vfunc165();
	int pos = v->m_pos70;
	if ( v->sub_101afaf0(pos) )
	{
		if ( v->m_b74 )
		{
			v->m_b75 = 0;
		}
		else if ( pos < v->m_n58 )
		{
			v->m_pos70 = ++pos;
		}
	}
	else
	{
		if ( pos < v->m_n58 )
		{
			v->m_pos70 = ++pos;
		}
		if ( v->sub_101afaf0(v->m_pos70) && !v->m_b74 )
			v->m_b75 = 1;
	}
	v->sub_101aff20();
	vfunc109();
	return vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101afd20 size=0x49
#include "vgui2__TextEntry.h"
struct SurfView63 {
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
	virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
	virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
	virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
	virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
	virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
	virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
	virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
	virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
	virtual void s60(); virtual void s61(); virtual void s62();
	virtual int s63(int);
};
SurfView63 *sub_101ac8d0();
struct PV { int sub_101ab1a0(); };
struct TEView { char pad[0xb1]; bool m_b1; char pad2[0x124 - 0xb2]; int m_124; };
int vgui2::TextEntry::vfunc162()
{
	TEView *v = (TEView *)this;
	if (v->m_b1)
		return 1;
	int a = sub_101ac8d0()->s63(v->m_124);
	int b = ((PV *)this)->sub_101ab1a0();
	return b / 2 - a / 2;
}
// END FUNCTION

// FUNCTION: 0x101afd70 size=0x154
#include "vgui2__TextEntry.h"

int sub_101ad550(int font, int ch);

struct DarC
{
	int m_Count;
	int m_Cap;
	char *m_pData;
	char Get(int i) { return (i >= 0 && i < m_Count) ? m_pData[i] : 0; }
};
struct DarI
{
	int m_Count;
	int m_Cap;
	int *m_pData;
	int Get(int i) { return (i >= 0 && i < m_Count) ? m_pData[i] : 0; }
};
struct TEView
{
	char m_pad0000[0x58];
	DarC m_text;	// 0x58
	DarI m_lines;	// 0x64
	int m_nCursorPos;	// 0x70
	char m_pad0074[1];
	char m_bCursorAtEnd;	// 0x75
	char m_pad0076[0x89 - 0x76];
	char m_bHideText;	// 0x89
	char m_pad008a[0xa4 - 0x8a];
	int m_na4;	// 0xa4
	char m_pad00a8[0x100 - 0xa8];
	char m_bf100;	// 0x100
	char m_pad0101[0x124 - 0x101];
	int m_nFont;	// 0x124
};

// TARGET: vgui2::TextEntry::vfunc136
void vgui2::TextEntry::vfunc136(int line, int pixelsAcross)
{
	TEView *v = (TEView *)this;
	if (line < 0)
		line = 0;
	if (line >= v->m_lines.m_Count)
		line = v->m_lines.m_Count - 1;
	v->m_bf100 = 1;
	int startIndex = vfunc162();
	int x = 3;
	v->m_na4 = 0;
	int i = 0;
	int lineIdx = 0;
	int ch;
	for (; i < v->m_text.m_Count; i++)
	{
		*(char *)&ch = v->m_text.Get(i);
		if (!vfunc164(*(char *)&ch, (int)&i, (int)&x, (int)&startIndex))
		{
			if (v->m_bHideText)
				*(char *)&ch = '*';
			int lb = v->m_lines.Get(lineIdx);
			if (lb == i)
			{
				if (lineIdx == line)
				{
					v->m_bCursorAtEnd = 1;
					v->m_nCursorPos = i;
					break;
				}
				vfunc161(&x, &startIndex);
				lineIdx++;
			}
			int w = sub_101ad550(v->m_nFont, ch);
			if (line == lineIdx && x + w / 2 > pixelsAcross)
			{
				v->m_nCursorPos = i;
				break;
			}
			x += w;
		}
	}
	if (i == v->m_text.m_Count)
		vfunc119();
	vfunc150();
	vfunc109();
	vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101affe0 size=0xc1
#include "vgui2__TextEntry.h"
extern "C" int __cdecl isspace(int);
struct TextEntryCharVec
{
	int size; int m4; char *data;
	char Get(int i) const { if (i < 0 || i >= size) return 0; return data[i]; }
};
struct TEView { char pad[0x58]; TextEntryCharVec v; char pad2[0x70 - 0x64]; int pos; };
// TARGET: vgui2::TextEntry::vfunc114
void vgui2::TextEntry::vfunc114()
{
	TEView *t = (TEView *)this;
	vfunc165();
	t->pos++;
	while (t->pos < t->v.size) {
		if (isspace(t->v.Get(t->pos)))
			break;
		t->pos++;
	}
	t->pos++;
	while (t->pos < t->v.size) {
		if (!isspace(t->v.Get(t->pos)))
			break;
		t->pos++;
	}
	if (t->pos > t->v.size)
		t->pos = t->v.size;
	sub_101aff20();
	vfunc150();
	vfunc109();
	vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101b00b0 size=0xac
#include "vgui2__TextEntry.h"
extern "C" int __cdecl isspace(int);
struct TECharVec { int m0; int m4; int size; int m0c; char *data; char Get(int i) const { if (i < 0 || i >= size) return 0; return data[i]; } };
// TARGET: vgui2::TextEntry::vfunc115
void vgui2::TextEntry::vfunc115()
{
	vfunc165();
	int &cur = *(int *)((char *)this + 0x70);
	TECharVec *v = (TECharVec *)((char *)this + 0x50);
	if (cur >= 1) {
		cur--;
		while (cur >= 0) {
			if (!isspace(v->Get(cur))) break;
			cur--;
		}
		cur--;
		while (cur >= 0) {
			if (isspace(v->Get(cur))) break;
			cur--;
		}
		cur++;
		sub_101afee0();
		vfunc150();
		vfunc109();
		vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101b0160 size=0x35
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual int f150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual int f165(); };
}
int vgui2::TextEntry::vfunc118()
{
    ((lifted::V *)this)->f165();
    *(int *)((char *)this + 0x70) = 0;
    *(char *)((char *)this + 0x75) = 0;
    *(int *)((char *)this + 0xd0) = 0;
    ((lifted::V *)this)->f150();
    ((lifted::V *)this)->f109();
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b01a0 size=0x38
#include "vgui2__TextEntry.h"
namespace lifted {
struct C101aff20 { int sub_101aff20(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual int f150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual int f165(); };
}
int vgui2::TextEntry::vfunc119()
{
    int t0 = ((lifted::V *)this)->f165();
    int t1 = *(int *)((char *)this + 0x58);
    *(char *)((char *)this + 0x75) = 1;
    *(int *)((char *)this + 0x70) = t1;
    ((lifted::C101aff20 *)this)->sub_101aff20();
    ((lifted::V *)this)->f150();
    ((lifted::V *)this)->f109();
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b01e0 size=0x3b
#include "vgui2__TextEntry.h"
namespace lifted {
struct C101b0220 { int sub_101b0220(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual int f150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual int f165(); };
}
int vgui2::TextEntry::vfunc116()
{
    ((lifted::V *)this)->f165();
    *(int *)((char *)this + 0x70) = ((lifted::C101b0220 *)this)->sub_101b0220();
    *(char *)((char *)this + 0x75) = 0;
    *(int *)((char *)this + 0xd0) = *(int *)((char *)this + 0x70);
    ((lifted::V *)this)->f150();
    ((lifted::V *)this)->f109();
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b02b0 size=0x3c
#include "vgui2__TextEntry.h"
namespace lifted {
struct C101aff20 { int sub_101aff20(); };
struct C101b02f0 { int sub_101b02f0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual int f150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual int f165(); };
}
int vgui2::TextEntry::vfunc117()
{
    ((lifted::V *)this)->f165();
    *(int *)((char *)this + 0x70) = ((lifted::C101b02f0 *)this)->sub_101b02f0();
    *(char *)((char *)this + 0x75) = 1;
    ((lifted::C101aff20 *)this)->sub_101aff20();
    ((lifted::V *)this)->f150();
    ((lifted::V *)this)->f109();
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b06b0 size=0x4b
#include "vgui2__TextEntry.h"
struct TEView2 { char pad[0xb0]; bool m_b0; };
void vgui2::TextEntry::vfunc121(const char *text)
{
	if (text && *text) {
		vfunc131();
		for (const char *p = text; *p; p++)
			vfunc120(*p);
		if (((TEView2 *)this)->m_b0)
			vfunc157();
	}
}
// END FUNCTION

// FUNCTION: 0x101b0700 size=0xd1
#include "vgui2__TextEntry.h"

struct TEView
{
	char pad0[0x58];
	int m_nLength;		// 0x58
	int m_nCapacity;	// 0x5c
	char *m_pText;		// 0x60
	int m_n64;		// 0x64
	char pad68[0x6c - 0x68];
	int *m_p6c;		// 0x6c
	int m_nCursor;		// 0x70
	char pad74[0x8a - 0x74];
	char m_bFlag;		// 0x8a
	char pad8b[0xb0 - 0x8b];
	char m_bB0;		// 0xb0
	char padB1[0xd0 - 0xb1];
	int m_nD0;		// 0xd0
	char padD4[0x114 - 0xd4];
	int m_n114;		// 0x114
};

struct TEBuf
{
	int m_nCount;
	int m_nCapacity;
	char *m_pData;
};

inline char TEGetChar(TEBuf *b, int i)
{
	if (i >= 0 && i < b->m_nCount)
		return b->m_pData[i];
	return 0;
}

void __fastcall sub_101b0650(void *self)
{
	TEView *v = (TEView *)self;
	int n = v->m_nLength;
	int cur = v->m_nCursor;
	if (cur == n)
	{
		v->m_n114 = v->m_n64 - 2;
		return;
	}
	v->m_n114 = 0;
	int a;
	for (;;)
	{
		a = v->m_n114;
		int d = (a >= 0 && a < v->m_n64) ? v->m_p6c[a] : 0;
		if (cur <= d)
			break;
		v->m_n114 = a + 1;
	}
	v->m_n114 = a - 1;
}

// TARGET: ?vfunc122@TextEntry@vgui2@@UAEXXZ
void vgui2::TextEntry::vfunc122()
{
	TEView *v = (TEView *)this;
	TEBuf *b = (TEBuf *)((char *)this + 0x58);
	if (!v->m_bFlag || v->m_nCursor == 0 || v->m_nLength == 0)
		return;
	vfunc131();
	for (int i = v->m_nCursor; i < v->m_nLength; i++)
	{
		char c = TEGetChar(b, i);
		vfunc156(c, i - 1);
	}
	int n = v->m_nLength - 1;
	if (n >= 0 && n <= v->m_nCapacity)
		v->m_nLength = n;
	if (v->m_nCursor == v->m_nD0)
	{
		int t = v->m_nD0 - 6;
		v->m_nD0 = t < 0 ? 0 : t;
	}
	v->m_nCursor--;
	v->m_bB0 = 1;
	::sub_101b0650(this);
	vfunc150();
	vfunc109();
	vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101b09c0 size=0xf
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::TextEntry::vfunc124()
{
    *(int *)((char *)this + 0x9c) = -1;
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b09d0 size=0x33
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc158(int a0, int a1)
{
    int t0 = *(int *)((char *)this + 0x9c);
    if (t0 == -1) {
        return 0;
    }
    *(int *)((char *)a0) = t0;
    int t1 = *(int *)((char *)this + 0xa0);
    *(int *)((char *)a1) = t1;
    int t2 = *(int *)((char *)a0);
    if (t1 < t2) {
        *(int *)((char *)a0) = t1;
        *(int *)((char *)a1) = t2;
    }
    return 1;
}
// END FUNCTION

// FUNCTION: 0x101b0a10 size=0x196
#include "vgui2__TextEntry.h"
#include "vgui2__Menu.h"
struct Surface_101b0a10
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
	virtual void GetScreenSize(int *wide, int *tall);
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71();
	virtual void GetCursorPos(int *x, int *y);
};
Surface_101b0a10 *sub_101ac8d0();
// TARGET: vgui2::TextEntry::vfunc125
void vgui2::TextEntry::vfunc125()
{
	vgui2::Menu *menu = *(vgui2::Menu **)((char *)this + 0xfc);
	if (!menu)
		return;
	int cursorX, cursorY;
	sub_101ac8d0()->GetCursorPos(&cursorX, &cursorY);
	vgui2::Panel *top = this;
	while (top->vfunc31())
		top = (vgui2::Panel *)top->vfunc31();
	top->vfunc27(&cursorX, &cursorY);
	int px, py;
	top->sub_101a98c0(&px, &py);
	cursorX += px;
	cursorY += py;
	int s0, s1;
	if (vfunc158((int)&s0, (int)&s1))
	{
		(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc124("&Cut", 1);
		(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc124("C&opy", 1);
	}
	else
	{
		(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc124("&Cut", 0);
		(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc124("C&opy", 0);
	}
	(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc21(1);
	(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc15(0);
	(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc57(1, 0);
	int menuWide, menuTall;
	(*(vgui2::Menu **)((char *)this + 0xfc))->sub_101a9920(&menuWide, &menuTall);
	int wide, tall;
	sub_101ac8d0()->GetScreenSize(&wide, &tall);
	int y, x;
	if (wide - menuWide > cursorX)
	{
		x = cursorX;
		y = cursorY;
		if (!(tall - menuTall > cursorY))
			y -= menuTall;
	}
	else
	{
		y = cursorY;
		if (!(tall - menuTall > cursorY))
			y -= menuTall;
		x = cursorX - menuWide;
	}
	(*(vgui2::Menu **)((char *)this + 0xfc))->sub_101a9890(x, y);
	(*(vgui2::Menu **)((char *)this + 0xfc))->vfunc15(0);
}
// END FUNCTION

// FUNCTION: 0x101b0bb0 size=0x2a
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual int f127(); virtual void u128(); virtual int f129(); };
}
void vgui2::TextEntry::vfunc126()
{
    if ((*(char *)((char *)this + 0x8a)) != 0) {
        ((lifted::V *)this)->f127();
        ((lifted::V *)this)->f129();
        ((lifted::V *)this)->f15(0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b0be0 size=0x1ae
#include "vgui2__TextEntry.h"
#include "utlvector.h"

struct Sys_101b0be0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void vfunc6(const char *text, int len);
};
extern Sys_101b0be0 *sub_101ac8e0();
extern void sub_101b1ec0(char *p, const char &src);
struct GV_101b0be0
{
	void sub_101b1ee0(int num);
	void sub_101b1e90(int elem, int num);
};

struct Dar_101b0be0
{
	int m_nCount;
	int m_nAlloc;
	char *m_pData;
	char GetElement(int i) const
	{
		if (i < 0 || i >= m_nCount)
			return 0;
		return m_pData[i];
	}
};
struct TEView_101b0be0
{
	char m_pad[0x58];
	Dar_101b0be0 m_TextStream;
};

// TARGET: vgui2::TextEntry::vfunc127
void vgui2::TextEntry::vfunc127()
{
	if (*((char *)this + 0x89))
		return;
	int x0, x1;
	if (vfunc158((int)&x0, (int)&x1))
	{
		CUtlVector<char> buf;
		for (int i = x0; i < x1; i++)
		{
			Dar_101b0be0 *pText = &((TEView_101b0be0 *)this)->m_TextStream;
			if (!vfunc163(pText, &i))
			{
				char c = pText->GetElement(i);
				int elem = buf.m_Size;
				if (elem + 1 > buf.m_Memory.m_nAllocationCount)
					((GV_101b0be0 *)&buf)->sub_101b1ee0(elem + 1 - buf.m_Memory.m_nAllocationCount);
				buf.m_Size += 1;
				buf.m_pElements = buf.m_Memory.m_pMemory;
				((GV_101b0be0 *)&buf)->sub_101b1e90(elem, 1);
				sub_101b1ec0(buf.m_Memory.m_pMemory + elem, c);
			}
		}
		int elem = buf.m_Size;
		if (elem + 1 > buf.m_Memory.m_nAllocationCount)
			((GV_101b0be0 *)&buf)->sub_101b1ee0(elem + 1 - buf.m_Memory.m_nAllocationCount);
		buf.m_Size += 1;
		buf.m_pElements = buf.m_Memory.m_pMemory;
		((GV_101b0be0 *)&buf)->sub_101b1e90(elem, 1);
		char *p = buf.m_Memory.m_pMemory + elem;
		if (p)
			*p = 0;
		sub_101ac8e0()->vfunc6(buf.Base(), x1 - x0);
	}
	vfunc15(0);
}
// END FUNCTION

// FUNCTION: 0x101b0d90 size=0x12e
// TARGET: ?vfunc128@TextEntry@vgui2@@UAEXXZ
#include "vgui2__TextEntry.h"
#include "utlvector.h"

struct IVGuiSystem_101b0d90
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6();
	virtual int GetClipboardText(int offset, char *buf, int bufLen);
};

extern IVGuiSystem_101b0d90 *sub_101ac8e0();

void vgui2::TextEntry::vfunc128()
{
	if (!((bool *)this)[0x8a])
		return;
	if (((bool *)this)[0x89])
		return;

	CUtlVector<char> buf;
	int len = *(int *)((char *)this + 0xac);
	if (len <= 0)
		len = 1024;

	buf.EnsureCount(len);
	int nRead = sub_101ac8e0()->GetClipboardText(0, buf.Base(), len);
	if (nRead < 1)
		return;

	vfunc131();

	for (int i = 0; i < nRead - 1; i++)
	{
		if (buf[i] == 0)
			break;
		vfunc120(buf[i]);
	}

	((bool *)this)[0xb0] = true;
	vfunc15(0);
}
// END FUNCTION

// FUNCTION: 0x101b0ec0 size=0xc6
#include "vgui2__TextEntry.h"
#include <stdlib.h>
#include <string.h>

struct TextEntryDar
{
	int m_nCount;
	int m_nCapacity;
	char *m_pData;

	void EnsureCapacity(int wanted)
	{
		if (wanted > m_nCapacity)
		{
			int newCap = m_nCapacity;
			if (newCap == 0)
				newCap = 1;
			while (newCap < wanted)
				newCap += newCap;
			char *newData = (char *)operator new(newCap);
			if (!newData)
				exit(0);
			memset(newData, 0, newCap);
			m_nCapacity = newCap;
			for (int i = 0; i < m_nCount; i++)
				newData[i] = m_pData[i];
			operator delete(m_pData);
			m_pData = newData;
		}
	}

	void CopyFrom(const TextEntryDar &other)
	{
		EnsureCapacity(other.m_nCount);
		memcpy(m_pData, other.m_pData, other.m_nCount);
		m_nCount = other.m_nCount;
	}
};

struct TextEntryView_101b0ec0
{
	char pad00[0x58];
	TextEntryDar m_TextStream;     // 0x58
	char pad64[0x0c];
	int m_nCursorPos;              // 0x70
	int m_n74;
	TextEntryDar m_UndoTextStream; // 0x78
	int m_nUndoCursorPos;          // 0x84
};

// TARGET: ?vfunc130@TextEntry@vgui2@@UAEXXZ
void vgui2::TextEntry::vfunc130()
{
	TextEntryView_101b0ec0 *v = (TextEntryView_101b0ec0 *)this;
	v->m_nCursorPos = v->m_nUndoCursorPos;
	v->m_TextStream.CopyFrom(v->m_UndoTextStream);
	vfunc57(0, 0);
	vfunc6();
	vfunc124();
}
// END FUNCTION

// FUNCTION: 0x101b0f90 size=0xb1
#include "vgui2__TextEntry.h"
extern "C" __declspec(noreturn) void __cdecl exit(int);
extern "C" void *__cdecl memset(void *, int, unsigned int);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
struct TECharBuf { int size; int alloc; char *data; };
// TARGET: vgui2::TextEntry::vfunc131
void vgui2::TextEntry::vfunc131()
{
	*(int *)((char *)this + 0x84) = *(int *)((char *)this + 0x70);
	TECharBuf *src = (TECharBuf *)((char *)this + 0x58);
	TECharBuf *dst = (TECharBuf *)((char *)this + 0x78);
	if (src->size > dst->alloc) {
		int n = dst->alloc;
		if (n == 0)
			n = 1;
		while (n < src->size)
			n += n;
		char *p = new char[n];
		if (!p)
			exit((int)p);
		memset(p, 0, n);
		dst->alloc = n;
		for (int i = 0; i < dst->size; i++)
			p[i] = dst->data[i];
		delete[] dst->data;
		dst->data = p;
	}
	memcpy(dst->data, src->data, src->size);
	dst->size = src->size;
}
// END FUNCTION

// FUNCTION: 0x101b1050 size=0x3c
#include "vgui2__TextEntry.h"
bool vgui2::TextEntry::vfunc164(int a1, int a2, int a3, int a4)
{
	if (*(char *)((char *)this + 0x8b) && a1 == 1) {
		int *p = (int *)a2;
		*p = vfunc171((char *)this + 0x58, *p, a3, a4);
		return true;
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x101b10e0 size=0x215
#include "vgui2__TextEntry.h"

#define F(T, off) (*(T *)((char *)this + (off)))

struct SurfView_101b10e0
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
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int GetFontTall(int font);
};

struct ScrollView_101b10e0
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
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107();
	virtual int GetValue();
};

// vgui's Dar<T> (count, capacity, data): operator[] gives 0 for an index out of range
template <class T> struct Dar_101b10e0
{
	int m_iCount;
	int m_iCapacity;
	T *m_pData;
	int GetCount() const { return m_iCount; }
	bool IsValidIndex(int i) const { return i >= 0 && i < m_iCount; }
	T operator[](int i) const { return IsValidIndex(i) ? m_pData[i] : 0; }
};

extern SurfView_101b10e0 *sub_101ac8d0();
extern int sub_101ad550(int font, char ch);

#define m_TextStream_101b10e0 (*(Dar_101b10e0<char> *)((char *)this + 0x58))
#define m_LineBreaks_101b10e0 (*(Dar_101b10e0<int> *)((char *)this + 0x64))

int vgui2::TextEntry::sub_101afbf0()
{
	int lineCount = m_LineBreaks_101b10e0.GetCount();
	int cursor = F(int, 0x70);
	int i;
	for (i = 0; i < lineCount; i++)
	{
		if (cursor < m_LineBreaks_101b10e0[i])
			break;
	}
	if (F(char, 0x75) && F(int, 0x70) != m_TextStream_101b10e0.GetCount())
		i--;
	return i;
}

// TARGET: ?vfunc172@TextEntry@vgui2@@UAEHPAH@Z
int vgui2::TextEntry::vfunc172(int *pLineIdx)
{
	int numLines = m_LineBreaks_101b10e0.GetCount();
	int startIndex = 0;
	int lineStart = 0;
	if (F(ScrollView_101b10e0 *, 0xb4) && !F(char, 0x8d))
	{
		startIndex = F(ScrollView_101b10e0 *, 0xb4)->GetValue();
	}
	else
	{
		int font = F(int, 0x124);
		int maxLines = sub_101ab1a0() / (sub_101ac8d0()->GetFontTall(font) + 1);
		if (numLines > maxLines)
		{
			int cur = sub_101afbf0();
			startIndex = F(int, 0xcc);
			if (cur < startIndex)
			{
				startIndex = cur;
				if (F(ScrollView_101b10e0 *, 0xb4))
				{
					sub_101af9e0(1);
					startIndex = F(ScrollView_101b10e0 *, 0xb4)->GetValue();
				}
			}
			else if (cur > startIndex + maxLines - 1)
			{
				startIndex = cur - maxLines + 1;
				if (F(ScrollView_101b10e0 *, 0xb4))
				{
					sub_101af9e0(-1);
					startIndex = F(ScrollView_101b10e0 *, 0xb4)->GetValue();
				}
			}
		}
		else if (!F(char, 0xb1))
		{
			int width = 3;
			int flag = 1;
			for (int i = F(int, 0xd0); i < m_TextStream_101b10e0.GetCount(); i++)
			{
				char c = m_TextStream_101b10e0[i];
				if (!vfunc164(c, (int)&i, (int)&width, (int)&flag))
				{
					if (F(char, 0x89))
						c = '*';
					if (F(int, 0x70) == i)
						break;
					width += sub_101ad550(font, c);
				}
			}
			if (width >= sub_101ab130())
				F(int, 0xd0)++;
			else if (width <= 0 && F(int, 0xd0) > 0)
				F(int, 0xd0)--;
		}
	}
	if (startIndex)
	{
		*pLineIdx = startIndex;
		if (startIndex < m_LineBreaks_101b10e0.GetCount())
			lineStart = m_LineBreaks_101b10e0[startIndex - 1];
	}
	if (!F(char, 0xd4))
		return 0;
	F(int, 0xcc) = startIndex;
	if (F(char, 0xb1))
		return lineStart;
	return F(int, 0xd0);
}
// END FUNCTION

// FUNCTION: 0x101b1390 size=0x43
#include "vgui2__TextEntry.h"
struct KV101b5670 { KV101b5670 *sub_101b5670(const char *); };
void *sub_101b6840(int);
// TARGET: ?vfunc157@TextEntry@vgui2@@UAEHXZ
int vgui2::TextEntry::vfunc157()
{
	KV101b5670 *kv = (KV101b5670 *)sub_101b6840(0x1c);
	vfunc43(kv ? kv->sub_101b5670("TextChanged") : 0);
	*((char *)this + 0xb0) = 0;
	return vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101b13e0 size=0x24
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::TextEntry::vfunc132(int a0)
{
    *(int *)((char *)this + 0x124) = a0;
    ((lifted::V *)this)->f57(0, 0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b1410 size=0xc
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::TextEntry::vfunc168()
{
    *(char *)((char *)this + 0x100) = 1;
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b1420 size=0x17
#include "vgui2__TextEntry.h"
namespace lifted {
int sub_101b1760();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::TextEntry::vfunc169()
{
    lifted::sub_101b1760();
    *(char *)((char *)this + 0x100) = 1;
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b1440 size=0x76
#include <string.h>
#include "vgui2__TextEntry.h"

#define V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
struct TEView
{
	V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V10(j)
	virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
	virtual void k4(); virtual void k5(); virtual void k6(); virtual void k7();
	virtual void GetText(int start, char *buf, int len);
};

struct KVv
{
	virtual const char *GetName();
	virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
	virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8();
	virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12();
	virtual void d13();
	virtual void SetString(const char *key, const char *value);
};

struct PanelV
{
	bool sub_101ac540(vgui2::KeyValues *data);
};

bool vgui2::TextEntry::vfunc14(vgui2::KeyValues *data)
{
	if (!strcmp(((KVv *)data)->GetName(), "GetText"))
	{
		char buf[256];
		((TEView *)this)->GetText(0, buf, 255);
		((KVv *)data)->SetString("text", buf);
		return true;
	}
	return ((PanelV *)this)->sub_101ac540(data);
}
// END FUNCTION

// FUNCTION: 0x101b14c0 size=0x8
#include "vgui2__TextEntry.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(); };
}
void vgui2::TextEntry::vfunc167()
{
    ((lifted::V *)this)->f107();
}
// END FUNCTION

// FUNCTION: 0x101b14d0 size=0xbd
#include "vgui2__TextEntry.h"
#include "vgui2__KeyValues.h"
struct TextEntryCharVec
{
	int size; int m4; char *data;
	char Get(int i) const { if (i < 0 || i >= size) return 0; return data[i]; }
};
// TARGET: vgui2::TextEntry::vfunc170
void vgui2::TextEntry::vfunc170(int startpos)
{
	char text[0x200];
	int a, b;
	int n = 0;
	TextEntryCharVec *v = (TextEntryCharVec *)((char *)this + 0x58);
	int i;
	int sz = v->size;
	*((char *)this + 0xd9) = 1;
	i = startpos;
	while (i < sz && *((char *)this + 0xd9)) {
		char c = v->Get(i);
		if (!vfunc164(c, (int)&i, (int)&a, (int)&b))
			text[n++] = c;
		i++;
		sz = v->size;
	}
	text[n] = 0;
	vfunc43(new vgui2::KeyValues("TextClicked", "text", text));
}
// END FUNCTION

// FUNCTION: 0x101b1590 size=0xb1
#include "vgui2__TextEntry.h"
#include "vgui2__Image.h"
typedef vgui2::Image::ImageColor TEColor;
struct TEKV9 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual int GetInt(const char *key, int def); };
struct TELoc { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual TEColor GetColor(const char *name, TEColor def); };
struct TESch { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual TELoc *Get(int); };
TESch *sub_101ac8c0();
struct CUnknown101aa220 { int sub_101aa220(); };
// TARGET: vgui2::TextEntry::vfunc75
void vgui2::TextEntry::vfunc75(int p)
{
	Panel::vfunc75(p);
	TEKV9 *kv = (TEKV9 *)p;
	vfunc133(kv->GetInt("textHidden", 0) != 0);
	vfunc134(kv->GetInt("editable", 1) != 0);
	vfunc143(kv->GetInt("maxchars", -1));
	TESch *s = sub_101ac8c0();
	TELoc *loc = s->Get(((CUnknown101aa220 *)this)->sub_101aa220());
	TEColor def;
	*(TEColor *)((char *)this + 0xf0) = loc->GetColor("BorderSelection", def);
}
// END FUNCTION

// FUNCTION: 0x101b1650 size=0x59
#include "vgui2__TextEntry.h"
#include "vgui2__KeyValues.h"
void vgui2::TextEntry::sub_101b1650(int a)
{
	vgui2::KeyValues *data = (vgui2::KeyValues *)a;
	Panel::sub_101ab750(a);
	data->vfunc15((int)"textHidden", *(unsigned char *)((char *)this + 0x89));
	data->vfunc15((int)"editable", vfunc135());
	data->vfunc15((int)"maxchars", *(int *)((char *)this + 0xac));
}
// END FUNCTION

// FUNCTION: 0x101b16b0 size=0x23
#include "vgui2__TextEntry.h"
namespace lifted {
extern char g_102d8820;
extern char g_10678e00;
int sub_101ab860();
int sub_101d3192(int, int, int, int);
}
int vgui2::TextEntry::vfunc77()
{
    lifted::sub_101d3192((int)&lifted::g_10678e00, 0x400, (int)&lifted::g_102d8820, lifted::sub_101ab860());
    return (int)&lifted::g_10678e00;
}
// END FUNCTION

// FUNCTION: 0x101b1840 size=0x29
#include "vgui2__TextEntry.h"
namespace lifted {
int sub_101ab3e0();
}
void vgui2::TextEntry::vfunc80()
{
    if ((*(char *)((char *)this + 0x118)) != 0) {
        *(int *)((char *)this + 0x9c) = 0;
        *(int *)((char *)this + 0xa0) = *(int *)((char *)this + 0x58);
        *(int *)((char *)this + 0x70) = *(int *)((char *)this + 0x58);
        *(char *)((char *)this + 0x118) = 0;
    }
    lifted::sub_101ab3e0();
}
// END FUNCTION

// FUNCTION: 0x101b1a20 size=0x1e
#include "vgui2__TextEntry.h"
int vgui2::TextEntry::vfunc151(int a0, int a1)
{
    *(char *)((char *)this + 0x11a) = 1;
    *(int *)((char *)this + 0x11c) = a0;
    *(int *)((char *)this + 0x120) = a1;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b1c60 size=0x6
#include "vgui2__TextEntry.h"
namespace lifted {
extern char g_102d8650;
}
int vgui2::TextEntry::vfunc102()
{
    return (int)&lifted::g_102d8650;
}
// END FUNCTION
