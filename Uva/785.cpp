#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

char arreglo[100][100];
vector <string> matriz;

char pared(){

for (int i=0; i<matriz.size();i++){
    for (int j=0;j<matriz.at(i).size();j++){
        if ( matriz.at(i).at(j)!=' ') return matriz.at(i).at(j);
    }
  }
}

void llenar(char caracter, int i,int j,char pare){

    for (int b=j;b>=0;b--){
        if ( matriz[i][b]==pare) break;
        else matriz[i][b]=caracter;
    }

    for (int b=j;b< matriz.at(i).size();b++){
        if ( matriz[i][b]==pare) break;
        else matriz[i][b]=caracter;
    }

    for (int a=i;a>=0;a--){
        if ( matriz[a][j]==pare) break;
        else matriz[a][j]=caracter;
    }

    for (int a=i;a<matriz.size();a++){
        if ( matriz[a][j]==pare) break;
        else matriz[a][j]=caracter;
    }
    return;
}

int main(){

int flag=false;
while(1){
    matriz.clear();
    while (1){
    string linea;
    getline(cin,linea);
    if (cin.eof()) {
        flag=true;
        break;
    }
    matriz.push_back(linea);
    if (linea.size()>0) if (linea.at(0)=='_') break;
    }

    if (flag) break;

    char pare = pared();

    char pintar;
    for (int x=0;x<10;x++){
    for (int i=0;i<matriz.size();i++){
    for (int j=0;j<matriz.at(i).size();j++){

    if (matriz.at(i).at(j)!=' ' && matriz.at(i).at(j)!=pare && matriz.at(i).at(j)!='_'){
        pintar = matriz.at(i).at(j);
        llenar(pintar,i,j,pare);
      }
    }
   }
    for (int i=matriz.size()-1;i>=0;i--){
    for (int j=matriz.at(i).size()-1;j>=0;j--){

    if (matriz.at(i).at(j)!=' ' && matriz.at(i).at(j)!=pare && matriz.at(i).at(j)!='_'){
        pintar = matriz.at(i).at(j);
        llenar(pintar,i,j,pare);
      }
    }
   }
}
    for (int i=0;i<matriz.size();i++){
    cout << matriz.at(i);
    cout <<endl;
    }


}
return 0;

}
