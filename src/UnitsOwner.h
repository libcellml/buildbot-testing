#ifndef Libcellml_UnitsOwner_h
#define Libcellml_UnitsOwner_h

#include <memory>
#include <string>

#include "Unit.h"
#include "Parent.h"

namespace libcellml {

class Unit;
class Model;
class Component;

//! Implements ownership of units, behaviour shared by Component and Model.
class UnitsOwner :
  public Parent<UnitsOwner, Unit>
{
  friend class Model;
  friend class Component;

  UnitsOwner(){}

public:

  /**
   * Create a child unit object, of which this UnitsOwner object is the parent/owner
   * \param unitName The name of the new unit
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Unit> createUnit(std::wstring unitName);

};

} // namespace libcellml

#endif
