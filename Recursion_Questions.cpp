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


