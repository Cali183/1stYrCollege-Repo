// a program that asks the user for the array size, and its elements. 
// aims to find the maximum element in an array of integers.
#include <iostream>

using namespace std;

// Ang function nito ay para malaman o mahanap ang maximum value sa loob ng integer array
int findMax(int arr[], int size){
	int max = arr[0]; // Initialize ang maximum value sa first element of the array
	
	// Loop through sa lahat ng elements of the array
	for (int i = 0; i < size; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	// Return the maximum value
	return max;
}

int main(){
	int size;
	cout << "Enter the size of array: ";
	cin >> size;
	
	int arr[size];

	// Loop through each element of the array and tatanunin ang user to input its value
	for (int i = 0; i < size; i++){
		cout << "Enter Element " << i+1 << ": ";
		cin >> arr[i];
	}
	
	int max;

	// Call the findMax() function to find the maximum value in the array
    max = findMax(arr, size);

	// Print the maximum value to the console 
	cout << "The maximum element is: " << max << endl;
	
	return 0;
}
