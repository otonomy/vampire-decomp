// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010f480 size=0xa2
#include "engineclient.h"
#include "CWaterEnum.h"
#include "IClientEntity.h"



int CWaterEnum::vfunc0(IClientEntity *pEntity)
{
	int *pEntIndex = m_pEntIndex;
	if (pEntity && (pEntity->Collideable_vfunc7() & 0x20))
	{
		m_nContents = engine->vfunc66(
			m_vecPoint,
			engine->vfunc18(pEntity->GetCollisionModelIndex()),
			pEntity->GetAbsOrigin(),
			pEntity->GetAbsAngles());
		if (m_nContents)
		{
			if (pEntIndex)
				*pEntIndex = pEntity->entindex();
			return 1;
		}
	}
	return 0;
}
// END FUNCTION
