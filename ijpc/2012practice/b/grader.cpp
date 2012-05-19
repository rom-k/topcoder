#include "primehazard.h"
#include "grader.h"
#include <cstdio>
#include <cstdlib>

static int state;

static int *bits;
static int bits_size;

void send(int b) {
  if(state == 1 || b < 0 || b > 1) {
    fprintf(stderr, "Illegal library call\n");
    exit(1);
  }
  if(bits_size >= 12) {
    fprintf(stderr, "too many library call\n");
    exit(1);
  }
  bits[bits_size++] = b;
}

int main() {
  int N; scanf("%d", &N);
  bits_size = 0;
  bits = new int[12];
  state = 0;
  taro(N);
  state = 1;
  printf("%d\n", jiro(bits_size, bits));
  delete[] bits;
  return 0;
}
