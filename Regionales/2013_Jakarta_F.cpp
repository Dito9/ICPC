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
long long int base = 27;
long long int mod = 1000004;
int main(void){
int casos;
cin >>casos;
for (int a=1;a<=casos;a++){
    int rpt;
    rpt=0;
    string cadena;
    cin >> cadena;
    int i = 0;
    int j = cadena.size()-1;
    long long int L=0;
    long long int R=0;
    long long int P=1;

    while (i<=j){
       L=((( (L%mod)*(base%mod))%mod)+(cadena[i]-'A'+1))%mod;
       R=( R%mod + ((P%mod)*((cadena[j]-'A'+1)%mod)))%mod;
       P=(P%mod)*(base%mod)%mod;
//QWERTYUIOPASDFGHJKLZXCVBNMQWERTYUIOPASDFGHJKLZXCVBNM
       if (L==R && i<j){
        rpt+=2;
        L=0;R=0;P=1;
       }
       i++;
       j--;
    }

    if (P!=1) rpt++;
    cout <<rpt<<endl;

}

return 0;
}
