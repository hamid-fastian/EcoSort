#include"Queue.h"

Node::Node(int ReqId, int BId, int LocId)
{
	c.RequestId = ReqId;
	c.BinId = BId;
	c.locationId = LocId;
	next = nullptr;
}

Queue::Queue()
{
	front = rare = nullptr;
	count = 0;
}


bool Queue::isEmpty()
{
	return(count == 0);
}



void Queue::Enqueue(int ReqId, int BId, int LocId)
{
	Node* newNode = new Node(ReqId,BId,LocId);
	
	if (isEmpty())
	{
		front = rare = newNode;
		count++;
		return;
	}
	
	rare->next = newNode;
	rare = newNode;
	count++;
}

CollectionRequest Queue::Dequeue()
{
	if (isEmpty())
	{
		cout << "NO Pending Request\n";
		return CollectionRequest(); 
	}

	CollectionRequest Rc = front->c;
	Node* temp = front;
	front = front->next;
	if (front == nullptr)
	{
		rare = nullptr;
	}
	delete temp;
	count--;
	return Rc;
}

CollectionRequest Queue::Peek()
{
	if (front) 
	{
		return front->c;
	}
}

int Queue::Size()
{
	return count;
}

void Queue::Display()
{
	if (isEmpty())
	{
		cout << "=================================" << endl;
		cout << "          EcoSort - Queue" << endl;
		cout << "=================================" << endl;
		cout << "No pending collection requests." << endl;
		return;
	}
	Node* temp = front;
	cout << "========================================================" << endl;
	cout << "                 EcoSort - Pending Requests" << endl;
	cout << "========================================================" << endl;

	cout << left
		<< setw(15) << "Request ID"
		<< setw(12) << "Bin ID"
		<< setw(15) << "Location ID" << endl;

	cout << "--------------------------------------------------------" << endl;
	while (temp)
	{
		cout << left << setw(15) << temp->c.RequestId << setw(12) << temp->c.BinId << setw(15) << temp->c.locationId << endl;
		temp = temp->next;
	}
	cout << "========================================================" << endl;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rare = nullptr;
	count = 0;
}

