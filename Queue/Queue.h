#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

struct CollectionRequest {
	int RequestId;
	int BinId;
	int locationId;
};

class Node {
public:
	CollectionRequest c;
	Node* next;
	Node(int ReqId,int BId,int LocId);
};

class Queue {
private:
	Node* front;
	Node* rare;
	int count;
public:
	Queue();
	bool isEmpty();
	void Enqueue(int ReqId, int BId, int LocId);
	CollectionRequest Dequeue();
	CollectionRequest Peek();
	int Size();
	void Display();
	~Queue();
};

