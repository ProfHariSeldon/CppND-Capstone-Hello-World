#include <stdio.h>
#include <tensorflow/c/c_api.h>
#include "/usr/local/lib/libtensorflow-cpu-linux-x86_64-1.15.0/include/tensorflow/c/c_api.h"

int main() {
  printf("Hello from TensorFlow C library version %s\n", TF_Version());
  return 0;
}