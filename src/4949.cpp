#include <iostream>
#include <stack>
#include <string>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;

    while(std::getline(std::cin, str))
    {
        if(str == ".")
            break;

        std::stack<char> stk;
        bool is_true = true;
        for(auto s : str)
        {
            if(s != '(' && s != ')' && s != '[' && s != ']')
                continue;

            if(stk.empty() && (s == ')' || s == ']'))
            {
                is_true = false;
                break;
            }

            if(s == '(' || s == '[')
            {
                stk.push(s);
                continue;
            }

            if((stk.top() == '('))
            {
                if(s == ')')
                {
                    stk.pop();
                    continue;
                }
                else
                {
                    is_true = false;
                    break;
                }
            }
            else if(stk.top() =='[')
            {
                if(s == ']')
                {
                    stk.pop();
                    continue;
                }
                else
                {
                    is_true = false;
                    break;
                }
            }
        }

        if(!stk.empty())
            is_true = false;

        if(is_true)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }

    return 0;
}