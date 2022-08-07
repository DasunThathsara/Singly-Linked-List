#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Functions Declaration
void insertB();
void insertE();
void insertM();

int RemoveB();
int RemoveE();

int Count();
void Search();
void display();
void Reverse();

//Creating node structure
struct node {
    int data;            //Data of the node
    struct node *next;   //Address of the next node
};

//Node Declaration
struct node *start = NULL, *ptr, *newNode, *preptr, *ptrT, *ptrR, *prev, *temp;

int op, element, op1, val;
bool value = true;

int main(){

    printf("--------------------- Linked List --------------------");

    while(value){
        printf("\n\n===== MENU =====\n\n");
    	printf("  1. Insert\n");
        printf("  2. Delete\n");
		printf("  3. Search\n");
        printf("  4. Traverse\n");
        printf("  5. Reverse\n");
        printf("  6. Count\n");
        printf("  7. Exit\n");

        printf("\nEnter Option : ");
        scanf("%i", &op);

        switch(op){
        // --------------------- Inserting Options ---------------------
        case 1:
        	printf("\n  1. Insert at the beginning");
	    	printf("\n  2. Insert at the end");
	    	printf("\n  3. Insert at the middle");

	    	printf("\n\nEnter option : ");
	    	scanf("%d", &op1);

	    	if(op1 == 1)
		   		insertB();
	    	else if(op1 == 2)
	    		insertE();
	    	else if(op1 == 3)
	    	 	insertM();

            break;
        // ---------------------- Deleting Options ---------------------
        case 2:
            printf("\n");
        	printf("  1. Delete from the beginning\n");
			printf("  2. Delete from the end\n");

			printf("\nEnter option : ");
	    	scanf("%d", &op1);

	    	if(op1 == 1)
	    		RemoveB();
	    	else if(op1 == 2)
	    		RemoveE();
            break;
        // ----------------------- Search Option -----------------------
        case 3:
            Search();
            break;
        // --------------------- Traversing Option ---------------------
        case 4:
            display();
            break;
        // ---------------------- Reverse Options ----------------------
        case 5:
            Reverse();
            break;
        // ------------------------ Count Option -----------------------
        case 6:
            printf("\nCount : %i\n", Count());
            break;
        // ------------------------ Exit Option ------------------------
        case 7:
            value = false;
            break;
        // -------------------- Invalid input Option -------------------
        default:
            printf("Invalid option...\n");
        }
    }

    return 0;
}

// ------------------------ Inserting Functions ------------------------

// Insert At The End
void insertE(){
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode != NULL){
        printf("\nEnter value : ");
        scanf("%i", &element);

        newNode->data = element;
        newNode->next = NULL;

        if(start == NULL){
            start = newNode;
            ptr = start;
            printf("\nSuccessfully Added\n");
        }
        else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            ptr = ptr->next;
            printf("\nSuccessfully Added\n");
        }
    }
    else
        printf("Memory can not be allocated.");
}

// Insert At The Beginning
void insertB(){
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode != NULL){
        printf("\nEnter value : ");
        scanf("%i", &element);

        ptr = start;
        newNode->data = element;
        newNode->next = NULL;

        if(start == NULL){
            start = newNode;
            ptr = start;
            printf("\nSuccessfully Added\n");
        }
        else{
            newNode->next = start;
            start = newNode;
            printf("\nSuccessfully Added\n");
        }
    }
    else
        printf("Memory can not be allocated.");
}

// Insert At The Middle (Given Location)
void insertM(){
	int location;
	printf("\nEnter Location : ");
	scanf("%i", &location);

	if(location == 1)
        insertB();    // Call Insert At The Beginning (Line 140)
    else{
        ptr = start;
        preptr = NULL;
        int count1 = 0;
        while(ptr != NULL){
            if(count1 == location - 1)
                break;

            preptr = ptr;
            ptr = ptr->next;
            count1++;
        }

        if(Count() >= location){
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode != NULL){
                printf("\nEnter value : ");
                scanf("%i", &element);

                newNode->data = element;
                newNode->next = ptr;
                preptr->next = newNode;
                printf("\nSuccessfully Added\n");
            }
            else
                printf("Memory can not be allocated.");
        }
        else{
            printf("\nOut of range..\n");
        }
    }
}

// ------------------------- Deleting Functions ------------------------

// Delete From The Beginning
int RemoveB(){
    ptrR = start;

	if(start == NULL){
        printf("\nList is empty\n");
    }
    else{
        ptrR = start;
        start = start->next;

        printf("\nDeleted Value is : %i\n", ptrR->data);
        free(ptrR);
        printf("\nSuccessfully deleted\n");
    }
}

// Delete From The End
int RemoveE(){
	ptrR = start;
	preptr = NULL;

	if(start == NULL){
        printf("\nList is empty\n");
    }
    else{
        if(Count() == 1)
            RemoveB();
        else{
            while(ptrR->next != NULL){
            preptr = ptrR;
            ptrR = ptrR->next;
        }

        preptr->next = NULL;
        int data = ptrR->data;
        free(ptrR);

        printf("\nSuccessfully deleted\n");
        printf("\nDeleted Value is : %i\n", data);
        }
    }
}

// --------------------------- Search Option ---------------------------
void Search(){
	printf("\nEnter Value : ");
	scanf("%i", &val);

	int Count = 0;
	ptrT = start;
    while(ptrT->data != val){
    	Count++;
        ptrT = ptrT->next;
    }

    if(Count == 0)
    	printf("\nNothing Found\n");
    else{
    	printf("\n\nFounded. Location is : %d", Count + 1);
	}
}

// ------------------------ Traversing Function ------------------------
void display(){
    ptrT = start;
    if(start == NULL){
        printf("\nList is empty\n");
    }
    printf("\nList : ");
    while(ptrT != NULL){
        printf("%i  ", ptrT->data);
        ptrT = ptrT->next;
    }
    printf("\n");
}

// -------------------------- Reverse Function -------------------------
void Reverse(){
    int countR = 0;
    prev = NULL;
    temp = start;

    while(temp != NULL){
        temp = temp->next;
        start->next = prev;
        prev = start;
        start = temp;
    }

    start = prev;
}

// --------------------------- Count Function --------------------------
int Count(){
    int Count = 0;
	ptrT = start;
    while(ptrT != NULL){
        Count++;
        ptrT = ptrT->next;
    }
    return Count;
}
