#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int b, result=0;
    std::string n;

    std::cin >> n >> b;

    for(auto i=0; i<n.length(); i++)
    {
        if('0' <= n[i] && '9' >= n[i])
            result = result * b + (n[i] - '0');
        else
            result = result * b + (n[i] - 'A' + 10);
    }

    std::cout << result;
}