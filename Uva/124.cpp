#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <ctime>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define sz size

using namespace std;

vector<int> solucion;
vector<string>vertices;
vector< vector <int> > listaAdyacencia;
map<string,int> mapa;
vector<int> gradosEntrada;


void dfs(int u){

     gradosEntrada[u]-=1;

     for (int i=0;i<listaAdyacencia.at(u).size();i++){
        gradosEntrada[listaAdyacencia.at(u).at(i)]--;
     }
     for (int i=0;i<gradosEntrada.size();i++){
        if (gradosEntrada[i]==0){
                solucion.push_back(i);
                dfs(i);
            }
     }
}


int main(){

    int valor;
    int caso=0;
    while (cin >> valor){
        caso++;
        solucion.clear();
        mapa.clear();
        gradosEntrada.clear();
        listaAdyacencia.clear();
        vertices.clear();

        for (int i=0;i<valor;i++) {vertices.push_back(" ");
        gradosEntrada.push_back(0);
        }
        for (int i=0;i<valor;i++){
            string bebida;
            cin >> bebida;
            vertices.at(i)=bebida;
            listaAdyacencia.push_back( vector< int >());
            mapa[bebida]=i;
        }
        int aristas;
        cin >> aristas;
        while (aristas--){
        string u,v;
        cin >> u>> v;
        listaAdyacencia[mapa[u]].push_back(mapa[v]);
        gradosEntrada[mapa[v]]+=1;
        }

        for (int i=0;i<gradosEntrada.size();i++){
            if (gradosEntrada[i]==0){
                solucion.push_back(i);
                dfs(i);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",caso);

        for (int i=0; i< solucion.size();i++){
            cout << vertices.at(solucion.at(i));
            if (i!=(int)(solucion.size()-1)) cout <<" ";
            else cout << "."<<endl;
        }
        cout <<endl;
    }



	return 0;
}

