#define CATCH_CONFIG_MAIN
#include <string>
#include <vector>
#include "catch.hpp"
#include "../src/grammar.h"

using std::string;
using std::vector;

TEST_CASE( "splitting strings" ) {
    SECTION( "one word length" ) {
        string line = "baba";
        REQUIRE(splitline(line).size() == 1);
        REQUIRE(splitline(line)[0] == "baba");
    }
    SECTION( "two word length" ) {
        string line = "baba alibaba";
        REQUIRE(splitline(line).size() == 2);
        REQUIRE(splitline(line)[0] == "baba");
        REQUIRE(splitline(line)[1] == "alibaba");
    }
    SECTION( "two word multispace" ) {
        string line = "baba        alibaba";
        REQUIRE(splitline(line).size() == 2);
        REQUIRE(splitline(line)[0] == "baba");
        REQUIRE(splitline(line)[1] == "alibaba");
    }
}

TEST_CASE( "bracketing" ) {
    REQUIRE(bracketed("<>"));
    REQUIRE(bracketed("<fdfd>"));
    REQUIRE(!bracketed("<fdfdfd"));
    REQUIRE(!bracketed("!!>"));
    REQUIRE(!bracketed("gfg"));
    REQUIRE(!bracketed(""));
}
