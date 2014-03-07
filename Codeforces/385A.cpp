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
vector<int> arreglo;
int main(){

int n,c;
int maximoprofit=0;
int dif;

cin >> n >>c;
for (int i=0;i<n;i++){
    int a;
    cin >> a;
    arreglo.push_back(a);
}

for (int i=0;i<(n-1);i++){
    int a,b;
    a=arreglo.at(i);
    b=arreglo.at(i+1);
    dif = a-b;
    int profit = a - b - c;
    if  (profit>maximoprofit) maximoprofit=profit;

}
    cout << maximoprofit<<endl;
return 0;











}
