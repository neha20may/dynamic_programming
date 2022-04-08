//
// Created by neha2 on 19-01-2022.
//
using namespace std;
#include <bits/stdc++.h>
/**
 * x(i,j) denotes longest subsequence of A[i:] and B[j:]
 * x(i,j)={1+x(i+, j+1), if ai=bj;
 * else
 * max(x(i, j+1), x(i+1,j))}
 * ans=x(0,0)
 * base cases x(|A|, j)=0 for any j
 * x(i, |B|)=0 fir any i ====> one of the strings is empty
 *
 * smaller problesm depend upom loarger probelms
 * so
 * topolofgical ordering==> decreasing i+j ==> decrease i first, then decrease j;
 *
 * A B X C D _
 * B       1 0
 * C       1 0
 * D     <-1 0
 *       ^              one from right and one from bottom
 *       |
 * - 0 0 0 0 0
 * @return
 */
int main(){
    return 0;
}
