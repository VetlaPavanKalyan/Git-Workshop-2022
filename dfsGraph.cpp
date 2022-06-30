#include<bits/stdc++.h>
using namespace std;
int reach[100]={ 0 },a[100][100]={ 0 },n;
void dfs(int v)
{
    reach[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i] && !reach[i])
        {
            cout<<v<<" -> "<<i<<endl;
            dfs(i);
        }
    }
}


int main()
{
    int c=0;
    cout<<"Enter no. of nodes : ";
    cin>>n;
    cout<<"Enter Adjacency Matrix : "<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<endl;
    dfs(1);
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(reach[i])
            c++;
    }
    if(c==n)
    {
        cout<<"The Graph is Connected";
    }
    else
    {
        cout<<"The Graph is not connected";
    }
    return 0;
}