#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Array{
    int *A;
    int length;
    int size;
};

void Display(Array a){

	for (int i=0; i<a.length;i++){
		cout<<"Array element "<<i<<" :"<<a.A[i]<<endl;
	}
}

void Append(Array *a, int x){
	if (a->length < a->size){
		a->	A[a->length++] = x;
	}

    
  //  return a; // Because void isn't working. Because it is generating a new array and the existing array isn't being called. Use call by address.
}

void Insert(Array *a, int index, int x){
    if (index >= 0 && index < a->length){
        for (int i = a->length; i > index; i--){
            a->A[i] = a->A[i-1];
        }
        a->A[index] = x;
        a->length++;
    }
    else{
        cout<<"Array already full";
    }
    
}

void Delete(Array *a, int index){
    if (index>=0 && index < a->length){
        for(int i = index; i<a->length-1; i++){
            a->A[i] = a->A[i+1];
        }
        a->length --;
    }
}

void swap(Array *a, int index1, int index2){
	int temp = a->A[index1];
	a->A[index1] = a->A[index2];
	a->A[index2] = temp;
}

int LinearSearch(Array *a, int key){
	for (int i=0;i<a->length;i++){
		if (key == a->A[i]){
			swap(a,i,i-1);
			return i;
		}
	}
	return -1;
}

