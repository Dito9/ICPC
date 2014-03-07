#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
while(1){
 int t;
 cin >> t;
 int maximo =0;
 int sumaAcu=0;
 if (t==0) break;
 for (int i=0;i<t;i++){
  int a;
  cin >>a;
  sumaAcu+=a;
  if (sumaAcu>maximo) maximo=sumaAcu;
  if (sumaAcu<0) sumaAcu=0;

 }
if (maximo>0) {cout << "The maximum winning streak is "<<maximo<<"."<<endl;}
else {cout << "Losing streak."<<endl;}

}

return 0;

}
