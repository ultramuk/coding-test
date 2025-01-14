#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a;
    std::cin >> a;

    for(int i=0; i<a; i++)
    {
        for(int j=a-i-1; j>0; j--)
            std::cout << " ";

        for(int k=0; k<i*2+1; k++)
            std::cout << "*";

        std::cout << "\n";
    }

    for(int i=1; i<a; i++)
    {
        for(int j=0; j<i; j++)
            std::cout << " ";

        for(int k=0; k<(a-i-1)*2+1; k++)
            std::cout << "*";

        std::cout << "\n";
    }
}
