#include <iostream>
#include <cmath>
int isPrime(int n)
{
    if(n < 2) return false;
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    while(true)
    {
        std::cin >> n;

        if(n == 0)
            break;

        int count = 0;
        for(int i=n+1; i<=n*2; i++)
        {
            if(isPrime(i))
                count++;
        }

        std::cout << count << "\n";
    }

    return 0;
}