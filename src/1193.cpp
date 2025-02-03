#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int line = 1;
    int n;
    std::cin >> n;

    while(n - line > 0)
    {
        n -= line;
        line++;
    }

    if(line % 2 == 0)
        std::cout << n << "/" << line + 1 - n;
    else
        std::cout << line + 1 - n << "/" << n;

}