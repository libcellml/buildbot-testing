#include "Variable.h"
#include "Component.h"

using namespace std;
using namespace libcellml;


Variable::Variable(weak_ptr<Component> p, const this_is_private &t) : Child<Component, Variable>(p, t){}

const std::vector<std::weak_ptr<const Variable>> Variable::getConnectedVariables() const {
  std::vector<std::weak_ptr<const Variable>> vs(connectedVars_.begin(), connectedVars_.end()); // Have to copy to get const version.
  return std::move(vs);
}

void Variable::connect(std::weak_ptr<Variable> v){
  this->connectedVars_.push_back(v);

  if (this == v.lock().get() ) {
    return;
  }

  v.lock()->connectWithoutReciprocating(shared_from_this());
}

void Variable::connectWithoutReciprocating(std::weak_ptr<Variable> v){
  this->connectedVars_.push_back(v);
}
