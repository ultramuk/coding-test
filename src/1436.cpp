#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, count = 0;
    std::cin >> n;

    for(int i=666; i<=10000000; i++)
    {
        auto num = i;

        while(num != 0)
        {
            if(num % 1000 == 666)
            {
                count++;
                break;
            }

            num /= 10;
        }

        if(count == n)
        {
            std::cout << i;
            break;
        }
    }

    return 0;
}