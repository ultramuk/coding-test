#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while(true)
    {
        int n, sum = 0;
        std::vector<int> vec;
        std::cin >> n;

        if(n == -1) break;

        for(int i=1; i<n; i++)
        {
            if(n % i == 0)
            {
                sum += i;
                vec.push_back(i);
            }
        }

        if(sum == n)
        {
            std::cout << n << " = ";

            for(auto i=0; i < vec.size()-1; i++)
                std::cout << vec[i] << " + ";
            std::cout << vec.at(vec.size()-1) << "\n";
        }
        else
            std::cout << n << " is NOT perfect.\n";
    }

}