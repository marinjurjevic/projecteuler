#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<vector<int> > unos(n);
  for(int i = 0; i<n; i++)
    unos[i].insert(unos[i].begin(), i+1, 0);

  vector<vector<int> > DP, put;
  DP = put = unos;

  for(int i=0; i<n;i++)
    for(int j=0; j<=i; j++)
      cin >> unos[i][j];

  DP[0][0] = unos[0][0];    // inicijalno stanje

  for(int i=1; i<n; i++)
    for(int j=0; j<=i; j++){
      if(j-1>=0 &&  DP[i-1][j-1] + unos[i][j] > DP[i][j]){
        DP[i][j] = DP[i-1][j-1] + unos[i][j];
        put[i][j] = -1;
      }
      if(j<i && DP[i-1][j] + unos[i][j] > DP[i][j]){
        DP[i][j] = DP[i-1][j] + unos[i][j];
        put[i][j] = 0;
      }
    }
  
  int x = 0;
  for(int i=1; i<n; i++)
    if( DP[n-1][i] > DP[n-1][x]) 
      x=i;

  vector<int> rjesenje;
  for(int i=n-1; i>=0; i--){
    rjesenje.push_back(unos[i][x]);
    x+=put[i][x];
  }

  for(int i=n-1; i>=0; i--)
    cout << rjesenje[i] << ' ';

  cout << endl;
  int sum = 0;
  for(auto a : rjesenje)
    sum += a;

  cout << sum << endl;

  return 0;
}
