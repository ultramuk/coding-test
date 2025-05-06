#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1,2,3};

    do{
        for(int i=0; i<2; i++)
            std::cout << v[i] << " ";
        std::cout << "\n";
    } while(std::next_permutation(v.begin(), v.end()));
}
