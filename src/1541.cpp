#include <iostream>
#include <string>
#include <sstream>

int sum_of_segment(const std::string& segment)
{
    std::stringstream ss(segment);
    std::string token;
    int sum = 0;

    // + 기준으로 숫자 쪼개기
    while(std::getline(ss, token, '+'))
        sum += std::stoi(token);

    return sum;
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string expr;
    std::cin >> expr;

    std::stringstream ss(expr);
    std::string segment;

    int result = 0;
    bool first = true;

    while(std::getline(ss, segment, '-'))
    {
        int part_sum = sum_of_segment(segment);

        if(first)
        {
            result += part_sum;
            first = false;
        }
        else
        {
            result -= part_sum;
        }
    }

    std::cout << result << "\n";
    return 0;
}