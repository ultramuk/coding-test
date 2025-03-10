#include <iostream>
#include <cmath>
bool isPrime(int n)
{
    if(n < 2)
        return false;

    for(int i=2; i<sqrt(n); i++)
        if(n % i == 0)
            return false;

    return true;
}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n;

    std::cin >> m >> n;

    for(int i=m; i<=n; i++)
    {
        if(isPrime(i))
            std::cout << i << "\n";
    }

    return 0;
}