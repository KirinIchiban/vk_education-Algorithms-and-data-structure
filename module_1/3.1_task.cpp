//версия с итераторами
// #include <iostream>
// #include <vector>
// using namespace std;
// using iter = vector<int>::iterator;

// int main() {
//     int k;
//     cin >> k;
//     vector<int> v(k);
//     for (size_t i=0; i < k; i++) {
//         cin >> v[i];
//     }
//     iter right = v.end();

//     for (size_t i = 0; i < v.size(); ) {  
//         if (v[i] == 0 && (v.begin() + i != right)) {
//             v.erase(v.begin() + i);  
//             v.push_back(0); 
//             i--;         
//         } else {
//             i++;
//         }
//     }

//     for (auto x: v) {
//         cout << x << ' ';
//     }

//     return 0;
// }


//версия со стандартными операциями над вектором
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int k;
    cin >> k;
    deque<int> d;
    vector<int> v(k);
    for (size_t i=0; i < k; i++) {
        cin >> v[i];
    }

    for (size_t i = v.size(); i != 0; i--) {  
        if (v[i-1] == 0) {
            d.push_back(0); 
        } else {
            d.push_front(v[i-1]);
        }
    }

    for (auto x: d) {
        cout << x << ' ';
    }

    return 0;
}
