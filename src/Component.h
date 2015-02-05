#ifndef Libcellml_Component_h
#define Libcellml_Component_h

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include "Model.h"
#include "Variable.h"
#include "UnitsOwner.h"

#include "Child.h"
#include "Parent.h"


namespace libcellml {

class Model;
class Variable;

//! In-memory representation of a CellML component
class Component :
  public Child<Model, Component>,
  public Parent<Component, Variable>
{
  friend class Model;

  //! Component name
  std::wstring name_;

  //! Units Owner delegate
  std::shared_ptr<UnitsOwner> unitsOwner_;

public:
  Component(std::weak_ptr<Model>, const this_is_private &);

  /** Component name attribute
   * \return component name
   */
  std::wstring getName() const {
    return name_;
  }

  /**
   * Create a child variable object, of which this component object is the parent
   * \param variableName The name of the new variable
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Variable> createVariable(std::wstring variableName, boost::optional<std::weak_ptr<Unit>>);

  /**
   * Create a child unit object, of which this component object is the parent
   * \param unitName The name of the new unit
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Unit> createUnit(std::wstring unitName);

};


} // namespace libcellml

#endif
