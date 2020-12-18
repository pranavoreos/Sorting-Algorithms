#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class sorting{
private:

public:
  int numElements;

  double *quickSortArray; 
  double *mergeSortArray;
  double *selectSortArray;
  double *insertSortArray;
  double *bubbleSortArray;

  sorting();
  ~sorting();

  void setFile(string file);

  void quickSort(double array[], int left, int right);
  int partition(double array[], int left, int right);
  void merge(double array[], int left, int middle, int right);
  void mergeSort(double array[], int left, int right);
  void selectSort(double array[]);
  void insertSort(double array[]);
  void bubbleSort(double array[]);

  void sort();
  void swap(double array[], int a, int b);
};
