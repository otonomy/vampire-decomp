// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10161840 size=0x14
#include "CVTraitDependencyValue_t.h"
namespace lifted {
struct C10160670 { int sub_10160670(); };
}
void CVTraitDependencyValue_t::vfunc0()
{
    int t0 = ((lifted::C10160670 *)((char *)this + 4))->sub_10160670();
    *(int *)((char *)this + 0x14) = -1;
}
// END FUNCTION

// FUNCTION: 0x10161860 size=0x87
#include "CVTraitDependencyValue_t.h"
#include "CParsedValue.h"
#include "StatOwner2.h"
extern "C" char *strtok(char *, const char *);

struct CTraitBlock_10161860 { void sub_101608a0(const char *psz); };

// TARGET: CVTraitDependencyValue_t::vfunc1
void CVTraitDependencyValue_t::vfunc1(const char *psz)
{
	if (*psz)
	{
		char *buf = sub_1015fb60(psz);
		char *first = strtok(buf, " ");
		CTraitBlock_10161860 *blk = (CTraitBlock_10161860 *)((char *)this + 4);
		blk->sub_101608a0(first);
		char *tok = strtok(0, " ");
		if (tok)
		{
			int id = g_105f93c0.sub_1015f160("Equality");
			*(int *)((char *)this + 0x14) = g_105f93c0.sub_1015f270(id)->sub_1015ed00(tok);
			((CParsedValue *)((char *)this + 0x18))->sub_101616b0(blk, strtok(0, " "));
		}
	}
}
// END FUNCTION
