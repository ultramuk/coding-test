#include <iostream>
#include <vector>

void dfs(int index, int level, const int n, const int result_level,
        const std::vector<int>& vec, std::vector<int>& choose)
{
    if(level == result_level)
    {
        for(auto& ch : choose)
            std::cout << ch << " ";
        std::cout << "\n";
        return;
    }

    for(int i=index; i<n; i++)
    {
        choose.push_back(vec[i]);
        dfs(i+1, level+1, n, result_level, vec, choose);
        choose.pop_back();
    }
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec(n);
    std::vector<int> choose;
    for(int i=0; i<n; i++)
        vec[i]=i+1;

    dfs(0, 0, n, m, vec, choose);

    return 0;
}