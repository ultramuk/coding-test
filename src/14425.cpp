#include <iostream>
#include <string>
#include <unordered_set>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::unordered_set<std::string> str_set;
    for(int i=0; i<n; i++)
    {
        std::string str;
        std::cin >> str;
        str_set.insert(str);
    }

    int count=0;
    for(int i=0; i<m; i++)
    {
        std::string str;
        std::cin >> str;
        if(str_set.find(str) != str_set.end())
            count++;
    }

    std::cout << count;

    return 0;
}
