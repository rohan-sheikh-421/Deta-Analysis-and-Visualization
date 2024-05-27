#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        comparisons++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        comparisons++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        comparisons++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, long long& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}

void heapify(vector<int>& arr, int n, int i, long long& comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons++;
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        comparisons++;
        heapify(arr, i, 0, comparisons);
    }
}

int partition(vector<int>& arr, int low, int high, long long& comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }
    swap(arr[i + 1], arr[high]);
    comparisons++;
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    srand(time(0));

    int numExperiments = 5;
    int n = 1000000000; // 10^9

    long long mergeSortComparisons = 0;
    long long heapSortComparisons = 0;
    long long quickSortComparisons = 0;

    double mergeSortTime = 0;
    double heapSortTime = 0;
    double quickSortTime = 0;

    for (int i = 0; i < numExperiments; i++) {
        vector<int> A, B, C;
        for (int j = 0; j < n; j++) {
            int num = rand();
            A.push_back(num);
            B.push_back(num);
            C.push_back(num);
        }

        auto start = chrono::high_resolution_clock::now();
        mergeSort(A, 0, n - 1, mergeSortComparisons);
        auto end = chrono::high_resolution_clock::now();
        mergeSortTime += chrono::duration_cast<chrono::milliseconds>(end - start).count();

        start = chrono::high_resolution_clock::now();
        heapSort(B, heapSortComparisons);
        end = chrono::high_resolution_clock::now();
        heapSortTime += chrono::duration_cast<chrono::milliseconds>(end - start).count();

        start = chrono::high_resolution_clock::now();
        quickSort(C, 0, n - 1, quickSortComparisons);
        end = chrono::high_resolution_clock::now();
        quickSortTime += chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }

    mergeSortComparisons /= numExperiments;
    heapSortComparisons /= numExperiments;
    quickSortComparisons /= numExperiments;

    mergeSortTime /= numExperiments;
    heapSortTime /= numExperiments;
    quickSortTime /= numExperiments;

    cout << "Average Comparisons:" << endl;
    cout << "Merge Sort: " << mergeSortComparisons << endl;
    cout << "Heap Sort: " << heapSortComparisons << endl;
    cout << "Quick Sort: " << quickSortComparisons << endl;

    cout << "Average Time (ms):" << endl;
    cout << "Merge Sort: " << mergeSortTime << endl;
    cout << "Heap Sort: " << heapSortTime << endl;
    cout << "Quick Sort: " << quickSortTime << endl;

    return 0;
}

