#include <iostream>
#include <vector>
#include <queue>
#include <map>

void rotate(std::deque<bool>& gear, const int dir)
{
    if(dir == 1)
    {
        gear.push_front(gear.back());
        gear.pop_back();
    }
    else if(dir == -1)
    {
        gear.push_back(gear.front());
        gear.pop_front();
    }
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::deque<bool>> gear(4);

    for(int i=0; i<4; i++)
    {
        std::string str;
        std::cin >> str;

        for(auto& s : str)
            gear[i].push_back(static_cast<bool>(s-'0'));
    }

    int K;
    std::cin >> K;

    while(K--)
    {
        int index, dir;
        std::cin >> index >> dir;
        index--;

        std::vector<std::pair<int, int>> candidate = {{index, dir}}; // {index, dir}
        int candidate_dir = dir;
        for(int i=index-1; i>=0; i--)
        {
            if(gear[i+1][6] == gear[i][2])
                break;

            if(candidate_dir == 1)
                candidate_dir = -1;
            else
                candidate_dir = 1;

            candidate.push_back({i, candidate_dir});
        }
        candidate_dir = dir;
        for(int i=index+1; i<4; i++)
        {
            if(gear[i-1][2] == gear[i][6])
                break;

            if(candidate_dir == 1)
                candidate_dir = -1;
            else
                candidate_dir = 1;

            candidate.push_back({i, candidate_dir});
        }

        for(auto& c: candidate)
        {
            rotate(gear[c.first], c.second);
        }

    }

    auto sum = 0;
    if(gear[0][0]) sum += 1;
    if(gear[1][0]) sum += 2;
    if(gear[2][0]) sum += 4;
    if(gear[3][0]) sum += 8;

    std::cout << sum << "\n";

    return 0;
}
