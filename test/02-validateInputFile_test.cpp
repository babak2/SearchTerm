/*********************************************************
 * File: 02-validateInputFile_test.cpp
 * Description: This test file contains test cases for testing validateInputFile() function.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-14
 * Modified: 2023-05-20
 *********************************************************/

#include "third_party/catch2/catch.hpp"
#include "common/matchLines.h"
#include <iostream>
#include <string>

#include <fstream>

#ifdef _WIN32
    #include <direct.h>  // Windows specific header
#else
    #include <unistd.h>  // POSIX compliant header (Linux, macOS, etc.)
#endif

/**
 * Test case: validateInputFile function with empty file
 * Description: This test case verifies the behavior of the validateInputFile function when given an empty file
 * with only one line. It checks if the function correctly handles the case when the input file is empty (no content)
 * and returns false.
 * Test category: validateInputFile
 */
TEST_CASE("2.1: Test validateInputFile function with empty file", "[validateInputFile:empty-file]")
{
    // Test case description
    std::cout << "Empty input file should return false" << std::endl;

    char currentPath[FILENAME_MAX];

    #ifdef _WIN32
    if (_getcwd(currentPath, sizeof(currentPath)) != nullptr)
    #else
    if (getcwd(currentPath, sizeof(currentPath)) != nullptr)
    #endif
    {
        // Print the current directory
        std::cout << "Current Directory: " << currentPath << std::endl;
    }
    else
    {
        std::cout << "Failed to get current directory." << std::endl;
    }

    std::string filePath;
    std::cout << "Enter the file path to an empty .txt file: ";
    std::getline(std::cin, filePath);

    // Open the input file
    std::ifstream inputFile(filePath);
    if (!inputFile)
    {
        // File opening failed, handle the error case
        std::cout << "Failed to open the file." << std::endl;
        FAIL("Test case failed because of the wrong path and/or filename.txt");

        // Exit the test case
        return;
    }
    REQUIRE(inputFile.is_open()); // Ensure the file is opened successfully

    // Output the file content to check
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }

    inputFile.clear();                // Clear any error flags
    inputFile.seekg(0, std::ios::beg); // Reset the file position to the beginning

    // Validate the input file using the function under test
    REQUIRE_FALSE(validateInputFile(inputFile));
}

/**
 * Test case: validateInputFile function with single-line file
 * Description: This test case verifies the behavior of the validateInputFile function when given a file with only one line.
 * It checks if the function correctly handles an input file with a single line and returns false.
 * Test category: validateInputFile
 */
TEST_CASE("2.2: Test validateInputFile function with single-line file", "[validateInputFile:single-line-file]" ) {
    // Test case description
    std::cout << "Input file with only one line should return false" << std::endl;

    // Variable to store the current directory path
    char currentPath[FILENAME_MAX];

    // Get the current directory path
    #ifdef _WIN32
        if (_getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #else
        if (getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #endif  
            std::cout << "Current Directory: " << currentPath << std::endl;
        } else {
            std::cout << "Failed to get current directory." << std::endl;
        }

    // Prompt the user to enter the file path
    std::string filePath;
    std::cout << "Enter the file path to a single/one line .txt file: ";
    std::getline(std::cin, filePath);

    // Open the input file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        // Handle the case when the file fails to open
        std::cout << "Failed to open the file." << std::endl;
        FAIL("Test case failed because of the wrong path and/or filename.txt");

        // Exit the test case
        return;
    }
    REQUIRE(inputFile.is_open());  // Ensure the file is opened successfully

    // Output the file content to check
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.clear();  // Clear any error flags
    inputFile.seekg(0, std::ios::beg);  // Reset the file position to the beginning

    // Validate the input file using the validateInputFile function
    REQUIRE_FALSE(validateInputFile(inputFile));
}

/**
 * Test case: validateInputFile function with valid file
 * Description: This test case verifies the behavior of the validateInputFile function when given a valid file as input.
 * It checks if the function correctly handles a valid input file and returns true.
 * Test category: validateInputFile
 */
TEST_CASE("2.3: Test validateInputFile function with valid file", "[validateInputFile:valid-file]" ) {
    // Test case description: Test the behavior of the validateInputFile function with a valid file.

    std::cout << "Valid input file should return true" << std::endl;

    char currentPath[FILENAME_MAX];

    #ifdef _WIN32
        if (_getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #else
        if (getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #endif  
        // Get the current directory path
        std::cout << "Current Directory: " << currentPath << std::endl;
    } else {
        std::cout << "Failed to get current directory." << std::endl;
    }

    std::string filePath;
    std::cout << "Enter the file path to a valid .txt file: ";
    std::getline(std::cin, filePath);

    // Open the input file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cout << "Failed to open the file." << std::endl;
        // Handle the error case accordingly
        FAIL("Test case failed because of the wrong path and/or filename.txt");

        // Exit the test case
        return;
    }
    REQUIRE(inputFile.is_open());  // Ensure the file is opened successfully

    // Output the file content to check
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.clear();  // Clear any error flags
    inputFile.seekg(0, std::ios::beg);  // Reset the file position to the beginning

    // Perform the validation and check the result
    REQUIRE(validateInputFile(inputFile));
}

/**
 * Test case: validateInputFile function with large file
 * Description: This test case verifies the behavior of the validateInputFile function when given a large file as input.
 * It checks if the function correctly handles an input file larger than 500 MB and returns false.
 * Test category: validateInputFile
 */
TEST_CASE("2.4: Test validateInputFile function with large file (> 50 MB)", "[validateInputFile:large-file]") {
    // Print a description of the test case
    std::cout << "Input file larger than 500 MB should return false" << std::endl;

    // Variable to store the current directory path
    char currentPath[FILENAME_MAX];

    // Get the current directory path based on the operating system
    #ifdef _WIN32
        if (_getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #else
        if (getcwd(currentPath, sizeof(currentPath)) != nullptr) {
    #endif  
            // Print the current directory path
            std::cout << "Current Directory: " << currentPath << std::endl;
        } else {
            std::cout << "Failed to get current directory." << std::endl;
        }

    // Prompt the user to enter the file path to a large (>50M) .txt file
    std::string filePath;
    std::cout << "Enter the file path to a large (> 50 MB) .txt file: ";
    std::getline(std::cin, filePath);

    // Open the input file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        // Failed to open the file
        std::cout << "Failed to open the file." << std::endl;
        // Handle the error case accordingly
        FAIL("Test case failed because of the wrong path and/or filename.txt");

        // Exit the test case
        return;
    }
    // Ensure the file is opened successfully
    REQUIRE(inputFile.is_open());

    // Output the file content to check
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Clear any error flags of the input file
    inputFile.clear();
    // Reset the file position to the beginning
    inputFile.seekg(0, std::ios::beg);

    // Verify that validateInputFile returns false
    REQUIRE_FALSE(validateInputFile(inputFile));
}
