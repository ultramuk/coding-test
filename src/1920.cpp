#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    std::sort(vec.begin(), vec.end());

    std::cin >> m;
    for(int i=0; i<m; i++)
    {
        int x;
        std::cin >> x;
        if(std::binary_search(vec.begin(), vec.end(), x))
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }

    return 0;
}
