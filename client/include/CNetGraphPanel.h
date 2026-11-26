// CNetGraphPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

struct NGEntry { int m_type; int m_val; };
struct NGState { int m_0; int m_4; int m_8; int m_c; };
class CNetGraphPanel : public vgui2::Panel
{
public:
	virtual ~CNetGraphPanel();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CNetGraphPanel's own function
	virtual void vfunc2();
	virtual int vfunc74(int);
	virtual void vfunc98();
	// the slots CNetGraphPanel adds to its base's vtable: 107-107, vfuncK at slot K
	virtual bool vfunc107();
	unsigned int sub_101698d0();
	void sub_10169140(struct packet_latency_t *packet_latency, struct netbandwidthgraph_t *graph, int *choke_count, int *loss_count, int *biggest_message, float *latency, int *latency_count, float *avg_message, float *f95thpercentile);
	void sub_10168ce0(int, unsigned char *, unsigned char *);
	void sub_10168d20(NGEntry *, unsigned char *, int *, unsigned char *);
	void sub_10169c20(int, int);
	int sub_10169c80(NGState *, int, unsigned char, unsigned char, unsigned char, int);
	void sub_1016a550(NGState *, unsigned char *, int);
	void sub_10168eb0(struct vrect_10168eb0 vrect, struct cmdinfo_10168eb0 *cmdinfo, int x, int w);
};
