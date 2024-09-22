#include "StringCalculator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

// Helper function to split a string by a delimiter
vector<string> split(const string &str, const string &delimiters) {
    // ... (unchanged)
}

// Helper function to convert a string to an integer
int toInt(const string &s) {
    // ... (unchanged)
}

// Helper function to ignore numbers greater than 1000
int filterLargeNumbers(int num) {
    // ... (unchanged)
}

// Function to collect negative numbers from the list
vector<int> collectNegatives(const vector<int> &numbers) {
    // ... (unchanged)
}

// Function to create the exception message for negative numbers
string createNegativesMessage(const vector<int> &negatives) {
    // ... (unchanged)
}

// Function to check and throw an exception if there are negative numbers
void checkNegatives(const vector<int> &numbers) {
    // ... (unchanged)
}

// New helper functions to reduce CCN of CalculateAdd

pair<string, string> extractCustomDelimiter(const string &input) {
    if (input.substr(0, 2) == "//") {
        size_t delimiterEnd = input.find("\n");
        return {input.substr(2, delimiterEnd - 2), input.substr(delimiterEnd + 1)};
    }
    return {",\n", input};
}

vector<int> parseNumbers(const string &numbersStr, const string &delimiters) {
    vector<string> strNumbers = split(numbersStr, delimiters);
    vector<int> numbers;
    for (const string &numStr : strNumbers) {
        if (!numStr.empty()) {
            numbers.push_back(filterLargeNumbers(toInt(numStr)));
        }
    }
    return numbers;
}

int sumNumbers(const vector<int> &numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

// Main CalculateAdd function with reduced CCN
int StringCalculator::CalculateAdd(const string &input) {
    if (input.empty()) return 0;
    
    auto [delimiters, numbersStr] = extractCustomDelimiter(input);
    vector<int> numbers = parseNumbers(numbersStr, delimiters);
    checkNegatives(numbers);
    return sumNumbers(numbers);
}
