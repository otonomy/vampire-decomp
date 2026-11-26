// C_BaseAnimating: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"

class C_BaseAnimating : public C_BaseEntity
{
public:
	C_BaseAnimating();
	void sub_100966e0();
	void sub_100935a0(const Vector &origin, const QAngle &angles, int event, const char *options);
	void sub_100941d0(const char *, int, int);
	void sub_10094250(int, int, int);
	void sub_100027f0(int iBone, Vector *pOrigin, QAngle *pAngles);
	void sub_10096650();
	void sub_10095c40();
	bool sub_10091860(int, Vector &, QAngle &, matrix3x4_t &);
	void sub_10095880();
	int sub_10095b90(int, int, int);
	int sub_100958f0(int);
	float sub_100955f0(int);
	float sub_10095640(int);
	void sub_10095680(int, Vector *);
	float sub_10095910(int, void *);
	bool sub_10094020();
	float sub_10091020(float, float, float, bool);
	float sub_1008fa70(float, int, float, float, float);
	struct PoseDesc1008fa70 *sub_10096830(int);
	int sub_10092810();
	bool sub_10091910(int idx, int arg);
	bool sub_10093e40();
	void sub_10002680(int);
	bool sub_10095ac0(int idx, int arg);
	int sub_1008f900(int index);
	void sub_100968a0(Vector *pos, class Quaternion *q, int sequence, float cycle, const float *poseParameter, const struct CBitVecWords *boneMask);	// CalcPose over the model and its two extra studio headers (bone maps at +0x4d0)
	int sub_100940d0(int index, int *pOut);
	int LookupBone(const char *pszName);
	void sub_10096c30();
	int sub_100965d0(int, int);
	void sub_100bdbd0(Vector &, Vector &);
	void sub_100947b0(Vector &, Vector &);
	void sub_100bdb60(Vector &, Vector &);
	void sub_10094350(Vector &, Vector &);
	void sub_100bdc40(Vector &, Vector &);
	void sub_10094040(Vector &, Vector &);
	void sub_100bdcb0(Vector &, Vector &);
	void sub_1009f360(Vector &, Vector &);
	void sub_101364b0();
	void sub_100a2930();
	void sub_100948d0(int);
	bool sub_10095d00(Vector *pVecWorldMins, Vector *pVecWorldMaxs);
	int sub_10095990(int a, int b, int *p);
	virtual ~C_BaseAnimating();
	virtual void OnDataChanged(int updateType);
	void sub_10094930();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BaseAnimating's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual bool vfunc27(int, int, int);
	virtual void vfunc37();
	virtual bool vfunc57(int, int, int);
	virtual void vfunc61();
	virtual int vfunc62();
	virtual int vfunc66();
	virtual bool vfunc67();
	virtual int vfunc70();
	virtual bool vfunc71();
	virtual int vfunc72();
	virtual bool vfunc73();
	virtual int vfunc86();
	virtual void vfunc112();
	// the slots C_BaseAnimating adds to its base's vtable: 120-142, vfuncK at slot K
	virtual void vfunc120(float *, float);
	virtual float vfunc121(int, int, float *poseParameter, float cycle, float);
	virtual float vfunc122();
	virtual void vfunc123(const Vector *pos, const Quaternion *q, const matrix3x4_t &cameraTransform, const struct StudioBoneMask *pBoneComputed);	// BuildTransformations
	virtual void vfunc124(int, int);
	virtual int vfunc125(int, int);
	virtual int vfunc126();
	virtual void vfunc127(const Vector &origin, const QAngle &angles, int event, const char *options);
	virtual void vfunc128();
	virtual float vfunc129(int, float, float, float);
	virtual void vfunc130(const struct CBitVecWords *boneMask, Vector *pos, Quaternion *q);
	void sub_10091110(const struct CBitVecWords *boneMask, float cycle, float *poseParameter, Vector *pos, Quaternion *q);
	void sub_10096b30(Quaternion *q1, Vector *pos1, int sequence, const Quaternion *q2, const Vector *pos2, float s, const struct CBitVecWords *boneMask);
	virtual void vfunc131(int, int, int, int, int, int);
	virtual void vfunc132(bool);
	virtual int vfunc133();
	virtual void vfunc134();
	virtual void vfunc135();
	virtual float vfunc136(float flInterval);
	virtual float vfunc137(float);
	virtual float vfunc138(int iSequence);
	virtual int vfunc139(int);
	virtual bool vfunc140();
	virtual void vfunc141();
	virtual bool vfunc142();
};
