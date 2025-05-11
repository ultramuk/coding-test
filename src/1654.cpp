#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(const std::vector<int>& vec, long long int x, const int n)
{
    long long int num = 0;

    for(const auto& v : vec)
    {
        num += v / x;
    }

    return num >= n;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n;
    std::cin >> k >> n;

    std::vector<int> vec(k);
    for(auto& v : vec)
        std::cin >> v;

    long long int left = 1;
    long long int right = *std::max_element(vec.begin(), vec.end());

    long long int result = 0;
    while(left <= right)
    {
        auto mid = (left + right) / 2;

        if(isValid(vec, mid, n))
        {
            result = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    std::cout << result;

    return 0;
}