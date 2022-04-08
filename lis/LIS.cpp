//
// Created by neha2 on 19-01-2022.
//

using namespace std;

#include <bits/stdc++.h>

int getLIS(vector<int> &seq);

void print(vector<stack<int>> &stacks);
void getLIS_patience_sort(vector<int> &seq);

int main() {
    vector<int> seq = {10, 9, 2, 5, 3, 7, 101, 18};
//    int lis = getLIS(seq);
//    cout << "LIS is " << lis << endl;
    getLIS_patience_sort(seq);

}

void getLIS_patience_sort(vector<int> &seq) {
    int n = seq.size();
    vector <stack<int>> stacks(n , stack<int>());
    vector<int> topStack(n, 100000);
    vector<int> pred(n);
    for (auto c: seq) {
        auto pos = lower_bound(topStack.begin(), topStack.end(), c);
        //lower bound returns the iterator where value is not less then the passed value c;
        int index = distance(topStack.begin(), pos);
        topStack[index]=c;
        stacks[index].push(c);
        pred[index] = index - 1;
    }
    cout << "longest increasing sequence is" << endl;
    print(stacks);
}

void print(vector<stack<int>> &stacks) {
    int count=0;
    for (auto st: stacks) {
        if(!st.empty())
            count++;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    cout << endl;
    cout<<"No pf piles "<<count<<endl;
}

int getLIS(vector<int> &seq) {
    /**
     * LIS; longest increasing subsequence
     * Sub problem: x(l) 0<=l<N; subsequence starts at l;
     * Relation: x(l)=max {  1+ x(j)}; where l<=j<N and x(j)<x(l)};
     * Topological order: j increasing, l decreasing
     * Base: X(N)=0
     * Original problem:X(0)***, Nope, return max(x(l))!
     */
    int N = seq.size();
    vector<int> X(N + 1, -INFINITY);
    X[N] = 0;
    for (int l = N - 1; l >= 0; l--) {
        int max_j = 0;
        for (int j = l + 1; j < N; j++) {
            if (seq[j] > seq[l])
                max_j = max(max_j, X[j]);
        }
        X[l] = 1 + max_j;
    }
//    int overall_mx=*max(X.begin(), X.end()); this max is for int, not for vectors; if you pass iterators, it retunrs the iterator which is max.
    return *max_element(X.begin(), X.end());
}
