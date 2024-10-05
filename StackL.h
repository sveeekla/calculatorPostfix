#pragma once
#include "NODE.h"

using ptrNODE = NODE*;

struct StackL
{
private:
	ptrNODE head;
	size_t count;
public:
	StackL();
	bool empty();
	size_t size();
	void push(TInfo elem);
	void pop();
	TInfo top();
	void view();
	void clear();
	~StackL();
};