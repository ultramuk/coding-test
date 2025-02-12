#include <iostream>
#include <queue>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::queue<int> q;
    for(int i=1; i<=n; i++)
    {
        q.push(i);
    }

    std::cout << "<";
    while(q.size() > 1)
    {
        for(auto i=1; i<k; i++)
        {
            auto q_front = q.front();
            q.pop();
            q.push(q_front);
        }

        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() << ">";

    return 0;
}