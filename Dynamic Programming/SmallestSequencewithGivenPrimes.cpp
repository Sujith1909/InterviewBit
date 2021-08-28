vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    ans.push_back(1);
    int i=0,j=0,k=0;
    while(D--){
        int x=min(ans[i]*A,min(ans[j]*B,ans[k]*C));
        if(x==ans[i]*A)
        i++;
        if(x==ans[j]*B)
        j++;
        if(x==ans[k]*C)
        k++;
        ans.push_back(x);
    }
    ans.erase(ans.begin());
    return ans;
}
