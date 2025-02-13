// https://gliver.tistory.com/14
// 순열

#include <iostream>
#include <vector>

const int N = 10;
const int R = 3;
int list[10] = {1,2,3,4,5,6,7,8,9,10};
bool check[10] = {false,false,false,false,false,false,false,false,false,false};

std::vector<int> choose;

void permutation(int level)
{
    if(level == R)
    {
        for(auto& u : choose)
            std::cout << u << " ";
        std::cout << "\n";
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(check[i] == true)
            continue;

        choose.push_back(list[i]);
        check[i] = true;

        permutation(level+1);

        check[i] = false;
        choose.pop_back();
    }
}

int main()
{
    permutation(0);
    return 0;
}
