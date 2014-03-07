#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool arregloprimos[110][110];
int n;
vector <int> arregloMax;
int maximo=0;
vector <int> arregloActual;
int maximoActual=0;


bool cumple(vector<int> arregloActual,int posicion){

    for (int i=0;i<arregloActual.size();i++){
        if (arregloprimos[arregloActual.at(i)][posicion]==1) return false;
    }
    return true;
}
void backtrack(vector<int> arregloActual,int posicion){

    if (posicion==n){

        if (maximoActual>maximo) {
                maximo=maximoActual;
                arregloMax.clear();
                for (int i=0;i<arregloActual.size();i++){
                arregloMax.push_back(arregloActual.at(i));
                }
        }

    }
    else {
        for (int i=0;i<2;i++){
           if (i==0){
           if (cumple(arregloActual,posicion+1)){
            arregloActual.push_back(posicion+1);
            maximoActual++;
            backtrack(arregloActual,posicion+1);
            arregloActual.erase(arregloActual.begin()+arregloActual.size()-1);
            maximoActual--;
           }
        }
        else{
            backtrack(arregloActual,posicion+1);
        }

        }

    }

}
int main(){

    int caso=0;
    int t;
    cin >>t;
    while (t--){
    memset(arregloprimos,0,sizeof(arregloprimos));
    arregloMax.clear();
    maximo=0;
    maximoActual=0;

    int m;
    cin >> n>>m;

    for (int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        arregloprimos[a][b]=1;
        arregloprimos[b][a]=1;
    }
    arregloActual.clear();

    backtrack(arregloActual,0);

    cout << maximo << endl;
    for(int i=0; i<arregloMax.size();i++){
            if (i) cout << " ";
        cout<< arregloMax.at(i);
    }
    cout <<endl;

}
return 0;
}




