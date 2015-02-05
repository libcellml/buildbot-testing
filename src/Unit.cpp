#include "Unit.h"
#include "UnitsOwner.h"

using namespace std;
using namespace libcellml;

Unit::Unit(weak_ptr<UnitsOwner> p, const this_is_private &t) : Child<UnitsOwner, Unit>(p, t){}
