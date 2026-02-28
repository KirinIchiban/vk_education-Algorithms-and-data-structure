#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    int K;
    cin >> K;
    if (K > N) {
        return 0;
    }
    const long long INF = numeric_limits<long long>::max();

    vector<vector<long long>> dpMax(N + 1, vector<long long>(K + 1, -INF));
    vector<vector<long long>> dpMin(N + 1, vector<long long>(K + 1, INF));

    dpMax[0][0] = dpMin[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        dpMax[i][0] = dpMin[i][0] = 1;

        for (int j = 1; j <= K; j++) {
            dpMax[i][j] = dpMax[i-1][j];
            dpMin[i][j] = dpMin[i-1][j];

            if (dpMax[i-1][j-1] != -INF) {
                long long p1 = dpMax[i-1][j-1] * a[i];
                long long p2 = dpMin[i-1][j-1] * a[i];

                dpMax[i][j] = max(dpMax[i][j], max(p1, p2));
                dpMin[i][j] = min(dpMin[i][j], min(p1, p2));
            }
        }
    }

    cout << dpMax[N][K] << endl;
    return 0;
}