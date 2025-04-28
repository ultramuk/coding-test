#include <iostream>
#include <queue>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::queue<int> que;
    for(int i=1; i<n+1; i++)
        que.push(i);

    while(que.size() > 1)
    {
        que.pop();
        auto x = que.front();
        que.pop();
        que.push(x);
    }


    std::cout << que.front();

    return 0;
}
