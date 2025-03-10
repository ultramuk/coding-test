#include <iostream>
#include <cmath>
bool isPrime(long long n)
{
    if(n == 1)
        return false;
    for(long long i=2; i<= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, x;
    std::cin >> n;

    for(long long i=0; i<n; i++)
    {
        std::cin >> x;

        while(!isPrime(x))
            x++;

        std::cout << x << "\n";
    }

    return 0;
}