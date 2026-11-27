#pragma once
#include "CSpriteRendererSub.h"
#include "Vector.h"
#include "QAngle.h"
class C_SpriteRenderer
{
public:
	~C_SpriteRenderer();
	void sub_100c31e0(int type, const Vector &origin, const QAngle &angles, Vector &forward, Vector &right, Vector &up);	// "GetSpriteAxes" (2003 c_sprite.cpp): SPR_VP_PARALLEL_UPRIGHT 0, FACING_UPRIGHT 1, VP_PARALLEL 2, ORIENTED 3, VP_PARALLEL_ORIENTED 4
	C_SpriteRenderer() { m_unk18 = -1; }
	int sub_100c3480(void *entity, const void *model, const Vector &origin, const QAngle &angles, float frame, void *attachedto, int attachmentindex, int rendermode, int renderfx, int alpha, int r, int g, int b, float scale);
	float sub_100c24a0(const Vector &origin, int rendermode, int renderfx, int alpha, float *pScale);
	CSpriteRendererSub m_sub;
	int m_unk18;
	int m_unk1c;
	int m_unk20;
	int m_unk24;
	int m_unk28;
	int m_unk2c;
	int m_unk30;
	int m_unk34;
	int m_unk38;
	int m_unk3c;
	int m_unk40;
	int m_unk44;
	int m_unk48;
	int m_unk4c;
	int m_unk50;
	int m_unk54;
	int m_unk58;
	int m_unk5c;
};
