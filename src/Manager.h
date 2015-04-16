#ifndef libCellML_Manager_h
#define libCellML_Manager_h

#include <memory>
#include <vector>

#include "Model.h"
#include "Parent.h"
#include "Child.h"

//! Everything in LibCellML is in this namespace.
namespace libcellml {


//! Manages models
class Manager
  : public Parent<Manager, Model>
{

public:
  /**
   * Create a child model object, of which this manager object is the parent
   * \param modelName The name of the new model
   * \return a pointer the newly created child object.
   */
  const std::shared_ptr<Model> createModel(std::wstring modelName);
};


} //namespace libcellml
#endif
