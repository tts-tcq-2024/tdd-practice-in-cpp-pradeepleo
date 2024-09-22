#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

class StringCalculator {

public:
    // Main Add function that handles sum calculation, custom delimiters, and exceptions
    int add(const std::string &input) {
        if (input.empty()) return 0;

        std::string delimiters = ",\n";
        std::string numbersStr = input;

        // Handle custom delimiters
        if (input.substr(0, 2) == "//") {
            size_t delimiterEnd = input.find("\n");
            delimiters = input.substr(2, delimiterEnd - 2);
            numbersStr = input.substr(delimiterEnd + 1);
        }

        std::vector<std::string> strNumbers = split(numbersStr, delimiters);
        std::vector<int> numbers;

        // Convert string numbers to integers, and apply filter for numbers > 1000
        for (const std::string &numStr : strNumbers) {
            if (!numStr.empty()) {
                numbers.push_back(filterLargeNumbers(toInt(numStr)));
            }
        }

        // Check for negatives and throw exception if any
        checkNegatives(numbers);

        // Calculate the sum
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }

        return sum;
    }

private:
    // Helper function to split a string by a delimiter
    std::vector<std::string> split(const std::string &str, const std::string &delimiters) {
        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = str.find_first_of(delimiters, start)) != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }

    // Helper function to convert a string to an integer
    int toInt(const std::string &s) {
        return std::stoi(s);
    }

    // Helper function to ignore numbers greater than 1000
    int filterLargeNumbers(int num) {
        return num > 1000 ? 0 : num;
    }

    // Function to collect negative numbers from the list
    std::vector<int> collectNegatives(const std::vector<int> &numbers) {
        std::vector<int> negatives;
        for (int num : numbers) {
            if (num < 0) {
                negatives.push_back(num);
            }
        }
        return negatives;
    }

    // Function to create the exception message for negative numbers
    std::string createNegativesMessage(const std::vector<int> &negatives) {
        std::stringstream ss;
        ss << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) ss << ",";
            ss << negatives[i];
        }
        return ss.str();
    }

    // Function to check and throw an exception if there are negative numbers
    void checkNegatives(const std::vector<int> &numbers) {
        std::vector<int> negatives = collectNegatives(numbers);
        if (!negatives.empty()) {
            throw std::runtime_error(createNegativesMessage(negatives));
        }
    }
};  
