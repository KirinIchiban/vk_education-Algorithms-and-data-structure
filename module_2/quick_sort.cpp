#include <iostream>
#include <vector>
using namespace std;

//быстрая сортирвка рекурсией
void qsortRec(vector<int>& v, int begin, int end) {
    int i  = begin, j  = end;
    int pivot = v[v.size()/2];
    while(i<=j) {
        while(v[i]<pivot) { i++; }
        while(v[j]>pivot) { j--; }
        if (i <= j ) {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    if (j > 0) {
        qsortRec(v, begin, j);
    }
    if (i < v.size())
        qsortRec(v, i, end)
}