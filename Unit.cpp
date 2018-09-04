#include <stdexcept>
#include "Unit.h"

Unit::Unit()
{
    _UnitId = _NextUnitId++;
}

int Unit::_NextUnitId = 1;

//-----------------------------------------------------------------

