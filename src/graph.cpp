#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// 전역 변수 선언
// 그래프
std::vector<std::vector<std::pair<int, int>>> graph; // (노드, (인접노드, 거리))
// 최단거리
std::vector<int> dist;
// 직전노드
std::vector<int> prev;
// 방문여부
std::vector<bool> visited;

/* 다익스트라 알고리즘 함수 */
void dijkstra(int start) {
    // 그래프 노드 개수
    int n = graph.size();
    // 최단 거리 배열 무한대 초기화
    dist.assign(n, INF);
    // 직전 노드 -1 초기화
    prev.assign(n, -1);
    // 시작 노드의 거리는 0으로 초기화
    dist[start] = 0;

    // 최소힙(우선순위 큐) 선언
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>> pq; // (노드, 거리)
    // 시작 노드를 큐에 추가
    pq.push({start, 0});

    // 큐가 빌때까지 반복
    while(!pq.empty()) {
        // 현재 노드
        int u = pq.top().first;
        // 현재 노드까지의 거리
        int d = pq.top().second;

        // 현재 노드까지의 거리가 이미 더 짧은 경로가 있으면 무시
        if (visited[u]) continue;
        visited[u] = true;

        // 현재 노드의 모든 인접 노드를 탐색
        for(const auto& edge : graph[u]) {
            int v = edge.first; // 인접 노드
            int w = edge.second; // 가중치

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

}
