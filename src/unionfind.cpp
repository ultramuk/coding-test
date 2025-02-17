#include <iostream>

const int MAX_SIZE = 10;

int parent[MAX_SIZE];
int rank[MAX_SIZE];

// 초기화 함수: n개의 요소로 초기ㅗ하
void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;  // 초기에는 모든 요소가 자기 자신을 부모로 가짐
        rank[i] = 0;    // 초기 랭크는 0
    }
}

void print()
{
    for(int i=0; i<MAX_SIZE; i++)
        std::cout << "i : " << i << ", parent : " << parent[i] << "\n";
    std::cout << "\n";
}

// find 함수: 경로 압축 기법을 사용하여 루트 찾기
// 이 함수는 경로 압축 기법을 사용하여 트리의 루트를 찾음
// 시간 복잡도: O(1) -> 아커만 함수의 역함수에 비례
int find(int x)
{
    if(parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// union 함수: rank를 사용하여 두 집합 합치기
// 이 함수는 두 집합을 합치기 위해 랭크를 사용하여 트리의 높이를 최적화합니다.
// 더 낮은 랭크의 트리를 더 높은 랭크의 트리 밑에 붙입니다.
// 시간복잡도: 거의 O(1)로 간주될 수 있습니다 (아커만 함수의 역함수에 비례)
void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY)
    {
        // rank가 더 낮은 트리를 더 높은 트리 밑에 붙임
        if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
            parent[rootY] = rootX;
            ++rank[rootX];
    }
}

int main()
{
    int n = 10;
    initialize(n);

    unionSets(1,2);
    print();
    unionSets(3,4);
    print();
    unionSets(2,4);
    print();
    unionSets(5,6);
    print();

    std::cout << "find(1): " << find(1) << std::endl;  // 1
    std::cout << "find(2): " << find(2) << std::endl;  // 1
    std::cout << "find(3): " << find(3) << std::endl;  // 1
    std::cout << "find(4): " << find(4) << std::endl;  // 1
    std::cout << "find(5): " << find(5) << std::endl;  // 5
    std::cout << "find(6): " << find(6) << std::endl;  // 5

    return 0;
}
