// RUN: hlstool --no_trace --rebuild --tb_file %s dynamic --run_sim

#include "insertion_sort.h"
#include <stdlib.h>

#ifndef N_KERNEL_CALLS
#define N_KERNEL_CALLS 1
#endif

int main(void) {
  int a[N_KERNEL_CALLS][1000];
  int n[N_KERNEL_CALLS];
  for (int i = 0; i < N_KERNEL_CALLS; ++i) {
    n[i] = 30;
    for (int j = 0; j < 1000; ++j) {
      a[i][j] = rand() % 10;
    }
  }
  for (int i = 0; i < N_KERNEL_CALLS; ++i) {
    insertion_sort(a[i], n[i]);
  }
}
