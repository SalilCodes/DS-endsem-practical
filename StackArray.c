#include <stdio.h>;
#include <stdlib.h>;

//Impliment STACK using ARRAY.

struct stack{
  int size;
  int top;
  int * arr;
};

isEmpty(struct stack * ptr){
  if(ptr->top == -1)
    return 1;
  else
    return 0;
}

isFull(struct stack * ptr){
  if(ptr->top == ptr->size - 1)
    return 1;
  else
    return 0;
}

void push(struct stack* ptr, int val){
  if(isFull(ptr))
    printf("stack overflow");
  else{
    ptr->top++;
    ptr->arr[ptr->top] = val;
  }
    
}

int pop(struct stack* ptr){
  if(isEmpty(ptr))
    printf("stack underflow");
  else{
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}
int main(){
  int n;
  struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
  printf("Size of your stack?\n");
  scanf("%d",&n);
  sp->size = n;
  sp->top = -1;
  sp->arr = (int *)malloc(sp->size*sizeof(int));
  printf("Stack successfully implemented using Array");
  printf("contribution check");
  printf("contri check again");

  


}
