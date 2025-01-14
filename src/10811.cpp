#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int i, j;

    std::cin >> n >> m;
    std::vector<int> a;

    for(int z=1; z<=n; z++)
        a.push_back(z);

    while(m--)
    {
        std::cin >> i >> j;
        i--;
        j--;
        if(i != j)
        {
            for(int z=0; z<=(j-i)/2; z++)
            {
                std::swap(a[i+z], a[j-z]);
            }
        }
    }

    for(int z=0; z<n; z++)
        std::cout << a[z] << " ";
}