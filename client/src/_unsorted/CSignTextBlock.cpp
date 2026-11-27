// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10060400 size=0x1e
#include "CSignTextBlock.h"

// VC6 writes CSignTextBlock's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CSignTextBlock *pcd_emit_10060400(const CSignTextBlock &other) { return new CSignTextBlock(other); }

// TARGET: ??_GCSignTextBlock@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10060530 size=0x2c
#include "CSignTextBlock.h"
CSignTextBlock::~CSignTextBlock()
{
	::operator delete(*(void **)((char *)this + 0x128));
	::operator delete(*(void **)((char *)this + 0x12c));
}
// END FUNCTION
