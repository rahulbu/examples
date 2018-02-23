//stack operations using function pointers
#include<stdio.h>
const size=5;
void push(int*,int*);
void pop(int*,int*);

int main()
{
    int stack[size],top=-1;
    unsigned int ch;
    void (*funptr[])()={push,pop};//function pointer array
    printf("stack\n");
    while(1)
    {
            printf("1.push 2.pop\n");
            scanf("%d",&ch);
            if(ch<3)
                    (*funptr[ch-1])(stack,&top);
            else break ;
    }
    return 0;
}

void push(int *stack,int *top)
{
    if(*top>=size-1){
        printf("stack is full\n");
        return;
    }
    int item;
    printf("enter the item : ");
    scanf("%d",&stack[++(*top)]);
}
void pop(int *stack,int *top)
{
    if(*top<0){
        printf("stack is empty\n");
        return;
    }
    printf("%d popped\n",stack[(*top)--]);
}
