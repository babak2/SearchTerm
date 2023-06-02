/*********************************************************
 * File: solution.cpp
 * Description: This file contains the main function for the solution program. It ...
 *    - reads the source text lines from the input file
 *    - gets the search term from the user
 *    - searches for matching lines in the source text
 *    - prints the matching lines
 * 
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-12
 * Modified: 2023-05-20
 *********************************************************/

#include "common/matchLines.h"

using namespace std;

int main(int argc, char* argv[]) {


    // Check that the correct number of arguments were provided
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <path_to_txt_file>" << endl;
        return 1;
    }

    // Open and validate the input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cout << "Error opening input file" << endl;
        cout << "Path to file, filename or file format (must be .txt) may be wrong" << endl;

        return 1;
    }
    if (!validateInputFile(inputFile)) {
        return 1;
    }

    // Read the source text lines from the input file
    std::vector<std::vector<std::string>> sourceTextLines = readSourceTextLines(inputFile);

    // Get the search term from the user
    std::string searchTerm = getSearchTerm(sourceTextLines);

    // Search for matching lines in the source text
    std::vector<std::vector<std::string>> matchingLines = searchSourceText(sourceTextLines, searchTerm);

    // DiaplY the matching lines
    displayMatchingLines(matchingLines);

    return 0;
}

