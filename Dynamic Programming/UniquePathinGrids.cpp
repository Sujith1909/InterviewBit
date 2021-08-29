int Solution::uniquePathsWithObstacles(vector<vector<int> > &A)
{
    int m = A.size();
    int n = A[0].size();

    int dp[m][n];

    // base case 
    if(A[0][0] == 1) return 0;
    dp[0][0] = 1;
    // first row i.e i = 0
    for(int j =1;j<n;j++)
    {
        if(A[0][j] == 1) dp[0][j] = 0;
        else
        {
            dp[0][j] = dp[0][j-1];
        }
    }
    // first coloumn
    for(int i =1;i<m;i++)
    {
        if(A[i][0] == 1) dp[i][0] = 0;
        else
        {
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i =1;i<m;i++)
    {
        for(int j = 1;j<n;j++)
        {
            if(A[i][j] == 1) dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];

}
