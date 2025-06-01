#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(auto& v : vec)
    std::cin >> v;

    std::vector<int> dp(n, 1);
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(vec[j] < vec[i])
            {
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }

    int result = *std::max_element(dp.begin(), dp.end());
    std::cout << result << "\n";

    return 0;
}
