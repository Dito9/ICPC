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
    map<string,int> mapa;
    int numero =1;

    vector <string> letra1;
    char ini='a';
    for(int a=0;a<26;a++)
    {
       string de1="";
        de1+=ini;
        ini++;
        mapa[de1]=numero;
        numero++;
        letra1.push_back(de1);
    }

    vector<string> letra2;
    for (int i=0;i<letra1.size();i++){
            for (int j=i+1;j<26;j++){
                string de2="";
                char ini = 'a'+j;
                de2= de2 + (letra1.at(i))+ ini;
                mapa[de2]= numero;
                letra2.push_back(de2);
                numero++;
            }
    }
    vector<string> letra3;
    for (int i=0;i<letra2.size();i++){
            string cadena=letra2.at(i);
            for (int j= (cadena[1]-'a'+1) ;j<26;j++){
                string de3="";
                char ini = 'a'+j;
                de3= de3 + (letra2.at(i))+ ini;
                mapa[de3]= numero;
                numero++;
                letra3.push_back(de3);
            }
    }

    vector<string> letra4;
    for (int i=0;i<letra3.size();i++){
            string cadena=letra3.at(i);
            for (int j= (cadena[2]-'a'+1) ;j<26;j++){
                string de4="";
                char ini = 'a'+j;
                de4= de4 + (letra3.at(i))+ ini;
                mapa[de4]= numero;
                numero++;
                letra4.push_back(de4);
            }
    }

    vector<string> letra5;
    for (int i=0;i<letra4.size();i++){
            string cadena=letra4.at(i);
            for (int j= (cadena[3]-'a'+1) ;j<26;j++){
                string de5="";
                char ini = 'a'+j;
                de5= de5 + (letra4.at(i))+ ini;
                mapa[de5]= numero;
                numero++;
                letra5.push_back(de5);
            }
    }

    string lectura;
    while( cin >> lectura ){

        cout<< mapa[lectura]<<endl;

    }

    return 0;
}
