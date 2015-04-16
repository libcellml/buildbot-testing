#include <XmlSerialisation.h>
#include <memory>
#include <iostream>
#include <strstream>
#include <string>

#include "Cellml_1_2.h"

using namespace std;
using namespace cellml12;

namespace libcellml {

string createXml(const libcellml::Manager& m) {
  ostringstream oss;

  auto models = m.getChildrenReadOnly();
  for( auto model : models) {
    auto modelName = model->getName();

    cellml12::Model modelXml(modelName);

    auto components = model->getChildrenReadOnly();
    for( auto component : components) {
      auto compName = component->getName();
      cellml12::Component componentXml(compName);

      auto vars = component->getChildrenReadOnly();
      for( auto var : vars ) {
        auto varName = var->getName();
        auto varUnit = var->getUnit();
        auto unitName = varUnit ? varUnit.value().lock()->getName() : L"";
        cellml12::Variable varXml(varName, unitName, L"real");

        componentXml.getVariable().push_back(varXml);
      }
      modelXml.getComponent().push_back(componentXml);

    }
    serializeModel(oss, modelXml);
  }

  return oss.str();

}

} // namespace libcellml
