#include <iostream>
#include <vector>
#include <string>
#include <map>
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, x, y, K;
    std::cin >> N >> M >> y >> x >> K;

    std::vector<std::vector<int>> map(N, std::vector<int>(M));
    std::map<std::string, int> dice = {
        {"top", 0}, {"bottom", 0}, {"front", 0},
        {"back", 0}, {"left", 0}, {"right", 0}
    };

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            std::cin >> map[i][j];

    int dx[5] = {0, 1, -1, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};

    while(K--)
    {
        int dir;
        std::cin >> dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;

        int swap;
        switch (dir)
        {
        case 1:
            swap = dice["top"];
            dice["top"] = dice["right"];
            dice["right"] = dice["bottom"];
            dice["bottom"] = dice["left"];
            dice["left"] = swap;
            break;
        case 2:
            swap = dice["top"];
            dice["top"] = dice["left"];
            dice["left"] = dice["bottom"];
            dice["bottom"] = dice["right"];
            dice["right"] = swap;
            break;
        case 3:
            swap = dice["top"];
            dice["top"] = dice["back"];
            dice["back"] = dice["bottom"];
            dice["bottom"] = dice["front"];
            dice["front"] = swap;
            break;
        case 4:
            swap = dice["top"];
            dice["top"] = dice["front"];
            dice["front"] = dice["bottom"];
            dice["bottom"] = dice["back"];
            dice["back"] = swap;
            break;
        }

        x = nx;
        y = ny;

        if(map[y][x] == 0)
            map[y][x] = dice["bottom"];
        else
        {
            dice["bottom"] = map[y][x];
            map[y][x] = 0;
        }

        std::cout << dice["top"] << "\n";
    }

    return 0;
}
