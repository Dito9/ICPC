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

vector< vector < int> > matriz;

vector<int> usados;

int main(){
    int nodos;
    int aristas;
    cin >>nodos;
    cin >>aristas;

    for (int i=0;i<nodos;i++){
        matriz.push_back( vector<int>() );
        usados.push_back(0);
        for (int j=0;j<nodos;j++){
            matriz.at(i).push_back(0);
        }

        matriz.at(i).push_back(0); //entran
        matriz.at(i).push_back(0); //salen
    }
    int centro;
    int maximo=0;
    for (int i=0;i<aristas;i++){
        int u,v;
        cin >> u>>v;
        u=u-1;
        v=v-1;
        matriz.at(u).at(v)=1;
        matriz.at(u).at(nodos+1)+=1;
        matriz.at(v).at(nodos)+=1;
        if (matriz.at(u).at(nodos+1)>maximo){
            maximo= matriz.at(u).at(nodos+1);
            centro=u;
        }
    }
    int tengo=aristas;
    int puesto=0;
    int quitado;
    int optimo = (3*nodos)- 2;

    for (int i=0; i<nodos;i++){
        if (i!=centro){
        if (matriz.at(i).at(centro)==0){
            puesto++;
        }
        if (matriz.at(centro).at(i)==0){
            puesto++;
        }
        }
        bool flag=true;

        for (int j=0;j<nodos;j++){

        if (i!=j) {
            if (matriz.at(i).at(j)==1 && matriz.at(j).at(i)==1 && usados.at(i)!=1 && usados.at(j)!=1){
                usados.at(i)=1;
                usados.at(j)=1;
                flag = false ;
                break;
            }
        }
        }

        if ( (usados.at(i)!=1) && (matriz.at(i).at(i)==0) ) puesto++;

    }

    quitado = tengo+puesto-optimo;

    cout << (quitado+puesto)<<endl;


	return 0;

}
