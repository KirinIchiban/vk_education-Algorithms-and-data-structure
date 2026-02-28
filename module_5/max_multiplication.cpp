#include <iostream>
#include <vector>
#include <utility>
#define MAX(a, b) ((a) > (b) ? (a) : (b))  
#define MIN(a, b) ((a) < (b) ? (a) : (b))  
using namespace std;
#include <climits>
const long long INF = LLONG_MAX;


int main() {
    long long n, k, max = 0, ans = -INF;
    cin >> n;
    vector<vector<long long>> v(n,vector<long long>(n));
    vector<vector<long long>> v_min(n,vector<long long>(n));
    for (long long i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][1] = v[i][0];
        v_min[i][0] = v[i][0];
        v_min[i][1] = v[i][0];
    }
    cin >> k;
    if (k > n) {
        return 0;
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 2; j < n; j++) {
            v[i][j] = -INF;     
            v_min[i][j] = INF; 
        }
    }
    for (long long j = 2; j <= k; j++) {
        for (long long i = j - 1; i < n; i++) {
            if (i < j-1) {
                v[i][j] = -INF;
                v_min[i][j] = INF;
                continue;
            }
            v[i][j] = v[i-1][j];
            v_min[i][j] = v_min[i-1][j];

            if (v[i-1][j-1] != -INF) {

                long long a1 = v[i-1][j-1] * v[i][0];
                long long a2 = v_min[i-1][j-1] * v[i][0];

                v[i][j] = MAX(v[i][j], MAX(a1, a2));
                v_min[i][j] = MIN(v_min[i][j], MIN(a1, a2));
            }
        }
    }

    for (long long i = k-1; i < n; i++) {
        ans = MAX(ans, v[i][k]);
    }
    cout << ans << '\n';

    return 0;
}
