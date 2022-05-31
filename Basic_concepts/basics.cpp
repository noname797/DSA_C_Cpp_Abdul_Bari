//% Array Basics
#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
   int A[5] = {2,4,6,8,10};
   int A[] = {1,2,3,4,5,6};

   int A[10] = {1,2,3,5,4};
//    % A[6] = 0 remaining all elements will be 0
    
    int A[10] = {0};
//    % Initialises araay A of all elements 0


    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    cout<<sizeof(A);

    for (int i = 0; i < 10; i++)
    {
        cout<< A[i]<<endl;
    }
    
//    % Example of for each loop

   for (int x:A )
   {
       cout<<x<<endl;
   }


    return 0 ;
}


// Structures

#include<stdio.h>
#include<iostream>

using namespace std;

struct Rectangle{
	int length;
	int breadth; // char x; //padding in memory : 4 bytes are assigned but only one byte is consumed for making accessiblity easy
}; // } r1,r2,r3,r4; // Declaration

// struct Rectangle r1; // will be accessible to all functions



int main()
{
	struct Rectangle r1 = {10,5};
	
	printf("%d",sizeof(r1));
	

}



// Pointers 
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
//	int a = 10;
//	int *p; // only for declaration and dereferencing we use *
//	p = &a;
//	
//	cout<<*p;

// array in stack main frame of the function

	int A[5] = {2,4,6,8,10};
	int *p;
	p = A; // no "&" when giving an array as A itself is thestarting address of the array
	// p = &A[0] works too
	
	
	for (int i=0;i<5;i++){
		cout<<A[i]<<endl;
		cout<<p[i]<<endl;
	}
	
	// Array in the heap
	
	int *p;
	p = (int *)malloc(5*sizeof(int));
	
	// p = new int[5];
	
	p[0] = 2;
	p[1] = 4;
	p[2] = 6;
	p[3] = 8;
	p[4] = 10;
	
	// Whenever we are using dynamic memory/ heap memory we should free it 
	// delete [] p;
	// free(p);
	
	for (int i = 0; i<5;i++){
		cout<<p[i]<<endl;
	}

	
	
	// All pointers are 8 bytes independent of data type
	
	
	
	return 0;
}

// Reference

int main(){
    int a = 10;
    int &r = a; // declares r as the reference to a


}

// Pointers to sturctures
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

int main(){
	struct Rectangle r={10,5};
	// in C++ Rectangle r={10,5}; works 
	
	cout<< r.length<<endl;
	
	struct Rectangle *p;
	p = & r;
	//cout<<(*p).length<<endl;
	cout<<p->breadth<<endl;
	
	// for variable use . for pointer use ->
	
	
	// Creating object in heap
	
	struct Rectangle *p;
	p = new struct Rectangle; // for C/C++ even "new Rectangle" works
	p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // for C 
	
	p->breadth = 15;
	p->length = 20;
	
	cout<<p->length<<endl;
	
	
	
	
	
	return 0;
	
}

// Functions
#include<iostream>

using namespace std;

// Using template class
template <class T>
T add(T a,T b){
	return (a+b);
}

// Normal function
int adder(int a, int b){
	return  (a+b);
}

int main(){
	int num1 = 10, num2 = 15,sum;
	sum = adder(num1,num2);
	cout<<sum<<endl;
	
	float num3=10.042, num4=11.0245,sum2;
	sum2 = add<float>(num3,num4);
	cout<<sum2;

	
}

// Parameter passing methods


#include<iostream>

using namespace std;

// Normal function

//call by value
int adder(int a, int b){
	return  (a+b);
}


