#include <vector>
#include <iostream>
//using namespace std;

//started on 02.12.2023
//source - https://stackoverflow.com/questions/47382423/c-quicksort-with-vectors

void swap(std::vector<int>& v, int x, int y);

void quicksort(std::vector<int>& vec, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void swap(std::vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

int main() {
    std::vector<int> vec1;
    const int count = 10;

    for (int i = 0; i < count; i++) {
        vec1.push_back(1 + rand() % 100);
    }
    std::cout << "Before sort: " << std::endl;
    for (std::vector<int>::iterator it = vec1.begin(); it < vec1.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    quicksort(vec1, 0, count - 1);

    std::cout << "After sort: " << std::endl;

    for (std::vector<int>::iterator it = vec1.begin(); it < vec1.end(); it++)
    {
        std::cout << *it << std::endl;
    }

}
