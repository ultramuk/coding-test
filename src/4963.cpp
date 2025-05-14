#include <iostream>
#include <vector>

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x, const int Y, const int X, std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited)
{
    visited[y][x] = true;

    for(int dir=0; dir<8; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
        if(graph[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx, Y, X, graph, visited);
    }
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::vector<std::vector<int> > graph;
    std::vector<std::vector<bool> > visited;

    while(std::cin >> x >> y)
    {
        if(x == 0 && y == 0)
            break;

        graph.assign(y, std::vector<int>(x, 0));
        visited.assign(y, std::vector<bool>(x, false));

        for(int i=0; i<y; i++)
        {
            for(int j=0; j<x; j++)
            {
                int x;
                std::cin >> x;
                graph[i][j] = x;
            }
        }

        int count = 0;
        for(int i=0; i<y; i++)
        {
            for(int j=0; j<x; j++)
            {
                if(graph[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j, y, x, graph, visited);
                    count++;
                }
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}
