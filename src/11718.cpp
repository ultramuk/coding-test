#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string s;
    while(true)
    {
        std::getline(std::cin, s);

        if(s == "") break;

        std::cout << s << "\n";
    }
}