#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int,int> ti;
typedef vector<ti> vt;
int  sucess=0;
tuple<int,int> switch_tuple(tuple<int,int> a)
{
  int tmp;
  tmp=get<0>(a);
  get<0>(a)= get<1> (a);
  get<1> (a)= tmp;
  return a;
}

void solve(int spaces, int pieces,vt domino, vt trail, ti end)
{
  int target;
  vt temp_domino;
  vt temp_trail;
  /* if(trail.size()==spaces+2){ */
  /*   return ; */
  /* } */
  if(trail.size()==0) {
    /*Still no path, add the start piece */
    trail.push_back(domino[0]);
    domino.erase(domino.begin());
  }
  target= get<1>(trail[trail.size()-1]);
  if(trail.size()==spaces+1){
    /*Last piece to add */
    if(target==get<0>(end) or target==get<1>(end)){
      sucess=1;
    }
      return;
  }
  for(int i=0;i<domino.size();i++){
    if(get<0>(domino[i])==target){
      temp_trail=trail;
      temp_domino=domino;
      temp_trail.push_back(domino[i]);
      temp_domino.erase(domino.begin()+i-1);
      solve(spaces,pieces,temp_domino,temp_trail,end);
      temp_trail.clear();
      temp_domino.clear();
    }
    if(get<1>(domino[i])==target){
      temp_trail=trail;
      temp_domino=domino;
      temp_trail.push_back(switch_tuple(domino[i]));
      temp_domino.erase(domino.begin()+i-1);
      solve(spaces,pieces,temp_domino,temp_trail,end);
      temp_trail.clear();
      temp_domino.clear();
    }
  }

}
int main(void)
{
  int spaces,pieces,aux1,aux2;
  vt domino,trail;
  while(scanf("%d",&spaces)!=EOF){
    if(spaces==0){
      break;
    }
    else{
      scanf("%d",&pieces);
      for(int i=0;i<pieces+2;i++){
        scanf("%d %d",&aux1,&aux2);
        ti aux_tuples(aux1,aux2);
        domino.push_back(aux_tuples);
      }
    }
    ti end= domino[1];
    domino.erase(domino.begin()+1);
    solve(spaces,pieces,domino,trail,end);
    if(sucess==1){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}
