#include <iostream>
#include <vector>

int n = 3, r = 2;
std::vector<int> arr = {1, 2, 3};
std::vector<int> comb;

void dfs(int start, int depth)
{
    if(depth == r)
    {
        for(int c : comb)
            std::cout << c << " ";
        std::cout << "\n";
        return;
    }

    for(int i = start; i < n; i++)
    {
        comb.push_back(arr[i]);
        dfs(i + 1, depth + 1);
        comb.pop_back();
    }
}

int main()
{
    dfs(0, 0);
}
