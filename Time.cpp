#include <bits/stdc++.h>

using namespace std;

int binarySearchRightest(vector<int> A, int l, int r, int Target)
{

    int L = l;
    int R = r;

    while (L < R)
    {
        int m = (L + R) / 2;

        if (A[m] > Target)
            R = m;
        else
            L = m + 1;
    }

    return R;
}

int N_esimo(vector<int> A, vector<int> B, int Nesimo)
{

    int n = int(B.size());           // tamaño del elemnto
    int l = min(B[0], A[0]);         // izquierda
    int r = max(A[n - 1], B[n - 1]); // derecha
    int ans = r + 1;                 // Respuesta
    int SumDistance;                 // suma de indeces
    int m;                           // mitad

    while (l <= r)
    {
        m = (l + r) / 2;

        SumDistance = binarySearchRightest(A, 0, n, m);
        SumDistance += binarySearchRightest(B, 0, n, m);

        if (SumDistance >= Nesimo)
        {
            ans = min(ans, m);
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return ans;
}

int main(){

  int n;

  cout << "x y\n";
  while(scanf("%d",&n) != EOF)
  {

    vector<int> S(n,0);
    vector<int> T(n,0);

    for(int i = 0; i < n; i++)
      scanf("%d",&S[ i ]);
    
    for(int i = 0; i < n; i++)
      scanf("%d",&T[ i ]);
    
    std::chrono::time_point< std::chrono::system_clock > instanteInicial, instanteFinal;
    instanteInicial = std::chrono::system_clock::now();
    
    N_esimo(S, T, n);
    
    instanteFinal   = std::chrono::system_clock::now();
    std::chrono::duration<double> segundos = instanteFinal-instanteInicial;
    
    cout << n << " " << (segundos).count() << endl;

  }

  return 0;

}
