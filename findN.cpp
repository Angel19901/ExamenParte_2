#include <bits/stdc++.h>

using namespace std;

/*
    Busqueda binaria para encontrar el elemnto mas a la derecha de un arreglo
    A = [1,2,3,4,5,6,7,7,7,7,7,7,8]
                               ^
                               |
    Si lo ejecutara upperBound(A,0,A.size(), 7) encontraria ese ultimo 7

*/
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

int main()
{

    printf("**************************************************************************************************\n");
    printf("*NOTA:                                                                                           *\n");
    printf("* Si quieres que este algoritmo sea O(( lg(n) )^2)                                               *\n");
    printf("* Entonces coloca valores K, K + 1, K + 2, ..., K + 2 n - 1                                      *\n");
    printf("* k = minimo valor entre tus dos arreglos, n = tamanio de tus arreglos                           *\n");
    printf("* En otro caso este algoritmo sera 0( lg( max(S[ i ],T[ i ]) - min(S[ i ], T[ i ] ) ) * lg(n) )  *\n");
    printf("**************************************************************************************************\n");
    printf("\n\nPresiona cualquier letra de tu teclado para continuar... ");
    getchar();

    int n;
    printf("\n\ningrese el tamanio de su arreglo: ");
    scanf("%d", &n);
    printf("\n");
    getchar();
    // Crea Arreglo de tamaño n con valores de cero
    vector<int> S(n, 0);
    vector<int> T(n, 0);
    /*Llena el arreglo */

    printf("Llene sus dos arreglos.\n");
    printf("Sus arreglos ya deben estar ordenados\n");

    for (int i = 0; i < n; i++)
    {
        printf("Llene el arreglo en la posicion S[ %d ] ", i + 1);
        scanf("%d", &S[i]);
        printf("\n");
        getchar();
    }

    for (int i = 0; i < n; i++)
    {
        printf("Llene el arreglo en la posicion T[ %d ] ", i + 1);
        scanf("%d", &T[i]);
        printf("\n");
        getchar();
    }

    /*Encuentra el Nesimo elementos*/
    printf("El enesimo es: %d\n", N_esimo(S, T, n));

    return 0;
}
