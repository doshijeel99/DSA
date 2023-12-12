#include<stdio.h>
#include<stdlib.h>

struct ll_1 {
    int coefficient, power;
    struct ll_1 *next;
}*start1;

struct ll_2 {
    int coefficient, power;
    struct ll_2 *next;
}*start2;

struct result {
    int coefficient, power;
    struct result *next;
}*start3;

void link(int c, int p){
    struct result *newNode, *temp;
    newNode = (struct result *) malloc(sizeof(struct result));
    newNode -> coefficient = c;
    newNode -> power = p;
    newNode -> next = NULL;

    if(start3 == NULL){
        start3 = newNode;
    }
    else{
        temp = start3;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void create(int j){
    int no_of_nodes, i, c, p;
    if(j == 0){
    printf("Enter number of nodes for linked list %d: ",(j + 1));
    scanf("%d",&no_of_nodes);
    struct ll_1 *newNode, *temp;
    
        for(i = 0; i < no_of_nodes; i++){
            newNode = (struct ll_1 *)malloc(sizeof(struct ll_1));
            printf("Enter coefficient: ");
            scanf("%d",&c);
            newNode -> coefficient = c;

            printf("Enter power: ");
            scanf("%d",&p);
            newNode -> power = p;
            newNode -> next = NULL;
            
            if(start1 == NULL){
                start1 = newNode;
            }
            else {
                temp = start1;
                while(temp -> next != NULL){
                    temp = temp -> next;
                }
                temp -> next = newNode;
            }
        }
    }
    else {
    printf("Enter number of nodes for linked list %d: ",(j + 1));
    scanf("%d",&no_of_nodes);
    struct ll_2 *newNode, *temp;
    
        for(i = 0; i < no_of_nodes; i++){

            newNode = (struct ll_2 *)malloc(sizeof(struct ll_2));
            printf("Enter coefficient: ");
            scanf("%d",&c);
            newNode -> coefficient = c;

            printf("Enter power: ");
            scanf("%d",&p);
            newNode -> power = p;
            newNode -> next = NULL;
            
            if(start2 == NULL){
                start2 = newNode;
            }
            else {
                temp = start2;
                while(temp -> next != NULL){
                    temp = temp -> next;
                }
                temp -> next = newNode;
            }
        }
    }
}

void add(){
    int c, p;
    struct ll_1 *temp1;
    struct ll_2 *temp2;
    temp1 = start1;
    temp2 = start2;
    while(temp1 != NULL && temp2 != NULL){  
          
        if(temp1 -> power > temp2 -> power){
            c = temp1 -> coefficient;
            p = temp1 -> power; 
            link(c, p);
            temp1 = temp1 -> next;
        }
        else if(temp1 -> power == temp2 -> power){
            c = temp1 -> coefficient + temp2 -> coefficient;
            p = temp1 -> power; 
            link(c, p);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else{
            c = temp2 -> coefficient;
            p = temp2 -> power; 
            link(c, p);
            temp2 = temp2 -> next;
        }

    }
    while(temp1 != NULL){
        c = temp1 -> coefficient;
        p = temp1 -> power; 
        link(c, p);
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
        c = temp2 -> coefficient;
        p = temp2 -> power; 
        link(c, p);
        temp2 = temp2 -> next;
    }
}

void subtract(){
    int c, p;
    struct ll_1 *temp1;
    struct ll_2 *temp2;
    temp1 = start1;
    temp2 = start2;
    while(temp1 != NULL && temp2 != NULL){  
          
        if(temp1 -> power > temp2 -> power){
            c = temp1 -> coefficient;
            p = temp1 -> power; 
            link(c, p);
            temp1 = temp1 -> next;
        }
        else if(temp1 -> power == temp2 -> power){
            c = temp1 -> coefficient - temp2 -> coefficient;
            p = temp1 -> power; 
            link(c, p);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else{
            c = temp2 -> coefficient;
            p = temp2 -> power; 
            link(c, p);
            temp2 = temp2 -> next;
        }

    }
    while(temp1 != NULL){
        c = temp1 -> coefficient;
        p = temp1 -> power; 
        link(c, p);
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){
        c = temp2 -> coefficient;
        p = temp2 -> power; 
        link(c, p);
        temp2 = temp2 -> next;
    }
}

void display(){
    struct result *temp;
    temp = start3;
    while(temp != NULL){
       if(temp -> next != NULL){
        printf("Coefficient: %d, Power: %d -> ",temp -> coefficient, temp -> power);
        }
        else{
        printf("Coefficient: %d, Power: %d ",temp -> coefficient, temp -> power);
        }
        temp = temp -> next;
    }
}

int main(){
    create(0);
    create(1);
    printf("Addition of the polynomial is: \n");
    add();
    display();
    printf("\n\n");
    printf("Subtraction of the polynomial is: \n");
    subtract();
    display();
    return 0;
}