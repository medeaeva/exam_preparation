#pragma once
class TestClass {
private:
  int number;
public:
  TestClass(int) throw(int);
  ~TestClass();
};

