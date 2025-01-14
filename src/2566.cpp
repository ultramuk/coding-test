#include <iostream>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[9][9];

    auto max = 0;
    int max_i, max_j;

    for(auto i=0; i<9; i++)
    {
        for(auto j=0; j<9; j++)
        {
            std::cin >> a[i][j];

            if(max <= a[i][j])
            {
                max = a[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    std::cout << max << "\n";
    std::cout << max_i+1 << " " << max_j+1;
}