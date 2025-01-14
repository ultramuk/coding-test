#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    float a, score = 0.0, grade = 0.0;

    for(int i=0; i<20; i++)
    {
        std::cin >> s1 >> a >> s2;

        if(s2 == "P")
            continue;

        score += a;

        if(s2 == "A+") grade += (4.5 * a);
        else if(s2 == "A0") grade += (4.0 * a);
        else if(s2 == "B+") grade += (3.5 * a);
        else if(s2 == "B0") grade += (3.0 * a);
        else if(s2 == "C+") grade += (2.5 * a);
        else if(s2 == "C0") grade += (2.0 * a);
        else if(s2 == "D+") grade += (1.5 * a);
        else if(s2 == "D0") grade += (1.0 * a);
    }

    std::cout << grade / score;
}