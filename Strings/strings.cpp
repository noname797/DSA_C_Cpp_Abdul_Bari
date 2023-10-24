// Strings // Just an Array of characters with \0
// Aall the library functions for strings are dependent on \0
#include<iostream>


using namespace std;

string changeCase(string s){
	int i = 0;
	for (i = 0; s[i]!='\0'; i++){
		if(s[i]>=65 && s[i]<=90){
			s[i]+=32;
		}
		else if (s[i]>='a' && s[i] <= 122){
			s[i]-=32;
		}
	}
	
	return s;
}

void perm(char *s,int k){
	static int A[10] = {0};
	static char R[10];
	int i;
	
	if (s[k] == '\0'){
		R[k] = '\0';
		printf("%s", R);
	}
	else{
		for (i = 0; s[i]!='\0'; i++){
			if (A[i] == 0){
				A[i] = 1;
				R[k] = s[i];
				perm(s,k+1);
				A[i] = 0;	
			}
			
		}
	}
}



int main(){
	char temp;
	char X[5] = {65,66,67,68}; // Even {'a','b','c'} // This again can be read as string
	char name[10] = {'j','o','h','n','\0'};
	string john = name;
	temp = 'A';
	printf("%d\n",temp);
	printf("%s\n",X);
	printf("%s\n",name);
	// scanf("%s",name); // Reads the alphabets followed by \0
	// gets() // Can be used to read even space.
	
	// reverse case
	string reverseCase;
	reverseCase = changeCase(name); 
	cout<<reverseCase<<endl;
	
	
	// Finding permtations
	char s[] = "abc";
	perm(s,0);

	return 0;
}