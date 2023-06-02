#ifndef MATCHLINES_H
#define MATCHLINES_H

/*********************************************************
 * File: matchLines.h
 * Description: This file contains the headers of the solution program functions.
 * Author: Babak Mahdavi Ardestani
 * Email: babak.m.ardestani@gmail.com
 * Created:  2023-05-12
 * Modified: 2023-05-20
 *********************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

// Function to parse a line of text and extracts the words.
std::vector<std::string> parseLine(const std::string& str);

// Function to check if a line of text contains the search term
bool lineContains(std::vector<std::string> words, std::string searchTerm);

// Function to validate the input file
bool validateInputFile(std::ifstream& inputFile);

// Function to display the matching lines
void displayMatchingLines(std::vector<std::vector<std::string>> matchingLines);

// Function to read the source text lines from the input file
std::vector<std::vector<std::string>> readSourceTextLines(std::ifstream& inputFile);

// Function to get the search term from the source text lines
std::string getSearchTerm(std::vector<std::vector<std::string>>& sourceTextLines);

// Function to search the source text for lines containing the search term
std::vector<std::vector<std::string>> searchSourceText(const std::vector<std::vector<std::string>>& sourceTextLines, const std::string& searchTerm);

#endif
