#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include "ulliststr.h"

int main() {
    ULListStr ull;

    assert(ull.empty() && ull.size() == 0);

    ull.push_back("1");
    ull.push_front("0");
    assert(!ull.empty() && ull.size() == 2);
    assert(ull.get(0) == "0" && ull.get(1) == "1");

    assert(ull.back() == "1" && ull.front() == "0");

    ull.pop_back();
    assert(ull.size() == 1 && ull.back() == ull.front());
    ull.pop_front();
    assert(ull.empty());

    try {
        ull.front();
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }

    try {
        ull.back();
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }

    ull.push_back("2");
    ull.push_back("3");
    assert(ull.size() == 2 && ull.get(0) == "2" && ull.get(1) == "3");

    ull.set(0, "4");
    assert(ull.get(0) == "4");

    ull.clear();
    assert(ull.empty() && ull.size() == 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
