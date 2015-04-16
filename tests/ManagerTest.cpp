#include <memory>
#include <iostream>
#include <algorithm>
#include "Manager.h"


#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

//! Test creation of empty model using manager
TEST(Manager, CreateEmptyModel) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel(L"test model");
  ASSERT_NE(v1, nullptr);
}


//! Test that creating 2 empty models results in two different objects
TEST(Manager, Create2EmptyModels) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel(L"test model 1");
  const auto v2 = m->createModel(L"test model 2");
  ASSERT_NE(v1, nullptr);
  ASSERT_NE(v2, nullptr);
  ASSERT_NE(v1, v2);
}


//! Test that manager's list of models contains exactly only those created.
TEST(Manager, ChildModelsExactlyMatchCreated) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto ms0 = m->getChildren();

  ASSERT_EQ( 0, ms0.size());

  const auto v1 = m->createModel(L"test model 1");
  const auto v2 = m->createModel(L"test model 2");

  const auto ms2 = m->getChildren();
  ASSERT_EQ( 2, ms2.size());
  ASSERT_EQ( 1, count(ms2.begin(), ms2.end(), v1));
  ASSERT_EQ( 1, count(ms2.begin(), ms2.end(), v2));
}


//! Test that created model points back to it's creator
TEST(Manager, ModelPointsToCreator) {
  shared_ptr<Manager> m = make_shared<Manager>();
  const auto v1 = m->createModel(L"test model");
  ASSERT_EQ(v1->getParent().lock(), m);
}


//! Test that 2 different managers are distinct from the point of view of a child model of each
TEST(Manager, ManagersDistinct) {
  shared_ptr<Manager> m1 = make_shared<Manager>();
  shared_ptr<Manager> m2 = make_shared<Manager>();
  const auto v1 = m1->createModel(L"test model 1");
  const auto v2 = m2->createModel(L"test model 2");
  ASSERT_NE(v1->getParent().lock(), v2->getParent().lock());
}


