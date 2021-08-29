int Solution::minPathSum(vector<vector<int> > &A)
{
    // min path
    int m = A.size();
    int n = A[0].size();
    int dp[m][n];
    //dp[i][j] contains the min path from 0,0 to i,j

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0) dp[0][0] = A[i][j];
            else if(i == 0) dp[i][j] = dp[0][j-1] + A[i][j];
            else if(j == 0) dp[i][j] = dp[i-1][0] + A[i][j];
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j];
            }
        }
    }

    return dp[m-1][n-1];
}
