#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<int> count_zero(41);
    std::vector<int> count_one(41);

    // fibo(0) -> 0 1
    count_zero[0] = 1;
    count_one[0] = 0;

    // fibo(1) -> 1 0
    count_zero[1] = 0;
    count_one[1] = 1;

    for(int i=2; i<= 40; ++i)
    {
        count_zero[i] = count_zero[i-1] + count_zero[i-2];
        count_one[i] = count_one[i-1] + count_one[i-2];
    }

    while(t--)
    {
        int n;
        std::cin >> n;
        std::cout << count_zero[n] << " " << count_one[n] << "\n";
    }

    return 0;
}
