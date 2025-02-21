#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void merge(vector<int>& arr, int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[first + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int partition(vector<int>& arr, int first, int last) {
    int pivot = arr[first];
    int i = first + 1;
    int j = last;

    while (i <= j) {
        while (i <= last && arr[i] <= pivot) {
            i++;
        }
        while (j >= first && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[first], arr[j]); 
    return j;
}

void quickSort(vector<int>& arr, int first, int last) {
    if (first < last) {
        int pivot_index = partition(arr, first, last);
        quickSort(arr, first, pivot_index - 1);
        quickSort(arr, pivot_index + 1, last);
    }
}

