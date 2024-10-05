#include"StackV.h"

StackV::StackV()
{
	head = -1;
}

bool StackV::empty()
{
	return head == -1;
}

bool StackV::full()
{
	return head == MaxCount - 1;
}

size_t StackV::size()
{
	return head + 1;
}

void StackV::push(TInfo elem)
{
	if (head != MaxCount - 1)
		elements[++head] = elem;
	else
		std::cout << "Stack overflow";
}

void StackV::pop()
{
	if (head != -1)
		head--;
}

TInfo StackV::top()
{
	return elements[head];
}

void StackV::view()
{
	for (int i = head; i >= 0; --i)
	{
		std::cout << elements[i] << ' ';
	}
	std::cout << '\n';
}

void StackV::clear()
{
	head = -1;
}
