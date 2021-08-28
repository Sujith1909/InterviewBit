int Solution::solve(vector<vector<int> > &A) {
int r = A.size();
for(int i=1;i<r;i++)
    for(int j=0;j<r;j++)
        A[i][j] += max(A[i-1][j], j>=1?A[i-1][j-1]:0);
return *max_element(A[r-1].begin(), A[r-1].end());}