#include <iostream>
#include <vector>
#include <deque>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n;

    std::vector<int> dataStructure(n);
    for(int i=0; i<n; i++)
        std::cin >> dataStructure[i];

    std::deque<int> queueStack;
    for(int i=0; i<n; i++)
    {
        std::cin >> x;

        if(dataStructure.at(i) == 0)
            queueStack.push_back(x);
    }

    int m;
    std::cin >> m;

    for(int i=0; i<m; i++)
    {
        std::cin >> x;
        queueStack.push_front(x);
        std::cout << queueStack.back() << " ";
        queueStack.pop_back();
    }

    return 0;
}