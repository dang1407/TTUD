#include<iostream>
#include<stdlib.h>
using namespace std;

int **array = new int*[1000];
int result = 0;
int m, n;
// check hcn có góc trên bên trái là i, j, kích thước row_len x col_len
int checkIJ(int i, int j, int row_len, int col_len){
      for(int u = i; u < i + row_len; u++){
            for(int v = j; v < j + col_len; v++){
                  cout << array[u][v] << " ";
                  if(array[u][v] == 0){
                        return 0;
                  }
            }
            cout << "\n";
      }
      return 1;
}

int main(){

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int result = 0;
      for(int i = 0; i < 1000; i++){
            array[i] = new int[1000];
      }
      cin >> m >> n;
      for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                  cin >> array[i][j];
            }
      }
      cout << endl;

}