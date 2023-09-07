// a program that asks the user for the row and column size of a 2D array and asks the user for the elements and shows the total of the sum of each row multiplied with the row number.
#include <iostream>

using namespace std;

int main() {
    int row, column;
    cout << "Enter the number of row size: ";
    cin >> row;
    cout << "Enter the number of column size: ";
    cin >> column;  
    
    int arr[row][column];
    int rowSum = 0, totalSum = 0;
    
    // Loop through each row and column of the 2D array and prompt the user to input its value
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "R" << i+1 << "C" << j+1 << ": ";
            cin >> arr[i][j];
            rowSum += arr[i][j]; // Add the current element to the row sum
        }
        totalSum += rowSum * (i+1); // Multiply the row sum by the row number and add it to the total sum
        rowSum = 0; // Reset the row sum for the next row
    }
    
    // Loop through each row and column of the 2D array and print its value to the console
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl; // Move to the next row of the 2D array
    }

    // Print the total sum of the elements to the console
    cout << "Total sum of the elements: " << totalSum << endl;
    
    return 0;
}
