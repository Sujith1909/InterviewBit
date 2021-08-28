int Solution::lis(const vector<int> &A) 
{
    int n = A.size();

    int dp[n];
    dp[0] = 1;
    for(int i =1;i<n;i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    return *max_element(dp,dp + n);
}
