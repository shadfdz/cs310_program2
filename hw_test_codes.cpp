// #include <iostream>

// using namespace std;

// // Codes for selectionSort

// void swap(int *xp, int *yp) {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// void selectionSort(int arr[], int n) {
//     int i, j, min_idx;

//     for (i = 0; i < n-1; i++) {  // i = 0 n = 5
//         min_idx = i;
//         for (j = i+1; j < n; j++) 
//             if (arr[j] < arr[min_idx])
//             min_idx = j;
        
//         swap(&arr[min_idx], &arr[i]);
//     }
// }

// void printArray(int arr[], int size) {
//     int i;
//     for (i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// // Codes for insertion sort
// void insertionSort(int arr[], int n) {
//     int i, key, j;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;

//         while (j >= 0 && arr[j] > key) 
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }


// int main()
// {
//     int arr[] =  {21,1,0,23,5,4};
//     int n = sizeof(arr) /sizeof(arr[0]);
//     // selectionSort(arr, n);
//     // cout << "Sorted array: \n";
//     // printArray(arr,n);
//     insertionSort(arr, n);
//     printArray(arr, n);




//     return 0;
// }