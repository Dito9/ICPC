#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
int n,m;

cin >>n>>m;

cout<<(n+m-1)<<endl;




for (int i=0; i<m;i++){
    cout << 1 <<" " << (i+1) <<endl;
}

for (int i=1; i<n;i++){
    cout << (i+1) <<" " << 1 <<endl;
}


return 0;
}
