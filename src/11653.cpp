#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, i=2;
    std::cin >> n;

    while(n > 1)
    {
        if(n % i != 0)
        {
            i++;
            continue;
        }

        std::cout << i << "\n";
        n /= i;
    }
}