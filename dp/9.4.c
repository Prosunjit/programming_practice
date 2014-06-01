#include<stdio.h>
#include<string.h>
#define SIZE 10
#define LEN 10000

char result[LEN][SIZE];
int indes; // number of element in the result

void set(char ch) {
	int i;
	char tmp[2];
	int existing=indes;
	char tmp_res[20];
	tmp[0]=ch;
	tmp[1] = '\0';

	for(i=0; i<existing; i++) {
		strcpy(tmp_res,result[i]);
		strcat(tmp_res,tmp);
		strcpy(result[indes], tmp_res);
		indes++;
	}
	
}

void print_set() {

	int i=0;
	for(i=0; i<indes; i++) {
		printf("%d) %s\n",i,result[i]);
	}

}



int main() {

int i,len;

char input[SIZE];
indes = 0;
strcpy(result[indes],"");
indes++;
scanf("%s",input);
len= strlen(input);

for(i=0; i<len; i++){
	set(input[i]);

}


print_set();
return 0;
}
