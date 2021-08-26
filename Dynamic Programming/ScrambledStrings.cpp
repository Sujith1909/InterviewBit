map<string,bool>mp;

bool soln(string A,string B)

{

    int n=A.length();

    int m=B.length();

    if(A==B) return 1;

    if(A.length()<=1) return 0;

    string key=A;

    key.push_back('_');

    key.append(B);

    if(mp.find(key)!=mp.end()) return mp[key];

    bool flag=false;

    int len=A.length();

    for(int i=1;i<A.length();i++)
    {

        if((soln(A.substr(0,i),B.substr(0,i))&&soln(A.substr(i),B.substr(i)))||(soln(A.substr(0,i),B.substr(len-i))&&soln(A.substr(i),B.substr(0,len-i)))) flag=true;

    }
    mp[key]=flag;
    return mp[key];

}

int Solution::isScramble(const string A, const string B)

{

    mp.clear();

    return soln(A,B);
}