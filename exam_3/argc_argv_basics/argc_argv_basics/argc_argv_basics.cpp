#include "stdafx.h" //visual studio bizbasz
#include <iostream>

int main(int argc, char* argv[]) { //vagy (int argc, char* argv[])
  //ha argumentum nelkul futtatjuk, ezt fogja kiirni:
  if (argc == 1) {
    std::cout << "irja valamit moge" << std::endl;
  }
  //ha mogeirjuk a "-a" argumentumot, akkor a "valami" szoveget irja ki
  else if (argc == 2 && (std::string)argv[1] == "a") {
    std::cout << "valami" << std::endl;
  }
  /*
  illetve, ha char* argv[] formaban adjuk meg, akkor nem kell stringge alakitani
  viszont ilyen formaban kell kiirni:

  else if (argc == 2 && argv[1][0] == 'a') {
    std::cout << "valami" << std::endl;
  }
  */

  //ha azt irom be a commandlineba hogy: ./a.exe a majom, akkor kiirja, hogy majom :)
  else if (argc == 3 && (std::string)argv[1] == "a") {
    std::cout << argv[2] << std::endl;
  }
  return 0;
}

