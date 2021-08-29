int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int maxar = 0;
    //building histogram for each row upto that row 
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j])    A[i][j] += A[i-1][j];
    //calculating max area of histogram for each row
    for (int i = 0; i < n; i++) {
        stack<int> l, r;
        vector<int> lv(m), rv(m);
        //previous smaller element
        for (int j = 0; j < m; j++) {
            while (!l.empty() && A[i][l.top()] >= A[i][j])  l.pop();
            lv[j] = (!l.empty()) ? l.top() : -1;
            l.push(j);
        }
        //next smaller element
        for (int j = m-1; j >= 0; j--) {
            while (!r.empty() && A[i][r.top()] >= A[i][j])  r.pop();
            rv[j] = (!r.empty()) ? r.top() : m;
            r.push(j);
        }
        //max area calculation
        for (int j = 0; j < m; j++)
            maxar = max(maxar, A[i][j] * (rv[j] - lv[j] - 1));
    }
    return maxar;
}