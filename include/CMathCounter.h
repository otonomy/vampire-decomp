// CMathCounter (RTTI .?AVCMathCounter@@): math_counter, flattened onto CLogicalEntity (the real bases are not modelled).
#pragma once

#include "CLogicalEntity.h"
#include "inputdata_t.h"

class CMathCounter : public CLogicalEntity
{
public:
	virtual CBaseEntity *vfunc5(unsigned int flags);	// slot 5: scalar deleting destructor (destroys the three outputs at +0x48c / +0x474 / +0x45c, then the base)
	virtual bool vfunc110(const char *pszKey, const char *pszValue);	// slot 110 KeyValue: "startvalue" sets the output value (+0x45c) from atoi(value) as a float; any other key goes to the base
	bool sub_1009e430(const char *pszKey, const char *pszValue);	// CBaseEntity::vfunc110 (stub 0x1000fc86), called directly
	virtual void vfunc103();	// slot 103 "CMathCounter::Spawn": orders the min / max (+0x450 / +0x454) and, unless both are zero, clamps the output value (+0x45c) into that range and stores it back (variant_t::sub_100d0390(1, &value))
	void sub_10133910(inputdata_t &inputdata);
	void InputSetValue(inputdata_t &inputdata);	// input handler: sub_10133950(activator, the input's float)	// input handler: calls sub_10133950(activator, outvalue - the input's float)
	void sub_10134c80(inputdata_t &inputdata);	// input handler: m_flMin = the input's float (0 for another type), then sub_10134d30(activator, m_flMin)
	void sub_10133950(void *pActivator, float flNewValue);	// "CMathCounter::SetValue"-like (stub 0x1000206d): clamps and fires the outputs
	void sub_10134d30(void *pActivator, float flNewValue);	// "CMathCounter::UpdateOutValue": a value equal to the maximum (+0x454) fires the output at +0x470; any other value fires the output at +0x488, then the one at +0x4a0 when it is above the maximum, else the one at +0x458 (each output gets the value as a float variant)

#ifndef CLOGICALENTITY_BASED
	char m_pad0004[0x450 - 4];
#endif
	float m_flMin;	// 0x450
	float m_flMax;	// 0x454
	bool m_bHitMin;	// 0x0458
	bool m_bHitMax;	// 0x0459
	char m_pad045a[0x45c - 0x45a];
	variant_t m_OutValue;	// 0x45c
public:
    virtual datamap_t *vfunc82();
	char m_pad0470[0x4a4 - 0x470];
};
