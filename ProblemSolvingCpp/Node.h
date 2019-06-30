
#ifndef __NODE_H__
#define __NODE_H__

#include "pch.h"

struct Node;
using NodePtr = std::shared_ptr<Node>;

struct Node {
	int i;
	NodePtr next;
	
	Node (int i, NodePtr other) {
		this->i=i;
		this->next = other;
	}
	
	Node (int i) {
		this->i=i;
	}
	
	bool operator == (Node const &other) const noexcept {
		
		if (i!=other.i) {
			return false;
		}
		
		if (next == nullptr && other.next ==nullptr)
			return true;
		if (next != nullptr && other.next ==nullptr)
			return false;
		if (next == nullptr && other.next !=nullptr)
			return false;
		
		return (*next == *other.next);
	}
	
	friend std::ostream& operator << (std::ostream &os, Node &nd) {
		os << nd.i;
		if (nd.next) {
			os << " -> " << *nd.next;
		}
		return os;
	}
};

#endif //__NODE_H__
