#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec(n);
    for(auto& v : vec) std::cin >> v;

    std::vector<long long> prefix(n + 1, 0);
    for (int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + vec[i];
    }

    long long max_sum = 0;
    for (int i=0; i<=n-m; i++) {
        long long sum = prefix[i+m] - prefix[i];
        max_sum = std::max(max_sum, sum);
    }

    std::cout << max_sum <<"\n";

    return 0;
}
