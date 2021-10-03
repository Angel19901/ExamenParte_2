#include <bits/stdc++.h>

using namespace std;

int main()
{

  for(int i = 10; i <= 10000; i *= 10)
  {
    printf("%d\n", i);

    for(int j = 0; j < i*2; j++)
      if((j + 1) % 2)
        printf("%d ",j + 1);
    printf("\n");
    for(int j = 0; j < i*2; j++)
      if(!((j + 1) % 2))
        printf("%d ",j + 1);
    printf("\n");
  }

  for(int i = 11000 ; i <= 100000;i += 1000)
  {
    printf("%d\n", i);

    for(int j = 0; j < i*2; j++)
      if((j + 1) % 2)
        printf("%d ",j + 1);
    printf("\n");
    for(int j = 0; j < i*2; j++)
      if(!((j + 1) % 2))
        printf("%d ",j + 1);
    printf("\n");
  }

  return 0;

}
