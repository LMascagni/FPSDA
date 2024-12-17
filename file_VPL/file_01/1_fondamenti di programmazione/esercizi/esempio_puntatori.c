#include <stdio.h>
#include <stdlib.h>
int main()
{
  int x = 5;
  int *ip;
  ip = &x; // adesso *ip vale 5
  *ip = 0; // adesso *ip vale 0, e anche x
  return 0;
}