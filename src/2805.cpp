#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long int m;

    std::cin >> n >> m;
    std::vector<int> vec(n);

    for(auto& v : vec)
        std::cin >> v;

    std::sort(vec.begin(), vec.end());

    int left=0, right=vec.back();
    int result = 0;

    while(left <= right)
    {
        int mid = (left+right)/2;

        long long sum = 0;
        for(auto v : vec)
            if(v > mid)
                sum += (v - mid);

        if(sum >= m)
        {
            result = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }

    std::cout << result;

    return 0;
}
