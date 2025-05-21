#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> times(n);
    for(int i=0; i<n; i++)
        std::cin >> times[i];

    std::sort(times.begin(), times.end());

    int total = 0;
    int prefix = 0;

    for(int i=0; i<n; i++)
    {
        prefix += times[i];
        total += prefix;
    }

    std::cout << total;

    return 0;
}
