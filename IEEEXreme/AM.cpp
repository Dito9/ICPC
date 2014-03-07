#include <iostream>
#include <vector>

using namespace std;

int sum[3]={-1,0,1};
int MAX=1000000000;

int main(){
    int y,x;
    cin>>y>>x;
    int mat[y][x];
    int sol[y][x];
    int maux[y][x];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
        }
    }
    /*cout<<endl;*/
    for(int i=0;i<x;i++) sol[y-1][i]=mat[y-1][i];
    for(int i=y-2;i>=0;i--){
        for(int j=0;j<x;j++){
            int n[3];
            for(int k=0;k<3;k++){
                int ny=i+1;
                int nx=j+sum[k];
                if(nx>=0 and nx<x) {
                    n[k]=mat[i][j]+sol[ny][nx];
                }
                else n[k]=MAX;
            }
            int mini=1;
            if (n[0]<=n[1]) mini=0;
            if (n[mini]>n[2]) mini=2;
            sol[i][j]=n[mini];
            maux[i][j]=mini-1;
        }
    }/*
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cout<<maux[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/
    int ini=0;
    int minimo=sol[0][0];
    for(int i=1;i<x;i++){
        if(sol[0][i]<minimo) {
            ini=i;
            minimo=sol[0][i];
        }
    }
    vector <int> path;
    path.push_back(ini);
    for(int i=0;i<y;i++){
        int h=path[path.size()-1]+maux[i][path[path.size()-1]];
        path.push_back(h);
    }
    cout<<"Minimum risk path = ";
    for(int i=0;i<y;i++){
        cout<<"["<<i<<","<<path[i]<<"]";
    }
    cout<<endl<<"Risks along the path = "<<sol[0][path[0]]<<endl;
}