// call by address
// modifying actual parameters
void swap(int *a, int *b ){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// call by reference

void swapref(int &x,int &y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}


int main(){
	int num1 = 10, num2 = 15,sum;
	sum = adder(num1,num2);
	cout<<sum<<endl;
	
	swap(&num1,&num2);
	cout<<num1<<endl<<num2;
	
	swapref(num1,num2);
	cout<<num1<<endl<<num2;
	

	
}


// Aray as Parameters
#include <iostream>
using namespace std;


void fun (int A[], int n){ // Even int *A, int n works
	// arrays are always passed by address
	
	cout<<sizeof(A)/sizeof(int)<<endl; // output is 2 this implies only int* is passed through the function
	// pointer of latest compilers take 8 bytes and int is of 4 bytes


	for (int i = 0; i<n;i++){
		cout<<A[i]<<" ";
	}
}

// Creating a function that'll return array

int * funptr(int size){
	int *p;
	p = new int[size];
	
	for (int i =0; i<size; i++){
		p[i] = i+1;
	}
	return p
	
}

int main(){
	int A[] = {2,4,6,8,10};
	int n = 5;
	
	fun(A,n);
	cout<<endl<<sizeof(A)/sizeof(int)<<endl;// This shows 5
	
	for (int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	
	int *ptr,sz = 5;
	ptr = funptr(sz)
	for (int i=0; i<sz;i++){
		cout<<ptr[i]<<endl;
	}
}


// Structure as parameter
#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

void fun (struct Rectangle r){ // Call y value
	cout<<"Length "<<r.length<<endl<<"Breadth "<<r.breadth<<endl;
}

void funcba (struct Rectangle *r){ // Call by address
	cout<<"Length "<<r->length<<endl<<"Breadth "<<r->breadth<<endl; // for pointers we use ->
	
}


int main(){
	struct Rectangle r={10,5};
	
	printf("Length %d \nBreadth %d \n",r.length,r.breadth);
	fun(r);
	funcba(&r);
	
	return 0;
}

// Structure as parameter in a Heap
#include<iostream>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

struct Rectangle * fun(){
	struct Rectangle *p;
	p = new Rectangle;
//	p = (struct Rectangle *)malloc(sizeof(struct Rectangle));  // For C 

	p->breadth = 7;
	p->length = 10;
	return p;
}

int main(){
	
	struct Rectangle *p;
	p=fun();
	cout<<"Length "<<p->length<<endl<<"Breadth "<<p->breadth<<endl;
	return 0;
}


// Monolithic Style of Programming
// Everything in the main function
// always initialize the variable 

#include<iostream>

using namespace std;

int main(){
	int length=0,breadth = 0;
	printf("Enter Length & Breadth ");
	cin>>length>>breadth;
	
	int area = length*breadth;
	
	int peri = 2*(length + breadth);
	
	printf("Area %d \nPerimeter %d",area,peri);
	
	
	return 0;
}

//Modular or Procedural Programming
#include<iostream>

using namespace std;

int area(int a, int b){
	return a*b;
}

int peri(int a, int b){
	return 2*(a+b);
}

int main(){
	
	int length=0, breadth=0;
	printf("Enter Length & Breadth ");
	cin>>length>>breadth;
	printf("Area %d \nPerimeter %d",area(length,breadth),peri(length,breadth));
	
	
	return 0;
}

// Structures and functions

#include<iostream>

using namespace std;

struct Rectangle {
	int length;
	int breadth;
};


int area(struct Rectangle r){
	return r.length*r.breadth;
}

int peri(struct Rectangle r){
	return 2*(r.length+r.breadth);
}


int main(){
	
	struct Rectangle r={0,0};
	printf("Enter Length & Breadth ");
	cin>>r.length>>r.breadth;
	printf("Area %d \nPerimeter %d",area(r),peri(r));
	
	
}

// OOPS

#include<iostream>

using namespace std;

class Rectangle {
	private:
		
		int length;
		int breadth;
		

	public:
		
		Rectangle (){
			length = 0;
			breadth = 0;
		}
		
		Rectangle(int l,int b){
			length = l;
			breadth = b;
		}

		int area(){
			return length*breadth;
		}
		
		int peri(){
			return 2*(length+breadth);
		}
		
		~Rectangle(){
			cout<<"Destructor";
		}
	
};


int main(){
	

	int l,b;
	printf("Enter Length & Breadth ");
	cin>>l>>b;
	Rectangle r(l,b);
	
	printf("Area %d \nPerimeter %d",r.area(),r.peri());
	
	
}

// Template Classes

#include<iostream>

using namespace std;

template <class T>
class Arithmatic{
	private:
		T a;
		T b;
		
	public:
		Arithmatic(T a , T b);
		T add();
		T sub();
};
template <class T>
Arithmatic<T>::Arithmatic(T a , T b){
			this->a = a;
			this->b = b;
		}
template <class T>
T Arithmatic<T>::add(){
	return (a+b);
}
template <class T>
T Arithmatic<T>::sub(){
	return (a-b);
}

int main(){
	int a,b;
	cout<<"Enter two numbers ";
	cin>>a>>b;
	Arithmatic<int> ar(a,b);
	printf("Add %d \nSub %d",ar.add(),ar.sub());
	

	
	return 0;
}

// How to debug in Dev C++

#include <iostream>
using namespace std;

// Steps to debug
// Select the break point from where debugging must start by clicking on the number on the left
// Debug the program
// Add the variable to watch by right clicking on it
// do next line and continue debugging


int main() {
	int sum =0;
	int A[]={1,2,3,4,5,6,7,8,9};
	
	for (int x:A){
		sum = sum+x;
	}
	
	cout<<sum;
	return 0;
}