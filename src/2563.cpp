#include <algorithm>
#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int arr[100][100] = {0};
    int n, x, y;

    std::cin >> n;

    while(n--)
    {
        std::cin >> x >> y;

        for(int i=x-1; i<x+9; i++)
        {
            for(int j=y-1; j<y+9; j++)
            {
                arr[i][j] = 1;
            }
        }
    }

    auto num=0;
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(arr[i][j] == 1)
                num++;
        }
    }

    std::cout << num;
}