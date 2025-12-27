#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;
int evalStack[MAX];
int evalTop=-1;

void push(char c)
{
if(top<MAX-1)
stack[++top]=c;
}

char pop()
{
if(top!=-1)
return stack[top--];
return '\0';
}

char peek()
{
if(top!=-1)
return stack[top];
return '\0';
}

int precedence(char op)
{
if(op=='^')
return 3;
else if(op=='*'||op=='/')
return 2;
else if(op=='+'||op=='-')
return 1;
else
return 0;
}

int isOperator(char c)
{
return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int isOperand(char c)
{
return(c>='0' && c<='9');
}

void infix_to_postfix(char infix[],char postfix[])
{
int i=0,j=0;
char c;
while(infix[i]!='\0')
{
c=infix[i];
if(isOperand(c))
{
postfix[j++]=c;
}
else if(c=='(')
{
push(c);
}
else if(c==')')
{
while(peek()!='(' && top!=-1)
postfix[j++]=pop();
pop();
}
else if(isOperator(c))
{
while(top!=-1 && precedence(c)<=precedence(peek()) && peek()!='(')
postfix[j++]=pop();
push(c);
}
i++;
}


while(top!=-1)
postfix[j++]=pop();
postfix[j]='\0';
}

void evalPush(int val)
{
if(evalTop<MAX-1)
evalStack[++evalTop]=val;
}

int evalPop()
{
if(evalTop!=-1)
return evalStack[evalTop--];
return 0;
}

int evaluate_postfix(char postfix[])
{
int i=0;
char c;
int op1,op2,result;

while(postfix[i]!='\0')
{
c=postfix[i];
if(isOperand(c))
{
evalPush(c-'0');
}
else if(isOperator(c))
{
op2=evalPop();
op1=evalPop();
switch(c)
{
case '+':result=op1+op2;break;
case '-':result=op1-op2;break;
case '*':result=op1*op2;break;
case '/':result=op1/op2;break;
case '^':result=op1^op2;break;
}
evalPush(result);
}
i++;
}
return evalPop();
}

int main()
{
char infix[MAX],postfix[MAX];
int i=0;
printf("Enter infix expression:");
scanf("%s",infix);

infix_to_postfix(infix,postfix);

printf("Postfix expression is %s\n",postfix);

int result=evaluate_postfix(postfix);
printf("Value of expression is %d\n",result);
return 0;
}
