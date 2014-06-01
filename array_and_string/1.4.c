#include<stdio.h>
#include<string.h>

void replace_space(char s[], char t[]) {
	
	char *src=s, *dest=t;
	while(*src) {
		if (*src == ' ') {
			src ++;
			*dest++ = '%';
			*dest++ = '2';
			*dest++ = '0';
		} else {
			*dest = *src;
			dest++;src++;
		}	
		
	}

}


int main(){

	char input[1000];
	char output[1000];

	gets(input);
	replace_space(input,output);
	puts(output);


}

