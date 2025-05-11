#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool isValid(const std::vector<int>& vec, int num, const int m)
{
    int count = 1;
    int sum = 0;

    for(const auto& v : vec)
    {
        if(sum + v > num)
        {
            count++;
            sum = v;
        }
        else
            sum += v;
    }

    return count <= m;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    int left = *std::max_element(vec.begin(), vec.end());
    int right = std::accumulate(vec.begin(), vec.end(), 0);

    int result = right;
    while(left <= right)
    {
        int mid = (left + right)/2;

        if(isValid(vec, mid, m))
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    std::cout << result;

    return 0;
}

