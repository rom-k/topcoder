#include <cstdio>
#include "ijpc.h"

static const int MAXN = 100000;
static int N;
static char S[MAXN+50];

int main()
{
  scanf("%d%s", &N, S);
  
  int ret = replace(N, S);
  
  printf("%d\n", ret);
  
  return 0;
}
