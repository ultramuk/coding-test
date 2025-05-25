#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<int> vec(11, 0);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 4;

    for(int i=4; i<11; i++)
    {
        vec[i] = vec[i-1] + vec[i-2] + vec[i-3];
    }


    while(t--)
    {
        int n;
        std::cin >> n;

        std::cout << vec[n] << "\n";
    }

    return 0;
}
