#include "UnitsOwner.h"
#include "Unit.h"

using namespace std;
using namespace libcellml;

const shared_ptr<Unit> UnitsOwner::createUnit(wstring unitName) {
  auto u = createChild();
  u->name_ = unitName;
  return u;
}
