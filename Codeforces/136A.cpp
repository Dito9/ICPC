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


int main(void){
int n,read;
int* persona;

cin >> n;
persona = (int*)malloc(sizeof(int)*n);
memset(persona,0,sizeof(persona));


for (int i=0;i<n;i++){
    cin >> read;
    read--;
    persona[read]=i+1;

}

for (int i=0;i<n;i++){
    cout << persona[i]<<" ";
}
cout <<endl;

return 0;
}
