//
// Created by neha2 on 14-03-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int> &seq) {
        int N = seq.size();
        cout << "original sequence" << endl;
        copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        vector<int> X(N + 1, -INFINITY);
        X[N] = 0;
        for (int l = N - 1; l >= 0; l--) {
            int max_j = 0, sumj = 0;
            for (int j = l + 1; j < N; j++) {
                if (seq[j] >= seq[l]) {
//                    max_j = max(max_j, X[j]);
                    sumj += X[j];
                    break;
                } else {
                    seq[l] = seq[j];
                    sumj += X[j];
                    break;
                }
            }
            X[l] = seq[l] + sumj;
        }
//    int overall_mx=*max(X.begin(), X.end()); this max is for int, not for vectors; if you pass iterators, it retunrs the iterator which is max.
        cout << "changed sequence" << endl;
        copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
//        return *max_element(X.begin(), X.end());
        return X[0];
    }
};

int main() {
    vector<vector<int>> test = {{1, 2, 3},
                                {1, 3, 2},
                                {2, 1, 3},
                                {2, 3, 1},
                                {3, 1, 2},
                                {3, 2, 1},
                                {1},
                                {2},
                                {3},
                                {1, 2},
                                {1, 3},
                                {1, 4},
                                {1, 5},
                                {3, 1},
                                {3, 2},
                                {3, 0},
                                {0}};
    Solution s;
    for (int i = 0; i < 17; i++) {
        int ans = s.solve(test[i]);
        cout << ans << endl;
    }
}
