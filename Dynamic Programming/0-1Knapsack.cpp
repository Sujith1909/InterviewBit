int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    int dp[n+1][C+1];
    for(int i =0;i<=n;i++)
    {
        for(int j =0;j<=C;j++)
        {
            if(i ==0 || j == 0) dp[i][j] = 0;

            else if(B[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j], A[i-1] + dp[i-1][j-B[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][C];
}
