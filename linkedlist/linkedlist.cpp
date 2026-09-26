#include <stdio.h>
#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    };
struct Node2 {
    double data;
    struct Node2* next;
};

struct Node* createNode(int value) {
    struct Node* tmp = (Node*)malloc(sizeof(struct Node));
   tmp->data = value;
   tmp->next = NULL;
   printf("node created with value %d \n", value);
    return tmp;
}

//creade node but with double 
struct Node2* createNode2(double value) {
    struct Node2* tmp = (Node2*)malloc(sizeof(struct Node2));
    tmp->data = value;
    tmp->next = NULL;
    return tmp;

}
//changes head
void changeHead(struct Node* oldhead, struct Node* nexthead) {
    struct Node* temp = nexthead;
    nexthead->next = oldhead->next;
    oldhead->next = temp->next;
    *oldhead = *nexthead;
    printf("head changed \n");

}

//replaces 2 nodes
void replace(struct Node** prev, struct Node** target) {
    // A - prev is a pointer, which has an address
    //i want this address to point to target
    //which means i want prev's value, which is an address, to be target's address
    //B - 
    struct Node* temp = *prev;
    
    *prev = *target; // A - complete
    *target = temp;
    
    printf("replaced \n");
}
//function that adds a node to end of a list, using the head
void addToList(struct Node** head, struct Node** nodetoadd) {
        //pointer that points to a struct node pointer
    struct Node** ptr = head;
    
    while ((*ptr)->next != NULL)
    {
        ptr = &((*ptr)->next);
 
    }
    (*ptr)->next = *nodetoadd;
    printf("added to list\n");
}
void deleteFromListAddress(struct Node** head,struct Node** member) {
    
    // IF YOU PUT 0 (aka head itself) THIS WILL IMPLODE.

    
    struct Node** ptr = head; //ptr starts at head
    printf("deleting from list...\n");
    while ((*ptr)->next != *member) {
        printf("%d \n", (*ptr)->data);
        ptr = &((*ptr)->next);
    }
    
    
    //after the while loop, ptr points to the previous node. right now : (prev).
    //I want to make prev node's next to point to next node. (next) = (*member)->next.
    (*ptr)->next = (*member)->next; //now prev skips the member.
    // right now, its like ...->(prev)->(next)->...
    //so long as the order doesnt change, the values shouldnt be important

    printf("deleted from list\n");
}
struct Node** getNodePointer(struct Node** head, int index) {
    //returns pointer to indexth member of list
    // index 0 would be the head
    struct Node** ptr = head;
    if (index == 0) {
        return head;
    }
    int counter = 0;
        while (counter < index) 
        {
                                
            //if index = 0, this will not run,0<0==0, counter will stay at 1
            //if index = 1, 0<1==1, this will run, ptr will point to next node,


            ptr = &((*ptr)->next); // like if its 0, this will never run because itll equal 0, 
            counter++;                       //which means the while statement isnt true
                                    // if you say index 1, itll point to next member from head,
        }
    printf("pointing to member with value of %d\n",(*ptr)->data);
    return ptr;
}

void addToListUnnamed(struct Node** head, int value) {
    struct Node* temp = createNode(value);
    addToList(head, &temp);
    printf("added unnamed node to list\n");

}

int main()
{
    struct Node* head = createNode(3);
    

    addToListUnnamed(&head, 6767);
    addToListUnnamed(&head, 67672);
    addToListUnnamed(&head, 671);
    addToListUnnamed(&head, 123);
    addToListUnnamed(&head, 1235);
    for (int i=0; i < 25; i++) {
        addToListUnnamed(&head, i);
    }
    
    struct Node** memberindex = (getNodePointer(&head, 1));
    printf("-------------- \nsigma %d \n------------ \n", ((*memberindex)->data));
    deleteFromListAddress(&head, memberindex);
    memberindex = (getNodePointer(&head, 15));
    printf("------------ \nsigma %d \n------------ \n", (*memberindex)->data);
    
    printf("Got to end.");
    return 0;
}


