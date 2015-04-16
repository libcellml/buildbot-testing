#include "Manager.h"

#include <algorithm>
#include <memory>

#include "Model.h"

using namespace std;
using namespace libcellml;


const shared_ptr<Model> Manager::createModel(wstring modelName) {
  auto m = createChild();
  m->name_ = modelName;
  return m;
}
