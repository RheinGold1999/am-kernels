#include "klib.h"

#define N 32

unsigned char data[N];

void reset() {
  int i;
  for (i = 0; i < N; i++) {
    data[i] = i + 1;
  }
}

void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i++) {
    assert(data[i] == (val + i - l));
  }
}

void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i++) {
    assert(data[i] == val);
  }
}

void test_memset() {
  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      reset();
      unsigned char val = (l + r) / 2;
      memset(data + l, val, r - l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
  // printf("test_memset: PASSED.\n");
}

void test_memcpy() {
  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      reset();
      unsigned char val = (l + r) / 2;
      unsigned char val_arr[N] = {val};
      memcpy(data, val_arr, r - l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
}