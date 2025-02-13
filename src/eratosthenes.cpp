// https://gliver.tistory.com/8
// 에라토스테네스의 체 알고리즘 -> 약수구하기
// 소수를 판별해야 할 때 사용


#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{
    int n;
    std::cin >> n;

    bool is_prime[n+1];

    for(int i=1; i<=n; i++)
        is_prime[i] = true;

    is_prime[1] = false;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(!is_prime[i])
            continue;

        for(int j=2; i*j <= n; j++)
            is_prime[i*j] = false;
    }

    for(int i=1; i<=n; i++)
        if(is_prime[i])
            std::cout << i << " ";
}

