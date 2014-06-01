#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

int choice[N];

int stair(int n){
	
	if (choice[n] != -1 )
		return choice[n];
	else 
		return stair(n-1) + stair(n-2) + stair(n-3);

}

int main() {
	int input;
	//initialize choice with -1
	memset (choice, -1, sizeof (int) * N);
	choice[0] = 0;
	choice[1] = 1;
	choice[2] = 2;
	choice[3] = 4;
	printf("Number of stair:");
	scanf("%d",&input);

	printf("# of choice is %d\n",stair(input));
	return 0;
}
