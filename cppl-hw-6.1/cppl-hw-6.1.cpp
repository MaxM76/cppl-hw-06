#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

struct CharFreqLess : public std::binary_function<const std::pair<char, int>, const std::pair<char, int>, bool> {
    bool operator()(const std::pair<char, int> ch1, const std::pair<char, int> ch2) const {
        return ch1.second > ch2.second;
    }
};

int main()
{
    std::string inputStr = "Hello world!!";
    std::cout << "[IN]: ";
    std::cout << inputStr << "\n";
    char* chars = new char[inputStr.length() + 1];
    inputStr.copy(chars, inputStr.length());

    std::map <char, int> charFreq;
    for (int i = 0; i < inputStr.length(); i++) {
        if (charFreq.count(chars[i]) == 1) {
            charFreq[chars[i]] = charFreq[chars[i]]++;
        }
        else {
            charFreq[chars[i]] = 1;
        }
    }

    std::multiset<std::pair<char, int>, CharFreqLess> v;
    std::transform(charFreq.begin(), charFreq.end(), std::inserter(v, v.begin()),
            [](const std::pair<char, int>& p) {
                return p;
            }); 

    std::cout << "[OUT]:\n";
    std::multiset<std::pair<char, int>> ::iterator it = v.begin();
    for (; it != v.end(); it++) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}