#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char** argv)
{
    int n, sum = 0;

    std::cin >> n;
    std::vector<double> vec(n);

    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cin >> *it;
        sum += *it;
    }

    auto max = *std::max_element(vec.begin(), vec.end());

    std::cout << sum * 100.0 / max / n;
}