bool valid(int i, int j, int N, int M){
    return (i<N && i>=0 && j<M && j>=0);
}

int Solution::solve(vector<vector<int> > &A) {
    // every element of dp array is the len of longest path from 0,0 to that point
    // can move either down or right
    int N = A.size();
    int M = A[0].size();
    vector<vector<int>> dp(N, vector<int>(M,-1));
    //max_len = 0;
    dp[0][0] = 1;
    // first row
    for(int j = 1; j<M; j++){
        if(A[0][j] > A[0][j-1]) dp[0][j] = dp[0][j-1] + 1;
    }
    // first col
    for(int i = 1; i<N; i++){
        if(A[i][0] > A[i-1][0]) dp[i][0] = dp[i-1][0] + 1;
    }
    
    for(int i = 1; i<N; i++){
        for(int j = 1; j<M; j++){
            // check top and left
            if(dp[i-1][j]==-1 && dp[i][j-1]==-1) return -1; // no scope of getting val 
            // in bottom rightmost cell
            
            if(A[i][j] > A[i-1][j] || A[i][j] > A[i][j-1]){
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
    }
    if(dp[N-1][M-1] == 0) return -1;
    return dp[N-1][M-1];
    
}