#include <iostream>
#include <vector>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(int i=0; i<n; i++)
        std::cin >> vec[i];

    std::vector<int> dist;
    for(int i=0; i<n-1; i++)
    {
        dist.push_back(vec[i+1] - vec[i]);
    }

    auto g = dist[0];
    for(int i=0; i<dist.size(); i++)
    {
        g = gcd(g, dist[i]);
    }

    int num=0;
    for(const auto d : dist)
    {
        num += d / g - 1;
    }

    std::cout << num;

    return 0;
}