#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;
pair<int,char> matriz[12][12];
int bordebajo,bordederecho;

pair<int,int> solve(int start){
    int columna=start;
    int fila = 0;
    int contSalida=0;
    int contCiclo=0;
    pair<int,char> posActual= matriz[fila][columna];
    bool ciclo=false;
    while ( (fila>=0 && fila<bordebajo) && (columna>=0 && columna<bordederecho) && (!ciclo) ){
        char direccion = matriz[fila][columna].second;
        matriz[fila][columna].first+=1;
        if (matriz[fila][columna].first==1) {
            contSalida++;
        }
        else {
            if (matriz[fila][columna].first==2){
                contCiclo++;
            }
            else {
                ciclo=true;
                contSalida=contSalida-contCiclo;
            }
        }
        if (direccion=='N')fila--;
        if (direccion=='S')fila++;
        if (direccion=='W')columna--;
        if (direccion=='E')columna++;
    }

    return make_pair(contSalida,contCiclo);
}

int main(){
int rows,column,start;
while(1){
cin >>rows >> column >> start;
if (rows == 0) return 0;
bordebajo=rows;
bordederecho=column;

for (int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            pair <int,char> ini = make_pair(0,'X');
            matriz[i][j]=ini;
        }
}
for(int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            char cadena;
            cin >> cadena;
            matriz[i][j]= make_pair(0,cadena);
        }
}

pair<int,int> rpt = solve(start-1);

if (rpt.second==0){
    cout <<rpt.first<<" step(s) to exit"<<endl;
}
else{
    cout <<rpt.first<<" step(s) before a loop of "<<rpt.second<<" step(s)"<<endl;
}


}
return 0;
}
