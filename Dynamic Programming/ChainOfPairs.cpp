int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    vector<int> count(N, 1);
    for(int i = 1; i<N; i++){
        for(int j = 0; j<i; j++){
            if((A[i][0] > A[j][1]) && (count[i] < count[j]+1)) count[i] = count[j]+1;
        }
    }
    return *max_element(count.begin(), count.end());
}