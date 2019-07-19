#pragma once

template <class T>
struct BSTNode {

	T value;
	BSTNode 
		*left = nullptr,
		*right = nullptr;


	~BSTNode ()
	{
		delete left;
		delete right;
	}
};