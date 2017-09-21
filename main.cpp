#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

void f(std::vector<char> const& v) {
    if (v.size() == 0) {
        return;
    }
    using st = std::vector<char>::size_type;
    std::vector<st> indexes(26, 0);
    auto max = std::numeric_limits<st>::max();
    st pos = 0;
    for(auto c: v) {
        auto i = int(c) - 'a';
        indexes[i] = (indexes[i] != 0) ? max : pos;
        ++pos;
    }
    auto index_0 = int(v[0]) - 'a';
    st value_0 = (indexes[index_0] != 0) ? max : 0;
    for(auto&& i: indexes) {
        if (i == 0) {
            i = max;
        }
    }
    indexes[index_0] = value_0;
    std::sort(indexes.begin(), indexes.end());
    if (indexes[0] != max) {
        std::cout << indexes[0] << std::endl;
    }
}

int main() {
    std::vector<char> v = {'a', 'b', 'c', 'b', 'd', 'a'};
    f(v);
}
