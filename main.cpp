#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// =========================================================
// GLOBAL VARIABLES & MASTER ARRAYS
// =========================================================
const int SIZE = 100000;
int originalArray[SIZE];
int testArray[SIZE];
int temp[SIZE]; // Used specifically for Merge Sort

// =========================================================
// FUNCTION PROTOTYPES
// =========================================================
// Helpers
void copyArray(int source[], int dest[], int size);
void swap(int& data1, int& data2);
bool loadArrayFromFile(const string& filename, int arr[], int size);

// Bubble Sort
void BubbleSortV1_Ascending(int arr[], int first, int last);
void BubbleSortV1_Descending(int arr[], int first, int last);
void BubbleSortV2_Ascending(int arr[], int first, int last);
void BubbleSortV2_Descending(int arr[], int first, int last);

// Insertion Sort
void InsertionSortV1_Ascending(int arr[]);
void InsertionSortV1_Descending(int arr[]);
void InsertionSortV2_Ascending(int arr[]);
void InsertionSortV2_Descending(int arr[]);
int binarySearchAsc(int arr[], int item, int first, int last);
int binarySearchDesc(int arr[], int item, int first, int last);

// Merge Sort
void MergeSortV1_Ascending(int arr[], int first, int last);
void MergeSortV1_Descending(int arr[], int first, int last);
void MergeSortV2_Ascending(int arr[], int first, int last);
void MergeSortV2_Descending(int arr[], int first, int last);

// Quick Sort
int partitionAscV1(int arr[], int first, int last);
void quickSortAscV1(int arr[], int first, int last);
int partitionAscV2(int arr[], int first, int last);
void quickSortAscV2(int arr[], int first, int last);
int partitionDescV1(int arr[], int first, int last);
void quickSortDescV1(int arr[], int first, int last);
int partitionDescV2(int arr[], int first, int last);
void quickSortDescV2(int arr[], int first, int last);

// Selection Sort
void selectionSortAscending_V1(int arr[], int size);
void selectionSortDescending_V1(int arr[], int size);
void selectionSortAscending_V2(int arr[], int size);
void selectionSortDescending_V2(int arr[], int size);

// =========================================================
// MAIN PROGRAM
// =========================================================
int main() {
    // Fill the original array with random numbers for Phase 1
    if (!loadArrayFromFile("random.txt", originalArray, SIZE)) {
        return 1;
    }

    clock_t start, end;

    // ##########################################################
    // PHASE 1: RANDOM ARRAY SCENARIO
    // ##########################################################
    cout << "###########################################" << endl;
    cout << "        PHASE 1: RANDOM ARRAY INPUT        " << endl;
    cout << "###########################################\n" << endl;

    // --- Bubble Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Insertion Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Descending(testArray);
    end = clock();
    cout << "InsertionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Descending(testArray);
    end = clock();
    cout << "InsertionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Selection Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Merge Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Quick Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";


    // ##########################################################
    // PHASE 2: ASCENDING ARRAY SCENARIO
    // ##########################################################
    cout << "###########################################" << endl;
    cout << "     PHASE 2: ASCENDING ARRAY INPUT        " << endl;
    cout << "###########################################\n" << endl;

    // Use QuickSort to instantly prepare the array for Ascending phase
    if (!loadArrayFromFile("ascending.txt", originalArray, SIZE)) {
        return 1;
    }

    // --- Bubble Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Insertion Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Descending(testArray);
    end = clock();
    cout << "InsertionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Descending(testArray);
    end = clock();
    cout << "InsertionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Selection Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Merge Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Quick Sort ---
    /* copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    */
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";


    // ##########################################################
    // PHASE 3: DESCENDING ARRAY SCENARIO
    // ##########################################################
    cout << "###########################################" << endl;
    cout << "     PHASE 3: DESCENDING ARRAY INPUT       " << endl;
    cout << "###########################################\n" << endl;

    // Use QuickSort to instantly prepare the array for Descending phase
    if (!loadArrayFromFile("descending.txt", originalArray, SIZE)) {
        return 1;
    }

    // --- Bubble Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    BubbleSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "BubbleSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Insertion Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV1_Descending(testArray);
    end = clock();
    cout << "InsertionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Ascending(testArray);
    end = clock();
    cout << "InsertionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    InsertionSortV2_Descending(testArray);
    end = clock();
    cout << "InsertionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Selection Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V1(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortAscending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    selectionSortDescending_V2(testArray, SIZE);
    end = clock();
    cout << "SelectionSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Merge Sort ---
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV1_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Ascending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    MergeSortV2_Descending(testArray, 0, SIZE - 1);
    end = clock();
    cout << "MergeSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    // --- Quick Sort ---
    /* copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV1(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V1 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    */
    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortAscV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Ascending:  " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    copyArray(originalArray, testArray, SIZE);
    start = clock();
    quickSortDescV2(testArray, 0, SIZE - 1);
    end = clock();
    cout << "QuickSort V2 Descending: " << fixed << setprecision(6) << double(end - start) / CLOCKS_PER_SEC << " seconds\n\n";

    return 0;
}


