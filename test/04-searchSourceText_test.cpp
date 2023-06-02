/*********************************************************
 * File: 04-searchSourceText_test.cpp
 * Description: This test file contains test cases for testing searchSourceText() function.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-14
 * Modified: 2023-05-20
 *********************************************************/

#include "third_party/catch2/catch.hpp"
#include "common/matchLines.h"

/** 
* Test searchSourceText function
* This test case verifies the behavior of the searchSourceText function.
*/
TEST_CASE("4.1: Test searchSourceText function", "[searchSourceText]") {

    // Define the source text lines to search
    std::vector<std::vector<std::string>> sourceTextLines = {
        {"apple", "banana", "orange"},
        {"car", "bus", "train"},
        {"apple", "grape", "kiwi"},
        {"banana", "carrot", "mango"}
    };

    SECTION("Search term is present in some lines") {

        // Print test information
        std::cout << "Test 1: search an existing term among 4 lines terms" << std::endl;

        // Define the search term
        std::string searchTerm = "apple";

        // Define the expected matching lines
        std::vector<std::vector<std::string>> expectedMatchingLines = {
            {"apple", "banana", "orange"},
            {"apple", "grape", "kiwi"}
        };

        // Call the searchSourceText function with the source text lines and search term
        std::vector<std::vector<std::string>> matchingLines = searchSourceText(sourceTextLines, searchTerm);

        // Verify if the matching lines match the expected matching lines
        REQUIRE(matchingLines == expectedMatchingLines);
    }

    SECTION("Search term is not present in any line") {

        // Print test information
        std::cout << "Test 2: search a non-existing term among 4 lines terms" << std::endl;

        // Define the search term
        std::string searchTerm = "pear";

        // Define the expected matching lines
        std::vector<std::vector<std::string>> expectedMatchingLines = {};

        // Call the searchSourceText function with the source text lines and search term
        std::vector<std::vector<std::string>> matchingLines = searchSourceText(sourceTextLines, searchTerm);

        // Verify if the matching lines match the expected matching lines
        REQUIRE(matchingLines == expectedMatchingLines);
    }
}
