#include <stdio.h>

void elem2 (int a[3], int v)
{
  a[2] = v*v;
}

int main ()
{
  int a[3] = {1,2,3};

  elem2(a,10);

  return printf("elem[2] = %d\n",a[2]) == EOF;
}
