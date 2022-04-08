//
// Created by neha2 on 19-01-2022.
//
using namespace std;

#include <bits/stdc++.h>

int edit_distance(string s1, string s2);

int main() {
    string s1 = "voldemort";
    string s2 = "dumbledore";
    int dist = edit_distance(s1, s2);
    cout<<"edit distance is "<<dist;
}

int edit_distance(string s1, string s2) {
    int N = s1.size(); //#column
    int M = s2.size();//#row
    vector <vector<int>> dist(M + 1, vector<int>(N + 1));
    /**
     * dist(N, M)=0;
     * dist(i, N)=i;
     * dist(M, j)=j;
     * dist(i,j)=min {
     *             dist(i+1, j)+delete i;
     *             dist(i, j+1)+insert j;
     *             dist(i+1, j+1)+replace i and j;
     * }
     * Goal= dist(0,0)
     * Initial matrix
     *   n e h a -
     * e 0 0 0 0 3
     * e 0 0 0 0 2
     * h 0 0 0 0 1
     * - 4 3 2 1 0
     *
     */
    //N= column =5
    //M row = 4
    dist[M][N] = 0;
    for (int j = 0; j < M; j++) {
        dist[j][N] = M - j; //(M-j is the siffix length)
    }
    for (int i = 0; i < N; i++)
        dist[M][i] = N - i;
    cout << "initial matrix" << endl;
    for (auto x: dist) {
        for (int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    //topological order , decreasing i-j;
    for (int col = N - 1; col >= 0; col--) {
        for (int r = M - 1; r >= 0; r--) {
//            cout << r << " " << col << endl;
//            cout<<s1[col]<<" "<<s2[r]<<endl;
            if (s1[col] == s2[r]) {
                dist[r][col] = dist[r + 1][col + 1];
            } else {
                int a = dist[r + 1][col + 1] + 1;
                int b = dist[r + 1][col] + 1;
                int c = dist[r][col + 1] + 1;
                dist[r][col] = min({a, b, c});
            }
        }
    }
    cout << "edit distance matrix" << endl;
    for (auto x: dist) {
        for (int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return dist[0][0];
}
