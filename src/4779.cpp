#include <iostream>
#include <cmath>
void cantor(int n)
{
    if(n == 0)
    {
        std::cout << "-";
        return;
    }

    cantor(n-1);
    for(int i=0; i<pow(3, n-1); i++)
        std::cout << " ";
    cantor(n-1);

}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    int n;
    while(std::cin >> n)
    {
        cantor(n);
        std::cout << "\n";
    }

    return 0;
}