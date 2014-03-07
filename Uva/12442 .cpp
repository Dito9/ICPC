#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

pair<int, int> dp[50001];

vector< vector < int > > padres(50001);
vector <int> hijos(50001);
vector<int> ciclo(50001,0);
vector<int> hojas;
int ciclosTotales=1;
int dfs(int nodo){

    if (dp[nodo].first==0){
      dp[nodo].first=1;
      dp[nodo].second=1+dfs(hijos.at(nodo));

      if (dp[nodo].first>1) dp[nodo].second=ciclosTotales;

      else dp[nodo].second=1+dp[hijos.at(nodo)].second;

      return dp[nodo].second;
    }
    else {
        if (dp[nodo].first==1){

            dp[nodo].first=2;
            while ( dp[hijos.at(nodo)].first==1){
                nodo = hijos.at(nodo);
                dp[nodo].first=2;
                ciclosTotales++;
            }

            nodo=hijos.at(nodo);
            dp[nodo].first=3;
            while ( dp[hijos.at(nodo)].first==2){
                dp[nodo].second=ciclosTotales;
                nodo = hijos.at(nodo);
            }
            dp[nodo].first=2;
            dp[nodo].second=ciclosTotales;
        }
        else {
             if (dp[nodo].first>1) return dp[nodo].second;
        }
    }

return 0;

}
int maximoGlobal=0;
int rpt;
int main(){

    int test;
    cin >> test;
    int caso=0;
    while(test--){
        ciclosTotales=1;
        for (int i=0;i<hijos.size();i++){
            hijos[i]=-1;
        }
        for (int i=0;i<padres.size();i++){
            padres[i].clear();
        }
        hojas.clear();
        for (int i=0;i<50001;i++){
            dp[i]= make_pair(0,0);
        }
        caso++;
        maximoGlobal=0;

        int n;
        cin >> n;
        for (int i=0;i<n;i++){
        int padre,hijo;
        cin >> padre>>hijo;

        hijos.at(padre-1)=hijo-1;
        padres.at(hijo-1).push_back(padre-1);
        }

        for (int i=0;i<n;i++){
            if (padres.at(i).size()==0) hojas.push_back(i);

        }

        int solociclos=false;

        if (hojas.size()==0) solociclos=true;

        if (!solociclos)
        {
            cout << "solo ciclos"<<endl;

            int maximo=0;
            for (int i=0; i<hojas.size();i++){
             dp[hojas.at(i)].first=1;
             dp[hojas.at(i)].second = 1+dfs( hijos.at(hojas.at(i)));
             maximo=dp[hojas.at(i)].second;
             if (maximo>maximoGlobal){
                maximoGlobal=maximo;
                maximo=0;
                rpt = hojas.at(i);
            }
            else {
                    if (maximo==maximoGlobal){
                     int rpta=hojas.at(i);
                         if (rpta<rpt) rpt=rpta;
                    }
                }
          }
        }
        else {
                cout << "solo ciclos "<<endl;
            int maximo=0;
            for (int i=0;hijos.at(i)!=-1 ;i++){
                dp[i].first=1;
                dp[i].second=dfs( hijos.at(i));
                maximo=dp[i].second;
                 if (maximo>maximoGlobal){
                    maximoGlobal=maximo;
                    maximo=0;
                    rpt = i;
                    }
                else {
                    if (maximo==maximoGlobal){
                     int rpta=i;
                         if (rpta<rpt) rpt=rpta;
                    }
                }
            }
        }

    for (int i=0;hijos.at(i)!=-1;i++){
        cout << "dp["<<i<<"]: "<<dp[i].second<<endl;
    }
     cout <<"Case "<<caso<<": "<<rpt+1<< endl;
    }

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int est[50000+10];
int dis[50000+10];
int adj[50000+10];
int V,cicl;

void dfs_cicl(int v){
	if(dis[adj[v]]!=-1 and est[v]==0){
		dis[v]=dis[adj[v]]+1;
		est[v]++;
		return;
	}
	if(est[v]==0) cicl=0;
	if(est[v]==1) cicl++;
	if(est[v]==2) dis[v]=cicl;
	est[v]++;
	if(est[adj[v]]<=2) dfs_cicl(adj[v]);
	if(est[v]!=3) {
		dis[v]=dis[adj[v]]+1;
		est[v]=1;
		return;
	}
}

int main(){
	int N,a,b;
	scanf("%d",&N);
	int cas=1;
	while(N--){
		memset(est, 0,sizeof(est));
		memset(dis,-1,sizeof(dis));
		memset(adj,-1,sizeof(adj));
		scanf("%d",&V);
		for(int i=0;i<V;i++){
			scanf("%d %d",&a,&b);
			adj[a]=b;
		}
		for(int i=1;i<=V;i++){
			if(est[i]==0) {
				dfs_cicl(i);
			}
		}
		int ans=0, sol=-1;
		for(int i=1;i<=V;i++){
			if(dis[i]>ans) sol=i,ans=dis[i];
		}
		printf("Case %d: %d\n",cas,sol);
		cas++;
	}
	return 0;
}

*/

