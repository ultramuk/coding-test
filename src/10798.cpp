#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s[5];

    for(int i=0; i<5; i++)
        std::cin >> s[i];

    for(int j=0; j<15; j++)
    {
        for(int i=0; i<5; i++)
        {
            if(s[i].length() > j)
                std::cout << s[i][j];
        }
    }
}