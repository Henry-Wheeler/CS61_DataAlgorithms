#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int partition(vector<int>& arr, int first, int last) {
    int pivot = arr[first]; 
    int i = first + 1;
    int j = last;

    while (i <= j) {
        while (i <= last && arr[i] <= pivot) i++;
        while (j >= first && arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[first], arr[j]); 
    return j; 
}

void quickSort2(vector<int>& arr) {
    int n = arr.size();
    stack<pair<int, int>> s;

    s.push({0, n - 1});

    while (!s.empty()) {
        int first = s.top().first;
        int last = s.top().second;
        s.pop();

        if (first < last) {
            int pivot_index = partition(arr, first, last);

            if (pivot_index - 1 > first) s.push({first, pivot_index - 1});
            if (pivot_index + 1 < last) s.push({pivot_index + 1, last});
        }
    }
}
