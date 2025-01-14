#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    for(int i=0; i<s.length()/2; i++)
    {
        if(s[i] != s[s.length()-1-i])
        {
            std::cout << "0";
            return 0;
        }
    }

    std::cout << "1";
}