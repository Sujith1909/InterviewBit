int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    for(int i = n-1;i >=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            if(i == n-1 && j == m-1){
                dp[i][j] = A[i][j] >= 0 ? 1 : abs(A[i][j])+1;
            }else if(i == n-1){
                dp[i][j] = max(dp[i][j+1] - A[i][j],1);
            }else if(j == m-1){
                dp[i][j] = max(dp[i+1][j] - A[i][j],1);
            }else{
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - A[i][j],1);
            }
        }
    }
    return dp[0][0];
}
