#include <iostream>
#include <deque>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <list>
#include <queue>
 
using namespace std;
 
int main(){
  int N ; cin >> N ;
  vector <int>a;
  for(int i = 0 ; i < N ; i++){
    int x;cin >> x;
    a.push_back(x);
  }
  vector<int> b(N,0);
  int count = 0;
  vector<int> ans;
  for(int i = N; i >= 1; i--){
    int f=0;
    for(int j = 2*i ; j <= N; j+=i){
      f^=b[j-1];
    }
    if(f!=a[i-1]){b[i-1]=1;count++; ans.push_back(i);}
  }
  cout << count << endl;
  for(int i = 0 ; i < (int)ans.size() ; i++){ cout << ans[i] << " "; }
  cout << endl;
  return 0;
}