int Solution::minimumTotal(vector<vector<int> > &A) 
{
    int n=A.size();
    int dp[n]={0};
    for(int i=0;i<n;i++) {
        for(int j=i;j>=0;j--) {
            if(j==0) dp[j]+=A[i][j];
            else if(i==j) dp[j]=A[i][j]+dp[j-1];
            else dp[j]=min(dp[j],dp[j-1])+A[i][j];
        }
    }
    int result=INT_MAX;
    for(int i=0;i<n;i++) if(result>dp[i]) result=dp[i];
    return result;
}
