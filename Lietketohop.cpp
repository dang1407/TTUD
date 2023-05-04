#include<iostream>
using namespace std;

int m, n;
int x[101] = {0};
bool check[101] = {false};

void print(){
      for(int i = 1; i <= m; i++){
            cout << x[i] << " ";
      }
      cout << endl;
}

void Try(int k){
      for(int i = x[k-1] + 1; i <= n - m + k; i++){
            if(check[i] == false){
                  check[i] = true;
                  x[k] = i;
                  if(k < m) Try(k+1);
                  else print(); 
                  check[i] = false;
            }
      }
}

int main(){
      cin >> n >> m;
      Try(1);
}