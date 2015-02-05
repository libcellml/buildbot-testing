#include <memory>
#include <iostream>

#include <Manager.h>
#include <Model.h>
#include <Component.h>

#include "gtest/gtest.h"

using namespace libcellml;
using namespace std;

//! Test component has name specified during creation
TEST(Component, ComponentNaming) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  auto c1 = m1->createComponent(L"test component");
  ASSERT_EQ(c1->getName(), L"test component");
}

//! Test creating unit within component
TEST(Component, UnitCreation) {
  shared_ptr<Manager> m = make_shared<Manager>();
  auto m1 = m->createModel(L"test model");
  auto c1 = m1->createComponent(L"test component");
  auto u1 = c1->createUnit(L"test unit");
  ASSERT_EQ(u1->getName(), L"test unit");
}


