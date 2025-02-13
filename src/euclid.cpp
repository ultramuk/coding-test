// https://gliver.tistory.com/10
// 유클리드 알고리즘 -> 최대공약수 구하기
// 최대공약수, 최소공배수, 숫자 3개의 최대공약수

#include <iostream>

int main(int argc, char** argv)
{
    int a, b;
    std::cin >> a >> b;

    while(true)
    {
        int tmp = a % b;
        a = b;
        b = tmp;

        if(b == 0)
        {
            std::cout << a;
            break;
        }
    }
    return 0;
}
