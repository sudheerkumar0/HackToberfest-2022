#include<stdio.h>
#define QSIZE 5
//Circular Queue implemetation using Arrays
struct queue
{
    int items[QSIZE];
    int front,rear;
};
typedef struct queue QU;

void insert(QU *q1,int ele){ //insert front
    if((q1->rear+1)%QSIZE==q1->front)
     {
        printf("QUEUE FULL ,CANNOT INSERT");
     }
    
    q1->rear=(q1->rear+1)%QSIZE;
    //q1->front=(q1->front+1)%QSIZE;

    q1->items[q1->rear]=ele;
    if(q1->front==-1)
     q1->front=0;
}
int  delete(QU *q1){
int x;
if(q1->front==-1){
    printf("Queue is empty");
    return -1;
}
else{
    x=(q1->items[q1->front]);
    if(q1->front==q1->rear) // ONLY ONE ELEMENT 
     q1->front=q1->rear=-1;
    else 
     q1->front=(q1->front+1)%QSIZE;
    return x;
}
}
void display(QU *q1){
   
   int i=q1->front;
   int j=q1->rear;
   while(i!=j){
    printf("\n%d",q1->items[i]);
    i=(i+1)%QSIZE;
   }
   printf("\n%d",q1->items[i]);
}
void cur(QU *q1){
    printf("\nCurrently front is at %d",q1->front);
        printf("\nCurrently rear is at %d",q1->rear);

}
int main(){

QU q;
int x;
q.rear=-1;
q.front=-1;
//Insert , remove and empty functions to be implemented 
insert(&q,10); //del
insert(&q,20);
insert(&q,30);
insert(&q,40);
insert(&q,80);
delete(&q);
cur(&q);
insert(&q,500);
cur(&q);

}