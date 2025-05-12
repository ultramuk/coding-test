#include <iostream>
#include <vector>
#include <algorithm>

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
        int a, b;
        std::cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    auto count = std::count(visited.begin(), visited.end(), true);
    std::cout << count -1;

    return 0;
}