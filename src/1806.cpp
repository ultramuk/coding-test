#include <iostream>
#include <vector>
#include <climits>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long s;
    std::cin >> n >> s;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    int minLength = INT_MAX;
    int left=0;
    long long sum=0;

    for(int right=0; right<n; right++)
    {
        sum+=vec[right];

        while(sum >= s)
        {
            minLength = std::min(minLength, right-left+1);
            sum-=vec[left++];
        }
    }
    if (minLength == INT_MAX)
        std::cout << 0 << '\n'; // 만족하는 구간이 없을 때
    else
        std::cout << minLength << '\n';

    return 0;
}