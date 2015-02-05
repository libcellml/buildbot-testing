#include <memory>
#include <iostream>
#include <strstream>
#include <string>

#include "Cellml_1_2.h"
#include "gtest/gtest.h"

using namespace std;
using namespace cellml12;

string xml1() {
  return
R"(<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<p1:model xmlns:p1="http://www.cellml.org/cellml/1.2#" name="modelName">
  <p1:component name="c1">
    <p1:variable name="v1" public_interface="yes" type="real" units="kg"/>
  </p1:component>
  <p1:component name="c2"/>
</p1:model>
)";
}

//! Test creation of a model and serialisation to XML
TEST(XmlBindingsSerialisation, SimpleExample01) {
  auto modelName = L"modelName";
  cellml12::Model m(modelName);
  cellml12::Component c1(L"c1");
  cellml12::Variable v1(L"v1", L"kg", L"real");

  v1.setPublic_interface(cellml12::Yesno::yes);
  c1.getVariable().push_back(v1);
  m.getComponent().push_back(c1);

  cellml12::Component c2(L"c2");
  m.getComponent().push_back(c2);

  ostringstream oss;

  serializeModel(oss, m);
  ASSERT_EQ(xml1(), oss.str());

}

//! Test reading in a simple model from XML text.
TEST(XmlBindingsDeserialisation, SimpleExample01) {

  istringstream iss (xml1());

  auto m2 = parseModel(iss, xml_schema::Flags::dont_validate);

  wostringstream oss;
  oss << "Read in model name: " << m2->getName() << endl;
  oss << "  Components:" << endl;
  auto cs = m2->getComponent();
  for (auto c : cs) {
    oss << "    " << c.getName() << endl;
    auto vs = c.getVariable();
    oss << "      Variables:" << endl;
    for (auto v : vs) {
      oss << "        " << v.getName() << "::" << v.getType() << "(private: " << v.getPrivate_interface() << ", public: " << v.getPublic_interface() << ")" << endl;
    }
  }

  string expectedSummary(
R"(Read in model name: modelName
  Components:
    c1
      Variables:
        v1::real(private: <not present>, public: yes)
    c2
      Variables:
)");
  //! todo: conversion from std::string to std::wstring should be a utility.
  wstringstream wss;
  wss << expectedSummary.c_str();
  wstring expectedSummaryW = wss.str();


  ASSERT_EQ(expectedSummaryW, oss.str());
}
