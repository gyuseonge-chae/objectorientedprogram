#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int id;
	string name;
	Node* prev;
	Node* next;
	Node() {};
	~Node() {};
};

class DLL
{
private:
	Node* head;
	Node* tail;
	void createDummyHead()
	{
		head = new Node;
		head->next = head;
		head->prev = head;
	}
public:
	DLL() 
	{ 
		createDummyHead();
		tail = head;
	}
	~DLL();
	Node* findNode(int target_id);
	void insertNode(int new_id, string new_name);
	void deleteNode(int target_id);
	void print_all();
	void print_reverse();
	void sortId();
	void sortName();
};


Node* DLL::findNode(int target_id)
{
	Node* cur = head->next;

	while (cur != head) 
	{
		if (cur->id == target_id)
		{
			return cur;
		}
		else if (cur->id != target_id)
		{
			cur = cur->next;
		}
		else
		{
			break;
		}
	}

	return NULL;
}

void  DLL::insertNode(int new_id, string new_name)
{
	Node* newNode;
	newNode = new Node;
	newNode->id = new_id;
	newNode->name = new_name;

	Node* cur;
	cur = head->next;

	while (cur != head) 
	{
		if (cur->id == new_id)
		{
			return;
		}
		else if (cur->id < new_id) 
		{
			cur = cur->next;
		}
		else
		{
			break;
		}
	}

	newNode->next = cur;
	newNode->prev = cur->prev;
	cur->prev = newNode;
	newNode->prev->next = newNode;
}

void DLL::deleteNode(int target_id)
{
	Node* cur;
	cur = findNode(target_id);

	if (cur != NULL) 
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
	}
}

void DLL::print_all()
{
	Node* cur = head->next;

	while (cur != head) 
	{
		cout << cur->id << " " << cur->name;
		cur = cur->next;
		cout << endl;
	}
}

void DLL::print_reverse()
{
	Node* cur = tail->prev;

	while (cur != head)
	{
		cout << cur->id << " " << cur->name << endl;
		cur = cur->prev;
	}
	return;
}

void DLL::sortId()
{
	int temp_id = 0;
	string temp_name;
	Node* cur = head->next;
	Node* curNext = cur->next;

	while (curNext != tail)
	{
		if (cur->id > curNext->id)
		{
			temp_id = cur->id;
			temp_name = cur->name;
			cur->id = curNext->id;
			cur->name = curNext->name;
			curNext->id = temp_id;
			curNext->name = temp_name;
		}
		curNext = curNext->next;
	}
	cur = cur->next;
	return;
}

void DLL::sortName()
{
	int temp_id = 0;
	string temp_name;
	Node* cur = head->next;
	Node* curNext = cur->next;

	while (curNext != tail)
	{
		if (cur->name > curNext->name)
		{
			temp_id = cur->id;
			temp_name = cur->name;
			cur->id = curNext->id;
			cur->name = curNext->name;
			curNext->id = temp_id;
			curNext->name = temp_name;
		}
		curNext = curNext->next;
		
	}
	cur = cur->next;
	return;
}

DLL::~DLL()
{
	Node* cur = head->next;
	Node* nextNode = NULL;

	while (cur != head)
	{
		nextNode = cur->next;
		delete cur;
		cur = nextNode;
	}
}

int main()
{
	int cmd = 0;
	DLL s;
	while (1)
	{
		cout << "Please Enter Command(1: insert, 2: print, 3: print_reverse, 4: sort_by_name, 5: sort_by_ID, 6: delete, 7: exit) :";
		cin >> cmd;

		if (cmd == 1)
		{
			int temp_id = 0;
			string temp_name;
			cin >> temp_id >> temp_name;

			s.insertNode(temp_id, temp_name);
		}
		else if (cmd == 2)
		{
			s.print_all();
		}
		else if (cmd == 3)
		{
			s.print_reverse();
		}
		else if (cmd == 4)
		{
			s.sortName();
			s.print_all();
		}
		else if (cmd == 5)
		{
			s.sortId();
			s.print_all();
		}
		else if (cmd == 6)
		{
			int target_id = 0;
			cin >> target_id;
			s.deleteNode(target_id);
		}
		else if (cmd == 7)
		{
			break;
		}
	}
	
	return 0;
}