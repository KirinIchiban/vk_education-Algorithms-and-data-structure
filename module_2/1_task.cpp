#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, target, found = 0;
    cin >> k;
    vector<int> v(k);
    for (size_t i = 0; i < k; i++) {
        cin >> v[i];
    }
    cin >> target;

    //binary search
    int left = 0;
    int right = k-1;
    while(left <= right) {
        int middle = left + (right - left)/2;
        if (v[middle] == target) {
            cout << middle <<'\n';
            found = 1;
            break;
        }
        if (v[middle] > target) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    if (!found) {
        if (!found) {
        cout << left <<'\n';
        }
    }

    return 0;
}