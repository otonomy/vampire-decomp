// CUnknown101dd910: projectile description of a discipline (name provisional): speed, model, particle, dies-on-hit flag.
#pragma once

class IKVNodeView;

class CUnknown101dd910
{
public:
	int m_nSpeed;	// 0x00
	const char *m_pszModel;	// 0x04
	const char *m_pszParticle;	// 0x08
	char m_bParticleDiesOnHit;	// 0x0c
	char m_bSyncs;	// 0x0d
	char m_pad000e[2];

		// fires the projectile at the target (ret 0x14, stub 0x10002068)
		// stub 0x100047ff: whether the projectile description is in use
	void sub_10147f40();	// prints the description with Msg ("[Projectile]:", speed, model, particle, "ParticleDiesOnHit: True"); nothing when sub_101dd4f0() is false
	void sub_10147e30();	// the constructor body (stub 0x10008ec7)
	char sub_10147e90(IKVNodeView *pKV);	// loads the description from the "Projectile" child
		// loads the description from the "Projectile" child of the node (Speed, Model, Particle, ParticleDiesOnHit, "Syncs" flag at +0xd, the SoundFX list at +0x10 and the interrupt effects at +0x20) and precaches the model; false for a null node
};
