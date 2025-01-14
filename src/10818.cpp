#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for(auto i=0; i<n; i++)
        std::cin >> v[i];

    auto min = *std::min_element(v.begin(), v.end());
    auto max = *std::max_element(v.begin(), v.end());

    std::cout << min << " " << max;
}