#include<stdio.h>
#define SIZE 257
#include<string.h>

void initialize_array(int arr[]){
	int index=0;
	for (index=0; index<SIZE; index++){
		*(arr+index) = 0;
	}

}

void populate_frequency(char str[], int fre[]){
	
	char *p = str;
	while(*p) {
		fre[(*p)] ++;
		p++;
	}
}

int compare_permutation(int freA[], int freB[]){
	
	int index=0;
	for (index=0; index<SIZE; index++){
		if (freA[index] != freB[index]) return 0;
	}
	return 1;

}

int main(int argc, char *argv[]){

char strA[100], strB[100];
int freA[SIZE], freB[SIZE];


gets(strA);
gets(strB);
//strcpy(argv[1], strA);
//strcpy(argv[2], strB);

initialize_array(freA);
initialize_array(freB);

//printf ("%d %d\n", freA[0], freA[2]);

populate_frequency(strA, freA);
populate_frequency(strB, freB);


//printf ("%d %d\n", freA[0], freA[1]);

if (compare_permutation(freA,freB))
	printf ("%s and %s are permutation of each other\n",strA, strB);
else
	printf ("%s and %s are not permutation of each other\n",strA,strB);

return 0;
}
