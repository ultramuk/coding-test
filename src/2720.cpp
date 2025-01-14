#include <iostream>
#include <array>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 4> arr = {25, 10, 5, 1};

    int n, x;
    std::cin >> n;

    while(n--)
    {
        std::array<int, 4> res = {0, 0, 0, 0};
        std::cin >> x;

        for(int i=0; i<4; i++)
        {
            res[i] = x / arr[i];

            if(x == 0 && i == 3)
                res[i] = x;

            if(x == 0)
                break;

            x = x - res[i] * arr[i];
        }

        for(auto r : res)
            std::cout << r << " ";

        std::cout << "\n";
    }
}