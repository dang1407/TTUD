#include <iostream>
using namespace std;

int n, m, p = 0;
int x[11] = {0}, f[11] = {0};

void print()
{
      for (int i = 1; i <= m; i++)
      {
            cout << x[i] << " ";
      }
      cout << endl;
}

void Try(int k)
{
      if (k < m)
      {
            int u = n - f[k - 1] - (m - k);
            for (int i = 1; i <= u; i++)
            {
                  x[k] = i;
                  f[k] = f[k - 1] + i;
                  Try(k + 1);
            }
      }
      else
      {
            if (n - f[m - 1] > 0)
            {
                  x[k] = n - f[m - 1];
                  print();
            }
      }
}

int main()
{
      cin >> n >> m;
      if (n < m)
      {
            cout << "So keo it hon so em be!" << endl;
            return 0;
      }
      p = n - m + 1;
      Try(1);
}