#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define X 100
#define Y 200
#define ERROR -99999

int mem[X][Y];

int choice(int x, int y) {
	
	if (x < 0 || y < 0 ) 
		return ERROR;

	if ( mem[x][y] != -1 )
		return mem[x][y];


	if ( ( (x-1) >=0) && ((y-1)>=0) ){
		printf("case 1\n");
		mem[x][y] = choice(x-1,y) + choice(x,y-1);
		return mem[x][y];
	}
	 if (( (x-1) >=0)) {
		printf("case 2\n");
		mem[x][y] = choice(x-1,y);
		return mem[x][y];
	} 
	if (((y-1)>=0)) {
		printf("case 3\n");
		mem[x][y] = choice(x,y-1);
		return mem[x][y];
	}
}

int main(){

int rowsize, colsize;

// initialize mem with -1
memset(mem,-1,sizeof(mem));
mem[0][0] = 1;
printf("row size:");
scanf("%d",&rowsize);
printf("col size:");
scanf("%d",&colsize);
printf("# of choice is: %d\n",choice(rowsize,colsize));
return 0;
}


