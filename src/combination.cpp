// 조합 -> 순서 X, 순열 -> 순서 O
// 조합 = nCr (n: 전체 원소 개수, r: 뽑을 원소 개수)
#include <iostream>
#include <vector>

const int N = 10;
const int R = 5;
int list[10] = {1,2,3,4,5,6,7,8,9,10};
std::vector<int> choose;

void combination(int index, int level)
{
    if(level == R)
    {
        for(auto& u : choose)
            std::cout << u << " ";
        std::cout << "\n";
        return ;
    }

    for(int i=index; i<N; i++)
    {
        choose.push_back(list[i]);
        combination(i+1, level+1);
        choose.pop_back();
    }
}

int main()
{
    combination(0,0);
    return 0;
}
