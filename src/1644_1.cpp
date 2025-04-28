#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=n; i++)
    {
        if(!isPrime[i]) continue;

        for(int j=2*i; j<=n; j+=i)
            isPrime[j] = false;
    }

    std::vector<int> vec;
    for(int i=2; i<=n; i++)
        if(isPrime[i]) vec.push_back(i);

    int left=0, right=0, sum=0, count=0;
    while(true)
    {
        if(sum>=n)
        {
            if(sum == n) count++;
            sum-=vec[left++];
        }
        else
        {
            if(right == vec.size()) break;
            sum+=vec[right++];
        }
    }

    std::cout << count;
}
