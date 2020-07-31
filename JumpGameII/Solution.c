#include <stdlib.h>
#include <stdio.h>

int jump(int* nums, int size){
  int* minJumps = malloc(size * sizeof(int));
  minJumps[size - 1] = 0;

  for (int i = size - 2; i >= 0; i--) {
    int min = -1;
    for (int j = 1; j <= nums[i] && i + j < size; j++) {
      if (minJumps[i + j] < 0) continue;
      else if (min <0) min = minJumps[i + j] + 1;
      else if (minJumps[i + j] + 1 > min) min = minJumps[i + j] + 1;
    }
    minJumps[i] = min;
  }

  return minJumps[0];
}

int* read(const char *file_name, int *size) {
  FILE *input_txt = fopen(file_name, "r");

  int current_num = 0, current_char = fgetc(input_txt), total_size = 1;

  struct s {int a;};

  while (current_char != EOF) {
    if (current_char == ',') {
      ++total_size;
    }
  }
}

int main(int argc, char *argv[]) {
  int size;
  int* nums = read("input.txt", &size);
  
  return 0;
}
