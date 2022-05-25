// Sum of first n natural numbers using recursion
// loops are faster and consumes less space check notes
#include <iostream>

using namespace std;

int sum = 0;

void recurr(int x){
	if (x==0)
		return;
		
	sum = sum + x;
	recurr(x-1); 
	
}

int main(){
	int a = 5;
	recurr(5);
	printf("%d",sum);
}

// OR

#include<iostream>
using namespace std;


int sum(int x){
	if (x==0)
		return 0;
	return sum(x-1) + x;
}

int main(){
	int a = 5;
	printf("%d",sum(a))
}

// Factorial using Recursion
#include<iostream>
using namespace std;


int factorial(int x){
	if (x==0 || x==1){
		return 1;
	}
	else{
		return x*factorial(x-1);
	}
}

int main(){
	int a = 5;
	printf("%d",factorial(a));
	return 0;
}


// Exponents a^n
#include<iostream>

using namespace std;

int power(int a, int n){
	if (n == 0)
		return 1;
	return a*power(a,n-1);
	
}

int main(){
	int a = 5, b = 3;
	
	printf("%d",power(a,b));
	return 0;
}

// OR using optimized method with reduced number of multiplication operations

#include<iostream>

using namespace std;

int power(int a, int n){
	if (n == 0)
		return 1;
	if (n%2 == 0)
		return power(a*a,n/2);
	else
		return a*power(a*a,(n-1)/2);
}

int main(){
	int a = 2, b = 9;
	
	printf("%d",power(a,b));
	return 0;
}


// e^x in recursion 
#include<iostream>

using namespace std;

double e(int x, int n){ // x is the power of e, n is how many terms we want
	static double p=1,f=1;
	double r;
	if (n==0)
		return 1;
		
	r = e(x,n-1);
	p = p*x;
	f = f*n;
	return r + p/f;

}

int main(){
	printf("%lf \n",e(1,5));
	return 0;
}

// Optimizing e^x 
#include<iostream>

using namespace std;

double e(int x, int n){ // x is the power of e, n is how many terms we want
	static double s;
	
	if (n==0)
		return s;
	s = 1+ x*s/n;
	return e(x,n-1);

}

int main(){
	printf("%lf \n",e(1,5));
	return 0;
}

// Taylor series iteratively
#include<iostream>

using namespace std;

double e(int x, int n){ // x is the power of e, n is how many terms we want
	double s=1;
	int i;
	double num=1;
	double den=1;
	for (int i=1;i<=n;i++){
		num*=x;
		den*=i;
		s+=num/den;
	}
	return s;
	

}

int main(){
	printf("%lf \n",e(1,10));
	return 0;
}


// Sine series recursion
#include<iostream>
#include<cmath>
using namespace std;


double sine(double x, double n){
	static double s=1;
	double r,m = (2*n-1);
	
	if ((n==0)|| (n==1))
		return s;
		
	s = 1-(pow(x,2)/(m*(m-1)))*s;
	
	return sine(x,n-1);
}

;
int main(){
	double x=5, n=10;
	double r = x*sine(x,n);
	printf("%lf \n",r);
	return 0;
}


// Cosine series using recursion
#include<iostream>
#include<cmath>
using namespace std;


double cos(double x, double n){
	static double s=1;
	double r,m = 2*(n-1);
	
	if ((n==0)||(n==1))
		return s;
		
	s = 1-(pow(x,2)/(m*(m-1)))*s;
	
	return cos(x,n-1);
}


int main(){
	double x=5, n=10;
	double r = cos(x,n);
	printf("%lf \n",r);
	return 0;
}

// Fibonnaci Series using iteration

#include<iostream>

using namespace std;

int fib(int n);

int main(){
	int r = fib(7);
	printf("%d",r);
}

int b = 0, f = 1 , s =0;

int fib(int n){
	if (n<=1){
		return n;
	}
	for (int i=2; i<n;i++){
		s = f +b;
		b = f;
		f = s;
	}
	
	return b+f;
}

// Fibonnaci Series using recursion

#include<iostream>

using namespace std;

int fib(int	n);

int main(){
	int r = fib(7);
	printf("%d",r);
}

int fib(int n){
	if (n<=1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}

// Fibonnaci Series using recursion

#include<iostream>

using namespace std;

int fib(int	n);

int f[10];

int main(){
	for (int i=0; i<10;i++)
		f[i] = -1;
	
	int r = fib(7);
	printf("%d",r);
}



int fib(int n){
	if (n<=1){
		f[n] = n;
		return n;
		}
	else{
		if (f[n-2] == -1)
			f[n-2] = fib(n-2);
		if (f[n-1] == -1)
			f[n-1] = fib(n-1);
		
		return f[n-2] + f[n-1];
		
		
	}
}

// nCr using direct method
#include<iostream>

using namespace std;

int fact(int n){
	if (n==0) return 1;
	return fact(n-1)*n;
}

int nCr(int n,int r){
	int num,den;
	num = fact(n);
	den = fact(r)*fact(n-r);
	
	return num/den;
}

int main(){
	printf("%d \n", nCr(5,2));
	return 0;
}

// nCr using basic maths
#include<iostream>

using namespace std;

double bruh(double n,double r){ // if we use int then due to datatype calculations ans are coming wrong
	
	if ((n==0) || (n==r) || (r==0))
		return 1;
		
	return (n/(n-r))*bruh(n-1,r);

}

int main(){
	printf("%d \n", bruh(5,1)); // %lf for float
	return 0;
}


// nCr using pascal's traingle
#include<iostream>

using namespace std;

int nCr(int n, int r){
	if (n==r || r==0)
		return 1;
	return nCr(n-1,r-1) + nCr(n-1,r);
}

int main(){
	printf("%d \n",nCr(5,1));
	return 0;
}

//Tower of hanoi using recursion

#include<iostream>

using namespace std;

void TOH(int n,int a,int b,int c){
	if(n>0){
		TOH(n-1, a,c,b);
		printf("(%d,%d)\n",a,c);
		TOH(n-1,b,a,c);
	}
	
}


int main(){
	TOH(3,1,2,3);
	return 0;

}