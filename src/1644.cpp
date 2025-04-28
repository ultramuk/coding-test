#include <iostream>
#include <vector>

bool isPrime(int n)
{
    if(n < 2) return false;

    for(int i=2; i * i <=n; i++)
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

    int n;
    std::cin >> n;

    std::vector<int> vec;
    for(int i=2; i<=n; i++)
    {
        if(isPrime(i))
            vec.push_back(i);
    }

    int left=0, count=0;
    long long sum=0;
    for(int right=0; right<vec.size(); right++)
    {
        sum+=vec[right];

        while(sum >= n)
        {
            if(sum == n) count++;

            sum-=vec[left++];
        }
    }

    std::cout << count;

    return 0;
}
