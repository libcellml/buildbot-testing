#include "Component.h"
#include "Model.h"

using namespace std;
using namespace libcellml;


Component::Component(weak_ptr<Model> p, const this_is_private &t)
:
  Child<Model, Component>(p, t),
  unitsOwner_(new UnitsOwner)
{}


const shared_ptr<Variable> Component::createVariable(wstring variableName, boost::optional<weak_ptr<Unit>> unit) {
  auto v = createChild();
  v->name_ = variableName;
  v->unit_ = unit;
  return v;
}

const shared_ptr<Unit> Component::createUnit(wstring unitName) {
  auto u = unitsOwner_->createUnit(unitName);
  return u;
}
