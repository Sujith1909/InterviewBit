int Solution::solve(string A) {
    string B = A;
    reverse(A.begin(),A.end());
    int n=A.length();
int m=B.length();
int dp[n+1][m+1];


for(int i=0;i<=n;i++)
{
    for(int j=0;j<=m;j++)
    {
        if(i==0 || j==0)
        {
            dp[i][j]=0;
        }
        else if(A[i-1]==B[j-1])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
return dp[n][m];
}
