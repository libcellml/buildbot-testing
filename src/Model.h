#ifndef Libcellml_Model_h
#define Libcellml_Model_h

#include <memory>
#include <string>
#include <vector>

#include "Component.h"
#include "UnitsOwner.h"

#include "Child.h"
#include "Parent.h"

namespace libcellml {

class Manager;
class Component;

//! In-memory representation of a CellML model
class Model :
  public Child<Manager, Model>,
  public Parent<Model, Component>
{
  friend class Manager;

  //! Model name
  std::wstring name_;

  //! Units Owner delegate
  std::shared_ptr<UnitsOwner> unitsOwner_;

public:
  Model(std::weak_ptr<Manager> p, const this_is_private &t);

  /** Model name attribute
   * \return model name
   */
  std::wstring getName() const {
    return name_;
  }

  /**
   * Create a child component object, of which this model object is the parent
   * \param componentName The name of the new component
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Component> createComponent(std::wstring componentName);

  /**
   * Create a child unit object, of which this model object is the parent
   * \param unitName The name of the new unit
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Unit> createUnit(std::wstring unitName);

};

} // namespace libcellml

#endif
