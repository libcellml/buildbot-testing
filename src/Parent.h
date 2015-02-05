#ifndef Parent_h
#define Parent_h

#include "Child.h"

#include <string>
#include <vector>


//! The class for a parent object
template<typename parent, typename child>
class Parent :
  public std::enable_shared_from_this<parent> // Needed so that a reference to the parent object creating the child object can be stored by the child object.
{
    //! Children
    std::vector<std::shared_ptr<child> > children;
    
public:
    //! For collection of const children (i.e. each element immutable).
    //! Overall collection is also not mutable
    typedef std::vector<std::shared_ptr<const child> > const childCollectionConstT;

    //! Overall collection is not mutable, but each element is mutable
    typedef std::vector<std::shared_ptr<child> > const& childCollectionT;

    /** Get read-only collection of children
     *
     * Each child element is immutable.
     * \return The collection of children, read-only.
     */
    childCollectionConstT getChildrenReadOnly() const {
      childCollectionConstT childrenConst(children.begin(), children.end()); // Have to copy to get const version.
      return std::move(childrenConst);
    }

    /** Get collection of mutable children
     *
     * Each child element is mutable.
     * Overall membership of collection is still fixed.
     * \return The collection of mutable children.
     */
    childCollectionT getChildren() {
      return children;
    }
  
    /**
     * Create a child object, of which this object is the parent
     * \return a pointer the newly created child object.
     */
    std::shared_ptr<child> createChild() {
      std::shared_ptr<child> childp(Child<parent, child>::create(Parent<parent, child>::shared_from_this()));
      children.push_back(childp);
      return children.back();
    }

};


#endif
