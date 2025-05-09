#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
void dfs(int l, int c, const std::vector<char>& vec, int index, std::string current, int vowelCount, int consoanaCount)
{
    if(current.length() == l)
    {
        if(vowelCount >= 1 && consoanaCount >=2)
            std::cout << current << "\n";
        return;
    }

    for(int i=index; i<c; i++)
    {
        char next = vec[i];

        if(isVowel(next))
            dfs(l, c, vec, i+1, current + next, vowelCount+1, consoanaCount);
        else
            dfs(l, c, vec, i+1, current + next, vowelCount, consoanaCount+1);
    }
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, c;
    std::cin >> l >> c;

    std::vector<char> vec(c);
    for(auto& v : vec)
        std::cin >> v;

    std::sort(vec.begin(), vec.end());

    dfs(l, c, vec, 0, "", 0, 0);

    return 0;
}