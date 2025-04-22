#include <iostream>
#include <string>
int recursion(const std::string& s, int l, int r, int& count){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

int isPalindrome(const std::string& s, int& count){
    return recursion(s, 0, s.length()-1, count);
}

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    for(int i=0; i<n; i++)
    {
        std::string s;
        std::cin >> s;

        int count = 0;
        std::cout << isPalindrome(s, count) << " " << count << "\n";
    }

    return 0;
}