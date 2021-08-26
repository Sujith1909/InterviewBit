int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i,j,Max=0;
    for(i=0;i<A.size();i++)Max=max(Max,A[i]);
    int dp[Max+1];
    dp[0]=0;
    for(i=1;i<=Max;i++)
    {
        dp[i]=INT_MAX;
        for(j=0;j<B.size();j++)
        {
            if(i>=B[j])dp[i]=min(dp[i-B[j]]+C[j],dp[i]);
        }
    }j=0;
    for(i=0;i<A.size();i++)j=j+dp[A[i]];
    return j;
}
