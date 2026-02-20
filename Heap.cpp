#include <iostream>
#include <cstring>

using namespace std;

int add(int n, int h[100]);
int remove(int h[100]);
int print(int h[100]);

int main() {

  int heap[100] = {};

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
