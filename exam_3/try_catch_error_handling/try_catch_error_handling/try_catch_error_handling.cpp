#include "stdafx.h"
#include <iostream>
#include "TestClass.h"

/*
Ez a feladat azt csinalja, hogy ha egy konstruktorban kurva nagy hibat akarok csinalni
akkor ne az legyen, hogy letrehozza az objektumot, hanem csak siman kidob belole.
Azert, mert ha new-val hozom letre, akkor ott marad heapen a lefoglalt hely, amit 
torolni kene. Ez nyilvan nem akkor ertelmes, ha mainben kapom el, hanem nagyobb programnal valami masik
classban valo objektum letrehozasnal.
Remelem ertheto :)
*/

int main() {
  TestClass* test;
  try {
    test = new TestClass(0);
  }
  catch (int) {
    std::cout << "Object not created." << std::endl;
    return 0;
  }
  delete test;
  return 0;
}

