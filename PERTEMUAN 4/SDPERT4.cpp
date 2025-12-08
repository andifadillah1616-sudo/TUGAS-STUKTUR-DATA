#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
class Stack 
{
	int top;
	public:
	int a[MAX]; // Ukuran maximum stack
	Stack() { top = -1;}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX-1)){
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top]= x;
		cout << x << " didorong ke dalam tumpukan\n";
		return true;
	}
}


int Stack::pop()
{
	if (top < 0){
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0){
		cout << "Tumpuhkan Kosong";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Dikeluarkan dari tumpukan\n";
	
	return 0;
}
