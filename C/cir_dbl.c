#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;
struct cdlist{
    NODE *head;
    //int num_nodes;
};
typedef struct cdlist CDLIST;
NODE *getnode(int ele){
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->llink=NULL;
    temp->rlink=NULL;

    return temp;
}
void init(CDLIST *p){
    p->head=NULL;
}
void insertf(CDLIST *p,int ele){
    NODE *newnode;
    newnode=getnode(ele);
    if(p->head==NULL){
        newnode->rlink=newnode;
        newnode->llink=newnode;
        p->head=newnode;
       
        }
    else {
            NODE *first=p->head;
            newnode->rlink=p->head;
           // first->rlink=newnode;   
           first->llink=newnode;     
             
      }
}
//Inserting at rear
void insertr(CDLIST *p,int ele){
    NODE *newnode;
    newnode=getnode(ele);
    if(p->head==NULL){
        newnode->rlink=newnode;
        newnode->llink=newnode;
        p->head=newnode;
        }
        else{
            NODE *first=p->head;
        NODE *last=(p->head)->llink;
        last->rlink=newnode;
        newnode->llink=last;
        newnode->rlink=first;
        first->llink=newnode;

        }
}
void del_f(CDLIST *p){
    NODE *temp,*last;
    temp=p->head;
    last=(p->head)->llink;
    if(last->rlink==p->head){
        p->head=NULL;
    }
    else{
     

    last->rlink=(p->head)->rlink;
    (p->head)->rlink->llink=last;
    p->head=(p->head)->rlink;
    }
free(temp);
}

void del_rear(CDLIST *p){
    //DIY
    NODE *temp,*last;
    temp=(p->head);
    last=(p->head)->llink;
    last->rlink=temp->rlink;

}
void disp(CDLIST *r){
    NODE *temp;
    temp=r->head;
    if(r->head ==NULL){
        printf("\nList is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->rlink;
    }

}
int main(){
    //printf("111");
    CDLIST l1;
    init(&l1);
    insertr(&l1,100);
    disp(&l1); // getting printed Infinite Times

}
