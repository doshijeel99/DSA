

#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int x){
    if(top==SIZE-1){
       printf("STACK OVERFLOW");
    }
    else{
        stack[++top]=x;
    }
}
int pop(){
    int x=-1;
    if(top==-1){
        printf("STACK EMPTY");
        return 0;
    }
    else{
        x=stack[top--];
        return x;
    }
}
void peek(){
    if(top==-1){
        printf("STACK EMPTY");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
    int i;
    if(top==-1){
        printf("Stack empty");
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d",stack[i]);
        }
        
    }
    printf("\n");
}
int main()
{
    int choice=0,x;
    do{
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    printf("Enter element to be pushed:");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2:
                    x=pop();
                    printf("Deleted element: %d",x);
                    break;
            case 3:
                    peek();
                    
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(0);
                    break;
        }
    }while(choice<6);
    return 0;
}
