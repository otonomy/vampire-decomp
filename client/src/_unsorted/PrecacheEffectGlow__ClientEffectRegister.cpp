// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100eea80 size=0x45
#include "engineclient.h"
#include "PrecacheEffectGlow.h"
struct IMat {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(int); virtual void v13(int);
};
extern const char *g_102bba80;
// TARGET: PrecacheEffectGlow::ClientEffectRegister::vfunc0
void PrecacheEffectGlow::ClientEffectRegister::vfunc0(bool on) {
	bool found;
	bool *pf = &found;
	const char *name = g_102bba80;
	IMat *m = ((IMat *)materials->FindMaterial(name, pf, true));
	if (found && m) {
		if (on)
			m->v12(0);
		else
			m->v13(0);
	}
}
// END FUNCTION
