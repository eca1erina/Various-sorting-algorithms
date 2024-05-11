#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std::chrono;

//Bubble Sort
void bubble(int *arr, int n)
{
    int ok;
    for(int i = 0; i < n; i++) {
        ok = 0;
        for(int j=0; j < n - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ok=1;
            }
        }
        if (!ok) break;
    }
}


//Selection Sort
void selection(int *arr, int n)
{
    for(int i=0; i<n; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//Insertion Sort
void insertion(int *arr, int n)
{
    for(int i = 1;i < n; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

//Merge Sort
void Merge(long* inputArray, long low, long mid, long high){
    long n1 = mid-low+1;
    long n2 = high - mid;
    long *L= new long [n1+1];
    long *R=new long [n2+1];
    for (int i=0;i<=n1;i++){
        L[i] = inputArray[low+i];
    }
    for (int j=0;j<=n2;j++){
        R[j] = inputArray[mid+j+1];
    }
    L[n1]=INT_MAX ;
    R[n2]=INT_MAX;
    long i=0;
    long j=0;
    for (long k=low;k<=high;k++){
        if (L[i] <= R[j] ){
            inputArray[k]=L[i];
            i=i+1;
        }
        else{
            inputArray[k]=R[j];
            j=j+1;
        }
    }

    delete[] L;
    delete[] R;
}


void mergesort(long* inputArray, long low, long high){
    if (low<high){
        int mid =(low+high)/2;
        mergesort(inputArray,low,mid);
        mergesort(inputArray,mid+1,high);
        Merge(inputArray,low,mid,high);
    }
    return;
}


//Quick Sort
int partition(long int *a, int start, int end)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = a[end];
    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    int pIndex = start;
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = start; i < end; i++) {
        if (a[i] <= pivot)
            std::swap(a[i], a[pIndex++]);
    }
    // swap `pIndex` with pivot
    std::swap (a[pIndex], a[end]);
    return pIndex;
}

void quicksort(long int *a, int start, int end)
{
    // base condition
    if (start >= end) {
        return;
    }

    // rearrange elements across pivot
    int pivot = partition(a, start, end);

    // recur on subarray containing elements that are less than the pivot
    quicksort(a, start, pivot - 1);

    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, end);
}

//Heap Sort
void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {

    int *arr = (int*)malloc(100000000*sizeof(int));
    int n = 100000;

    srand((unsigned) time(NULL));

    std::cout << "Before Sorting Array: " << std::endl;

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    for (int i = 0; i < 10; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout << std::endl;

    auto start = high_resolution_clock::now();

    heapSort(arr, n);

    auto stop = high_resolution_clock::now();

    std::cout << "After Sorting Array: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " "  ;
    }
    std::cout << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by function: "<< duration.count() << " microseconds" << std::endl;

    free(arr);
    return 0 ;
}
