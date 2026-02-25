#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right);
vector<int> MergeSort(vector<int> arr)
{
    if (arr.size() < 2)
    {
        return arr;
    }
    int middle = arr.size() / 2;
    // vector <int> left, right;

    // for (int i = 0; i < arr.size(); i++) {
    //     if (i < middle) {
    //         left.push_back(arr[i]);
    //     }
    //     else { right.push_back(arr[i]); }
    // }
    //вариант с итераторами, на тестах выполнялся быстрее
    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());

    return merge(MergeSort(left), MergeSort(right));
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    int i = 0, j = 0;

    while ((i < left.size()) && (j < right.size()))
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

int main()
{
    int k;
    cin >> k;
    vector<int> v(k), res(k);
    for (size_t i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    res = MergeSort(v);
    for (auto x : res)
    {
        cout << x << ' ';
    }
    return 0;
}
