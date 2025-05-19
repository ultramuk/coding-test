#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    while (t--)
    {
        int w, h;
        std::cin >> w >> h;

        std::vector<std::string> map(h);
        std::queue<std::pair<int, int>> fire_q;
        std::queue<std::pair<int, int>> person_q;
        std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));

        for (int i = 0; i < h; i++)
        {
            std::cin >> map[i];
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == '*')
                    fire_q.push({i, j});
                else if (map[i][j] == '@')
                {
                    person_q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        bool escaped = false;
        int time = 0;

        while (!person_q.empty())
        {
            // 1. 불 먼저 확산
            int fire_size = fire_q.size();
            for (int i = 0; i < fire_size; i++)
            {
                auto [fy, fx] = fire_q.front();
                fire_q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nfy = fy + dy[d];
                    int nfx = fx + dx[d];

                    if (nfy < 0 || nfy >= h || nfx < 0 || nfx >= w) continue;
                    if (map[nfy][nfx] == '.' || map[nfy][nfx] == '@')
                    {
                        map[nfy][nfx] = '*';
                        fire_q.push({nfy, nfx});
                    }
                }
            }

            // 2. 사람 이동
            int person_size = person_q.size();
            for (int i = 0; i < person_size; i++)
            {
                auto [py, px] = person_q.front();
                person_q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int npy = py + dy[d];
                    int npx = px + dx[d];

                    // 탈출 성공
                    if (npy < 0 || npy >= h || npx < 0 || npx >= w)
                    {
                        std::cout << time + 1 << "\n";
                        escaped = true;
                        break;
                    }

                    if (map[npy][npx] == '.' && !visited[npy][npx])
                    {
                        visited[npy][npx] = true;
                        person_q.push({npy, npx});
                    }
                }

                if (escaped) break;
            }

            if (escaped) break;
            time++;
        }

        if (!escaped)
        {
            std::cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}
