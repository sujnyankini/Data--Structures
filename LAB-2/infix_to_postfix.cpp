#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100
#define pf printf
#define sf scanf

int stack[MAX];
char postfix[MAX],infix[MAX];
int top=-1;



void push(char);
char pop();
int space(char);
void inToPost();
int precedence(char);
int isempty();
void print();
int post_eval();



int main()
{
	int result;
	printf("Enter the infix expression\n");
	gets(infix);
	
	inToPost();
	print();
	result=post_eval();
	pf("\n\n\nThe value of the above post fix expression is: %d",result);
	return 0;
	
}

void inToPost()
{
	int i,j=0;
	char symbol,next;
	for(i=0;infix[i]!='\0';i++)
	{
	
		if(!space(infix[i]))
		{	
			symbol=infix[i];
			switch(symbol){
			
				case '(': 
					push(symbol);
					break;
					
				case ')':
					while((next=pop())!='(')
						postfix[j++]=next;
						break;
				
				case '+':
				case '-':
				case '/':
				case '*':
				case '^':
					while(!isempty() && precedence(stack[top])>=precedence(symbol))
						postfix[j++]=pop();
					push(symbol);
					break;
				 default:
					postfix[j++]=symbol;
					break;
						}
		}
	}
	while(!isempty())
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';
}

void push(char c)
{
	
	stack[++top]=c;
}

char pop()
{
	return stack[top--];
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int precedence(char symbol)
{
	switch(symbol){
	
		case '^': return 3;break;
		case '+':
		case '-':
			return 1;break;
		case '/':
		case '*': 
			return 2;break;
		 default:return 0;
	}
}

void print()
{
	int i=0;
	printf("\n The postfix expression will be\n");
	while(postfix[i])
	{
	 printf("%c",postfix[i++]);
	}
	printf("\n");
	
}

int space(char c){
	if(c==' ' || c=='\t')
		return 1;
	else
		return 0;
}
int post_eval()
{
	int i,a,b;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0'&& postfix[i]<='9')
			push(postfix[i]-'0');
		else{
			a=pop();
			b=pop();
			switch(postfix[i]){
				case'+':
					push(b+a);break;
				case'-':
					push(b-a);break;
				case'/':
					push(b/a);break;
				case'*':
					push(b*a);break;
				case'^':
					push(pow(b,a));break;
				}
			}
			
	}
	pop();
			
}
		







