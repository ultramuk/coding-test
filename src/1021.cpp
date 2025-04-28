#include <iostream>
#include <deque>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::deque<int> deq;
    for(int i=1; i<n+1; i++)
        deq.push_back(i);

    int count = 0;
    for(int i=0; i<m; i++)
    {
        int x;
        std::cin >> x;

        while(true)
        {
            if(x == deq.front())
            {
                deq.pop_front();
                break;
            }

            int idx = 0;
            for(int d : deq)
            {
                if (d == x) break;
                idx++;
            }

            if(idx <= deq.size() / 2)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
            else
            {
                deq.push_front(deq.back());
                deq.pop_back();
            }

            count++;
        }
    }

    std::cout << count;

    return 0;
}