#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> exponential_search(vector<int> data, int target) {
    int border = 1;
    int lastel = data.size() - 1;

    while (border < lastel && data[border] <= target) {
        if (data[border] == target) {
            return {border, border*2};
        }
        border = border*2;
        if (border > lastel) {
            return {border/2, lastel};
        }
    }
    return {border/2, border};
}

int main() {
    int k, target, found = 0;
    cin >> k;
    vector<int> v(k);
    for (size_t i = 0; i < k; i++) {
        cin >> v[i];
    }
    cin >> target;

    pair<int, int> bords = exponential_search(v, target);
    //binary search
    int left = bords.first;
    int right = bords.second;
    while(left <= right) {
        int middle = left + (right - left)/2;
        if (v[middle] == target) {
            cout << bords.first << ' ' << bords.second <<'\n';
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
        cout << left - 1 << ' ' << right + 2 <<'\n';
    }

    return 0;
}