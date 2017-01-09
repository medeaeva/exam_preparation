//#include "waste\stdafx.h" //windowsosoknak illetve visual studio-soknak enelkul nem fut (mivel utalom, ezert betettem a projekten belul egy waste mappaba)
#define CATCH_CONFIG_MAIN //definialom a catch_config_maint, ami az ifdef-hez kell, alul ket blokk van (maines es test-es)
#include <iostream> //ez a ket include mindket blokkban includolasra kerul, a catch.hpp-t nem erdemes tehat idetenni, mert feledlegesen leforditana a sima main-nel
#include <string> //detto, ez mindkettonel includolasra kerul

#ifndef CATCH_CONFIG_MAIN ///itt kezdodik a maines blokk, ez akkor aktiv, ha itt ifdef van es a masik blokk ifndef

using std::cout;

int main(int argc, char* argv[]) {
  cout << "hello world";
  return 0;
}
#endif ///itt er veget a maines blokk

#ifdef CATCH_CONFIG_MAIN ///itt kezdodik a test-es blokk
#include "catch.hpp" //itt behuzom a test-hez szukseges catch headert. ez az include csak itt lesz leforditva

TEST_CASE("test 1") {
  int a = 2;
  REQUIRE(a == 6);
}

#endif ///itt er veget a test-es blokk