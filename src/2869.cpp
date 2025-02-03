#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, v;

    std::cin >> a >> b >> v;

    int day = 1;

    day += (v - a) / (a - b);

    if((v - a) % (a - b) != 0)
        day++;

    if(a >= v)
        std::cout << "1";
    else
        std::cout << day;

    return 0;
}