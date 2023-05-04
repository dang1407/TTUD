#include<iostream>
using namespace std;

int x[10], n;

void print(){
      for(int i = 1; i <= n; i++){
            cout << x[i] << " ";
      }
      cout << endl;
}

// Sinh xâu nhị phân bình thường
void Try(int k){
      for(int i = 0; i <= 1; i++){
            x[k] = i;
            if(k == n){
                  print();
            } else Try(k + 1);
      }
}

// Sinh xâu nhị phân không có 2 số 0 cạnh nhau
void Try_NDouble_Zero(int k){
      for(int i = 0; i <= 1; i++){
            if(x[k-1] == 0 && i == 0 && k > 1){
                  continue;
            } else {
                  x[k] = i;
            }

            if(k < n) Try_NDouble_Zero(k + 1);
            else print();
      }
}
int main(){
      cin >> n;
      Try_NDouble_Zero(1);
}