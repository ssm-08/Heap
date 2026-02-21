#include <iostream>
#include <cstring>

using namespace std;

void add(int n, int& size, int h[100]);
void sort(int index, int h[100]);

int remove(int h[100]);
void print(int h[100]);

int main() {

  int heap[100] = {};
  int size = 0;
  
  bool run = true;
  
  char input[99] = "";
  
  const char* ADD = "ADD";
  const char* PRINT = "PRINT";
  const char* REM = "REMOVE";
  const char* QUIT = "QUIT";
  
  while (run == true) {

    // Get input
    cout << "\n";
    cout << "Enter Command: ";
    cin >> input;
    cout << "\n";

    int n = 0;
    
    if (strcmp(input, ADD) == 0) { // Add num
    } else if (strcmp(input, PRINT) == 0) { // Print heap
    } else if (strcmp(input, REM) == 0) { // Remove root
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}

void add(int n, int& size, int h[100]) {

  // Add at the last slot
  h[size] = n;
  int index = size;
  size++;

  // Sort
  sort(index, h);
}

void sort(int index, int h[100]) {

  // Check if not at root
  if (index != 0) {
    int p = (index-1)/2;

    // Swap with parent when bigger
    if (h[p] < h[index]) {
      swap(h[p], h[index]);
      sort(p, h);
    }
  }
}


  
  
