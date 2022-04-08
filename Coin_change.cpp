//
// Created by neha2 on 19-01-2022.
//

using namespace std;

#include <bits/stdc++.h>

int coin_change(int n, vector<int> &denom);

int main() {
    int A = 3;
    vector<int> denominations = {2};
//get fewest coins possible for the amount
    int C = coin_change(A, denominations);
    cout << "minimum no of coins needed " << C;
    return 0;
}

int coin_change(int A, vector<int> &denom) {
    /**
     * The money, money needs to decrease. check all coins.
     * Note: check all brute-force sub problems.
     * X(money)={ 1+min(        X(money-coins(1)), if money>=coin_i
     *                          X(money-coins(2)),
     *                          X(money-coins(3)),
     *                          X(money-coins(n-1)),
     *                          X(money-coins(n))
     *                     )
     *           }
     * Note: you didnt decrease coins, so coins can be repeated as many times. hence one D table not 2D table.
     * X(money, 0)= no coin  ,0
     * X(0, coins)= 0, no money no solution
     * or X(0,0)=0
     *
     */
    int N = denom.size();
    vector <int > min_coins(A+1, -1);
    //Note:  if you put +INFINITY as intial value, the +1 makes it -1 in the loop and all hell break loose.
    min_coins[0]=0;
    for (int a = 1; a <= A; a++) {
        for(int c=0;c<N; c++)
            if(a>=denom[c]){
                int x=min_coins[a];
                int y=min_coins[a-denom[c]];
                min_coins[a]=1+min(x,y);
            }

    }
    return min_coins[A];
}
