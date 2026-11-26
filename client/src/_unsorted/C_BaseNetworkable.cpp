// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100a36f0 size=0x6
#include "C_BaseNetworkable.h"
namespace lifted {
extern char g_102b0204;
}
int C_BaseNetworkable::vfunc9()
{
    return (int)&lifted::g_102b0204;
}
// END FUNCTION

// FUNCTION: 0x100a3700 size=0x3
#include "C_BaseNetworkable.h"
int C_BaseNetworkable::vfunc8()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3870 size=0x41
#include "C_BaseNetworkable.h"
// TARGET: ??0C_BaseNetworkable@@QAE@XZ
C_BaseNetworkable::C_BaseNetworkable()
{
	m_unk10 = 1;
	m_unk12 = 0xffff;
	m_unk14.v = -1;
	m_unk18 = 0xffff;
	m_unkc = -1;
}
// END FUNCTION

// FUNCTION: 0x100a38c0 size=0x1e
#include "C_BaseNetworkable.h"

// VC6 writes C_BaseNetworkable's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseNetworkable *pcd_emit_100a38c0(const C_BaseNetworkable &other) { return new C_BaseNetworkable(other); }

// TARGET: ??_GC_BaseNetworkable@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100a38e0 size=0x2a
#include "C_BaseNetworkable.h"
int sub_100cc2e0(int);
C_BaseNetworkable::~C_BaseNetworkable()
{
    sub_100a3950();
    sub_100cc2e0(m_unkc);
}
// END FUNCTION

// FUNCTION: 0x100a39d0 size=0x2c
#include "C_BaseNetworkable.h"
// TARGET: ?NotifyShouldTransmit@C_BaseNetworkable@@UAEXH@Z
void C_BaseNetworkable::NotifyShouldTransmit(int state)
{
	if (state == 0)
		sub_100a3a60(0);
	else if (state == 2)
		sub_100a3a60(1);
}
// END FUNCTION

// FUNCTION: 0x100a3a00 size=0x30
#include "C_BaseNetworkable.h"

bool sub_100cc190(IClientNetworkable *ent, int updateType, int *storedEvent);	// AddDataChangeEvent

void C_BaseNetworkable::PreDataUpdate(int updateType)
{
	if (sub_100cc190(this, updateType, &m_unkc))
	{
		OnPreDataChanged(updateType);
	}
}
// END FUNCTION

// FUNCTION: 0x100a3a90 size=0x1c
#include "C_BaseNetworkable.h"
__declspec(dllimport) void DevMsg(int, const char *, ...);
class ClientClass
{
public:
	void *m_pCreateFn;
	void *m_pCreateEventFn;
	const char *m_pNetworkName;
};
void C_BaseNetworkable::ReceiveMessage(int classID, bf_read &msg)
{
	DevMsg( 1, "Unhandled entity message for C_BaseNetworkable %s.\n", GetClientClass()->m_pNetworkName );
}
// END FUNCTION

// FUNCTION: 0x100a3ac0 size=0xc
#include "C_BaseNetworkable.h"
int C_BaseNetworkable::vfunc0(int a0)
{
    *(int *)((char *)this + 0x14) = *(int *)((char *)a0);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a3ad0 size=0x4
#include "C_BaseNetworkable.h"
unsigned int * C_BaseNetworkable::vfunc1()
{
    return (unsigned int *)((char *)this + 0x14);
}
// END FUNCTION

// FUNCTION: 0x100a3af0 size=0x3
#include "C_BaseNetworkable.h"
ICollideable * C_BaseNetworkable::GetClientCollideable()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3b00 size=0xb
#include "C_BaseNetworkable.h"
IClientNetworkable * C_BaseNetworkable::GetClientNetworkable()
{
    if (((int)this) != 0) {
        return (IClientNetworkable *)((char *)this + 4);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3b10 size=0x3
#include "C_BaseNetworkable.h"
IClientRenderable * C_BaseNetworkable::GetClientRenderable()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3b20 size=0x3
#include "C_BaseNetworkable.h"
IClientEntity * C_BaseNetworkable::GetIClientEntity()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3b30 size=0x3
#include "C_BaseNetworkable.h"
C_BaseEntity * C_BaseNetworkable::GetBaseEntity()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a3b40 size=0xb
#include "C_BaseNetworkable.h"
IClientThinkable * C_BaseNetworkable::GetClientThinkable()
{
    if (((int)this) != 0) {
        return (IClientThinkable *)((char *)this + 8);
    }
    return 0;
}
// END FUNCTION
