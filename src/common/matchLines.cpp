/*********************************************************
 * File: matchLines.cpp
 * Description: This file contains the implementation of the solution program functions.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-12
 * Modified: 2023-05-20
 *********************************************************/

#include "common/matchLines.h"

using namespace std;

/**
 * Parses a line of text and extracts the words.
 * Words are considered to be alphabetical sequences of characters.
 * The function converts all words to lowercase before storing them in a vector.
 *
 * @param str The input string to parse.
 * @return A vector of extracted words.
 */
vector<string> parseLine(const std::string& str) {
    std::vector<std::string> words;
    std::regex word_regex("[a-zA-Z]+");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::string word = i->str();
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    return words;
}

/**
 * Function: lineContains
 * Description: Checks if a line of text contains the search term.
 * Parameters:
 *     - words: A vector of strings representing the words in a line of text.
 *     - searchTerm: A string representing the term to search for in the line.
 * Returns:
 *     - A boolean value indicating whether the line contains the search term.
 */
bool lineContains(vector<string> words, string searchTerm) {
    // Iterate over each word in the line
    for (auto word : words) {
        // Check if the word contains the search term
        if (word.find(searchTerm) != string::npos) {
            // If the search term is found, return true
            return true;
        }
    }
    // If the search term is not found in any word, return false
    return false;
}

/**
 * Function: validateInputFile
 * Description: Validates the input file based on specific criteria.
 *              Checks if the file is empty, has only one line, and if the file size is larger than 500 MB.
 * Parameters:
 *    - inputFile: A reference to an ifstream object representing the input file.
 * Returns:
 *    - bool: Returns true if the input file is valid, false otherwise.
 */
bool validateInputFile(ifstream& inputFile) {

    // Check if the file is empty
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cout << "Error: input file is empty." << endl;
        return false;
    }

    // Check if the file has only one line
    string line;
    getline(inputFile, line);
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cout << "Error: input file has only one line." << endl;
        return false;
    }

    // Check if the file size is larger than 500 MB
    inputFile.seekg(0, ios::end);
    int fileSize = inputFile.tellg();
    if (fileSize > 500000000) {
        cout << "Error: input file size is larger than 500 MB." << endl;
        return false;
    }

    // Reset the file position to the beginning
    inputFile.seekg(0, ios::beg);

    return true;
}

/**
 * Function: readSourceTextLines
 * Description: Reads the contents of an input file and returns a vector of vectors
 *              containing the parsed lines of text.
 * Parameters:
 *   - inputFile: An input file stream (ifstream) object passed by reference.
 * Return:
 *   - A vector of vectors (vector<vector<string>>) containing the parsed lines of text.
 */
vector<vector<string>> readSourceTextLines(ifstream& inputFile) {
    vector<vector<string>> sourceTextLines;  // Vector to store the parsed lines of text
    string line;  // Variable to hold each line read from the input file

    // Read each line from the input file and process it
    while (getline(inputFile, line)) {
        // Check if the line is not empty and the end of the file has not been reached
        if (!line.empty() && !inputFile.eof()) {
            vector<string> words = parseLine(line);  // Parse the line into individual words
            sourceTextLines.push_back(words);  // Add the parsed words to the sourceTextLines vector
        }
    }

    return sourceTextLines;  // Return the vector of parsed lines of text
}

/**
 * Function: getSearchTerm
 * Description: Retrieves the search term from the last line of the source text lines and removes that line.
 * Parameters:
 *     - sourceTextLines: A reference to a vector of vector of strings representing the lines of source text.
 * Returns:
 *     - A string representing the retrieved search term.
 */
string getSearchTerm(vector<vector<string>>& sourceTextLines) {
    // Declare a variable to store the search term
    string searchTerm;

    // Check if the source text lines are not empty
    if (!sourceTextLines.empty()) {
        // Retrieve the search term from the last line of the source text lines
        searchTerm = sourceTextLines.back().front();

        // Remove the last line from the source text lines
        sourceTextLines.pop_back();
    }

    // Return the retrieved search term
    return searchTerm;
}

/**
 * Function: searchSourceText
 * Description: Searches for lines containing a specific search term in a given set of source text lines.
 * Parameters:
 *    - sourceTextLines: A vector of vectors of strings representing the lines of source text.
 *    - searchTerm: A string representing the term to search for in the source text lines.
 * Returns:
 *    - A vector of vectors of strings containing the lines that match the search term.
 */
vector<vector<string>> searchSourceText(const vector<vector<string>>& sourceTextLines, const string& searchTerm) {
    // Initialize a vector to store the matching lines
    vector<vector<string>> matchingLines;

    // Iterate through each line in the source text lines
    for (auto line : sourceTextLines) {
        // Check if the line contains the search term using the lineContains function
        if (lineContains(line, searchTerm)) {
            // If the line contains the search term, add it to the matchingLines vector
            matchingLines.push_back(line);
        }
    }

    // Return the vector of matching lines
    return matchingLines;
}

/**
 * Function: displayMatchingLines
 * Description: Display the lines containing matches in a formatted manner (starts and ends with [ ]).
 * Parameters:
 *     - matchingLines: A vector of vectors of strings representing the matching lines.
 * Return Type: void
 */
void displayMatchingLines(vector<vector<string>> matchingLines) {
    // Check if there are any matching lines
    if (matchingLines.empty()) {
        cout << "There is no matching." << endl;
    } else {
        // Iterate over each matching line
        for (auto line : matchingLines) {
            cout << "[";

            int i = 0;
            // Iterate over each word in the line
            for (auto word : line) {
                cout << word;

                // Add space between words, except for the last word
                //if (i != line.size() - 1) {
                if (i != static_cast<int>(line.size() - 1)) {
                    cout << " ";
                }
                i++;
            }

            cout << "]" << endl; // Print closing bracket and move to the next line
        }
    }
}




