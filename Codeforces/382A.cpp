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
int main(void){

vector<char> izquierda;
vector<char> derecha;

string cadena;
cin >> cadena;
bool flag=true;

for (int i=0;i<cadena.size();i++){

    if (cadena.at(i)=='|') {flag=false; continue;}

    if (flag) izquierda.push_back(cadena.at(i));
    if (!flag) derecha.push_back(cadena.at(i));
}
cin >> cadena;

for (int i=0;i<cadena.size();i++){

    if (izquierda.size()<derecha.size()){
        izquierda.push_back(cadena.at(i));
    }
    else {
        derecha.push_back(cadena.at(i));
    }
}

if (izquierda.size()==derecha.size()) {

    for (int i=0; i< izquierda.size();i++){
        printf("%c",izquierda.at(i));
    }
    printf("%c",'|');
    for (int i=0; i< derecha.size();i++){
        printf("%c",derecha.at(i));
    }
}

else printf( "%s","Impossible");
    printf("\n");

return 0;
}
