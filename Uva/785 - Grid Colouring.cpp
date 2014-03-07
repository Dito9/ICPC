#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector <string> in;

int movx[4]={-1,0 ,0,1};
int movy[4]={0 ,-1,1,0};
queue < pair<int,int> > Q;
char pared=' ';

void bfs(){
    for(int i=0;i<in.size();i+6){
        for(int j=0;j<in[i].size();j++){
            if(in[i][j]!='X' and in[i][j]!=' '){
                char c=in[i][j];
                queue <pair <int,int> > Q;
                pair <int,int> p,q;
                p=make_pair(i,j);
                Q.push(p);
                while(!Q.empty()){
                    p=Q.front();
                    Q.pop();
                    int x0,y0,x1,y1;
                    x0=p.second;
                    y0=p.first;
                    for(int i=0;i<4;i++){
                        x1 = x0 + movx[i];
                        y1 = y0 + movy[i];
                        if (y1>=0 and y1<in.size() and x1<in[y1].size() and x1>=0){
                            if(in[y1][x1]!=pared) {
                                in[y1][x1]=c;
                                q=make_pair(y1,x1);
                                Q.push(q);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    char c=getchar();
    while(c!=EOF){
        string s="";
        while(c!='\n'){
            s+=c;
            if(pared==' ' and c!=' ') pared=c;
        }
        if(s[0]=='_'){
            cout<<"hola"<<endl;
            bfs();
            for(int i=0;i<in.size();i++){
                cout<<in[i]<<endl;
            }
            cout<<s<<endl;
            in.clear();
        }
        else in.push_back(s);
        c=getchar();
    }
    return 0;
}
