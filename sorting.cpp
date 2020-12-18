#include "sorting.h"

using namespace std;

//constructor
sorting::sorting(){}

//destructor
sorting::~sorting(){
  delete[] quickSortArray;
  delete[] mergeSortArray;
  delete[] selectSortArray;
  delete[] insertSortArray;
  delete[] bubbleSortArray;
}

//reads file in
void sorting::setFile(string file){
  string nElements;
  string line;
  double size;
  int lineNum = 1;

  ifstream inputFile;
  inputFile.open(file.c_str());

  getline(inputFile, nElements);
  numElements = atoi(nElements.c_str());

  quickSortArray = new double[numElements];
  mergeSortArray = new double[numElements];
  selectSortArray = new double[numElements];
  insertSortArray = new double[numElements];
  bubbleSortArray = new double[numElements];

  for(int i =0; i < numElements; ++i){
    lineNum++;
    getline(inputFile, line);
    size = atof(line.c_str());

    quickSortArray[i] = size;
    mergeSortArray[i] = size;
    selectSortArray[i] = size;
    insertSortArray[i] = size;
    bubbleSortArray[i] = size;
  }
  inputFile.close();
  sort();
}

//partition needed for quick sort
int sorting::partition(double array[], int left, int right){
  int pivot = array[(right + left)/2];

  while(left <= right){
    while(array[left] < pivot){
      left++;
    }

    while(array[right]>pivot){
      right--;
    }

    if(left<=right){
      swap(array, left, right);
      left++;
      right--;
    }
  }
  return left;
}

//quick sort
void sorting::quickSort(double array[], int left, int right){
  int index = partition(array, left, right);

  if(left < index - 1){
    quickSort(array, left, index-1);
  }
  if(right > index){
    quickSort(array, index, right);
  }
}

//merge method used for merge sort
void sorting::merge(double array[], int left, int middle, int right){
  int sizeLeftArray;
  int sizeRightArray;
  sizeLeftArray = middle - left +1;
  sizeRightArray = right - middle;
  double leftArray[sizeLeftArray];
  double rightArray[sizeRightArray];
  for(int i =0; i< sizeLeftArray; ++i){
    leftArray[i] = array[left + i];
  }
  for(int j = 0; j< sizeRightArray; ++j){
    rightArray[j] = array[middle + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = left;
  while(i < sizeLeftArray && j < sizeRightArray){
    if(leftArray[i] <= rightArray[j]){
      array[k] = leftArray[i];
      ++i;
    }
    else{
      array[k] = rightArray[j];
      ++j;
    }
    ++k;
  }
  while(i<sizeLeftArray){
    array[k] = leftArray[i];
    ++i;
    ++k;
  }
  while(j<sizeRightArray){
    array[k] = rightArray[j];
    ++j;
    ++k;
  }
}

//merge sort
void sorting::mergeSort(double array[], int left, int right){
  int middle;
  if(left<right){
    int middle = left+(right-left)/2;
    mergeSort(array, left, middle);
    mergeSort(array, middle+1, right);
    merge(array, left, middle, right);
  }
}

//select sort
void sorting::selectSort(double array[]){
  int min;
   for(int i = 0; i< numElements-1; ++i) {
      min = i;   //get index of minimum data
      for(int j = i+1; j<numElements; ++j)
         if(array[j] < array[min])
            min = j;
         //placing in correct position
         swap(array, array[i], array[min]);
   }
}

//insert sort
void sorting::insertSort(double array[]){
  for(int j=1; j< numElements; ++j){
    double temp = array[j];
    int k =j;
    while(k>0 && array[k-1] >= temp){
      array[k] = array[k-1];
      --k;
    }
    array[k] = temp;
  }
}

//bubble sort
void sorting::bubbleSort(double array[]){
  for(int j = 0; j < numElements-1; ++j) {
    int temp = 0;
    for (int k = 0; k < numElements - 1 - j; ++k){
      if(array[k] > array[k+1]){
        temp = array[k+1];
        array[k+1] = array[k];
        array[k] = temp;
      }
    }
  }
}

//method that does all calculations and does all the sorts
void sorting::sort(){
  clock_t clockStart;
  clock_t clockEnd;
  float calculatedTime;

  cout << "\nSORTING PROCESSES UNDERWAY...\n\n";

  //Quick Sort
  clockStart = clock();
  quickSort(quickSortArray, 0, numElements - 1);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Quick Sort Total Time: " << calculatedTime << " ms / Start Time: " << clockStart << " / End Time: " << clockEnd<< "\n";

  //Merge Sort
  clockStart = clock();
  mergeSort(mergeSortArray, 0, numElements - 1);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Merge Sort Total Time: " << calculatedTime << " ms / Start Time: " << clockStart << " / End Time: " << clockEnd<< "\n";

  //Select Sort
  clockStart = clock();
  selectSort(selectSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Select Sort Total Time: " << calculatedTime << " ms / Start Time: " << clockStart << " / End Time: " << clockEnd<< "\n";

  //Insert Sort
  clockStart = clock();
  insertSort(insertSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Insert Sort Total Time: " << calculatedTime << " ms / Start Time: " << clockStart << " / End Time: " << clockEnd<< "\n";

  //Bubble Sort
  clockStart = clock();
  bubbleSort(bubbleSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Bubble Sort Total Time: " << calculatedTime << " ms / Start Time: " << clockStart << " / End Time: " << clockEnd<< "\n";
}

//swap method for the sorts
void sorting::swap(double array[], int a, int b){
  double tempArray = array[a];
  array[a] = array[b];
  array[b] = tempArray;
}
