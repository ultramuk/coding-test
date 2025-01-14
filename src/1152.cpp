#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::getline(std::cin, s);

    if(s.length() == 1 && s[0] == ' ')
    {
        std::cout << 0;
        return 0;
    }

    int count = 1;
    for(auto i=1; i<s.length() -1; i++)
    {
        if(s[i] == ' ')
            count++;
    }

    std::cout << count;
}