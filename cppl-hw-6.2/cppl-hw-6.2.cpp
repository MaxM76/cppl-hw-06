#include <iostream>
#include <set>

struct SortLess : public std::binary_function<const int, const int, bool> {
    bool operator()(const int ch1, const int ch2) const {
        return ch1 > ch2;
    }
};

int main()
{
    std::cout << "[IN]:\n";
    int count = 0;
    std::cin >> count;
    std::set<int, SortLess> intSet;
    for (int i = 0; i < count; i++) {
        int value;
        std::cin >> value;
        intSet.insert(value);
    }
    
    std::cout << "[OUT]:\n";
    std::set<int>::iterator it = intSet.begin();
    for (; it != intSet.end(); it++) {
        std::cout << *it << "\n";
    }
}