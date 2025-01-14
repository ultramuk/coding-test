#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    std::string s1 = "abcdefghijklmnopqrstuvwxyz";
    std::string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<int> x(26);
    std::string s3;

    std::cin >> s3;

    for(auto i : s3)
    {
        auto a1 = std::find(s1.begin(), s1.end(), i);
        auto a2 = std::find(s2.begin(), s2.end(), i);

        if(a1 != s1.end())
            x[std::distance(s1.begin(), a1)]++;

        if(a2 != s2.end())
            x[std::distance(s2.begin(), a2)]++;
    }

    auto max_iter = std::max_element(x.begin(), x.end());
    auto max_index = std::distance(x.begin(), max_iter);

    if(std::count(x.begin(), x.end(), *max_iter) > 1)
        std::cout << "?";
    else
        std::cout << s2[max_index];
}