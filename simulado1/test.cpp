#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
 string linha;
 vector<int> a;
 a.push_back(1);
 cout << find(a.begin(), a.end(), 1);
 a.push_back(2);
 cout << find(a.begin(), a.end(), 2);
   return 0;
}

