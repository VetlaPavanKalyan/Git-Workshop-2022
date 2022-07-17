#include<bits/stdc++.h>
using namespace std;
int lCS(char*,char*,int,int);
int main()
{
    int m,n;
    char a[100],b[100];
    cout<<"Enter 1st String :"<<endl;
    cin>>a;
    cout<<"Enter 2nd string:"<<endl;
    cin>>b;
    m=strlen(a);
    n=strlen(b);
    int t=lCS(a,b,m,n);
    cout<<"Length of the common String is: "<<t<<endl;
    return 0;
}
int lCS(char* a,char* b,int m,int n)
{
    int l[m+1][n+1],t,i,j,x,y;
    vector <char> v;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                l[i][j]=0;
            }
            else if (a[i-1]==b[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
            }
            else
            {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    i=m;
    x=m;
    j=n;
    y=n;
    cout<<"Longest Common String is : ";
    while(l[i][j]>0)
    {
        if(l[i][j]==l[i-1][j])
        {
            i--;
            continue;
        }
        else if(l[i][j]==l[i][j-1])
        {
            j--;
            continue;
        }
        else if(l[i][j]==l[i-1][j-1]+1)
        {
            x--;
            y--;
            v.push_back(a[x]);
            i--;
            j--;
        }
    }
    for(i=v.size();i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return l[m][n];
}