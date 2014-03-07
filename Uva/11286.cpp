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
string transformar(vector<int>);
int main(){

int frosh;
while(1){
cin >> frosh;
int maxi=0;
if (frosh==0) break;
map <string, long int> mapa;
for (int i=0;i<frosh;i++){

    vector< int > week;
    for (int j=0;j<5;j++){

    int curso;
    cin>>curso;
    week.push_back(curso);
    }
    sort(week.begin(),week.end());

    string trans = transformar(week);
    if (mapa.count(trans)==0) {
            mapa[trans]=1;
            if ( mapa[trans]>maxi) maxi=mapa[trans];
    }
    else{
        mapa[trans]+=1;
        if ( mapa[trans]>maxi) maxi=mapa[trans];
        }
    }
    map <string,long int>::iterator it;
    long int retorno=0;
    for (it=mapa.begin();it!=mapa.end();it++){

        if ((it->second == maxi)) {
            retorno = retorno + (it->second);
        }
    }
    cout << retorno <<endl;

}
return 0;
}


string transformar(vector<int> week){


    string retorno="";
    for (int i=0; i< week.size();i++){
    long int a = week[i];
    char intStr[5];
    sprintf(intStr,"%ld",a);
    string str = string(intStr);
    retorno = retorno + str;
    }

    return retorno;
}



