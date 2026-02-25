#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, buf = 0;
    cin >>k;
    vector<int> v(k);
    for (size_t i = 0; i < k; i++) {
        cin >> v[i];
    }

    for (size_t i = 0; i < k; i++) {
        if (buf < v[i]) {
            buf = v[i];
        }
    }
    cout << buf << '\n';

    return 0;
}