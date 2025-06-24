#include <iostream>
#include <vector>

using namespace std;

int N, L;

bool is_possible(vector<int>& line) {
    vector<bool> is_used(N, false);

    for (int i = 0; i < N - 1; i++) {
        int diff = line[i + 1] - line[i];

        if (diff == 0) {
            continue;
        }
        else if (diff == 1) { // 올라가는 경우
            if (i - L + 1 < 0) // 왼쪽으로 L칸이 부족하면 불가능
                return false;
            for (int j = i - L + 1; j <= i; j++) {
                if (line[j] != line[i] || is_used[j])
                    return false;
                is_used[j] = true;
            }
        }
        else if (diff == -1) { // 내려가는 경우
            if (i + L >= N) // 오른쪽으로 L칸이 부족하면 불가능
                return false;
            for (int j = i + 1; j <= i + L; j++) {
                if (line[j] != line[i + 1] || is_used[j])
                    return false;
                is_used[j] = true;
            }
        }
        else {
            return false; // 높이 차이가 2 이상이면 불가능
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    vector<vector<int>> map(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    int count = 0;

    // 가로 검사
    for (int i = 0; i < N; i++) {
        if (is_possible(map[i]))
            count++;
    }

    // 세로 검사
    for (int j = 0; j < N; j++) {
        vector<int> column;
        for (int i = 0; i < N; i++)
            column.push_back(map[i][j]);
        if (is_possible(column))
            count++;
    }

    cout << count << "\n";
    return 0;
}
