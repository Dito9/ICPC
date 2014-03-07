#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

class clase{
    public: long long int l;
    long long int tipo;
    long long int nl;
    long int c;
};

vector<clase> arreglo;
vector<long long int> longitudes;


int f(long long int a){
    long long int i = (lower_bound(longitudes.begin(),longitudes.end(),a)-longitudes.begin());
    long long int res = *(lower_bound(longitudes.begin(),longitudes.end(),a));
    if (a==res && ((arreglo.at(i).tipo==1))) return arreglo.at(i).nl;
    else if (a==res && ((arreglo.at(i).tipo==2))) return f(arreglo.at(i).nl);
    else {
       long long int resta= a-longitudes.at(i-1);
       if ( resta%arreglo.at(i).nl ==0 ) return f(arreglo.at(i).nl);
       else return f(resta%arreglo.at(i).nl);
    }
}

int main(){
long long int n,l=0;
cin >> n;
longitudes.push_back(0);
clase inicial;
inicial.c=0;
inicial.l=0;
inicial.nl=0;
inicial.tipo=1;

arreglo.push_back(inicial);
for (int i=0;i<n;i++){

clase a;
cin >> a.tipo;
if (a.tipo==1){
    cin>>a.nl;
    l++;
    a.l=l;
    arreglo.push_back(a);
    longitudes.push_back(l);
}
else{
    long long int x,c;
    cin >> a.nl>>a.c;
    l=l+a.nl*a.c;
    a.l=l;
    arreglo.push_back(a);
    longitudes.push_back(l);
}

}
long long int q;
cin >>q;
long long int a;
for(int i=0;i<q;i++){
    cin >> a;
    cout <<f(a)<<" ";
}
cout << endl;

return 0;
}
