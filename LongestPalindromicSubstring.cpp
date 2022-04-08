//
// Created by neha2 on 08-03-2022.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void print_table(vector<vector<bool>> &dp){
        for(auto row:dp){
            for(auto e:row)
                cout<<e<<" ";
            cout<<endl;
        }
    }
    string getLongestPalindrome(string s){
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int k=0; //one length substring
        pair<int, int> max=make_pair(0,0);
        for(int i=0;i<n-k;i++){
            dp[i][i+k]=true;
            max= make_pair(i,i);
        }
        cout<<" k= 0, length 1 substrings"<<endl;
        print_table(dp);
        k=1; //two length substring
        for(int i=0;i<n-k;i++){
            if(s[i]==s[i+k]) {
                max = make_pair(i, i + k);
                dp[i][i + k] = true;
            }
        }
        cout<<" k= 1, length 2 substrings"<<endl;
        print_table(dp);
        for(k=2; k<n;k++){
            for(int i=0;i<n-k;i++){
                if(s[i]==s[i+k])
                {
                    dp[i][i+k]=dp[i+1][i+k-1];
                    if(dp[i][i+k]==true){
                        max= make_pair(i, i+k);
                    }
                }
            }
            cout <<"k "<<k<<" substrign of length "<<k+1<<endl;
            print_table(dp);
        }
        int maxi=max.first;
        int maxj=max.second;
        string palindrome=s.substr(maxi, maxj-maxi+1);
        return palindrome;
    }
};
int main(){
    string test="geeksskeegsdvkvknb";
    Solution s;
    cout<<s.getLongestPalindrome(test);

}