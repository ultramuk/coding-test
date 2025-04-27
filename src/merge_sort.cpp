#include <iostream>
#include <vector>

void merge(std::vector<int>& vec, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if(vec[i] <= vec[j])
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }

    while (i <= mid) temp[k++] = vec[i++];
    while (j <= right) temp[k++] = vec[j++];
    for (int t = 0; t < temp.size(); ++t) vec[left + t] = temp[t];
}

void mergeSort(std::vector<int>& vec, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}


int main(int argc, char** argv)
{
    std::vector<int> vec1 = {4,1,6,54,7,9,3,2,5,45,24,5,2,10};

    for(auto& v : vec1)
        std::cout << v << " ";
    std::cout << "\n";

    mergeSort(vec1, 0, vec1.size()-1);

    for(auto& v : vec1)
        std::cout << v << " ";
    std::cout << "\n";

    return 0;

    return 0;
}