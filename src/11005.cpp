#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int b, n=0;
    std::string result = "";

    std::cin >> n >> b;

    while(n > 0)
    {
        auto x = n % b;

        if(x >= 0 && x <= 9)
            result += x + '0';
        else
            result += x - 10 + 'A';

        n /= b;
    }

    std::reverse(result.begin(), result.end());

    std::cout << result;

}