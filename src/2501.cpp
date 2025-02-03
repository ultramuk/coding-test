#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::vector<int> vec;
    std::cin >> n >> k;

    for(int i=1; i<=n; i++)
    {
        if(n % i == 0)
            vec.push_back(i);
    }

    if(vec.size() < k)
        std::cout << "0";
    else
        std::cout << vec.at(k-1);
}