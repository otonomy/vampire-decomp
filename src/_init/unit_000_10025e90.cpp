// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"
#include <stddef.h>
#include "datamap.h"

// The dynamic initializers of the physics entities' data descriptions. Each BEGIN_DATADESC (and
// BEGIN_SIMPLE_DATADESC) of the game's Source datadesc macros declares the class's DataMapInit specialization and
// a namespace holder, g_DataMapHolder, that calls it at load time; DataMapInit fills the class's m_DataMap with
// its table (dataNumFields, then dataDesc) and returns &m_DataMap. The DataMapInit bodies follow each holder in
// the original file; here they are the 0x10025ed0 ... 0x100292d0 functions.
template <typename T> datamap_t *DataMapInit( T * );

class CConstantForceController;
class CPhysForce;
class CPhysThruster;
class CPhysTorque;
class CMotorController;
class CPhysMotor;
class CKeepUpright;

// FUNCTION: 0x10025e90 size=0x5
// BEGIN_SIMPLE_DATADESC( CConstantForceController )
template <> datamap_t *DataMapInit<CConstantForceController>( CConstantForceController * );
namespace CConstantForceController_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CConstantForceController *)NULL );
}
// END FUNCTION

// FUNCTION: 0x10026060 size=0x5
// BEGIN_DATADESC( CPhysForce )
template <> datamap_t *DataMapInit<CPhysForce>( CPhysForce * );
namespace CPhysForce_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CPhysForce *)NULL );
}
// END FUNCTION

// FUNCTION: 0x10027c40 size=0x5
// BEGIN_DATADESC( CPhysThruster )
template <> datamap_t *DataMapInit<CPhysThruster>( CPhysThruster * );
namespace CPhysThruster_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CPhysThruster *)NULL );
}
// END FUNCTION

// FUNCTION: 0x10028180 size=0x5
// BEGIN_DATADESC( CPhysTorque )
template <> datamap_t *DataMapInit<CPhysTorque>( CPhysTorque * );
namespace CPhysTorque_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CPhysTorque *)NULL );
}
// END FUNCTION

// FUNCTION: 0x10028380 size=0x5
// BEGIN_SIMPLE_DATADESC( CMotorController )
template <> datamap_t *DataMapInit<CMotorController>( CMotorController * );
namespace CMotorController_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CMotorController *)NULL );
}
// END FUNCTION

// FUNCTION: 0x100286e0 size=0x5
// BEGIN_DATADESC( CPhysMotor )
template <> datamap_t *DataMapInit<CPhysMotor>( CPhysMotor * );
namespace CPhysMotor_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CPhysMotor *)NULL );
}
// END FUNCTION

// FUNCTION: 0x10029290 size=0x5
// BEGIN_DATADESC( CKeepUpright )
template <> datamap_t *DataMapInit<CKeepUpright>( CKeepUpright * );
namespace CKeepUpright_DataDescInit
{
	datamap_t *g_DataMapHolder = DataMapInit( (CKeepUpright *)NULL );
}
// END FUNCTION
