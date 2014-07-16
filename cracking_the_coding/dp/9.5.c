#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100000

char prev[N][20];
char cur[N][20];
int prev_length=0;
int cur_length=0;
char newStr[20];

char * insert_at_position(char base[20], char ch, int position) {
	// abcd, x
	int base_index=0;
	int index=0;
	int length,i;
	//char newStr[20];

	length = strlen(base) + 1;

	for(i=0; i<length; i++) {
		if (i==position) {
			newStr[index++] = ch;	
		}
		else {
			newStr[index++] = base[base_index++];
		}
	}
	newStr[index] = '\0';
	return newStr;


}

void copy_content(){
//set prev_length = 
	int i,j;
	prev_length = 0;

	for (i=0; i<cur_length; i++) {
		strcpy(prev[prev_length++], cur[i]);
	}
	
	//prev_length = cur_length;
	//cur_length = 0;

}

void my_permutation(char ch) {
	int i,j,k;
	int perm_length;
	char base[20];
	cur_length=0;

	if (prev_length == 0) {
		base[0] = ch;
		base[1] = '\0';
		strcpy(cur[cur_length++],base);
		//return ;
	} else
	
	for(i=0; i<prev_length; i++) {
		perm_length = strlen(prev[i]);
		for(j=0; j<=perm_length; j++) {
			//cur[cur_length++] = insert_at_position(prev[i],ch,j);
			strcpy(cur[cur_length++], insert_at_position(prev[i],ch,j));
		}
	}
	copy_content(); // copy from cur to prev. cur should be 0 sized.


}


void print_prev() {
	int i,j;
	printf("prev is %d\n",prev_length);
	for (i=0; i<cur_length; i++) {
		printf("%s\n",cur[i]);
	}

}


int main(){

	//insert_at_position("abcd",'x',4);
	//printf("abcd + x at  is %s",newStr);
//printf ("%s","abcd");
/*	
	cur_length=0;
	strcpy(cur[cur_length++],"bac");
	strcpy(cur[cur_length++],"def");

	copy_content();


	printf("%s %d",prev[1],prev_length);

*/

	
	char input[20];
	int input_length;
	int i,j;
	printf("enter string to permutate:");
	scanf("%s",input);
	//printf("%s",input);
	input_length = strlen(input);

	for(i=0; i<input_length; i++) {
		my_permutation(input[i]);
	}

	print_prev();
	
}


