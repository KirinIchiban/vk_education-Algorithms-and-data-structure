#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    bool have_cont = 0;
    cin >>k;
    vector<int> v(k);
    for (size_t i = 0; i < k; i++) {
        cin >> v[i];
    }

    for (size_t i = k - 1; i != 0; i--)
        if (v[i] % 2 == 0) {
            cout << v[i] <<'\n';
            have_cont = 1;
            break;
        }
    if (!have_cont) {
        cout << -1 <<'\n';
    }

    return 0;
}