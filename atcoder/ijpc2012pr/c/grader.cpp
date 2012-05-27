#include<cstdio>
#include<cmath>
#include<cstdlib>
#include"submission.h"

static int N, calls;
static long long T, M;

int compare(long long X)
{
  if(N == 0 || X < 0 || X > M) {
    fprintf(stderr, "invalid library call\n");
    exit(42);
  }

  calls++;
  if(X >= T) {
    N--;
    return 1;
  } else {
    return 0;
  }
}

int main()
{
  int inN;
  scanf("%d%lld%lld", &inN, &M, &T);
  N = inN;
  calls = 0;

  long long ret = getT(N, M);
  N = inN;

  if(ret != T || (N==2 && calls>400000)) {
    puts("NG");
  } else {
    if(N == 1) puts("OK 1");
    else if(N == 2) puts("OK 2");
    else {
      double w = pow(M, 1.0/N);
      for(int i=2; i<=N; ++i)
        w *= pow(i, 1.0/N);
      int W = ceil(w + 1e-9) + N;
      double P;
      if(W >= calls) P = 50;
      else if(2*W <= calls) P = 0;
      else P = 100 - 50.0 * calls / W;
      printf("OK 3 %.6f\n", P);
    }
  }

  return 0;
}
