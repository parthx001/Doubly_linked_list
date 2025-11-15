#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head, *tail;
void create(){
    head=NULL;
    struct node*newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("do you want to continue?(0,1)");
        scanf("%d", &choice);
    }
    printf("your list is created successfully. ");
}

void insert_at_beg(){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: \n");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=NULL;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    printf("Element is successfully inserted at beginning. \n");
}
void insert_at_end(){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: \n");
    scanf("%d", &newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=NULL;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("Element is successfully inserted at end.\n");
}
void insert_at_pos() {
    int pos, i = 1;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    // Invalid position
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    // Case 1: Insert at beginning
    if (pos == 1) {
        insert_at_beg();
        return;
    }

    temp = head;

    // Traverse till (pos - 1)
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // If position is beyond current length
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    // Create new node
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    // Case 2: Insert at end
    if (temp == tail) {
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
    // Case 3: Insert in the middle
    else {
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    printf("Element successfully inserted at position %d\n", pos);
}
void del_at_beg(){
    struct node*temp;
    if(head== NULL){
        printf("list is empty:\n");
    }
    else{
        temp=head;
        head= head->next;
        head->prev=NULL;
        free(temp);
    }
    printf("first element is deleted\n");
}
void del_at_end(){
    struct node*temp;
    if(tail==NULL){
        printf("list is empty");

    }
    else{
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    }
    printf("last element is deleted successfully\n");
}

void del_at_pos(){
    struct node*temp;
    int pos, i=1;
   
    printf("enter the position: ");
    scanf("%d", &pos);
    if(pos==1){
        del_at_beg();
        return;
    }
    temp=head;
    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("invalid position\n");
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("element deleted \n");
    
}
void reverse_d_ll() {
    if (head == NULL) return;   // nothing to reverse
    struct node *current = head;
    struct node *nextnode = NULL;
    //For each node: save original next, swap next and prev, then move to saved next
    while (current != NULL) {
        nextnode = current->next;    //save original next
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;         //move to original next
    }
    // swap head and tail 
    struct node *tmp = head;
    head = tail;
    tail = tmp;
    printf("your list is reversed successfully. ");
}
void display(){
    struct node*temp;
    temp=head;
    printf("The list is : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
int main(){
    int n;
    printf("Menu: \n 1-Create list \n 2-display list \n 3-Insert at beginning \n 4-Insert at end \n 5-Insert at position \n 6-delete at beginning \n 7- delete at end \n 8- delete at pos \n 9-reverse \n 10- exit \n");
    do{
        printf("\nenter your choice: \n");
        scanf("%d", &n);
        switch (n){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_at_beg();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_pos();
                break;
            case 6:
                del_at_beg();
                break;
            case 7: 
                del_at_end();
                break;
            case 8: 
                del_at_pos();
                break;
            case 9:
                reverse_d_ll();
                break;
            case 10:
                printf("exit ");
                break;
            default:
                printf("Enter valid choice: ");
        }
    }while(n!=10);
    return 0;
}