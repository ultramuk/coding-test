#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, count = 0;
    std::cin >> n;

    while(n--)
    {
        std::string s;
        std::cin >> s;

        std::vector<char> x;
        auto is_sequence = true;
        char target;

        for(auto i=0; i<s.length(); i++)
        {
            if(i == 0)
            {
                x.push_back(s[i]);
                target = s[i];
                continue;
            }

            if(s[i-1] == s[i])
                continue;

            if(std::find(x.begin(), x.end(), s[i]) != x.end())
            {
                is_sequence = false;
                break;
            }

            x.push_back(s[i]);
        }

        if(is_sequence)
            count++;
    }

    std::cout << count;
}