#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Carro
{
   string name;
   int low;
   int high;

   Carro(string n, int l, int h)
   {
      name = n;
      low = l;
      high = h;
   }
};



int main()
{
   int N, numDB, query, val, cont;
   cin>>N;
   while(N--)
   {
      vector<Carro*> db;
      cin>>numDB;
      for(int i = 0; i < numDB; i++)
      {
         string n;
         int l, h;
         cin>>n>>l>>h;
         Carro* C = new Carro(n,l,h);
         db.push_back(C);
      }
      cin>>query;
      while(query--)
      {
         cont = 0;
         cin>>val;
         int index = 0;
         for(int i = 0; i < numDB; i++)
         {
            if((val >= db[i]->low) && (val <= db[i]->high))
            {
               cont++;
               index = i;
               if(cont > 1) break;
            }
         }
         if(cont == 1) cout<<db[index]->name<<endl;
         else cout<<"UNDETERMINED"<<endl;
      }
      db.clear();
   if (N) cout <<endl;
   }
   return 0;
}
