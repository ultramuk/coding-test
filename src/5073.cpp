#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, z;

    while(true)
    {
        std::cin >> x >> y >> z;

        if(x == 0 && y == 0 && z == 0)
            break;

        if(x + y <= z || x + z <= y || y + z <= x)
            std::cout << "Invalid\n";
        else if(x == y && x == z && y == z)
            std::cout << "Equilateral\n";
        else if(x == y || x == z || y == z)
            std::cout << "Isosceles\n";
        else
            std::cout << "Scalene\n";
    }
}