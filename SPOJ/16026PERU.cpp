#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>


using namespace std;

int main(){
long int n;
int dos=2;
long int arr[100001];
long int value=1;

for(int i=1;i<100001;i++){
    value=dos*value;
    value=value%1000000007;
    arr[i]=value;
}

while(1){
    cin >> n;
    if(n==0) break;
    cout << arr[n]<<endl;
}
return 0;
}
