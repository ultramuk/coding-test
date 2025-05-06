#include <iostream>
#include <queue>
#include <cmath>
struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, compare> pq;
    for(int i=0; i<n; i++)
    {
        int x;
        std::cin >> x;

        if(x == 0)
        {
            if(pq.empty())
                std::cout << "0\n";
            else
            {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}

