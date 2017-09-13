#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<int> vi;
typedef map<int, int> mii;
vector<vector <int>> solucoes;
ll _sieve_size;
vi primes;
bitset<20000010> bs;

void sieve(ll upperbound)
{
  _sieve_size = upperbound +1;
  bs.set();
  bs[0]= bs[1]=0;
  for (ll i=2; i<= _sieve_size; i++) if (bs[i]) {
    for(ll j= i*i; j<= _sieve_size; j+=i) bs[j]=0;
    primes.push_back((int)i);
  }
}
bool isPrimeSieve(ll N)
{
  if(N <=_sieve_size) return bs[N];
  for (int i=0; i<(int)primes.size() && (ll) primes[i]*primes[i]<= N; i++) 
    if(N % primes[i]==0) return false;
  return true;

}
void backtrack(vector<int> solution,int dim)
{
  int tam=solution.size();
  if(tam==dim){
    if(isPrimeSieve(solution[tam-1]+1)){
      solucoes.push_back(solution);}
    return ;
  }
  else{
    for(int j=2;j<dim+1;j++){
      bool add=true;
      for(int i=0;i<solution.size();i++){
        if(solution[i]==j){
          add=false;
        }
      }
      if(add and isPrimeSieve(solution[tam-1]+j)){
        vector <int> temp=solution;
        temp.push_back(j);
        backtrack(temp,dim);
      }
    }
  }
  return;
}
int main(int argc, char *argv[])
{
  int  i=0,num;
  sieve(100);
  while (scanf("%d",&num)!= EOF){
    vector<int> intial;
    if(i!=0) {
      printf("\n");
    }
    intial.push_back(1);
    backtrack(intial,num);
    i++;
    printf("Case %d:\n",i);
    for(int j=0;j<solucoes.size();j++){
      for(int k=0; k<solucoes[j].size();k++){
        printf("%d",solucoes[j][k]);
        if(k+1!=solucoes[j].size()){
          printf(" ");
        }
      }
      printf("\n");
    }
    solucoes.clear();
  }
  return 0;
}
