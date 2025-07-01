/* 문제 */
// {1, 2, 3, 4}로 이루어진 집합에서 숫자를 뽑아서 합이 5인 조합 구하기

/* 풀이 */
// 완전 탐색으로 풀면 오래 걸리므로 백트래킹을 사용하기

// 상태정의 : 현재 선택된 숫자들의 합
// 유망함수 : 현재 합이 목표값을 초과하면 유명하지 않다고 판단
// 해결책확인 : 현재 합이 목표값과 일치
// 재귀함수 : 다음 숫자 선택하여 부분합 갱신

#include <iostream>
#include <vector>

std::vector<int> vec = {1, 2, 3 ,4};
int target = 5;
std::vector<int> current;

void solution(int index) {
    // 합 구하기
    int sum = 0;
    for(auto c : current)
        sum += c;

    // 합이 target과 같다면 출력 & 반환
    if(sum == target) {
        for(auto c : current)
            std::cout << c << " ";
        std::cout << "\n";
        return;
    }

    // 합이 target 보다 크다면 반환
    if(sum > target) {
        return;
    }

    // 유명한 경우 다음 숫자 추가 후 탐색
    for(int i=index; i<vec.size(); ++i) {
        current.push_back(vec[index]);
        solution(i+1);
        current.pop_back();
    }
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solution(0);

    return 0;
}
