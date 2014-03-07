#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

int main(){
int cabeza=0;
int longitud=0;

vector<int> arreglo;
int f,ini;
cin >> f>>ini;
for (int i=0;i<ini;i++){
    int valor;
    cin >>valor;
    arreglo.push_back(valor);
    longitud++;
}

for (int i=0;i<f;i++){
    int accion;
    cin >>accion;
    if (accion==0){
     arreglo.push_back(0);
     longitud++;
    }
    if (accion==1){
     arreglo.push_back(1);
     longitud++;
    }
    if (accion==-1){

     while(longitud>0 && (arreglo.at(cabeza)<=longitud) ){
        longitud--;
        cabeza++;
     }
    }
}
if (longitud==0){
    cout << "Poor stack!"<<endl;
    return 0;
}
for (int i=(cabeza-1) ; i<arreglo.size();i++){
    cout<< arreglo.at(cabeza);
}
cout <<endl;

return 0;

}
