#include<stdio.h>
#include<ctype.h>

#define max 50

char stack[max];
int top=-1;
int vstack[max];
int vtop=-1;

void push(char ch){
if(top==max-1)
printf("Stack overflow\n");
else
stack[++top]=ch;
}

char pop(){
if(top==-1)
return '\0';
else
return stack[top--];
}

int precedence(char ch){
if(ch=='+' || ch=='-')
return 1;
if(ch=='*' || ch=='/')
return 2;
if(ch=='^')
return 3;
return 0;
}

void infixToPostfix(char infix[],char postfix[]){
int i=0,j=0;
char ch;
top=-1;

while(infix[i]!='\0'){
ch=infix[i];

if(isalnum(ch))
postfix[j++]=ch;
else if(ch=='(')
push(ch);
else if(ch==')'){
while(top!=-1 && stack[top]!='(')
postfix[j++]=pop();
pop();
}else{
while(top!=-1 && stack[top]!='(' && precedence(stack[top])>=precedence(ch)){
postfix[j++]=pop();
}
push(ch);
}
i++;
}

while(top!=-1)
postfix[j++]=pop();

postfix[j]='\0';
}

void vpush(int value){
if(vtop==max-1)
printf("Value stack overflow\n");
else
vstack[++vtop]=value;
}

int vpop(){
if(vtop==-1)
return -1;
else
return vstack[vtop--];
}

int evaluatePostfix(char postfix[]){
int i;
int a,b,result;
vtop=-1;

for(i=0;postfix[i]!='\0';i++){
if(isdigit(postfix[i]))
vpush(postfix[i]-'0');
else{
b=vpop();
a=vpop();

switch(postfix[i]){
case '+':
result=a+b;
break;
case '-':
result=a-b;
break;
case '*':
result=a*b;
break;
case '/':
result=a/b;
break;
case '^':
result=1;
while(b>0){
result=result*a;
b--;
}
break;
}
vpush(result);
}
}
return vpop();
}

int main(){
char infix[max],postfix[max];
int choice,result;

while(1){
printf("\n******** MENU ********");
printf("\n1. Convert Infix Expression to Postfix Expression");
printf("\n2. Evaluate Postfix Expression");
printf("\n3. Exit");
printf("\nEnter choice: ");
scanf("%d",&choice);

switch(choice){
case 1:
printf("Enter infix expression: ");
scanf("%s",infix);
infixToPostfix(infix,postfix);
printf("Postfix expression: %s\n",postfix);
break;

case 2:
printf("Enter postfix expression: ");
scanf("%s",postfix);
result=evaluatePostfix(postfix);
printf("Result = %d\n",result);
break;

case 3:
printf("Exit\n");
return 0;

default:
printf("Invalid choice\n");
}
}

return 0;
}
