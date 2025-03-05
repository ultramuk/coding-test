#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin >> str;

    std::vector<int> vec;
    for(auto s : str)
        vec.push_back(s - '0');

    std::sort(vec.rbegin(), vec.rend());

    for(auto v : vec)
        std::cout << v;

    return 0;
}