/*********************************************************
 * File: 03-getSearchTerm_test.cpp
 * Description: This test file contains test cases for testing getSearchTerm() function.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-14
 * Modified: 2023-05-20
 *********************************************************/

#include "third_party/catch2/catch.hpp"
#include "common/matchLines.h"

/**
 * Function: getSearchTerm
 * Description: Retrieves the last line from the sourceTextLines vector as the search term.
 * Parameters:
 *   - sourceTextLines: A vector of vectors containing lines of text.
 * Return: A string representing the search term.
 */
TEST_CASE("3.1: Test getSearchTerm function", "[getSearchTerm]" ) {

    SECTION("Empty sourceTextLines") {
        // Test case description
        std::cout << "Test 1: Using an empty sourceTextLines vector. The result should be an empty search term." << std::endl;

        // Prepare the input
        std::vector<std::vector<std::string>> sourceTextLines;

        // Call the function to get the result
        std::string result = getSearchTerm(sourceTextLines);

        // Verify the result
        REQUIRE(result.empty());
    }

    SECTION("One line sourceTextLines") {
        // Test case description
        std::cout << "Test 2: Using a sourceTextLines vector with a single line. The result should be an empty search term." << std::endl;

        // Prepare the input
        std::vector<std::vector<std::string>> sourceTextLines = {
            {"line 1"}
        };

        // Call the function to get the result
        std::string result = getSearchTerm(sourceTextLines);

        // Verify the result
        REQUIRE(sourceTextLines.size() == 0);
    }

    SECTION("Non-empty sourceTextLines") {
        // Test case description
        std::cout << "Test 3: Using a sourceTextLines vector with multiple lines. The result should be the last line as the search term." << std::endl;

        // Prepare the input
        std::vector<std::vector<std::string>> sourceTextLines = {
            {"search term"},
            {"line 2", "line 3"},
            {"line 4"}
        };

        // Call the function to get the result
        std::string result = getSearchTerm(sourceTextLines);

        // Verify the result
        REQUIRE(result == "line 4");
        REQUIRE(sourceTextLines.size() == 2);
    }
}
