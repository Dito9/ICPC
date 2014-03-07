#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

int Escuadrado(pair <int,int> inicio, pair<int,int> fin){

    if ( fin.first - inicio.first == fin.second - inicio.second  ) return 1;
    else return 0;

}

int EstaLleno(pair <int,int> inicio, pair<int,int> fin,vector<string> matriz){

    for ( int i = inicio.first; i<fin.first;i++){
        for (int j = inicio.second; j<fin.second;j++) {

            if (matriz.at(i).at(j)=='.') return 0;

        }

    }
    return 1;

}

int main ()
{
    int t;
    cin >> t;
    for (int i =0; i<t ; i++){

        vector<string> matriz;
        int n;
        cin >> n;

        for(int j=0;j<n;j++){
            string linea;
            cin >> linea;
            matriz.push_back(linea);
        }
        pair <int,int> inicio,fin;
        int primero=0;
        for (int b=0; b<n;b++){

            for ( int a=0; a<n;a++){

                char c =matriz.at(b).at(a);
                if ( (c=='#') && (primero==0) ){
                    //Primero que se encontro
                    primero=1;
                    inicio.first=b;
                    inicio.second=a;

                }
                if ( (c=='#') && (primero==1) ){

                    fin.first=b;
                    fin.second=a;
                }
            }
        }

        // Tenemos los 2 puntos de la diagonal

        if (  (Escuadrado(inicio,fin)==1) && (EstaLleno(inicio,fin,matriz)==1) ){
            cout << "Case #" << i+1 <<": YES" <<endl;
        }
        else {
            cout << "Case #" << i+1 <<": NO" <<endl;
        }
    }

    return 0;
}
