#include <iostream>
#include <cstring>

using namespace std;

void add(int n, int& size, int h[100]);
void sortUp(int index, int h[100]);

void remove(int& size, int h[100]);
void sortDown(int index, int h[100]);

void print(int index, int level, int h[100]);

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
  sortUp(index, h);
}

void sortUp(int index, int h[100]) {

  // Check if not at root
  if (index != 0) {
    int p = (index-1)/2;

    // Swap with parent when bigger
    if (h[p] < h[index]) {
      swap(h[p], h[index]);
      sortUp(p, h);
    }
  }
}

void remove(int& size, int h[100]) {

  // Output root and remove
  cout << h[0] << endl;

  h[0] = 0;
  swap(h[0], h[size]);
  int index = size;
  size--;

  // Sort
  sortDown(index, h);
  
}

void sortDown(int index, int h[100]) {

  int left = 2*index + 1;
  int right = 2*index + 2;

  if (h[left] > h[index]) { // Check left child
    swap(h[left], h[index]);
    sortDown(left, h);
  } else if (h[right] > h[index]) { // Check right child;
    swap(h[right], h[index]);
    sortDown(right, h);
  }
}

void print(int index, int level, int h[100]) {

  int left = 2*index + 1;
  int right = 2*index + 2;

  // Start from top
  if (h[right] != 0) {
    print(right, level++, h);
  }

  // Print current
  cout << "\n";

  for (int i = 0; i < level; i++) {
    cout << " ";
  }

  cout << h[index];
  
  // End with bottom
  if (h[left] != 0) {
    print(left, level++, h);
  }
  
}
