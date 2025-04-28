#include <iostream>
#include <vector>
#include <unordered_set>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long answer=0;
    std::cin >> n;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    int left=0;
    std::unordered_set<int> u_set;
    for(int right=0; right<n; right++)
    {
        while(u_set.find(vec[right]) != u_set.end())
        {
                u_set.erase(vec[left++]);
        }

        u_set.insert(vec[right]);
        answer+=(right-left+1);
    }

    std::cout << answer;

    return 0;
}