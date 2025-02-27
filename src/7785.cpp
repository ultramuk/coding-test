#include <iostream>
#include <string>
#include <map>
int main(int arc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, bool, std::greater<std::string>> container;
    while(n--)
    {
        std::string name, is_enter;
        std::cin >> name >> is_enter;

        if(is_enter == "enter")
            container[name] = true;
        else if(container.find(name) != container.end())
            container.erase(name);
    }

    for(auto& name : container)
        std::cout << name.first << "\n";

    return 0;
}