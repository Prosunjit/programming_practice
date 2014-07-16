#include<stdio.h>
#define N 100

void print_image(double img[N][N], int n){
	int i,j;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			printf ("%.2lf ",img[i][j]);
		printf ("\n");
	}
}

int main(){

int n;
int i,j;
double img[N][N];

scanf("%d\n",&n);

for (i=0; i< n; i++) {
	for (j=0; j<n; j++) {
		scanf("%lf ",&img[i][j]);	
	}
	
}

print_image(img, n );

for (i=0; i<n; i++) {
	for (j=i; j<n; j++) {
		img[j][i] = img[i][j];
	}

}

printf("\n");
print_image(img,n);


	


return 0;
}
