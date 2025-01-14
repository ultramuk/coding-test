#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    for(auto i=0; i<static_cast<int>(s1.length())/2; i++)
    {
        std::swap(s1[i], s1[s1.length()-1-i]);
    }

    for(auto i=0; i<static_cast<int>(s2.length())/2; i++)
    {
        std::swap(s2[i], s2[s2.length()-1-i]);
    }

    auto max = stoi(s1) > stoi(s2) ? stoi(s1) : stoi(s2);

    std::cout << max;
}