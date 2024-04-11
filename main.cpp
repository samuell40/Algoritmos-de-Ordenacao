#include <iostream>
#include <vector>
#include <fstream> 
#include <cstdlib> 
#include <chrono> 
#include <iomanip>

using namespace std;
using namespace chrono;

void printArray(const vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> randomVector(int size) {
    vector<int> vector(size);
    srand(time(nullptr));

    for(int i = 0; i < size; i++) {
        vector[i] = rand() % 100;
    }
   
    return vector;
}

// Bubble Sort
void bubbleSort(vector<int> &v) {
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Quick Sort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion Sort
void insertionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &v, int low, int high, int mid) {
    int i, j, k;
    vector<int> c(high - low + 1); // vetor temporário dinâmico

    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (v[i] < v[j]) {
            c[k] = v[i];
            k++;
            i++;
        } else {
            c[k] = v[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = v[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = v[j];
        k++;
        j++;
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        v[i] = c[k];
    }
}

void mergeSort(vector<int> &v, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, high, mid);
    }
}

// Shell Sort
void shellSort(vector<int> &v) {
    int n = v.size();
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i += 1) {
            int temp = v[i];
            int j;
            for (j = i; j >= h && v[j - h] > temp; j -= h)
                v[j] = v[j - h];
            v[j] = temp;
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &v) {
    int min_idx;
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[min_idx])
                min_idx = j;
        }
        if(min_idx != i) {
            int temp = v[min_idx];
            v[min_idx] = v[i];
            v[i] = temp;
        }
    }
}
main(){
    ofstream outputFile("tempo_execucao.txt");

    for (int size = 1000; size <= 200000; size += 10000) {
        vector<int> vt = randomVector(size);

        vector<int> vt_bubble = vt;
        vector<int> vt_quick = vt;
        vector<int> vt_insertion = vt;
        vector<int> vt_merge = vt;
        vector<int> vt_shell = vt;
        vector<int> vt_selection = vt;

    }

    outputFile.close();
    return 0;
}