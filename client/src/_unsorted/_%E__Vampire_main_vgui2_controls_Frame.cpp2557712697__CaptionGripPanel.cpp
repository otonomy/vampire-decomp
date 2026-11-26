// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b7af0 size=0x359
#include "vgui2__Frame.h"

extern "C" int abs(int);
#pragma intrinsic(abs)

#define V10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();

struct VSurfaceView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual int GetEmbeddedPanel();
	virtual void v7(); virtual void v8(); virtual void v9();
	V10(v1) V10(v2) V10(v3) V10(v4) V10(v5) V10(v6) V10(v7)
	virtual void v80(); virtual void v81(); virtual void v82();
	virtual void GetWorkspaceBounds(int &x, int &y, int &wide, int &tall);
};

struct VPanelView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void GetSize(int vpanel, int &wide, int &tall);
	virtual void v6(); virtual void v7(); virtual void v8();
	virtual void GetPos(int vpanel, int &x, int &y);
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual bool IsVisible(int vpanel);
	virtual void v15();
	virtual int GetChildCount(int vpanel);
	virtual int GetChild(int vpanel, int index);
	virtual void v18(); virtual void v19(); virtual void v20();
	virtual bool IsPopup(int vpanel);
};

// vgui2::Frame's slot 120 (IsMoveable); Frame.h numbers its own slots two too high
struct VFrameView
{
	V10(v0) V10(v1) V10(v2) V10(v3) V10(v4) V10(v5) V10(v6) V10(v7) V10(v8) V10(v9) V10(v10) V10(v11)
	virtual bool IsMoveable();
};

VSurfaceView *sub_101ac8d0();
VPanelView *sub_101ac900();

struct CaptionGripView
{
	int m_unk0[0x58 / 4];
	vgui2::Frame *m_frame;
	int m_unk5c;
	int m_unk60;
	int m_unk64;
	int m_dragOrgX;
	int m_dragOrgY;

	bool getInsideSnapPosition(int boundX, int boundY, int boundWide, int boundTall, int &snapToX, int &snapToY)
	{
		int wide, tall;
		m_frame->sub_101a9920(&wide, &tall);
		bool snapped = false;
		if (abs(snapToX - boundX) < 10)
		{
			snapToX = boundX;
			snapped = true;
		}
		else if (abs((snapToX + wide) - (boundX + boundWide)) < 10)
		{
			snapToX = boundX + boundWide - wide;
			snapped = true;
		}
		if (abs(snapToY - boundY) < 10)
		{
			snapToY = boundY;
			snapped = true;
		}
		else if (abs((snapToY + tall) - (boundY + boundTall)) < 10)
		{
			snapToY = boundY + boundTall - tall;
			snapped = true;
		}
		return snapped;
	}

	bool getOutsideSnapPosition(int boundX, int boundY, int boundWide, int boundTall, int &snapToX, int &snapToY)
	{
		int top = boundY;
		int left = boundX;
		int right = boundX + boundWide;
		int bottom = boundY + boundTall;
		int wide, tall;
		bool snapped = false;
		m_frame->sub_101a9920(&wide, &tall);
		bool bYOverlap = (snapToY > top && snapToY < bottom) || (snapToY + tall > top && snapToY + tall < bottom) || (snapToY < top && snapToY + tall > bottom);
		bool bXOverlap = (snapToX > left && snapToX < right) || (snapToX + wide > left && snapToX + wide < right) || (snapToX < left && snapToX + wide > right);
		if (bYOverlap || bXOverlap)
		{
			if (snapToX <= right + 10 && snapToX >= right - 10)
			{
				if (bYOverlap)
				{
					snapToX = right;
					snapped = true;
				}
			}
			else if (snapToX + wide >= left - 10 && snapToX + wide <= left + 10)
			{
				if (bYOverlap)
				{
					snapToX = left - wide;
					snapped = true;
				}
			}
			if (snapToY <= bottom + 10 && snapToY >= bottom - 10)
			{
				if (bXOverlap)
				{
					snapToY = bottom;
					snapped = true;
				}
			}
			else if (snapToY + tall <= top + 10 && snapToY + tall >= top - 10)
			{
				if (bXOverlap)
				{
					snapToY = top - tall;
					snapped = true;
				}
			}
		}
		return snapped;
	}

	void sub_101b7e50(int vpanel, int &x, int &y);
	void sub_101b7af0(int dx, int dy);
};

void CaptionGripView::sub_101b7af0(int dx, int dy)
{
	if (!((VFrameView *)m_frame)->IsMoveable())
		return;

	int newX = m_dragOrgX + dx;
	int newY = m_dragOrgY + dy;

	int wx, wy, ww, wt;
	sub_101ac8d0()->GetWorkspaceBounds(wx, wy, ww, wt);
	getInsideSnapPosition(wx, wy, ww, wt, newX, newY);

	int root = sub_101ac8d0()->GetEmbeddedPanel();
	for (int i = 0; i < sub_101ac900()->GetChildCount(root); i++)
	{
		int child = sub_101ac900()->GetChild(root, i);
		if (child == m_frame->vfunc0())
			continue;
		if (sub_101ac900()->IsVisible(child) && sub_101ac900()->IsPopup(child))
		{
			int x, y, wide, tall;
			sub_101ac900()->GetPos(child, x, y);
			sub_101ac900()->GetSize(child, wide, tall);
			if (getOutsideSnapPosition(x, y, wide, tall, newX, newY))
				continue;
		}
		for (int j = 0; j < sub_101ac900()->GetChildCount(child); j++)
		{
			int sub = sub_101ac900()->GetChild(child, j);
			sub_101b7e50(sub, newX, newY);
		}
	}

	m_frame->sub_101a9890(newX, newY);
}
// END FUNCTION
