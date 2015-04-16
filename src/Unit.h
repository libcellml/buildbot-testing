#ifndef Libcellml_Unit_h
#define Libcellml_Unit_h

#include <memory>
#include <string>

#include "UnitsOwner.h"
#include "Child.h"

namespace libcellml {

class UnitsOwner;

//! In-memory representation of a CellML Unit (i.e. physical unit of measure)
class Unit : public Child<UnitsOwner, Unit>{
  friend class UnitsOwner;

  //! Unit name
  std::wstring name_;

public:
  Unit(std::weak_ptr<UnitsOwner>, const this_is_private &);

  /** Unit's name attribute
   * \return Unit's name
   */
  std::wstring getName() const {
    return name_;
  }

};

} // namespace libcellml

#endif
