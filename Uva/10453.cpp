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
map<string,int> mapa;
pair <int,string> f(string s,int i,int j){

    if (i==j){
        pair<int,string> par;
        par.first=0;
        par.second=s;
        return par;
    }
    if (i>j){
        pair<int,string> par;
        par.first=0;
        par.second=s;
        return par;
    }
    stringstream ss;

    string iz;
    ss << s[i];
    ss >> iz;
    stringstream ss1;
    string de;
    ss1<<s[j];
    ss1>>de;

    if (iz.compare(de)==0){
        i++;
        j--;
        pair<int,string> par;
        if (!mapa.count(s)) {par=f(s,i,j);
            mapa[par.second]=par.first;
        }
        else{
            par.second=s;
            par.first=mapa[par.second];
        }
        return par;
    }
    else{
        string aux=s;
        string aux1=s;
        string s1= aux.insert(i,de);
        string s2 = aux1.insert(j+1,iz);
        pair<int,string> a;
        if (!mapa.count(s1)){
        a = f(s1,i+1,j);
        mapa[s1]=a.first;

        }else{
        a.second = s1;
        a.first = mapa[s1];
        }
        pair<int,string> b;
        if (!mapa.count(s2)){
        b = f(s2,i+1,j);
        mapa[s2]=b.first;
        }else{
        b.second = s2;
        b.first = mapa[s2];
        }
        pair<int,string> par;
        if (a.first<b.first){

            par.first = 1 + a.first;
            par.second=a.second;
            return par;
        }else{
            par.first=1+b.first;
            par.second=b.second;
            return par;
        }
    }
}
int main(){
    string s;
    while(1){
        cin >>s;
        if (cin.eof()) break;

        pair<int,string> par;
        par = f(s,0,(int)s.size()-1);
        cout <<par.first<<" "<<par.second<<endl;
    }
return 0;
}





