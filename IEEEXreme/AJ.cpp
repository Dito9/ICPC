#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector< vector < int > > adyEn;

vector< vector < int > > adySal;

vector < int > nivel;


vector < int > visit;
int minlvl=0;

void fun(int v){
    for(int i=0;i<adyEn[v].size();i++){
        if(visit[adyEn[v][i]]==-1) {
            visit[adyEn[v][i]]=1;
            nivel[adyEn[v][i]]=nivel[v]+1;
            fun(adyEn[v][i]);
        }
    }
    for(int i=0;i<adySal[v].size();i++){
        if(visit[adySal[v][i]]==-1) {
            visit[adySal[v][i]]=1;
            nivel[adySal[v][i]]=nivel[v]-1;
            if(nivel[adySal[v][i]]<minlvl) minlvl=nivel[adySal[v][i]];
            fun(adySal[v][i]);
        }
    }
}

int main() {

int vertices;
cin >> vertices;
vector < int > aux;


for (int i = 0; i<vertices; i++){
    adyEn.push_back(aux);
    adySal.push_back(aux);
    nivel.push_back(0);
    visit.push_back(-1);
}
int a,b;
for (int i = 0 ; i < vertices - 1;i++ ){
    cin >> a>>b;
    adyEn[a-1].push_back(b-1);
    adySal[b-1].push_back(a-1);
}

visit[0]=1;

fun(0);
for(int i=0;i<vertices;i++){
    nivel[i]-=minlvl;
}
//cout<<"hola"<<endl;
vector <vector <int> > sol(vertices);
for(int i=0;i<vertices;i++){
    sol[nivel[i]].push_back(i);
}
vector <int> rpta;
for(int i=1;i<vertices;i++){
    if(sol[i].size()==1) cout<<sol[i][0]+1<<endl;
}
return 0;
}
