//Doc on testing: https://github.com/philsquared/Catch/blob/master/docs/assertions.md

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp" //Include the catch header file, available here: https://raw.githubusercontent.com/philsquared/Catch/master/single_include/catch.hpp
#include "WordToolbox.hpp" //include your program's header file that you are testing

TEST_CASE("Check for charater included in the string") {
  WordToolbox word("Tarzan's toenails. Me Tarzan, you Jane");
  REQUIRE(word.countHowMany('a') == 6); //Expects to print 6
}

TEST_CASE("Check for charater not included in the string and throw exception") {
  WordToolbox word("Tarzan's toenails");
  CHECK_THROWS(word.countHowMany('y')); //Expects an expression to be thrown
}

TEST_CASE("Not anagram throws error") {
  WordToolbox word("alma");
  REQUIRE_FALSE(word.isAnAnagram("help")); //Expects the function to return false
}

