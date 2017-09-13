#include <bits/stdc++.h>
using namespace std;
int test_cases;
int sum;
float aux;
int main(int argc, char *argv[])
{
  scanf("%d",&test_cases);
  for (int i = 0; i < test_cases; ++i) {
  map<string,int> plantas;
    string line;  
    scanf("  ");
    while (getline(cin,line)){
      if(line.empty()) break;
      else{
        if(plantas.count(line)>0){
          plantas[line]=plantas[line]+1;
        }
        else{
          plantas.insert(std::pair<string,int>(line,1));
        }
      }
    }
    sum=0; 
    for (map<string,int>::iterator it=plantas.begin(); it!=plantas.end(); ++it)
      sum= int(it->second) +sum;
    for (map<string,int>::iterator it=plantas.begin(); it!=plantas.end(); ++it){
      aux=(float(it->second)/float(sum))*100;
      cout << it->first << " " <<std::fixed<<setprecision(4)<< aux << '\n';
    }
    if(i+1!=test_cases)
    printf("\n");
  }
  return 0;
}
