#include <iostream>
#include <vector>

void dfs(int node, const std::vector<int>& graph, std::vector<bool>& visited, std::vector<bool>& finished, int& count)
{
    visited[node] = true;
    int next = graph[node];

    if(!visited[next])
        dfs(next, graph, visited, finished, count);
    else if(!finished[next])
    {
        int cur = next;
        while(cur != node)
        {
            count++;
            cur = graph[cur];
        }
        count++;
    }

    finished[node] = true;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> graph(n+1);
        std::vector<bool> visited(n+1, false);
        std::vector<bool> finished(n+1, false);

        for(int i=1; i<=n; i++)
            std::cin >> graph[i];

        int cycleCount = 0;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
                dfs(i, graph, visited, finished, cycleCount);
        }

        std::cout << n - cycleCount << "\n";
    }

    return 0;
}