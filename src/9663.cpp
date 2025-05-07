#include <iostream>
#include <vector>
#include <cmath>

// 조건 검사 함수
bool is_valid(int row, int col, const std::vector<int>& queen) {
    for (int i = 0; i < row; i++) {
        if (queen[i] == col) return false;                          // 같은 열에 퀸이 있음
        if (abs(queen[i] - col) == abs(i - row)) return false;      // 같은 대각선
    }
    return true;
}

// 재귀 DFS 함수: 성공한 배치 수를 반환
int dfs(int row, int n, std::vector<int>& queen) {
    if (row == n) return 1;  // 모든 행에 퀸을 성공적으로 놓았음

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (is_valid(row, col, queen)) {
            queen[row] = col;  // 현재 행에 퀸 배치
            count += dfs(row + 1, n, queen);  // 다음 행 탐색
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> queen(n);  // queen[row] = col
    int result = dfs(0, n, queen);

    std::cout << result << '\n';
    return 0;
}
