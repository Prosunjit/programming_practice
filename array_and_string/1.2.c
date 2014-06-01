#include<stdio.h>


void swap(char* x, char* y);
void string_reverse(char input[]);

int main(){

	char s[100];
	scanf("%s",&s);
	printf ("%s\n",s);
	printf ("str len is %d\n",str_length(s));
	string_reverse(s);
	printf ("reversed string is: %s\n",s);


	return 0;
}

void swap(char *x, char *y){

	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void  string_reverse(char input[]){
	//get the lenght of the input ( 0 indexed)
	int index, length = str_length(input) - 1;
	
	for (index=0; index <= length/2; index ++)
		swap(&input[index], &input[length-index]);

}

int str_length(char *input){
	int index = 0;
	while ( input[index] != '\0' ) index++;
	return index;
}
