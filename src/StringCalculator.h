#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>

using namespace std;

class StringCalculator {
public:
    int add(const string& numbers);
    int getCalledCount();

private:
    int addCalledCount = 0;

    pair<vector<int>, bool> parseNumbers(const string &numbers);
    vector<string> extractDelimiter(string &numbers);
    vector<int> splitNumbers(const string &numbers, const vector<string> &delimiter);
};

#endif