// =========================================================
// HELPER FUNCTIONS
// =========================================================

bool loadArrayFromFile(const string& filename, int arr[], int size) {
    ifstream inputFile(filename.c_str());
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }
    for (int i = 0; i < size; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();
    return true;
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void swap(int& data1, int& data2) {
    int temp = data1;
    data1 = data2;
    data2 = temp;
}


// =========================================================
// BUBBLE SORT IMPLEMENTATIONS
// =========================================================
void BubbleSortV1_Ascending(int arr[], int first, int last) {
    for (int i = first; i < last; i++) {
        for (int j = first; j < last - (i - first); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSortV1_Descending(int arr[], int first, int last) {
    for (int i = first; i < last; i++) {
        for (int j = first; j < last - (i - first); j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSortV2_Ascending(int arr[], int first, int last) {
    bool swapped;
    int newLast;
    while (first < last) {
        swapped = false;
        newLast = first;
        for (int j = first; j < last; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                newLast = j;   // remember last swap ( improvement 1)
            }
        }
        last = newLast;   // shrink the sorted and unsorted ( improvement 2)
        if (!swapped) break;
    }
}

void BubbleSortV2_Descending(int arr[], int first, int last) {
    bool swapped;
    int newLast;
    while (first < last) {
        swapped = false;
        newLast = first;
        for (int j = first; j < last; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                newLast = j;   // remember last swap ( improvement 1)
            }
        }
        last = newLast;   // shrink the sorted and unsorted ( improvement 2)
        if (!swapped) break;
    }
}


// =========================================================
// INSERTION SORT IMPLEMENTATIONS
// =========================================================
void InsertionSortV1_Ascending(int arr[]) {
    int item, pass, insertIndex;
    for (pass = 1; pass < SIZE; pass++) { // starts from 2nd element and loops through the whole array
        item = arr[pass];
        // copies the current item we want to sort into a temporary variable
        insertIndex = pass;
        // sets our starting point to check backwards
        while ((insertIndex > 0) && (arr[insertIndex - 1] > item)) { // while we haven't reached the start AND the item to the left is bigger
            arr[insertIndex] = arr[insertIndex - 1];
            // shift the bigger item one spot to the right
            insertIndex--;
            // move our checking position one spot to the left
        }
        arr[insertIndex] = item;
        // we found the correct spot, place our item here
    }
}

void InsertionSortV1_Descending(int arr[]) {
    int item, pass, insertIndex;
    for (pass = 1; pass < SIZE; pass++) { // starts from 2nd element and loops through the whole array
        item = arr[pass];
        // copies the current item we want to sort into a temporary variable
        insertIndex = pass;
        // sets our starting point to check backwards
        while ((insertIndex > 0) && (arr[insertIndex - 1] < item)) { // while we haven't reached the start AND the item to the left is SMALLER (for descending)
            arr[insertIndex] = arr[insertIndex - 1];
            // shift the smaller item one spot to the right
            insertIndex--;
            // move our checking position one spot to the left
        }
        arr[insertIndex] = item;
        // we found the correct spot, place our item here
    }
}

int binarySearchAsc(int arr[], int item, int first, int last) {
    while (first <= last) { // keep halving the search area until we find the exact spot
        int mid = first + (last - first) / 2;
        // calculate the middle index of our current search range
        if (item == arr[mid]) return mid + 1;
        // if it matches the middle exactly, its spot is right next to it
        else if (item > arr[mid]) first = mid + 1;
        // if our item is bigger, ignore the left half and search the right half
        else last = mid - 1;
        // if our item is smaller, ignore the right half and search the left half
    }
    return first;
    // returns the exact index where the item belongs
}

void InsertionSortV2_Ascending(int arr[]) {
    int item, pass, insertIndex;
    for (pass = 1; pass < SIZE; pass++) { // starts from 2nd element and loops through the whole array
        item = arr[pass];
        // copies the current item we want to sort
        insertIndex = pass;
        // sets our starting index

        // OPTIMIZATION: Check if it's already in the correct spot
        if (item >= arr[pass - 1]) { // checks if our item is already bigger than the largest sorted item to its left
            continue;
            // if it is, skip the whole search and shift process entirely (makes already sorted arrays instant)
        }
        int loc = binarySearchAsc(arr, item, 0, pass - 1);
        // uses binary search to instantly calculate the correct index instead of checking one by one
        while (insertIndex > loc) { // loops backwards from current spot to the new correct spot
            arr[insertIndex] = arr[insertIndex - 1];
            // shifts all elements in between one space to the right to make room
            insertIndex--;
            // move one spot left
        }
        arr[insertIndex] = item;
        // drop the item into the empty space we just created
    }
}

int binarySearchDesc(int arr[], int item, int first, int last) {
    while (first <= last) { // keep halving the search area until we find the exact spot
        int mid = first + (last - first) / 2;
        // calculate the middle index
        if (item == arr[mid]) return mid + 1;
        // if it matches the middle exactly, its spot is right next to it
        else if (item < arr[mid]) first = mid + 1;
        // if our item is SMALLER, ignore the left half and search right (for descending)
        else last = mid - 1;
        // if our item is BIGGER, ignore the right half and search left
    }
    return first;
    // returns the exact index where the item belongs
}

void InsertionSortV2_Descending(int arr[]) {
    int item, pass, insertIndex;
    for (pass = 1; pass < SIZE; pass++) { // starts from 2nd element and loops through the whole array
        item = arr[pass];
        // copies the current item we want to sort
        insertIndex = pass;
        // sets our starting index

        // OPTIMIZATION: Check if it's already in the correct spot
        if (item <= arr[pass - 1]) { // checks if our item is already smaller than the smallest sorted item to its left
            continue;
            // if it is, skip the whole search and shift process entirely
        }
        int loc = binarySearchDesc(arr, item, 0, pass - 1);
        // uses binary search to instantly calculate the correct index
        while (insertIndex > loc) { // loops backwards from current spot to the new correct spot
            arr[insertIndex] = arr[insertIndex - 1];
            // shifts all elements in between one space to the right to make room
            insertIndex--;
            // move one spot left
        }
        arr[insertIndex] = item;
        // drop the item into the empty space we just created
    }
}


// =========================================================
// SELECTION SORT IMPLEMENTATIONS
// =========================================================
void selectionSortAscending_V1(int arr[], int size) {
    for (int last = size - 1; last >= 1; last--) {
        int largestIndex = 0; // Assume first element is largest
        for (int x = 1; x <= last; x++) { // Find the actual largest element
            if (arr[x] > arr[largestIndex]) {
                largestIndex = x; // Update index if largest value is found
            }
        }
        swap(arr[largestIndex], arr[last]); // Always perform swap
    }
}

void selectionSortDescending_V1(int arr[], int size) {
    for (int last = size - 1; last >= 1; last--) {
        int smallestIndex = 0; // Assume first element is smallest
        for (int x = 1; x <= last; x++) { // Find the actual smallest element
            if (arr[x] < arr[smallestIndex]) {
                smallestIndex = x; // Update index if smaller value is found
            }
        }
        swap(arr[smallestIndex], arr[last]); // Always perform swap
    }
}

void selectionSortAscending_V2(int arr[], int size) {
    for (int last = size - 1; last >= 1; last--) {
        int largestIndex = last; // Improvement: Initialize with 'last' to assume the target is already in place (best case)
        int currentMax = arr[last]; // Improvement: Cache arr[last] in a local variable to reduce slow memory lookups
        for (int x = 0; x < last; x++) {
            if (arr[x] > currentMax) { // Improvement: Compare against currentMax (faster than accessing arr[largestIndex] repeatedly)
                currentMax = arr[x];
                largestIndex = x; // Update index if larger value is found
            }
        }
        if (largestIndex != last) { // Improvement: Only swap if the largest element is NOT already at the end
            swap(arr[largestIndex], arr[last]); // Prevents 3 redundant memory writes when an element is already sorted
        }
    }
}

void selectionSortDescending_V2(int arr[], int size) {
    for (int last = size - 1; last >= 1; last--) {
        int smallestIndex = last; // Improvement: Initialize with 'last' to assume the target is already in place (best case)
        int currentMin = arr[last]; // Improvement: Cache arr[last] in a local variable to reduce slow memory lookups
        for (int x = 0; x < last; x++) {
            if (arr[x] < currentMin) { // Improvement: Compare against cached min (reduces CPU load compared to V1)
                smallestIndex = x; // Update index if smaller value is found
                currentMin = arr[x];
            }
        }
        if (smallestIndex != last) { // Improvement: Only swap if the smallest element is NOT already at the end
            swap(arr[smallestIndex], arr[last]); // Saves time by avoiding the overhead of a swap operation
        }
    }
}


// =========================================================
// MERGE SORT IMPLEMENTATIONS
// =========================================================
void MergeSortV1_Ascending(int arr[], int first, int last) {
    if (first < last) { // base case (stops when only one item left in array)
        int mid = (first + last) / 2; // this is the index where we will split the array from (midpoint of array)
        MergeSortV1_Ascending(arr, first, mid); // divide left half of array
        MergeSortV1_Ascending(arr, mid + 1, last); // divide right half of array

        // MERGE FUNCTION STARTS FROM HERE
        int first1 = first; // beginning of first sub-array
        int last1 = mid; // end of first sub-array
        int first2 = mid + 1; // beginning of second sub-array
        int last2 = last; // end of second sub-array
        int index = first1; // tracks where next element should be placed in temp[];

        for (; (first1 <= last1) && (first2 <= last2); index++) { // runs as long as there are items remaining in both the left and right sub-arrays
            if (arr[first1] < arr[first2]) { // checks if first item in left sub-array is less than first item in right sub-array, if it is, copies the item into temp[] array, if not, goes to else condition
                temp[index] = arr[first1];
                first1++;
            }
            else { // copies item from right sub-array into temp[] array
                temp[index] = arr[first2];
                first2++;
            }
        }

        for (; first1 <= last1; first1++, index++) { // ensures no data is lost from the left sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first1];
        }

        for (; first2 <= last2; first2++, index++) { // ensures no data is lost from the right sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first2];
        }

        for (index = first; index <= last; index++) { // temporary array is copied back into the original array and merge is complete
            arr[index] = temp[index];
        }
    }
}

void MergeSortV1_Descending(int arr[], int first, int last) {
    if (first < last) { // base case (stops when only one item left in array)
        int mid = (first + last) / 2; // this is the index where we will split the array from (midpoint of array)
        MergeSortV1_Descending(arr, first, mid); // divide left half of array
        MergeSortV1_Descending(arr, mid + 1, last); // divide right half of array

        // MERGE FUNCTION STARTS FROM HERE
        int first1 = first; // beginning of first sub-array
        int last1 = mid; // end of first sub-array
        int first2 = mid + 1; // beginning of second sub-array
        int last2 = last; // end of second sub-array
        int index = first1; // tracks where next element should be placed in temp[];

        for (; (first1 <= last1) && (first2 <= last2); index++) { // runs as long as there are items remaining in both the left and right sub-arrays
            if (arr[first1] > arr[first2]) { // checks if first item in left sub-array is greater than first item in right sub-array, if it is, copies the item into temp[] array, if not, goes to else condition
                temp[index] = arr[first1];
                first1++;
            }
            else { // copies item from right sub-array into temp[] array
                temp[index] = arr[first2];
                first2++;
            }
        }

        for (; first1 <= last1; first1++, index++) { // ensures no data is lost from the left sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first1];
        }

        for (; first2 <= last2; first2++, index++) { // ensures no data is lost from the right sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first2];
        }

        for (index = first; index <= last; index++) { // temporary array is copied back into the original array and merge is complete
            arr[index] = temp[index];
        }
    }
}

void MergeSortV2_Ascending(int arr[], int first, int last) {
    if (first < last) { // base case (stops when only one item left in array)
        int mid = (first + last) / 2; // this is the index where we will split the array from (midpoint of array)
        MergeSortV2_Ascending(arr, first, mid); // divide left half of array
        MergeSortV2_Ascending(arr, mid + 1, last); // divide right half of array

        if (arr[mid] <= arr[mid + 1]) { // Skips merge if 2 halves already sorted. This checks if biggest item in left sub-array is smaller than smallest item in right sub-array
            return;
        }

        // MERGE FUNCTION STARTS FROM HERE
        int first1 = first; // beginning of first sub-array
        int last1 = mid; // end of first sub-array
        int first2 = mid + 1; // beginning of second sub-array
        int last2 = last; // end of second sub-array
        int index = first1; // tracks where next element should be placed in temp[];

        for (; (first1 <= last1) && (first2 <= last2); index++) { // runs as long as there are items remaining in both the left and right sub-arrays
            if (arr[first1] < arr[first2]) { // checks if first item in left sub-array is less than first item in right sub-array, if it is, copies the item into temp[] array, if not, goes to else condition
                temp[index] = arr[first1];
                first1++;
            }
            else { // copies item from right sub-array into temp[] array
                temp[index] = arr[first2];
                first2++;
            }
        }

        for (; first1 <= last1; first1++, index++) { // ensures no data is lost from the left sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first1];
        }

        for (; first2 <= last2; first2++, index++) { // ensures no data is lost from the right sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first2];
        }

        for (index = first; index <= last; index++) { // temporary array is copied back into the original array and merge is complete
            arr[index] = temp[index];
        }
    }
}

void MergeSortV2_Descending(int arr[], int first, int last) {
    if (first < last) { // base case (stops when only one item left in array)
        int mid = (first + last) / 2; // this is the index where we will split the array from (midpoint of array)
        MergeSortV2_Descending(arr, first, mid); // divide left half of array
        MergeSortV2_Descending(arr, mid + 1, last); // divide right half of array

        if (arr[mid] >= arr[mid + 1]) { // Skips merge if 2 halves already sorted. This checks if smallest item in left sub-array is larger than largest item in right sub-array
            return;
        }

        // MERGE FUNCTION STARTS FROM HERE
        int first1 = first; // beginning of first sub-array
        int last1 = mid; // end of first sub-array
        int first2 = mid + 1; // beginning of second sub-array
        int last2 = last; // end of second sub-array
        int index = first1; // tracks where next element should be placed in temp[];

        for (; (first1 <= last1) && (first2 <= last2); index++) { // runs as long as there are items remaining in both the left and right sub-arrays
            if (arr[first1] > arr[first2]) { // checks if first item in left sub-array is greater than first item in right sub-array, if it is, copies the item into temp[] array, if not, goes to else condition
                temp[index] = arr[first1];
                first1++;
            }
            else { // copies item from right sub-array into temp[] array
                temp[index] = arr[first2];
                first2++;
            }
        }

        for (; first1 <= last1; first1++, index++) { // ensures no data is lost from the left sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first1];
        }

        for (; first2 <= last2; first2++, index++) { // ensures no data is lost from the right sub-array, checks if there are any remaining items and moves them into temp[] array
            temp[index] = arr[first2];
        }

        for (index = first; index <= last; index++) { // temporary array is copied back into the original array and merge is complete
            arr[index] = temp[index];
        }
    }
}



// =========================================================
// QUICK SORT IMPLEMENTATIONS
// =========================================================
// Since this is version 1, pivot is set to the first element of the array, with bottom as first and top as last. This is for partitioning the quick sort array.
int partitionAscV1(int arr[], int first, int last) {
    int pivot, temp, loop, cutPoint, bottom, top;
    pivot = arr[first];
    bottom = first;
    top = last;
    loop = true;
    while (loop) {
        while (arr[top] > pivot) {
            // the top index keeps decreasing by 1 as long as the top element is greater than the pivot
            top--;
        }
        // here bottom index keeps increasing by 1 as long as the bottom element is LESSER than the pivot.
        while (arr[bottom] < pivot) {
            bottom++;
        }
        // we check if the bottom index is less than the top index. If its truem then we swap both indexes and go on to next iteration of the while loop. If not, then break out of the loop and return the top point.
        if (bottom < top) {
            temp = arr[bottom];
            arr[bottom] = arr[top];
            arr[top] = temp;
            bottom++;
            top--;
        }
        else {
            loop = false;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortAscV1(int arr[], int first, int last) {
    // This function is to partition the array into 2 arrays and make it so that whatever elements in the left of the cutpoint are smaller and right of that point is bigger.
    int cut;
    if (first < last) {
        // we first find the cut point using the partition function and then use that cutpoint to divide the array into 2 parts. This keeps on repeating until every element is an array
        cut = partitionAscV1(arr, first, last);
        quickSortAscV1(arr, first, cut);
        quickSortAscV1(arr, cut + 1, last);
    }
}

// both the partitionAscV2 and quickSortAscV2 are the same as above but the only difference over here is the impovement. The improvement over here is that, instead of taking the pivot as the start of the array, we take pivot in the middle.
int partitionAscV2(int arr[], int first, int last) {
    int pivot = arr[first + (last - first) / 2];
    int bottom = first;
    int top = last;
    while (true) {
        while (arr[bottom] < pivot) bottom++;
        while (arr[top] > pivot) top--;
        // If bottom index is greater than or equal to top, we return top and end the function. If not, then we swap bottom and top element and increase bottom and decrease top indexes.
        if (bottom >= top) return top;
        int temp = arr[bottom];
        arr[bottom] = arr[top];
        arr[top] = temp;
        bottom++;
        top--;
    }
}
// Same as quickSortAscV1
void quickSortAscV2(int arr[], int first, int last) {
    if (first < last) {
        int cut = partitionAscV2(arr, first, last);
        quickSortAscV2(arr, first, cut);
        quickSortAscV2(arr, cut + 1, last);
    }
}

// Same as partitionAscV1. Only difference is we change if arr[top]>pivot to arr[top]<pivot and also change arr[bottom]<pivot to arr[bottom]>pivot. This is to reverse the order of checking so we do it in descending way.
int partitionDescV1(int arr[], int first, int last) {
    int pivot, temp, loop, cutPoint, bottom, top;
    pivot = arr[first];
    bottom = first;
    top = last;
    loop = true;
    while (loop) {
        while (arr[top] < pivot) {
            top--;
        }
        while (arr[bottom] > pivot) {
            bottom++;
        }
        if (bottom < top) {
            temp = arr[bottom];
            arr[bottom] = arr[top];
            arr[top] = temp;
            bottom++;
            top--;
        }
        else {
            loop = false;
            cutPoint = top;
        }
    }
    return cutPoint;
}

// Same as quickSortAscV1
void quickSortDescV1(int arr[], int first, int last) {
    int cut;
    if (first < last) {
        cut = partitionDescV1(arr, first, last);
        quickSortDescV1(arr, first, cut);
        quickSortDescV1(arr, cut + 1, last);
    }
}

// Same as partitionAscV2. Only difference is we change if arr[top]>pivot to arr[top]<pivot and also change arr[bottom]<pivot to arr[bottom]>pivot. This is to reverse the order of checking so we do it in descending way.
int partitionDescV2(int arr[], int first, int last) {
    int pivot = arr[first + (last - first) / 2];
    int bottom = first;
    int top = last;
    while (true) {
        while (arr[bottom] > pivot) bottom++;
        while (arr[top] < pivot) top--;
        if (bottom >= top) return top;
        int temp = arr[bottom];
        arr[bottom] = arr[top];
        arr[top] = temp;
        bottom++;
        top--;
    }
}

// Same as quickSortAscV2
void quickSortDescV2(int arr[], int first, int last) {
    if (first < last) {
        int cut = partitionDescV2(arr, first, last);
        quickSortDescV2(arr, first, cut);
        quickSortDescV2(arr, cut + 1, last);
    }
}
