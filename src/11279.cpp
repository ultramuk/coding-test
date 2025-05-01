#include <iostream>
#include <queue>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::priority_queue<int> pq;

    std::cin >> n;
    for(int i=0; i<n; i++)
    {
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
            pq.push(x);
    }

    return 0;
}
