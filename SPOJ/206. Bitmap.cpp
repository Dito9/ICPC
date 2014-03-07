#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool mat[190][190];
int dist[190][190];
int X,Y;
int movx[4]={-1,0 ,0,1};
int movy[4]={0 ,-1,1,0};
queue < pair<int,int> > Q;

void bfs(){
    int x0,y0,x1,y1;
    pair <int,int> p,q;
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        x0=p.second;
        y0=p.first;
        for(int i=0;i<4;i++){
            x1 = x0 + movx[i];
            y1 = y0 + movy[i];
            if (x1<X and x1>=0 and y1<Y and y0>=0){
                if(dist[y1][x1]==-1) {
                    dist[y1][x1]=dist[y0][x0]+1;
                    q=make_pair(y1,x1);
                    Q.push(q);
                }
            }
        }
    }

}

int main(){
    int n;
    cin>>n;
    while (n--){
        while (!Q.empty()){
            Q.pop();
        }
        pair <int,int> p;
        memset(dist,-1,sizeof(dist));
        cin>>Y>>X;
        string val;
        for(int i=0;i<Y;i++){
            cin>>val;
            for(int j=0;j<X;j++){
                if(val[j]=='1'){
                    dist[i][j]=0;
                    p=make_pair(i,j);
                    Q.push(p);
                }
            }
        }

        bfs();
        for(int i=0;i<Y;i++){
            for(int j=0;j<X;j++){
                cout<<dist[i][j];
                if(j==X-1) cout<<endl;
                else cout<<" ";
            }
        }
    }

    return 0;
}
