#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int k, elem, el;
    cin >> k;
    vector<int> v;
    queue<int> q; 
    for (size_t i = 0; i < k; i++) {
        cin >> el;
        q.push(el);
    }
    cin >> elem;

    while (!q.empty()) {
        if (q.front() != elem) {
            int buf = q.front();
            v.push_back(buf);
            q.pop();
        }
        else if (q.front() == elem) {
            q.pop();
        }
    }

    for (auto x: v) {
        cout << x <<' ';
    }
    cout <<'\n';

    return 0;
}