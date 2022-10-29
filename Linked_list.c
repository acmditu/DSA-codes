#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linked_list_traversal(struct node *ptr){
    if(ptr==NULL){
        printf("No elements in linked list");
    }
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
struct node* Insert_first(struct node*head,int item){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=head;
    
   
    return ptr;

}
struct node *Insert_last(struct node*head,int item){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;

    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node*Insert_index(struct node*head,int index,int item){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=item;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
struct node* Delete_first(struct node*head){
    struct node*ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
struct node *Delete_index(struct node *head,int index){
    struct node*p=head;
    struct node*q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node*Delete_last(struct node*head){
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main(){
   
    int option,in,d,n;
    struct node *head;
    struct node *second;
    struct node *third;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=18;
    third->next=NULL;
    
    while(1){
        printf("Linked List operations");
        printf("\n 1. Insert at First");
        printf("\n 2. Insert at any index");
        printf("\n 3. Insert at last");
        printf("\n 4. Delete at First ");
        printf("\n 5. Delete at any index");
        printf("\n 6. Delete at last");
        printf("\n 7.Display");
        printf("\n 8. Exit");
        printf("\nEnter your choice");
    scanf("%d",&option);
    switch(option){
        
        case 1:
        printf("Enter Number to be inserted:");
        scanf("%d",&n);
        head = Insert_first(head, n);
        break;
        case 2:
        printf("Enter Number to be inserted:");

        scanf("%d",&n);
         printf("Enter index where you want to insert ");
        scanf("%d",in);
         head = Insert_index(head, n, in);
        break;
        case 3:
        printf("Enter Number to be inserted:");
        scanf("%d",&n);
        head = Insert_last(head,n);
        break;
        case 4:
        head = Delete_first(head);
        break;
        case 5:
        printf("Enter index where you want to delete ");
        scanf("%d",d);
         head = Delete_index(head, d);
        break;
        case 6:
        head = Delete_first(head);
        break;
        case 7:
        linked_list_traversal(head);
        break;
        case 8:
        exit(0);
        break;
        default:
            printf("Enter Correct Choice :(((");
            break;
    }
    }
}
