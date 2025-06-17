#include <iostream>
#include <vector>

int main(int argc, char* argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> vec(N, 0);

    for(auto& v : vec)
        std::cin >> v;

    std::vector<int> prefix(N+1, 0);
    for(int i=0; i<N; i++)
        prefix[i+1] = prefix[i] + vec[i];

    while(M--) {
        int a, b;
        std::cin >> a >> b;

        std::cout << prefix[b] - prefix[a-1] << "\n";
    }

    return 0;
}