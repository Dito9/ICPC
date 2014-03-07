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

    int test;
    cin >> test;
    string cambio;
    getline(cin,cambio);
    getline(cin,cambio);
    while (test>0){
        map <string,long int> mapa;
        long int total=0;
        test--;
        string linea;
        getline(cin,linea);

        while (linea!=""){

        total++;

        if (mapa.count(linea)==0) mapa[linea]=1;
        else mapa[linea]+=1;

        getline(cin,linea);
        if (cin.eof()) break;

        }

    map<string,long int>::iterator it;

        for ( it=mapa.begin();it!=mapa.end();it++){
                double a = double(100*(double((it->second)/(double)total)));
            printf("%s %.4lf\n",(it->first).c_str(),a);

        }
        if (test>=1) cout <<endl;
        if (test==0) break;
    }

    return 0;
}
