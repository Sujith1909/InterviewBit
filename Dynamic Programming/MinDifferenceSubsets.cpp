int Solution::solve(vector<int> &A) {
    int n = A.size();
    int totalsum = 0;
    for(int i=0;i<n;i++)
    totalsum += A[i];
    
     int dp[n+1][totalsum];
     
     for(int i=0;i<totalsum+1;i++)
     dp[0][i] = 0;
     
     for(int i=0;i<n+1;i++)
     dp[i][0] = 1;
     
     for(int i=1;i<n+1;i++)
     for(int j=0;j<totalsum+1;j++)
     {
         if(A[i-1]<=j)
         dp[i][j] = dp[i-1][j-A[i-1]] | dp[i-1][j];
         else
         dp[i][j] = dp[i-1][j];
     }
     
     int ans = INT_MAX;

     for(int i=0;i<=totalsum/2;i++)
     {
         if(dp[n][i] == 1)
         ans = min(ans ,(totalsum - i*2));
     }
     return ans;
}
