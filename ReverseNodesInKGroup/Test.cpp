#include <iostream>

int& func() {
  int* a = new int(5);
  return *a;
}

int main() {
  int& b = func();
  
}
