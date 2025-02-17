#include <iostream>

const int MAX_SIZE = 10;

int parent[MAX_SIZE];

// 초기화 함수: n개의 요소로 초기ㅗ하
void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i; // 초기에는 모든 요소가 자기 자신을 부모로 가짐
    }
}

void print()
{
    for(int i=0; i<MAX_SIZE; i++)
        std::cout << "i : " << i << ", parent : " << parent[i] << "\n";
    std::cout << "\n";
}

// find 함수: 루트를 찾기 위한 기본적인 방법
// 이 함수는 트리의 루트를 찾기 위해 부모 배열 순회
// 시간 복잡도: O(n) -> 최악의 경우, 트리가 한쪽으로 치우쳐 있을 때
int find(int x)
{
    while(parent[x] != x)
    {
        x = parent[x];
    }
    return x;
}

// union 함수: 두 집합을 합침
// 이 함수는 두 집합을 합치는 작업 수행
// 시간 복잡도: O(n) -> find 함수의 시간 복잡도에 의해 결정됨
void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY)
        parent[rootY] = rootX;
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
