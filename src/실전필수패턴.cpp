#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <next_permutation>

/*** 기본 자료구조 & STL 실전 패턴 ***/
/** 배열, 문자열, STL 기본 **/
/* 문자열 분리 */
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;

    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim))
        result.push_back(item);

    return result;
}

/* map으로 빈도 세기 */
void Frequency_with_map() {
    std::vector<int> arr;
    std::unordered_map<int, int> cnt;
    for (auto num : arr)
        cnt[num]++;
}

/* 커스텀 정렬(복합 기준) */
void custom_sort() {
    std::vector<std::map<int, int>> vec;

    std::sort(vec.begin(), vec.end(), [](auto& a, auto& b){
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
}

/* 중복 원소 제거 */
void Removal_of_duplicate_elements() {
    std::vector<int> arr = {};

    std::sort(arr.begin(), arr.end());
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
}

/*** 탐색 알고리즘 핵심 패턴 ***/
/** 완전 탐색 & 백트래킹 **/
/* 조합 */
void combination(int start, int depth) {
    if (depth == K) {
        /* 사용 */
        return;
    }

    for (int i = start; i < N; i++) {
        selected[depth] = arr[i];
        combination(i + 1, depth + 1);
    }
}

/* 순열 */
void permutation(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());

    do {
        // 현재 순열 사용
    } while (std::next_permutation(arr.begin(), arr.end()));
}

/* 일반 DFS */
void dfs(int node) {
    visited[node] = true;
    for (auto next : adj[node]) {
        if (!visited[next])
            dfs(next);
    }
}

/** 이진 탐색 (Binary Search) **/
/* 실전 매개변수 탐색 일반형 */
int solve() {
    int left = 최소값, right = 최대값, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (조건(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

/* STL lower_bound / upper_bound 활용 */
int idx = std::lower_bound(arr.begin(), arr.end(), target) - arr.begin();

/** 투포인터 & 슬라이딩 윈도우 **/
/* 최대 길이 연속 부분합 */
void Maximum_length_continuous_part() {
    int left = 0, sum = 0;
    for (int right = 0; right < N; right++) {
        sum += arr[right];

        while(sum > S) sum -= arr[left++];
        answer = std::max(answer, right - left + 1);
    }
}

/* 부분합이 K인 경우의 수 세기 (누적합 + map)*/
void Century_when_partial_composite_is_K () {
    std::unordered_map<int, int> prefixCnt;
    prefixCnt[0] = 1;
    int sum = 0, ans = 0;

    for (int i=0; i<N; i++) {
        sum += arr[i];
        ans += prefixCnt[sum - K];
        prefixCnt[sum]++;
    }
}

/** DFS & BFS **/
/* 방향 배열 (4방향 / 8방향) */
void Direction_arrangement() {
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
}

/* BFS 최단거리 */
void BFS_The_shortest_distance() {
    std::queue<std::pair<int, int>> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (범위 체크 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

/* BFS 다중 시작점 */
void BFS_multi_starting_point() {
    visited[sy][sx] = true;
    q.push({sy, sx});
}

/*** 핵심 알고리즘 심화 패턴 ***/
/** Greedy **/
/* 회의실 배정 (종료 시간 기준 오름차순) */
void Conference_room_assignment(std::vector<std::pair<int, int>>& mettings) {
    std::sort(mettings.begin(), mettings.end(), [](auto& a, auto& b) {
        return a.end < b.end;
    });

    int last = 0, cnt = 0;
    for(auto m : mettings) {
        if (m.start >= last) {
            c++;
            last = m.end();
        }
    }
}

/* 동전 거스름돈 */
void Coin_change(std::vector<int> coins) {
    std::sort(coins.rbegin(), coins.rend());
    for (auto c : coins) {
        count += amount / c;
        amount %= c;
    }
}

/* 활동 선택 문제 (활동 최대 선택) */
void Selection() {
    std::sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
        return a.deadline < b.deadline;
    });
    std::priority_queue<int> pq;
    for (auto t : tasks) {
        pq.push(t.cost);
        if (pq.size() > t.deadline)
            pq.pop();
    }
    int answer = pq.size();
}

/** DP (Dynamic Programming) **/
/* 피보나치 기본 DP */
void Fibonacci() {
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=N; i++)
        dp[i] = dp[i-1] + dp[i-2];
}

/* 0-1 Knapsack (배낭 문제) */
void Knapsack() {
    for (int i=1; i<=N; i++) {
        for(int w = W; w >= weight[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - weight[i] + value[i]]);
        }
    }
}

/* LIS (최장 증가 부분수열) O(N log N) */
void LIS(std::vector<int>& arr) {
    std::vector<int> dp;
    for (int num : arr) {
        auto it = std::lower_bound(dp.begin(), dp.end(), num);

        if(it == dp.end())
            dp.push_back(num);
        else
            *it = num;
    }
    int lisLength = dp.size();
}

/* 2차원 DP: 경로 탐색 */
void Path_exploration() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (blocked[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
    }
}

/* 팰린드롬 판별 DP */
void Palindrome() {
    for (int i=0; i<N; i++)
        dp[i][i] = true;
    for (int len = 2; len <= N; len++) {
        for (int i=0; i+len-1 < N; i++) {
            int j = i+len-1;

            if(s[i] == s[j])
                dp[i][j] = (len == 2 || dp[i+1][j-1]);
        }
    }
}


/** 누적합 / 구간합 / 차이배열 **/
/* 누적합 기본 */
void Cumulative_sum_basic() {
    for (int i=1; i<=N; i++)
        prefix[i] = prefix[i-1] + arr[i];
    int sum = prefix[r] - prefix[l-1];
}

/* 차이배열 빠른 구간 업데이트 */
void Difference_array() {
    delta[l] += x;
    delta[r+1] -= x;

    for (int i=1; i<=N; i++)
        result[i] = result[i-1] + delta[i];
}

/** 시뮬레이션 **/
/* 방향 회전 (시계 방향으로 90도 회전) */
void Direction() {
    int temp[N][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            temp[j][N-1-i] = board[i][j];
        }
    }
    memcpy(board, temp, sizeof(board));
}

/* 이동 시뮬레이션 (다단계 이동 및 상태 변화) */
void move_simulation() {
    while (!종료조건) {
        // 1단계: 현재 위치 정보 수집
        for (auto& obj : objects) {
            obj.ny = obj.y + dy[obj.dir];
            obj.nx = obj.x + dx[obj.dir];
        }

        // 2단계: 경계 체크 및 벽 반사 등
        for (auto& obj : objects) {
            if (!in_range(obj.ny, obj.nx)) {
                obj.dir = reverse_direction(obj.dir);
                obj.ny = obj.y;
                obj.nx = obj.x;
            }
        }

        // 3단계: 이동 적용 및 충돌처리
        std::map<std::pair<int, int>, std::vector<Object>> cell;
        for (auto& obj : objects) {
            obj.y = obj.ny;
            obj.x = obj.nx;
            cell[{obj.y, obj.x}].push_back(obj);
        }

        // 4단계: 겹침/소멸 처리
        for (auto& [pos, objs] : cell) {
            if (objs.size() >= 2) {
                // 충돌 처리
            }
        }
    }
}

/* 탈출 시뮬레이션 (불 -> 사람 BFS 병렬 진행) */
void Escape_simulation() {
    // 불 BFS 먼저 퍼뜨림
    while (!fire.empty()) {
        auto [y, x] = fire.front();
        fire.pop();
        for(int d=0; d<4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (범위 && map[ny][nx] != '#' && fireTime[ny][nx] == -1) {
                fireTime[ny][nx] = fireTime[y][x] + 1;
                fire.push({ny, nx});
            }
        }
    }

    // 사람 BFS: 불보다 먼저 도착해야함
    while (!person.empty()) {
        auto [y, x] = person.front();
        person.pop();

        for(int d=0; d<4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if(범위 밖 -> 탈출 성공)
                return dist[y][x] + 1;
            if(범위 && map[ny][nx] == '.' && dist[ny][nx] == -1) {
                if(fireTime[ny][nx] != -1 && dist[y][x] + 1 >= fireTime[ny][nx])
                    continue;
                dist[ny][nx] = dist[y][x] + 1;
                person.push({ny, nx});
            }
        }
    }
}


/* 메인 함수 - test */
int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return 0;
}
