#include "StringCalculator.h"
#include <string>
#include <stdexcept>

using namespace std;

//  [ add ] : uses various methods and returns the sum of all positive numbers.
int StringCalculator::add(const string &numbers) {
    addCalledCount++;
    
    if(numbers == "") {
        return 0;
    }

    

    pair<vector<int>, bool> numElementPair = parseNumbers(numbers);

    vector<int> numElement = numElementPair.first;
    bool isAdd = numElementPair.second;


    
    if(isAdd) {
        int sum = 0;
        for (auto num : numElement) {
            sum += num;
        }

        return sum;
    }
    else {
        int result = 1;
        for(auto num : numElement) {
            result *= num;
        }
        return result;
    }
}

// [ getCalledCount ] : return the value of count that add() method called.

int StringCalculator::getCalledCount() {
    return addCalledCount;
}

// [ parseNumber ] : parse the given string and return the vector of all positive numbers.

pair<vector<int>, bool> StringCalculator::parseNumbers(const string &numbers) {

    string processedNumbers = numbers;
    vector<string> delimiter = extractDelimiter(processedNumbers);

    vector<int> number_splitted = splitNumbers(processedNumbers, delimiter);

    for(auto i : delimiter) {
        if(i == "*") {
            return make_pair(number_splitted, false);
        }
    }

    return make_pair(number_splitted, true);
}

/* 
    [ extractDelimiter ] : extract delimiter from given string and return the value of all delimiters in vector of string, 
                           if custom delimiter is not given then by default it returns {",", "\n"}
*/
vector<string> StringCalculator::extractDelimiter(string &numbers) {

    vector<string> delimiters;

    if (numbers.substr(0, 2) == "//") {
        int pos = numbers.find('\n');

        if (pos < 3) {
            throw invalid_argument("Invalid format for delimiter");
        }

        string section = numbers.substr(2, pos - 2);
        numbers = numbers.substr(pos + 1);

        if (section[0] == '[' && section.back() == ']') {
            
            int start = 0, end = -1;
            
            start = section.find('[', start);

            while (start != string::npos) {
                end = section.find(']', start);
                
                if (end == string::npos) {
                    throw runtime_error("invalid delimiter : missing closing bracket");
                }
                delimiters.push_back(section.substr(start + 1, end - start - 1));

                start = section.find('[', end + 1);
            }
        } else {
            delimiters.push_back(section);
        }
    }
    else {
        delimiters.push_back(",");
    }
    
    delimiters.push_back("\n");

    return delimiters;
}

/* 
    [ splitNumbers ] : returns vector of all positive numbers which is less than or equal to 1000
                       seperate all numbers with given delimiters from the given string
*/

vector<int> StringCalculator::splitNumbers(const string &numbers, const vector<string> &delimiters) {
    vector<int> result;
    vector<int> negativeNumbers;

    int pos = 0;

    while (pos < numbers.length()) {

        int position = -1;
        int length = 0;
        
        // Find the first match delimiter in the remaining string
        for (auto delimiter : delimiters) {
            
            auto currentPos = numbers.find(delimiter, pos);

            if (currentPos < position) {
                position = currentPos;
                length = delimiter.length();
            }
        }

        // if delimiter not found, set position to the end of the string
        if (position == -1) {
            position = numbers.length();
        }

        string numberString = numbers.substr(pos, position - pos);

        if (numberString != "") {
            int num = stoi(numberString);

            if (num < 0) {
                negativeNumbers.push_back(num);
            }
            else if (num <= 1000) {
                result.push_back(num);
            }
        }

        pos = position + length;
    }

    // if there is any negative numbers present, throw an exception with message of all negative numbers mentioned
    if (!negativeNumbers.empty()) {
        string errorMessage = "Negative numbers not allowed : ";

        for (int i = 0; i < negativeNumbers.size() ; i++) {
            errorMessage += to_string(negativeNumbers[i]);

            if (i < negativeNumbers.size() - 1) {
                errorMessage += ", ";
            }
        }

        throw runtime_error(errorMessage);
    }

    return result;
}