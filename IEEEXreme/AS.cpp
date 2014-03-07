#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

vector <vector <int> > adj (30) ;
vector <pair <int,string> > cad;
int w;

void dfs( int v, string sol){
    char c='A'+v;
    string news=sol+c;

    if(c=='A'+w) {
        pair<int,string> p=make_pair(news.size(),news);
        cad.push_back(p);
        return;
    }
    if(sol.find(c)==-1){
        for(int i=0;i<adj[v].size();i++){
            dfs(adj[v][i],news);
        }
    }
}


int main(){
    char fin;
    cin>>fin;
    w=fin-'A';
    string a,b;
    while(cin>>a>>b){
        if(a[0]=='A') break;
        int n=a[0]-'A';
        int m=b[0]-'A';
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    int ini='F'-'A';
    string sol="F";
    for(int i=0;i<adj[5].size();i++){
        dfs(adj[5][i],sol);
    }
    sort(cad.begin(),cad.end());
    if(cad.size()!=0){
        cout<<"Total Routes: "<<cad.size()<<endl;
        cout<<"Shortest Route Length: "<<cad[0].first<<endl;
        cout<<"Shortest Route after Sorting of Routes of length "<<cad[0].second.size()<<":";
        for(int i=0;i<cad[0].second.size();i++){
            cout<<" "<<cad[0].second[i];
        }
        cout<<endl;
    }
    else {
        cout<<"No Route Available from F to "<< (char)('A'+w)<<endl;
    }
}
