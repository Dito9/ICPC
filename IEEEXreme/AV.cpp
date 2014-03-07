#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int y,x;
vector <string> mat;
vector <vector < pair<int,int> > > visit;
pair<int,int> ini,fin,p,q;
int vy[8]={-1,-1,-1,0,0,1,1,1};
int vx[8]={-1,0,1,-1,1,-1,0,1};

void bfs(){
    visit[ini.first][ini.second].first= 0;
    visit[ini.first][ini.second].second= 0;
    queue < pair <int,int> > Q;
    Q.push(ini);

    while (!Q.empty()){
        //cout<<"hola"<<endl;
        p=Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            int ny= p.first+vy[i];
            int nx= p.second+vx[i];
            if (ny>=0 and ny<y and nx>=0 and nx<x){
                if (visit[ny][nx].first==-1){
                    int t=visit[p.first][p.second].first;
                    int a=visit[p.first][p.second].second;
                    if(i==1 or i==3 or i==4 or i==6) {t+=2;a+=2;}
                    else {t+=3;a+=3;}
                    if(a<=10){
                        visit[p.first][p.second].first=t;
                        if(mat[ny][nx]=='+') visit[ny][nx].second=0;
                        else visit[ny][nx].second=a;
                        if(mat[ny][nx]=='S') break;
                        q=make_pair(ny,nx);
                        Q.push(q);
                    }
                }
            }

        }
    }
}

int main(){

    cin>>y>>x;
    string s;
    vector <pair <int,int> > aux;
    pair<int,int> r=make_pair(-1,0);
    for(int i=0;i<x;i++) aux.push_back(r);
    for(int i=0;i<y;i++) {
        cin>>s;

        if (s.find('S')!=-1) ini=make_pair(i,s.find('S'));
        if (s.find('E')!=-1) fin=make_pair(i,s.find('E'));
        mat.push_back(s);
        visit.push_back(aux);
    }
    bfs();
    cout<<ini.first<<" "<<ini.second<<endl;
    cout<<fin.first<<" "<<fin.second<<endl;
    cout<<visit[fin.first][fin.second].first<<endl;
    return 0;
}
