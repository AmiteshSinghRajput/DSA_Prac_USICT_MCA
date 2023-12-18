#include<stdio.h>
char stack[30];
int top=-1;
void push(char x){
    stack[++top]=x;
}
char pop(){
    if(top==-1)
        return -1;
return stack[top--];
}
int precedence(char x)
{
if(x == '(')
    return 0;
else if(x == '+' || x == '-')
    return 1;
else if(x == '*' || x == '/')
    return 2;
return 3;
}
int main()
{
    char exp[30];
    char *ptr,x;
    printf("Enter The Infix Expression:\n");
    scanf("%s",exp);
    push('(');
    strcat(exp,")");
    ptr=exp;
    printf("The Postfix Expression: ");
    while(*ptr!='\0'){
        if(isalnum(*ptr)){
            printf("%c",*ptr);
        }
        else if(*ptr=='('){
            push(*ptr);
        }
        else if(*ptr==')'){
            while ((x=pop())!='('){
                printf("%c",x);
            }
        }
        else{
            while (precedence(stack[top])>=precedence(*ptr)){
                printf("%c",pop());
            }
            push(*ptr);
        }
        ptr++;
        }
return 0;
} // abcdfgh/+/-k+*+ij*-
