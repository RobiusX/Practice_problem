#include<bits/stdc++.h>
using namespace std;

 string s1,s2;
int LCS (int i,int j)
{
    if (i==s1.length()||j==s2.length())
        return 0;
    if(s1[i]==s2[j])

        return 1 +LCS(i+1,j+1);

    else

        return max (LCS(i+1,j),
                   LCS(i,j+1));

}

int main()
{
    cout<<"enter 2 string:"<<endl;
    cin>>s1>>s2;
    cout<<"LCS: "<<LCS(0,0)<<endl;
return 0;
}
