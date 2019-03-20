#include <stdlib.h> 
#include <iostream> 
#include <chrono>

using namespace std::chrono;
using namespace std;

void merge(int arr[], int l, int m, int r) { 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) { 
	if (l < r) { 
		int m = l+(r-l)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

int main() { 
    int n;
	cout << "Masukkan jumlah Data : "; cin >> n;
    int arr[n];
  	cout << "Masukkan Data (Dipisah Spasi) : ";
  	for(int i = 0; i < n; i++)
    	cin >> arr[i];
	
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	cout << "Array : ";
  	for(int i = 0; i < n; i++) 
      	cout << arr[i] << " ";
    cout << endl;
    auto start = high_resolution_clock::now();
	mergeSort(arr, 0, arr_size - 1); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);

	cout << "Array yang sudah diurut : ";
    for(int i = 0; i < n; i++)
      	cout << arr[i] << " ";
    cout << endl << endl << "Runtime merge sort : " << duration.count() << " microseconds" << endl;
    
	return 0; 
} 
