#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "../src/median.h"

using std::vector;

TEST_CASE( "median computations" ) {
    vector<double> testv;

    SECTION( "[1]" ){
        testv.push_back(1);
        REQUIRE( median(testv) == 1 );
    }

    SECTION( "[10 0]" ){
        testv.push_back(10);
        testv.push_back(0);
        REQUIRE( median(testv) == 5 );
    }

    SECTION( "[-20 -20 10000]" ){
        testv.push_back(-20);
        testv.push_back(-20);
        testv.push_back(100000);
        REQUIRE( median(testv) == -20 );
    }

    SECTION( "exception" ){
        REQUIRE_THROWS( median(testv) );
    }
}
