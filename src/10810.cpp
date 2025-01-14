#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int i, j, k;

    std::cin >> n >> m;

    std::vector<int> v(n);

    for(int x = 0; x < m; x++)
    {
        std::cin >> i >> j >> k;

        for(int y = i-1; y < j; y++)
        {
            v[y] = k;
        }
    }

    for(auto z : v)
        std::cout << z << " ";
}
