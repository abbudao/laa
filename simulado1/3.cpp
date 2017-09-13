#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;
vector<vector <int>> solucoes;
ll _sieve_size;
vi primes;
bitset<20000010> bs;
ll a=2,b=2;


void conjucture(int num){
  long long j=0,i=0;
  while(a<num){
    j=0;
    b=primes[j];
    a=primes[i];
    i++;
    while(a+b<=num){
      b=primes[j];
      j++;
      if(a+b==num){
        printf("%d = %d + %d\n",num,a,b);
        return;
      }
    }
  }
      return;
}
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

int main(int argc, char *argv[])
{
  ll num;
  sieve(1000000);
  while (scanf("%d",&num)!= EOF){
    if(num==0){
      return  false;
    }else{
      conjucture(num);
    }}
    return 0;
  }