void swapAB(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


int LinearSearchAB(Array *arr, int key){
	for(int i=0; i<arr->length; i++){
		if (key == arr->A[i]){
			swapAB(&arr->A[i],&arr->A[i-1]); // For move to head swap(a[i],a[0])
			return i;
		}
	}
	return -1;
}


int BinSearch(Array *a, int low, int high, int key){
	while (low <= high){
		int mid = (low + high)/2;
		
		if (key == a->A[mid]){
			return mid;
		}
		else if (key < a->A[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;
}

int BinarySearchAB(Array arr, int key){
	int l, mid, h;
	l = 0;
	h = arr.length-1;
	mid = (l + h)/2;
	
	while (l<=h){
		if (key == arr.A[mid]){
			return mid;
		}
		else if (key < arr.A[mid]) {
			h = mid -1;
		}
		else{
			l = mid +1;
		}
	}
	return -1;
		
}

int BinSearchRecursion(Array *a, int low, int high, int key){
	if (low>high){
		return -1;
	}
	else{
		int mid = (low + high)/2;
		if (key == a->A[mid]){
			return mid;
		}
		else if (key < a->A[mid]){
			BinSearchRecursion(a,low,mid-1,key);
			
		}
		else{
			BinSearchRecursion(a,mid+1 ,high,key);
		}
	}
}

int Get(Array arr, int idx){
	if (idx >=0 && idx<arr.length)
		return arr.A[idx];
	return -1;
}

void Set(Array *a, int idx, int key){
	if (idx >= 0 && idx< a->length)
		a->A[idx] = key;
	
}

int Max(Array arr){
	int max = arr.A[0];
	
	for (int i =1; i<arr.length ; i++){
		if (arr.A[i]>max){
			max = arr.A[i];
		}
	}
	return max;
}


int Min(Array arr){
	int min = arr.A[0];
	
	for (int i =1; i<arr.length ; i++){
		if (arr.A[i]<min){
			min = arr.A[i];
		}
	}
	return min;
}

int Sum(Array arr){
	int sum = 0;
	for (int i = 0; i< arr.length; i ++){
		sum = sum+arr.A[i];
	}
	return sum;
}

float Avg(Array arr){
	return (float)Sum(arr)/arr.length;
}

void Reverse(Array *arr){
	int i,j,temp;
	i = 0;
	j = arr->length-1;
	
	while (i<j){
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
		i++;
		j--;
	}
}

void ReverseAB(Array *arr){
	int *B;
	int i,j;
	B = new int[arr->length];
	for (i =arr->length-1,j=0; i>=0; i--,j++){
		B[j] = arr->A[i];	
	}
	for (i=0;i<arr->length;i++){
		arr->A[i]= B[i];
	}
}

void InsertSort(Array *arr, int x){
	
	int i = arr->length-1;
	
	if (arr->length<arr->size){
		while (i>=0 && arr->A[i] > x){
			arr->A[i+1] = arr->A[i];
			i--;
		}
	}
	else{
		return;
	}
	
	arr->A[i+1] = x;
	arr->length++; 	
		
}

bool checkSort(Array arr){
	for (int i = 0; i<arr.length; i++){
		if (arr.A[i+1] < arr.A[i]){
			return false;
		}
	}
	return true;
}

void Reaarrange(Array *a){
	int i,j;
	i=0;
	j=a->length-1;
	
	while (i<j){
		while (a->A[i]<0){
			i++;
		}
		while (a->A[j]>0){
			j--;
		}
		
		if (i<j){
			swapAB(&a->A[i],&a->A[j]);
		}
		
	}
}

Array* Merge(Array *arr1, Array *arr2){
	int i,j,k;
	i=j=k=0;
	Array *arr3 = (Array *)malloc(sizeof(Array));
	
	while (i<arr1->length && j< arr2->length){
		if (arr1->A[i]<arr2->A[j]){
			arr3->A[k++] = arr1->A[i++];
		}
		else{
			arr3->A[k++] = arr2->A[j++];
		}
	}
	
	for(;i<arr1->length;i++){
		arr3->A[k++] = arr1->A[i];
	}
	for(;j<arr2->length;j++){
		arr3->A[k++] = arr2->A[j];
	}
	
	arr3->length = arr1->length+arr2->length;
	
	return arr3;
}

Array* Union(Array *arr1, Array *arr2){
	int i,j,k;
	i=j=k=0;
	Array *arr3 = (Array *)malloc(sizeof(Array));
	
	while (i<arr1->length && j< arr2->length){
		if (arr1->A[i] < arr2->A[j]){
			arr3->A[k++] = arr1->A[i++];
		}
		
		else if (arr1->A[i] > arr2->A[j]){
			arr3->A[k++] = arr2->A[j++];
		}
		else{
			arr3->A[k++] = arr2->A[j++];
			i++;
		}
	}
	
	for(;i<arr1->length;i++){
		arr3->A[k++] = arr1->A[i];
	}
	for(;j<arr2->length;j++){
		arr3->A[k++] = arr2->A[j];
	}
	
	arr3->length = k;
	
	return arr3;
}

Array* Intersection(Array *arr1, Array *arr2){
	int i,j,k;
	i=j=k=0;
	Array *arr3 = (Array *)malloc(sizeof(Array));
	
	while (i<arr1->length && j< arr2->length){
		if (arr1->A[i] < arr2->A[j]){
//			arr3->A[k++] = arr1->A[i++];
			i++;
		}
		
		else if (arr1->A[i] > arr2->A[j]){
//			arr3->A[k++] = arr2->A[j++];
			j++
		}
		else{
			arr3->A[k++] = arr2->A[j++];
			i++;
		}
	}
	
	arr3->length = k;
	
	return arr3;
}

Array* Difference(Array *arr1, Array *arr2){
	int i,j,k;
	i=j=k=0;
	Array *arr3 = (Array *)malloc(sizeof(Array));
	
	while (i<arr1->length && j< arr2->length){
		if (arr1->A[i] < arr2->A[j]){
			arr3->A[k++] = arr1->A[i++];
		}
		
		else if (arr1->A[i] > arr2->A[j]){
			j++;
		}
		else{
			j++
			i++;
		}
	}
	
	for(;i<arr1->length;i++){
		arr3->A[k++] = arr1->A[i];
	}
	
	arr3->length = k;
	
	return arr3;
}

int main(){
	
    Array arr;
    
    cout<<"Enter the size array: ";
    cin>>arr.size;
    
    arr.A = new int [arr.size];
    arr.length = 0;
    
    int n;
    cout<<"Enter How many numbers: ";
    cin>>n;

    cout<<"Enter the elements"<<endl;

    for (int i = 0; i<n; i++){
        cin>>arr.A[i];
    }
    
	arr.length = n;

	cout<<"Displaying"<<endl;
	Display(arr);
	
    cout<<"Appending 5"<<endl;
    Append(&arr,5);

    Display(arr);

    cout<<"Inseting 100 at 4th index"<<endl;
    Insert(&arr,4,100);
    
    Display(arr);

    cout<<"Deleting the 4th index"<<endl;
    Delete(&arr,4); 
    Display(arr);

	int key;
	cout<<"Enter element to search linearly"<<endl;
	cin>>key;
	cout<<"Key found at: "<<LinearSearch(&arr,key)<<endl;
	Display(arr);
	
	cout<<"Enter element to search in Binary"<<endl; // Needs sorted array. We need to sort the array as well.
	cin>>key;
	cout<<"Key found at: "<<BinSearch(&arr,0,arr.length,key)<<endl;
	Display(arr);
	
	cout<<"Enter element to search in Binary Recursion"<<endl; // Needs sorted array. We need to sort the array as well.
	cin>>key;
	cout<<"Key found at: "<<BinSearchRecursion(&arr,0,arr.length,key)<<endl;
	Display(arr);
	
	cout<<"Reverrsing the array"<<endl;
	Reverse(&arr);
	Display(arr);
	
	cout<<"Inserting in sorted array"<<endl;
	InsertSort(&arr,3);
	Display(arr);
	
	cout<<"Rearranging"<<endl;
	Reaarrange(&arr);
	Display(arr);
	
	
	struct Array arr1 = {{2,6,8,10,14},10,5}; // Gives error. Don't use *A in struct
	struct Array arr2 = {{3,5,6,7,,10,11,17},10,5};
	struct Array *arr3, *arr4;
	arr3 = Merge(&arr1,&arr2);
	Display(*arr3);
	
	arr4 = Union(&arr1, &arr2);
	Display(*arr4);
	


    return 0;
} 