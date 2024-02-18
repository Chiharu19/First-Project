#include <iostream>
using namespace std;

//function declarations
void displayf(int array[], int size);
void bubblesort(int array[], int size);
void linearq(int array[], int size, int input);
void binaryq(int array[], int size, int input);

//  MAIN FUNCTION
int main(){
    int myArray[] = {105, 102, 445, 100, 234, 456, 872, 529, 300, 414, 567, 988, 572, 212, 434, 101, 898, 767, 564, 546};
    int arraySize = sizeof(myArray)/sizeof(myArray[0]);
    int userInput;
    string userResponse, userChoice;

    do{
      cout << "\n\nOriginal Array:\n";
      displayf(myArray, arraySize);
      bubblesort(myArray, arraySize);
      cout << endl;
      cout << "Sorted Array:\n";
      displayf(myArray, arraySize);
      cout << "\n\n";

      cout << "Enter element: ";
      cin >> userInput;
      cout << "Pick the type of algorithm[linear/binary]: ";
      cin >> userChoice;
      cout << endl;

      if(userChoice == "linear"){
        linearq(myArray, arraySize, userInput);
      }
      else{
        binaryq(myArray, arraySize, userInput);
      }

      cout << "\n\nDo you want to run again? ";
      cin >> userResponse;
    }while(userResponse == "yes" || userResponse == "Yes");
  return 0;
}

//  LINEAR FUNCTION
void linearq(int array[], int size, int input){
    for(int i = 0; i <= size; i++){
        if(array[i] != input){
            continue;    
        }
        else if(array[i] == input){
            cout << input << " is found at index " << i;
            break;
        }
        else{
            cout << "Element not found";
        }
    }
}

//   BINARY FUNCTION
void binaryq(int array[], int size, int input){
    int low = 0;
    int high = size - 1;
    int mid;
    int lowMoved, highMoved;
    
    while(mid != input){
        mid = (low+high)/2;
        if(array[mid] == input){
            cout << array[mid] << " is found at index " << mid;
            break;
        }
        else if(array[mid] < input){
            low = mid + 1;
            lowMoved++;
        }
        else{
            high = mid - 1;
            highMoved++;
        }
    }
    cout << "\nHigh moved " << highMoved << " times" << endl;
    cout << "Low moved " << lowMoved << " times" << endl;
}

//  BUBBLE SORT FUNCTION
void bubblesort(int array[], int size){
    int temp;
    for(int i = 0; i <= size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//  DISPLAY ARRAY FUNCTION
void displayf(int array[], int size){
  for(int i = 0; i <= size - 1; i++){
    cout << array[i] << "(" << i << ")" << " ";
  }
}