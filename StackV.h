#pragma once
#include "NODE.h"
const int MaxCount = 100;
using Array = TInfo[MaxCount];

struct StackV
{
private:
	Array elements;
	int head;
public:
	StackV();
	bool empty();
	bool full();
	size_t size();
	void push(TInfo elem);
	void pop();
	TInfo top();
	void view();
	void clear();
};