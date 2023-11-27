/* Problem:
Finding Single Missing element in sorted array
Finding Multiple Missing elements in sorted array
Finding elements in Unsorted array */

// 1,2,3,4,5,6,7,9,10,11,12 : Output 8

// Approach : If series staarts from 1 then use formula
// Approach : Difference between number and index should be same

#include<iostream>
using namespace std;

void display(int arr[], int n){
	for (int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

void findSingleMissingSorted(int arr[], int n){
	int diff = arr[0];
	for (int i=1; i<n;i++){
		if ((arr[i]-i) != diff){
			cout<<"Missing Element: "<<i+diff<<endl;;
			break;
		}
	}
}

void findMultipleMissingSorted(int arr[], int n){
	int diff = arr[0];
	int j=1;
	for (int i=1; i<n;i++){
		if ((arr[i]-j) != diff){
			cout<<"Missing Element: "<<j+diff<<endl;
			i--;
		}
		j++;
	}
}

void findMultipleMissingSortedAB(int arr[], int n){
	int diff = arr[0];
	for (int i=1; i<n;i++){
		if ((arr[i]-i) != diff){
			while (diff < arr[i] - i ){
				cout<<"Missing Element: "<<i+diff<<endl;
				diff++;
			}
 
		}
	}
}

// Overall 1st loop runs for n times, second loop only considers missing elements. Total time is O(n). At worst case it's quite basd.

int main(){
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	
	int array[n];
	
	cout<<"Enter the elements"<<endl;
	
	for (int i=0; i<n; i++){
		cin>>array[i];
	}
	
	display(array,n);
	findSingleMissingSorted(array,n);
	findMultipleMissingSorted(array,n);
	
    cout<<"Hello";
    return 0;

}
