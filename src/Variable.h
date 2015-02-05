#ifndef Libcellml_Variable_h
#define Libcellml_Variable_h

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>


#include "Component.h"
#include "Unit.h"

#include "Child.h"

namespace libcellml {

class Component;

//! In-memory representation of a CellML Variable
class Variable :
  public Child<Component, Variable>,
  public std::enable_shared_from_this<Variable> // Needed so that a reference to the parent object creating the child object can be stored by the child object.
{
  friend class Component;

  //! Variable name
  std::wstring name_;

  //! Unit of measure
  boost::optional<std::weak_ptr<Unit>> unit_;

  //! Connected variables
  std::vector<std::weak_ptr<Variable>> connectedVars_;

  //! Utility during creation of a connection
  void connectWithoutReciprocating(std::weak_ptr<Variable>);

public:
  Variable(std::weak_ptr<Component>, const this_is_private &);

  /** Variable's name attribute
   * \return Variable's name
   */
  std::wstring getName() const {
    return name_;
  }

  /** Variable's unit
   * \return Variable's unit
   */
  boost::optional<std::weak_ptr<const Unit>> const getUnit() const {
    if (!unit_) {
      return boost::none;
    }

    std::weak_ptr<const Unit> u = unit_.value(); // Convert to wrapped const.
    return u;
  }

  /** Returns the collection of variables connected to this variable.
   * \return Variables connected to this variable
   */
  const std::vector<std::weak_ptr<const Variable>> getConnectedVariables() const;

  /** Connect a variable to this variable
   */
  void connect(std::weak_ptr<Variable>);
};

} // namespace libcellml

#endif
