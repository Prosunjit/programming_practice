#include<stdio.h>
#include<stdlib.h>

#define MYNULL 0
#define UNDEFINED -999999

struct node{
	int data;
	struct node * next;

};

void print_linklist( struct node *  ref) {
	
	struct node * h = ref;
	while(h) {
		printf("%d \n",(h->data));
		h = h->next;
	}

}

int  get_kth_to_last(struct node * n, int kth) {
	
	struct node * head;
	
	struct node * runner;
	int k = kth;
	head = n;
	runner = n;
	// move runner to the kth from first.
	while ( k > 1 ) {
		
		if ( runner == MYNULL) {
			return UNDEFINED;
		}

		runner = runner->next;
		k --;
	}
	// now head is the head, and runner is kth node ahead

	//lets see when runner reach end
	
	while (runner->next) {
		runner = runner->next;
		head = head->next;
	}

	return head->data;
	
}

void delete ( struct node * n) {
	struct node * prev;
	struct node * curr;
	struct node * head;

	head = n;
	prev = n;
	curr = n->next;
	//check if n is the last in the link list

	if (n->next == MYNULL )
		; // do nothing
	while (curr) {
		if ( curr->data == head->data ) { //value match
			// if curr is the last element
			if (curr->next == MYNULL) {
				prev->next = MYNULL;
				curr = MYNULL;
				//prev = prev;
			} else {
				prev->next = curr->next;
				curr = curr->next;
				// prev = prev;
			}
	
		}
		else { // value does not match
			prev = curr;
			curr = curr->next;
		}

	}

}



void delete_duplicate(struct node * n) {

	struct node * head;
	head = n;

	while (n) {
		delete(n);
		n = n->next;
	}

}

struct node *head = MYNULL;


struct node * get_ref(int data) {

	struct node * cur = head;
	printf("%d",head->data);
	
	while ( cur->data != data ) {

		cur = cur->next;
		printf("test");
	}
	
	return cur;
}

void trick_delete(int value) {
	
	struct node * ref = get_ref(value);
	printf("test2");
	//ref->data = ref->next->data;
	//ref->next = ref->next->next;

}


int main(int argc, char * argv[] ) {

int i,k;

struct node * keep_ref;
struct node * tmp;
int v1_3;
head = (struct node *) malloc(sizeof(struct node));
head->data = atoi( argv[1] );
head->next = MYNULL;

keep_ref = head;

for (i=2; i< argc; i++) {
	tmp  = (struct node *) malloc (sizeof(struct node));
	tmp->data = atoi( argv[i] ) ;
	tmp->next = MYNULL;
	head->next = tmp;
	head = tmp;
}

print_linklist(keep_ref);


//printf("enter kth value:");
//scanf("%d",&k);

//delete_duplicate(keep_ref);

//printf("after delete\n");

//print_linklist(keep_ref);

//printf ("%d\n",keep_ref->data);

//printf("kth to the last element is : %d\n",get_kth_to_last(keep_ref,k));



/*
while ( keep_ref ) {
	printf("%d\n",keep_ref->data);
	keep_ref = keep_ref->next;
}
*/

//exercise 1.3
printf("enter value to delete:");
scanf("%d",&v1_3);

trick_delete(v1_3);

printf("after deleting %d list is\n",v1_3);

//exercise 1.3 end

return 0;
}
