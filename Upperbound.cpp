#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> A, int l, int r, int Target)
{

    int L = l;
    int R = r;

    while(L < R)
    {
        int m = (L + R) / 2;

        if (A[m] > Target)
            R = m;
        else
            L = m + 1;
    }

    return R;

}

int main()
{

  int n;
  printf("Cual es el tamaño de tu arreglo: ");
  scanf("%d", &n);
  getchar();

  printf("Porfavor llena tu arreglo.\n");

  vector<int> A( n, 0 );
  for(int i = 0; i < n ; i++)
  {

      printf("Porfavor llena tu arreglo en la posicion A[ %d ]: ", i + 1);
      scanf("%d", &A[ i ]);
      getchar();

  }

  sort( A.begin(), A.end() );

  int S;
  printf("Elemnto a buscar: ");
  scanf("%d", &S);

  printf("index del elemento buscado: %d\n",upperBound(A, 0, n, S));

  return 0;

}

