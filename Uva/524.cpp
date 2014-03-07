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

bool arregloprimos[32];
int n;
vector <int> arreglo;

bool esPrimo(int a){

     if (arregloprimos[a]==1) return true;
     else return false;

}

bool cumple(vector<int> arreglo,int posicion){

        if (posicion==n-1){
            if ( esPrimo(  arreglo.at(posicion)+1 ) && esPrimo(  arreglo.at(posicion)+arreglo.at(posicion-1) ) ) return true;
        }

        else{
             if (esPrimo(  arreglo.at(posicion)+arreglo.at(posicion-1) ) ) return true;

        }

        return false;

}
void backtrack(vector<int> arreglo,int posicion){

    if (posicion==n){

        for (int i=0;i<n;i++){
                if (i) cout<<" ";
            cout << arreglo.at(i);
        }
        cout <<endl;
    }
    else {
        for (int i=2;i<=n;i++){
           int flag=1;
           for (int j=0;j<arreglo.size();j++){
                if (arreglo.at(j)==i) flag=0;
           }
           if (flag==1){
           arreglo.push_back(i);
           if (cumple(arreglo,posicion)){
            backtrack(arreglo,posicion+1);
            arreglo.erase(arreglo.begin()+posicion);
           }
           else{
            arreglo.erase(arreglo.begin()+posicion);
           }
           }
        }

    }


}
int main(){
    memset(arregloprimos,1,sizeof(arregloprimos));

    for (int i=2;i<=6;i++){
            if ( arregloprimos[i])
               for (int j=i;j*i<32;j++){
                arregloprimos[i*j]=0;
        }
    }
    int caso=0;
    while (cin >>n){
    caso++;
    if (caso!=1){
        cout <<endl;
    }

    arreglo.clear();
    arreglo.push_back(1);
    cout<< "Case "<<caso<<":"<<endl;
    backtrack(arreglo,1);

}

return 0;

}




