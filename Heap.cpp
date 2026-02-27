#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

// Initialize functions
void add(int n, int& size, int h[100]);
void sortUp(int index, int h[100]);

void remove(int& size, int h[100]);
void sortDown(int index, int size, int h[100]);

void print(int index, int level, int size, int h[100]);

int main() {

  // Create program variables
  int heap[100] = {};
  int size = 0;
  
  bool run = true;
  
  char input[99] = "";
  
  const char* ADD = "ADD";
  const char* UPL = "UPLOAD";
  const char* PRINT = "PRINT";
  const char* REM = "REMOVE";
  const char* ERA = "ERASE";
  const char* QUIT = "QUIT";
  
  while (run == true) {

    // Get input
    cout << "\n";
    cout << "Enter Command: ";
    cin >> input;
    cout << "\n";

    int n = 0;
    
    if (strcmp(input, ADD) == 0) { // Add num
      cout << "Enter number: ";
      cin >> n;

      if (size < 100) {
	add(n, size, heap);
      }
      
    } else if (strcmp(input, UPL) == 0) { // Upload file

      int length = 0;
      fstream data("data.txt");
      data.seekg(0, data.end);
      length = data.tellg();
      length++;
      data.seekg(0, data.beg);

      char numbers[length];
      data.getline(numbers, length);

      char* value = strtok(numbers, " ");

      while (value != NULL) {

	n = atoi(value);

	cout << n << endl;
	
	if (size < 100) {
	  add(n, size, heap);
	}

	value = strtok(NULL, " ");
      }
	

    } else if (strcmp(input, PRINT) == 0) { // Print heap
      print(0, 0, size, heap);
    } else if (strcmp(input, REM) == 0) { // Remove root
      remove(size, heap);
    } else if (strcmp(input, ERA) == 0) { // Erase heap
      int times = size;
      for (int i = 0; i < times; i++) {
	remove(size, heap);
      }
    } else if (strcmp(input, QUIT) == 0) { // Quit
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
  swap(h[0], h[size-1]);
  int index = 0;
  size--;

  // Sort
  sortDown(index, size, h);
  
}

void sortDown(int index, int size, int h[100]) {

  int left = 2*index + 1;
  int right = 2*index + 2;
  int largest;

  if (left < size && right < size) { // Check bounds
    largest = left;

    if (h[right] > h[left]) { // Check largest
      largest = right;
    }

    if (h[largest] > h[index]) { // Check child and sort
      swap(h[largest], h[index]);
      sortDown(largest, size, h);
    }
  }
}

void print(int index, int level, int size, int h[100]) {

  int left = 2*index + 1;
  int right = 2*index + 2;

  // Start from top
  if (h[right] != 0 && right < size) {
    print(right, level + 1, size, h);
  }

  // Print current
  cout << "\n";

  for (int i = 0; i < level; i++) {
    cout << "\t";
  }

  cout << h[index];
  
  // End with bottom
  if (h[left] != 0 && left < size){
    print(left, level + 1, size, h);
  }
  
}
