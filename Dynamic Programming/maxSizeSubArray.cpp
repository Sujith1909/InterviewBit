int Solution::solve(vector<vector<int> > &A) {
    int m=A.size();if(m==0)return 0;
    int n=A[0].size(),ans=0;
    vector< vector<int> >dp(m+1,vector<int>(n+1,0));
       for(int i = 0; i < m; i++)  
        {dp[i][0] = A[i][0]; ans=max(ans,dp[i][0]);}  
    for(int j = 0; j < n; j++)  
        {dp[0][j] = A[0][j];  ans=max(ans,dp[0][j]);}
     for(int i= 1; i < m; i++)  
    {  
        for(int j = 1; j < n; j++)  
        {  
            if(A[i][j] == 1)  
                dp[i][j] = min(dp[i][j-1],min( dp[i-1][j],  
                                dp[i-1][j-1])) + 1;  
            else
                dp[i][j] = 0;
                ans=max(ans,dp[i][j]);
        }  
    }  
    return ans*ans;
}
