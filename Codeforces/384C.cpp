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
vector<long long int> arreglo;
int main(void){
    int n;
    cin >>n;
  long long int contD=0;
  long long int contI=0;
  long long int acumuladorI=0;
  long long int acumuladorD=0;
    for (int i=0;i<n;i++){
    long long int a;
    cin >>a;
    arreglo.push_back(a);
    if (a==1) contD++;
    if (a==0) acumuladorI+=contD;
    }
    for (int i=(n-1);i>=0;i--){
    long long int a = arreglo.at(i);
    if (a==0) contI++;
    if (a==1) acumuladorD+=contI;
    }

    cout<< min(acumuladorD,acumuladorI)<<endl;
    return 0;
}
