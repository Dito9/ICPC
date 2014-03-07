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

int main(){
string name;
int arreglo[28]={0};
cin >> name;
int count=0;
for (int i=0;i<name.size();i++){
		arreglo[(name[i]-'a')]++;
		if (arreglo[name[i]-'a']==1) count++;
}
if (count&1) cout << "IGNORE HIM!" <<endl;
else cout << "CHAT WITH HER!" <<endl;

return 0;
}
