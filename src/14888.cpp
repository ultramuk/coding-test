#include <iostream>
#include <vector>
#include <climits>

void dfs(const int n, const std::vector<int>& vec, int& min, int& max,
        int index, int result, int plus, int minus, int mul, int div)
{
    if(index == n)
    {
        min = std::min(min, result);
        max = std::max(max, result);
        return;
    }

    if (plus > 0)
        dfs(n, vec, min, max, index + 1, result + vec[index], plus - 1, minus, mul, div);
    if (minus > 0)
        dfs(n, vec, min, max, index + 1, result - vec[index], plus, minus - 1, mul, div);
    if (mul > 0)
        dfs(n, vec, min, max, index + 1, result * vec[index], plus, minus, mul - 1, div);
    if (div > 0)
        dfs(n, vec, min, max, index + 1, result / vec[index], plus, minus, mul, div - 1);
}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;

    std::vector<int> oper(4);
    for(auto& o : oper)
        std::cin >> o;

    int min = INT_MAX, max = INT_MIN;

    dfs(n, vec, min, max, 1, vec[0], oper[0], oper[1], oper[2], oper[3]);

    std::cout << max << "\n" << min;

    return 0;
}