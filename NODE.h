#pragma once
#include<iostream>
#include<Windows.h>
using TInfo = double;
struct NODE
{
	TInfo info;
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr) :info(info), next(ptr) {};
	~NODE()
	{
		next = nullptr;
	}
};
