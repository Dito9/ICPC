#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(){

long long int kinds;
long long int budget;

cin >> kinds>> budget;
vector< pair<long long int,long long int> > arr;

for (int i=0;i<kinds;i++){
	long long int precio;
	long long int vacas;
	cin>>precio>>vacas;
	pair<long long int,long long int> par;
	par.first=precio;
	par.second=vacas;
	arr.push_back(par);
}
sort(arr.begin(),arr.end());
long long int cont=0;

for(int i=0;i<kinds;i++){
	long long int precio=arr.at(i).first;
	long long int vacas=arr.at(i).second;
	long long int cap=budget/precio;
	if (cap>vacas) cap=vacas;
	cont+=cap;
	budget-=cap*precio;

}
cout<<cont<<endl;
return 0;
}

