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
#include <cstring>
using namespace std;
int main(){
string cadena;

cin >>cadena;
int cantidad=0;
int cont=0;
int longitud=cadena.size();
for (int i=0;i<(int)cadena.size()-3;i++){
    if ( strcmp(cadena.substr(i,4).c_str() ,"bear")==0 ){
        int derecha = longitud-(i+3);
        int izquierda = i+1;
        cantidad+=(izquierda*derecha);
        if (cont>0) cantidad-=derecha;
        cont++;

    }

}
cout << cantidad<<endl;

return 0;
}
