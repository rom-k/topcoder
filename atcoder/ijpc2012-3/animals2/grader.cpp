#include <cstdio>
#include <cstdlib>
#include "animals2.h"

static int N,M;
static int E[200000][3];
static int ans_count = 0;
void answer(long long C) {
  if(++ans_count >= N) {
    fprintf(stderr, "too many library call\n");
    exit(42);
  }
  printf("%lld\n", C);
}

int main() {
  if(scanf("%d%d", &N, &M) != 2) {
    fprintf(stderr, "read error\n");
    exit(1);
  }
  if( ! ( 1 <= N && N <= 100000 ) ) {
    fprintf(stderr, "invalid N\n");
    exit(1);
  }
  if( ! ( 0 <= M && M <= 200000 ) ) {
    fprintf(stderr, "invalid M\n");
    exit(1);
  }
  for(int i = 0; i < M; i++) {
    if(scanf("%d%d%d", &E[i][0], &E[i][1], &E[i][2]) != 3) {
      fprintf(stderr, "read error\n");
      exit(1);
    }
    if( ! ( 0 <= E[i][0] && E[i][0] < E[i][1] && E[i][1] < N ) ) {
      fprintf(stderr, "invalid E[%d]\n", i);
      exit(1);
    }
    if( ! ( 1 <= E[i][2] && E[i][2] <= 1000000000 ) ) {
      fprintf(stderr, "invalid E[%d]\n", i);
      exit(1);
    }
  }
  construct(N, M, E);
  if(ans_count < N-1) {
    fprintf(stderr, "too few library call\n");
    exit(42);
  }
  return 0;
}

