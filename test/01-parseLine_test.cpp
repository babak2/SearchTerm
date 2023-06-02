/*********************************************************
 * File: 01-parseLine_test.cpp
 * Description: This test file contains test cases for testing parseLine() function.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-14
 * Modified: 2023-05-20
 *********************************************************/

#include "third_party/catch2/catch.hpp"
#include "common/matchLines.h"

/**
    Test case: parseLine function with predefined string input

    Description: This test case verifies the behavior of the parseLine function when provided with a specific string input.

    It checks if the function correctly parses the input string and returns the expected result.

    Test category: parseLine
*/
TEST_CASE("1.1: Test parseLine function with string input1", "[parseLine:test1]")
{
    // Define the expected result
    std::vector<std::string> expected {"to", "get", "very"};

    // Print the input string to be passed to parseLine
    std::cout << "Input: 'to_get9_!very'" << std::endl;

    // Call the parseLine function with the input string
    std::vector<std::string> parsed_line = parseLine("to_get9_!very"); 

    // Print the returned result from parseLine
    std::cout << "Returned result from parseLine(): ";

    // Print each element of the parsed_line vector
    for (const std::string& str : parsed_line) {
        std::cout << str << " "; 
    }

    std::cout <<  std::endl;

    // Verify that the returned result matches the expected result
    REQUIRE(parseLine("to_get9_!very") == expected);
}
/**
    Test case: parseLine function with predefined string input

    Description: This test case verifies the behavior of the parseLine function when provided with a specific string input.

    It checks if the function correctly parses the input string and returns the expected result.

    Test category: parseLine
*/
TEST_CASE("1.2: Test parseLine function with string input2", "[parseLine:test2]" ) {
    // Define the expected output
    std::vector<std::string> expected {"tired", "of", "sitting"};

    // Print the input sent to parseLine for clarity
    std::cout << "Input: '1111tired1111of1111sitting1111'" << std::endl;

    // Call the function under test
    std::vector<std::string> parsed_line = parseLine("1111tired1111of1111sitting1111"); 

    // Print the returned result for verification
    std::cout << "Returned result from parseLine(): ";
    for (const std::string& str : parsed_line) {
        std::cout << str << " "; 
    }
    std::cout << std::endl;

    // Verify that the actual output matches the expected output
    REQUIRE(parseLine("1111tired1111of1111sitting1111") == expected);
}

