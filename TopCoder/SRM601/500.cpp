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
    vector <int> type;
		map <int,int> mapa;
		int suma=0;
		int mul=1;
		for (int i=0; type.size();i++){
		if ( mapa.count(type.at(i))==0){
		mapa[type.at(i)]=1;
		}
		else {
		mapa[type.at(i)]+=1;
		}
		}

		for (int i=1;i<51;i++){

		mul = mul * mapa[i];
		suma +=  mul;
		}

		return suma;

}
