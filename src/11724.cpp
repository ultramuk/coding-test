#include <iostream>
#include <vector>

std::vector<std::vector<int> > graph;
std::vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;

    for(int next : graph[node])
    {
        if(!visited[next])
            dfs(next);
    }
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    graph.assign(n+1, std::vector<int>());
    visited.assign(n+1, false);

    for(int i=0; i<m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }

    std::cout << count;

    return 0;
}