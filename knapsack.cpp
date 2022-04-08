//
// Created by neha2 on 19-01-2022.
//
/**
 * Lessons:
 * 1. matrix initialisation of row and column, there seems a confusion what should be rows and what shpuld be column , fix it first and then fill onw row and column
 * 2. according to row and column fixed in step 1 above, change the recurrence accordingly
 * 3. start from 1 not from 0, if 0 is already covered in step 1
 * 4. check your matrix original solution, what to return.
 */
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> values, vector<int> weight, int W);

int main() {
    vector<int> values = {10, 15, 40};
    vector<int> weight({1, 2, 3});
    int W = 6;
    int max_value = knapsack(values, weight, W);
    cout << "max value obtained is " << max_value << endl;
    return 0;
}

int knapsack(vector<int> values, vector<int> weight, int W) {
    /**
     * x(I:) rest of items starting from i
     * w weight
  * x(i,w)=max { vi+ x(i+1, w-wi) if wi<w,
  *              x(i+1, w)
  *             }
  * x(n, x)=0; for all x, no item left
  * x(x,0)=0; for all x, knapsack full or no weight left
  */
    int N = weight.size();
    vector<int> X;
    //columns: values N => X(x, N)=0; 0<=x<=W
    //rows: weight W => X(0, x)=0; 0<=x<=N-1
    vector<vector<int>> matrix(W + 1, vector<int>(N + 1, -INFINITY));
    for (int x = 0; x < N; x++) matrix[0][x] = 0;//check twice
    for (int x = 0; x <= W; x++)matrix[x][N] = 0;
    for (auto x: matrix) {
        for (int v: x) {
            cout << " " << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int w = 1; w <= W; w++) { //Weight in increasing order ( hint, you initialised weight from 0)
        for (int v_i = N - 1; v_i >= 0; v_i--) { //values in decreasing order (hint you initialised values for N)
            int a = -INFINITY;
            if (weight[v_i] <= w)//V. Imp, I forgot to update the weight w-w_i in first attempt
                matrix[w][v_i] = max({matrix[w - weight[v_i]][v_i + 1] + values[v_i], matrix[w][v_i + 1]});
            else
                matrix[w][v_i] = matrix[w][v_i + 1];
        }
    }
    cout << "matrix after fill is" << endl;
    for (auto x: matrix) {
        for (int v: x) {
            cout << v << "  ";
        }
        cout << endl;
    }
    return matrix[W][0]; //Imp check it twice
}
