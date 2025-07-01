/* 문제 */
// 체스의 퀸 N x N 체스판에 N개 배치했을 때, 서로 공격할 수 없는 위치에 놓을 수 있는 방법 경우의 수 확인

/* 풀이 */
// 완전탐색으로 풀면 N^N이므로 백트래킹으로 접근

// 상태정의 : 각 행에 하나의 퀸이 위치하도록 함
// 유망함수 : 현재 행을 놓았을 때, 다른 퀸과 충돌하는지 확인
// 해결책확인 : 모든 퀸이 배치되었는지 확인
// 재귀호출 : 다음 행에 퀸 배치

#include <iostream>
#include <vector>
#include <cmath>

int N;
std::vector<int> graph;
int count = 0;

bool check(int index) {
    for(int i=0; i < index; i++)
        if(graph[i] == graph[index]
                || abs(graph[index] - graph[i]) == index - i)
            return false;
    return true;
}

void solution(int index) {
    // 정답이 맞는지 확인
    if(index == N) {
        count++;
        return;
    }

    for(int i=0; i<N; i++) {
        graph[index] = i;
        if(check(index))
            solution(index+1);
    }
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    graph.assign(N, 0);

    solution(0);

    std::cout << count;

    return 0;
}
