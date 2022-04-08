//
// Created by neha2 on 19-01-2022.
//
using namespace std;

#include <bits/stdc++.h>

int main() {
    int L = 8;
    vector<int> prices = {0, 3, 5, 8, 9, 10, 17, 17,
                          20}; //prices(9) and then push back pushes element after 9 0s in vector.
//    string p = "0 3   5   8   9  10  17  17  20";
//    stringstream ps(p);
//    int pr = 0;
//    int length = 0;
//    while (ps >> pr) {
//        cout << "length " << length << " price " << pr << endl;
//        prices.push_back(pr);
//        length++;
//    }

    cout << "prices and length are " << endl;
    for (auto p: prices) {
        cout << p << " ";
    }
    cout << endl;
    vector<int> X(L + 1, -INFINITY);
    /**
     * X(l) where 0<=l<=L
     * X(l)=max{ price(p)+ X(l-p) where 1<=p<=l};
     * final solution X(L)
     * Example of problem more suited for prefix
     */
    X[0] = 0;
    map<int, int> parent_pointers;
    for (int l = 1; l <= L; l++) {
        int max = -INFINITY;
        int p_max = -1;
        for (int p = 1; p <= l; p++) {
            int value = prices[p] + X[l - p];
            if (max < value) {
                max = value;
                p_max = p;
            }
        }
        X[l] = max;
        parent_pointers[l] = p_max;

    }
    cout << "Prices are as follows " << endl;
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, "( "));
    cout << endl;
    cout << "The rod of length " << L << " can be cut to get the maximum price " << *(X.end() - 1) << endl;
    cout << "The cuts are as follows " << endl;
    int b = L;
    int a = 0;
    while (b > 0) {
        cout << "length " << b << " ";
        int local_a = parent_pointers[b];
        a = a + local_a;
        cout << "cut " << local_a << " ";
        b = L - a;
    }
    cout << endl;

    return 0;

}