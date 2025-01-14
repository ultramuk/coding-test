#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n;
    std::vector<int> vec(n+1);

    for(int i=1; i<=n; i++)
    {
        std::cin >> vec[i];
    }

    std::cin >> x;
    std::cout << std::count(vec.begin(), vec.end(), x);

}