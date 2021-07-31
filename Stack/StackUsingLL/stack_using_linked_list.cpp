#include <iostream>

using namespace std ;

struct Node{
	int data ;
	struct Node *next ;
};

struct Node *top = NULL ;

int isEmpty()
{
	struct Node *t ;
	t = top ;
	if(top == NULL)
		return 1 ;
	return 0 ;
}

int isFull()
{
	struct Node *t ;
	if(t == NULL)
		return 1 ;
	return 0 ;
}

void push(int x)
{
	struct Node *t ;
	t = new Node() ;
	
	if(t == NULL) 
		cout << "Heap Overflow" << endl ;
	else
	{
		t->data = x ;
		t->next = top;
		top = t ;
	}
}

int pop()
{
	struct Node *t ;
	int x = -1 ;
	if(top == NULL)
		cout << "Stack empty" << endl ;
	else
	{
		t = top ;
		x = t->data ;
		top = t->next ;
		t->next = NULL ;
		//free(t) ;
		
	}
	return x ;
}

void display()
{
	struct Node *t ;
	t = top ;
	while(t!=NULL)
	{
		cout << t->data << " " ;
		t = t->next ;
	}
}

int stackTop()
{
	if(!isEmpty())
		return top->data ;
	else
		return -1 ;
}


int main()
{
	push(10) ;
	push(20) ;
	push(30) ;
	push(40) ;
	push(50) ;
	push(60) ;
	
	cout << "Stack top: " << stackTop() << endl ;
	
	cout << "Display Stack" << endl ;
	display() ;
	
	pop() ;
	pop() ;
	pop() ;
	pop() ;
	
	cout << endl << "Display Stack" << endl ;
	display() ;
	
}
