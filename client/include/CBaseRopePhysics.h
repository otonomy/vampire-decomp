// CBaseRopePhysics (RTTI .?AVCBaseRopePhysics@@, base CSimplePhysics::IHelper): Source's rope simulation
// (rope_physics.h), vtable 0x10497510 with the two IHelper slots, constructed out of line (0x102492a0).
// CRopePhysics<N> below adds the node and spring arrays.
#pragma once

#include "Vector.h"
#include "CUnknown102496a0.h"	// m_timer: Source's CSimplePhysics integrator

struct CRopeNode	// CSimplePhysics::CNode, 36 bytes
{
	Vector m_vPos;	// 0x00
	Vector m_vPrevPos;	// 0x0c
	Vector m_vPredicted;	// 0x18
};

struct CRopeLink	// a pair of positions the constraint pulls together
{
	Vector *m_pA;	// 0x00
	Vector *m_pB;	// 0x04
};

// The outer class of the game's RTTI name .?AVIHelper@CSimplePhysics@@ (vtable 0x10497520, two __purecall slots):
// what the integrator asks for a node's forces and for the constraints. Source's CSimplePhysics integrator itself
// is CUnknown102496a0.
class CSimplePhysics
{
public:
	class IHelper
	{
	public:
		virtual void vfunc0(CRopeNode *pNodes, int iNode, Vector *pAccel) = 0;	// GetNodeForces
		virtual void vfunc1(CRopeNode *pNodes, int nNodes) = 0;	// ApplyConstraints
	};
};

class CBaseRopePhysics : public CSimplePhysics::IHelper
{
public:
	CBaseRopePhysics(void *pNodes, int nNodes, void *pSprings);
	virtual void vfunc0(CRopeNode *pNodes, int iNode, Vector *pAccel);	// GetNodeForces: the delegate's, else none
	virtual void vfunc1(CRopeNode *pNodes, int nNodes);	// ApplyConstraints: the global number of times pulls the first count - 1 link pairs back to the rest length (when further apart than the squared limit at +0x18), handing the nodes on to the delegate at +4 after every iteration; subclasses call it as CBaseRopePhysics::vfunc1

	CRopeNode *GetNode(int i) { return &m_pNodes[i]; }
	CRopeNode *GetFirstNode() { return GetNode(0); }
	CRopeNode *GetLastNode() { return GetNode(m_nNodes - 1); }
	int NumNodes() { return m_nNodes; }

	CSimplePhysics::IHelper *m_pNext;	// 0x04 the delegate the forces and constraints are handed on to
	CRopeNode *m_pNodes;	// 0x08
	int m_nNodes;	// 0x0c
	CRopeLink *m_pLinks;	// 0x10
	float m_flRestLength;	// 0x14
	float m_flMinDistSq;	// 0x18
	char m_pad001c[4];
	CUnknown102496a0 m_timer;	// 0x20

		// sets the timer's interval to 0.02 s
		// links the nodes into springs
		// stub 0x100142d6: the rest length of one segment, and the delegate that supplies the end points
		// stub 0x100060c3
};

// RTTI .?AV?$CRopePhysics@$09@@ (vtable 0x10464d44, the member at +8 of CPositionInterpolator_Rope) and
// .?AV?$CRopePhysics@$0CAA@@@ (vtable 0x10516cd4, CHangRope's base): a rope with its own N nodes and N - 1 springs;
// both vtables hold CBaseRopePhysics' two slots.
template<int N>
class CRopePhysics : public CBaseRopePhysics
{
public:
	CRopePhysics() : CBaseRopePhysics(m_nodes, N, m_springs) {}
	char m_nodes[N * sizeof(CRopeNode)];	// 0x38
	char m_springs[(N - 1) * sizeof(CRopeLink)];
};
