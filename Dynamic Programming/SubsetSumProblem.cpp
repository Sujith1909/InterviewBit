int Solution::solve(vector<int> &A, int B) {
    int n = A.size(); int sum = B;
    int dp[n+1][sum+1];
    // base case 
    
    for(int i = 0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(A[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}
