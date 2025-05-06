#include <iostream>
#include <stack>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::stack<int> stk;
    std::vector<char> result;
    int current=1;

    for(int i=0; i<n; i++)
    {
        int x;
        std::cin >> x;

        while(current <= x)
        {
            stk.push(current++);
            result.push_back('+');
        }

        if(stk.top() == x)
        {
            stk.pop();
            result.push_back('-');
        }
        else
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    for(char c : result)
        std::cout << c << '\n';

    return 0;
}