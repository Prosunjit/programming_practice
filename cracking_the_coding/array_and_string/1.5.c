#include<stdio.h>
#define null '\0'

int main(){

char input[1000];
char *p,*q;
int index,count=1;
char current;
char output[1000];

gets(input);

p = input;
q = output;
current = *p;
index = 0;

count = 1;
while(*p){
	
	if ( *p  == *(p+1) ) { // if current symbol == next symbol
		count++;
	
	}else {
		*q++ = *p;
		*q++ = 48 + count;
		count=1;
	}

	p++;
}

*p = null;

puts(output);


return 0;
}
