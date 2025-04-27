#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int low, int high)
{
    int pivot = vec[high]; // 마지막 요소를 pivot
    int i = low - 1;

    for(int j = low; j < high; ++j)
    {
        if(vec[j] < pivot)
            std::swap(vec[++i], vec[j]);
    }
    std::swap(vec[i + 1], vec[high]);

    return i + 1;
}

void quickSort(std::vector<int>& vec, int low, int high)
{
    if(low < high)
    {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main(int argc, char** argv)
{
    std::vector<int> vec1 = {4,1,6,54,7,9,3,2,5,45,24,5,2,10};

    for(auto& v : vec1)
        std::cout << v << " ";
    std::cout << "\n";

    quickSort(vec1, 0, vec1.size()-1);

    for(auto& v : vec1)
        std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
