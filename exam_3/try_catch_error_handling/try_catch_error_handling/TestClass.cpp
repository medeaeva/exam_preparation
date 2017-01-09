#include "stdafx.h"
#include "TestClass.h"
#include <iostream>


TestClass::TestClass(int x) throw(int) {
  if (x == 0) {
    throw 1;
  }
  number = 10 / x;
  std::cout << number << std::endl;
}

TestClass::~TestClass() {
}
