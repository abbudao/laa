#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;


ll _sieve_size;
vi primes;
bitset<20000010> bs;

/**
 * @brief: brief
 *
 * @param: ll uperbound
 *
 * @return: void
 */
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
/**
* @brief: brief
*
* @param: ll N
*
* @return: bool
*/
bool isPrimeSieve(ll N)
{
  if(N <=_sieve_size) return bs[N];
  for (int i=0; i<(int)primes.size() && (ll) primes[i]*primes[i]<= N; i++) 
    if(N % primes[i]==0) return false;
  return true;

}
int main(int argc, char *argv[])
{
  int num,c,i;
  sieve(20000010);
  vi twins;
  c=primes.size();
  for (i = 0; i < c; ++i) {
   if(isPrimeSieve(primes[i]+2)) {
     twins.push_back(primes[i]);
   }
  }
  while (scanf("%d",&num)!= EOF){
printf("(%d, %d)\n",twins[num-1],twins[num-1]+2);
  }
  return 0;
}
