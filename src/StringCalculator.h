#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>

using namespace std;

class StringCalculator {
public:
    int add(const string& numbers);

private:
    vector<int> parseNumbers(const string &numbers);
    string extractDelimiter(string &numbers);
    vector<int> splitNumbers(const string &numbers, const string &delimiter);
};

#endif
