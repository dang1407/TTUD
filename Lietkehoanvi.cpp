#include<iostream>
using namespace std;

int n;
int x[101] = {0};
bool check[101] = {false};

void print(){
      for(int i = 1; i <= n; i++){
            cout << x[i] << " ";
      }
      cout << endl;
}

void Try(int k){
      for(int i = 1; i <= n; i++ ){
            if(check[i] == false){
                  check[i] = true;
                  x[k] = i;
                  if(k < n) Try(k+1);
                  else print();
                  check[i] = false;
            }
      }
}

int main(){
      cin >> n;
      Try(1);
}