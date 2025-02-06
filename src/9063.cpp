#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y;
    int min_x = 10000, max_x = 1, min_y = 10000, max_y = 1;
    std::cin >> n;

    while(n--)
    {
        std::cin >> x >> y;

        if(min_x > x)
            min_x = x;
        if(max_x < x)
            max_x = x;
        if(min_y > y)
            min_y = y;
        if(max_y < y)
            max_y = y;
    }

    if(n == 1)
        std::cout << "0";
    else
        std::cout << (max_x - min_x) * (max_y - min_y);
}