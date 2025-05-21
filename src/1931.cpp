#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> a, const std::pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}
int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> meeting;
    for(int i=0; i<n; i++)
    {
        int start, end;
        std::cin >> start >> end;

        meeting.push_back({start, end});
    }

    std::sort(meeting.begin(), meeting.end(), compare);

    int standard_time = 0;
    int count = 0;
    for(auto& m : meeting)
    {
        if(standard_time <= m.first)
        {
            count++;
            standard_time = m.second;
        }
    }

    std::cout << count;

    return 0;
}
