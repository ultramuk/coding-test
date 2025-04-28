#include <iostream>
#include <stack>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string str;
    for(int i=0; i<n; i++)
    {
        std::stack<int> stk;
        bool is_true = true;
        std::cin >> str;

        for(auto& s : str)
        {
            if(s == '(')
                stk.push(s);
            else if(s == ')')
            {
                if(stk.empty())
                {
                    is_true = false;
                    break;
                }

                if(stk.top() == '(')
                    stk.pop();
                else
                {
                    is_true = false;
                    break;
                }
            }
        }

        if(is_true && stk.empty())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}