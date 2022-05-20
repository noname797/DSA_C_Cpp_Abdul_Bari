// Basic

#include <iostream>

using namespace std;

void fun(int n){
	if (n>0){
		printf("%d",n);// head recursion
		fun(n-1);
		printf("%d",n-1);// tail recursion
	}
}

int main(){
	int n=3;
	fun(n);
	return 0;
}

// Static and global variables

#include <iostream>

using namespace std;

//int x =0; // global var
int fun(int n){
	//static int x = 0; // static variable
	if (n>0){
		// x++;
		return fun(n-1)+n; // fun(n-1)+x
	}
	return 0;
}

int main(){
	int a = 5;
	printf("%d",fun(5));
	return 0;
}

// Tree Recursion
#include <iostream>

using namespace std;

void fun(int n){
	if (n>0){
		printf("%d",n);
		fun(n-1);
		fun(n-1);
	}
}

int main(){
	fun(3);
	return 0;
}

// Indirect Recursion

#include <iostream>

using namespace std;

void fb(int n); // Before using a function it must be defined

void fa(int n){
	if (n>0){
		printf("%d",n);
		fb(n-1);
	}
}

void fb(int n){
	if (n>1){
		printf("%d",n);
		fa(n/2);
	}
}

int main(){
	fa(20);
	return 0;
}

// Nested recursion

#include <iostream>

using namespace std;

int fun(int n){
	if (n>100)
		return n-10;
	else
		return fun(fun(n+11));
}

int main(){
	cout<<fun(96);
	return 0;
}