#include"StackL.h"

StackL::StackL()
{
	head = nullptr;
}

bool StackL::empty()
{
	return head == nullptr;
}

size_t StackL::size()
{
	return count;
}

void StackL::push(TInfo elem)
{
	ptrNODE newNode = new NODE(elem, head);
	head = newNode;
	++count;
}

void StackL::pop()
{
	if (!empty())
	{
		ptrNODE tmp = head;
		head = head->next;
		delete tmp;
		--count;
	}
	else
		std::cout << "Stack is empty\n";
}

TInfo StackL::top()
{
	return head->info;
}

void StackL::view()
{
	ptrNODE ptr = head;
	while (ptr)
	{
		std::cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	std::cout << '\n';
}

void StackL::clear()
{
	while (!empty())
		pop();
}

StackL::~StackL()
{
	clear();
}
