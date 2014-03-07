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
int unitarios[5000]={0};
int suma[5000]={0};
vector<int> arreglo;

int main(){
int n;
cin >>n;
for (int j=0;j<n;j++){
    int num;
    cin >>num;
    for ( int i = 2; i <= num && num!=1; i++ ){
        bool flag=false;
        if (num%i== 0)
        {
            if (!flag){
                unitarios[i]+=1;
                flag=true;
            }
            num /= i;
        }
    }

}
unitarios[1]=0;
unitarios[0]=0;
for (int i=1; i<100000001;i++){

suma[i]=suma[i-1]+unitarios[i];

}

int q;
cin >> q;
for (int i=0;i<q;i++){
    int a,b;
    cin >>a >>b;
    cout << (suma[b]-suma[a-1])<<endl;
}

return 0;
}
