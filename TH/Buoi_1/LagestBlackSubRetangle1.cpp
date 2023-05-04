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
      // Duyệt toàn bộ
      for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
                  for(int row_len = 1; row_len <= m - i; row_len++){
                        for(int col_len = 1; col_len <= n - j; col_len++){
                              if(checkIJ(i, j, row_len, col_len) == 1){
                                    printf("i = %d, j = %d, r_len = %d, c_len = %d\n", i, j, row_len, col_len);
                                    // checkIJ(i,j,row_len, col_len);
                                    result = row_len * col_len > result ? row_len * col_len : result;
                                    cout <<"result = " << result << endl;
                              }
                        }
                  }
            }
      }
      cout << result;
}