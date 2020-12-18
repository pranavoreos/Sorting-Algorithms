#include <iostream>
#include "sorting.h"

using namespace std;

int main(int argc, char** argv) {

  sorting s; //run the sorting simulations

  string file = argv[1];  //file input take from command line

  s.setFile(file); // file input
      
  return 0;
}
