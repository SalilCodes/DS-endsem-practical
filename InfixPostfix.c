#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack{
  int size;
  int top;
  char * arr;
};

int isEmpty(struct stack * ptr){
  if(ptr->top == -1)
    return 1;
  else
    return 0;
}

int isFull(struct stack * ptr){
  if(ptr->top == ptr->size - 1)
    return 1;
  else
    return 0;
}

char stackTop( struct stack * ptr){
  if(isEmpty(ptr))
    return('\0');
  else
    return ptr->arr[ptr->top];
}

void push(struct stack* ptr, int val){
  if(isFull(ptr))
    printf("stack overflow");
  else{
    ptr->top++;
    ptr->arr[ptr->top] = val;
  }
    
}

int prec(char op){
  if(op=='*' || op=='/')
    return 2;
  else if(op=='+' || op=='-')
    return 1;
  else
    return 0;
}


char pop(struct stack* ptr){
  if(isEmpty(ptr))
    printf("stack underflow");
  else{
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}

void infixToPostfix(char infix[]){
  struct stack s;
  s.top = -1;
  s.size = strlen(infix);
  s.arr = (char *)malloc(s.size*sizeof(char));
  
  if(s.arr==NULL){
    printf("Memory allocation failed");
    return;

  }
  
  char postfix[2*s.size + 1];

  int i=0, j=0;

  while(infix[i] != '\0'){
    if (infix[i] == ' '){
      i++;
      continue;
    }

    else if(infix[i] >= '0' && infix[i] <= '9'){
      while(infix[i] >= '0' && infix[i] <= '9'){
        postfix[j++] = infix[i++];
      }

      postfix[j++] = '0';
      continue;
    }

    else if(infix[i]=='('){
      push(&s,infix[i]);
    }
    else if(infix[i]==')'){
      while(isEmpty(&s) && stackTop(&s) !='('){
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';  
      }
      if(!isEmpty(&s))
        pop(&s);
    }
    else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
      while(!isEmpty(&s) && stackTop != '(' && prec(stackTop(&s)) >= prec(infix[i]) ) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
      }

      push(&s,infix[i]);
    }

    i ++;
  }

  while(!isEmpty(&s)){
    postfix[j++] = pop(&s);
    postfix[j++] = ' ';
  }

  postfix[j] = '\0';
  printf("Postfix: %s", postfix);

  free(s.arr);

}

int main(){
  char infix[100];

  printf("Enter infix expression: \n");
  fgets(infix, sizeof(infix), stdin);

  int i = 0;

  while(infix[i] != '\0' && infix[i] != '\n'){
    i ++;
  }

  infix[i] = '\0';

  infixToPostfix(infix);

  return 0;

}