//#include<bits/stdc++.h>
#include<stdio.h>
#include<cstring >
#include<stdbool.h>

using namespace std;

struct point
{
    long r;
    long c;
} pt[3];

int dr[4]= {1,0,0,-1};
int dc[4]= {0,1,-1,0};
long counter,m,n,st,st1,st2,st3;;
bool flag[10][10];

void solve(int r, int c,int count)
{
    if( count==st1 && ( r!=pt[0].r && c!=pt[0].c ) ) return;
    if( count==st2 && ( r!=pt[1].r && c!=pt[1].c ) ) return;
    if( count==st3 && ( r!=pt[2].r && c!=pt[2].c ) ) return;

    if( r==pt[0].r && c==pt[0].c && count!=st1 ) return;
    if( r==pt[1].r && c==pt[1].c && count!=st2 ) return;
    if( r==pt[2].r && c==pt[2].c && count!=st3 ) return;

    if( count==st )
    {
        if( r==0&&c==1 )
            counter++;
        return;
    }

    for(int i=0; i<4; i++)
    {
        int x=r+dr[i],y=c+dc[i];
        if( x<m && y<n && x>=0 && y>=0 && !flag[x][y] )
        {
            flag[x][y]=true;
            solve(x,y,count+1);
            flag[x][y]=false;
        }
    }
}

int main()
{

    int i;
    long tc=1;

    while(cout<<"enter the size of grid"&& cin>>m>>n &&m+n)
    {
        memset(flag,false,sizeof(flag));
        flag[0][0]=true;
        counter=0;
        st=m*n;
        st1=st/4;
        st2=st/2;
        st3=3*st/4;
        printf("\n Enter the check points:");
        for(i=0; i<3; i++)
            scanf("%ld%ld",&pt[i].r,&pt[i].c);
        solve(0,0,1);
        printf("Case %ld: %ld\n",tc++,counter);
    }
    return 0;
}
