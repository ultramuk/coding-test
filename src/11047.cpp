#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    std::sort(vec.rbegin(), vec.rend());

    int count = 0;
    for(auto v : vec)
    {
        if(k == 0) break;

        if(v <= k)
        {
            count += k / v;
            k %= v;
        }
    }

    std::cout << count;

    return 0;
}
