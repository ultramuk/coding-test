#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x, y;

    std::cin >> n >> m;

    std::vector<int> v;

    for(int i=1; i<=n; i++)
        v.push_back(i);

    for(int i=0; i<m; i++)
    {
        std::cin >> x >> y;

        auto temp = v[x-1];
        v[x-1] = v[y-1];
        v[y-1] = temp;
    }

    for(int i=0; i<n; i++)
        std::cout << v[i] << " ";
}
