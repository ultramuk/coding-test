#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;

    std::unordered_map<std::string, int> str_map;
    std::unordered_map<int, std::string> int_map;

    for(int i=1; i<=n; i++)
    {
        std::string str;
        std::cin >> str;

        str_map[str] = i;
        int_map[i] = str;
    }

    while(m--)
    {
        std::string str;
        std::cin >> str;

        if(std::isdigit(str[0]))
            std::cout << int_map.at(stoi(str)) << "\n";
        else
            std::cout << str_map.at(str) << "\n";
    }

    return 0;
}