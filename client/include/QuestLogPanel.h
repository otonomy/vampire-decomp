// QuestLogPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include <stdlib.h>
#include "vgui2__PropertyPage.h"

class QuestLogPanel : public vgui2::PropertyPage
{
public:
	QuestLogPanel();
	virtual ~QuestLogPanel();
	void sub_10188730();
	int sub_10189990(int);
	static void operator delete(void *pMem) { free(pMem); }
	void sub_101892d0(int);
	void sub_10189600();	// rebuilds the three quest lists (active / completed / other) of the player's area
	static void sub_10189600(QuestLogPanel *pPanel) { pPanel->sub_10189600(); }	// the call form 0x101892d0's source uses (it wrote the rebuild as a fastcall on the panel)
	void sub_101898c0(struct QuestRecY *q, char *buf, int *len);	// formats one quest record into a text buffer and advances its length (does not use this)
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with QuestLogPanel's own function
	virtual void vfunc3();
	virtual int vfunc21(int);
	virtual void vfunc78(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc119();
	// the slots QuestLogPanel adds to its base's vtable: 123-125, vfuncK at slot K
	virtual void vfunc123();
	virtual void vfunc124(int);
	virtual void vfunc125(int);
};
