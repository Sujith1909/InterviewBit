int Solution::longestSubsequenceLength(const vector<int> &A) {
    // aka Longest Bitonic Subsequence(LBS)
    // create Longest Inc Subseq(LIS) and Longest Dec Subseq(LDS)
    // LBS = max of LIS and LDS - 1
    int N = A.size();
    if(N == 0) return 0;
    vector<int> LIS(N, 1);
    vector<int> LDS(N,1);
    
    for(int i = 1; i<N; i++){
        for(int j = 0; j<i; j++){
            //standard LIS condition
            if((A[i] > A[j]) && (LIS[i] <= LIS[j])) LIS[i] = LIS[j] + 1;
        }
    }
    
    for(int i = N-2; i>=0; i--){
        for(int j = N-1; j>i; j--){
            //standard LDS condition
            if((A[i] > A[j]) && (LDS[i] <= LDS[j])) LDS[i] = LDS[j] + 1;
        }
    }
    
   int max = LIS[0] + LDS[0] - 1; 
   for (int i = 1; i < N; i++) 
     if (LIS[i] + LDS[i] - 1 > max) 
         max = LIS[i] + LDS[i] - 1; 
   return max; 
    
}