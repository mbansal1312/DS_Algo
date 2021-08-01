#include <iostream>

using namespace std ;

class Node
{
	
public:
	char data ;
	Node *next ;
	
};

class Stack
{
private:
	Node *top ;
public:
	Stack(){top = NULL ;}
	void push(char x) ;
	char pop() ;
	void display() ;
	int isBalanced(char *exp) ;
};

void Stack::push(char x)
{
	Node *t = new Node ;
	if(t == NULL)
		cout << "Heap overflow" << endl ;
	else
	{
		t->data = x ;
		t->next = top ;
		top = t ;
	}
}

char Stack::pop()
{
	char x = 'Z' ;
	if(top == NULL)
		cout << "Stack is Empty" << endl ;
	else
	{
		x = top->data ;
		Node *t = top ;
		top = top->next ;
		delete t ;
	}
	return x ;
}

void Stack::display()
{
	Node *t = top ;
	while(t != NULL)
	{
		cout << t->data << ' ' ;
		t = t->next ;	
	}	
	cout << endl ;
}

int Stack::isBalanced(char *exp)
{
	int i ;
	
	for(i=0 ; exp[i] != '\0' ; i++)
	{
		if(exp[i] == '(')
		{
			push(exp[i]) ;
		}
		else if(exp[i] == ')')
		{
			if(top == NULL)
			{
				cout << "Empty Stack, Parenthesis not matching" ;
				return 0 ;				
			}
			pop() ;
		}
	}
	if(top == NULL)
	{
		cout << "Parethesis are matching" << endl ;
		return 1 ;	
	}
	else
	{
		cout << "Parethesis not matching" << endl ;
		return 0 ;
	}

}

int main()
{
	Stack stk ;
	char *exp = "((a+b)*(c-d))" ;
	
	stk.isBalanced(exp) ;
}
