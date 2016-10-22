#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

// This line is not needed for the simple single-file
// program (similar to what Codeeval wants you to submit)
#include "test_longestLines.h"

#include <sstream>
using std::stringstream;
using std::ostringstream;

TEST_CASE( "Factorials are computed", "[factorial]" ) {

    stringstream test_input(
        "2\n"
        "Hello World\n"
        "CodeEval\n"
        "Quick Fox\n"
        "A\n"
        "San Francisco\n"
    );

    stringstream test_output(
        "San Francisco\n"
        "Hello World\n"
    );

    ostringstream out;
    longestLines(test_input, out);

    REQUIRE( test_output.str() == out.str());
}
