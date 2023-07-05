#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct Flight
{
	string src;
	string des;
	int hour;
	int min;	
};

struct NODE {
	NODE *next;
	NODE *prev;
	Flight data;
};

struct DList {
	NODE *head;
	NODE *tail;
};

NODE *createNode(Flight fl){
	NODE *node = new NODE;
	node -> data = fl;
	node -> next = node -> prev = NULL;
	return node;
}

void createList() {
	DList L;
	L.head = L.tail = NULL;
}

void addHead(DList &L,Flight data){
	NODE *node = createNode(data);
	if (L.head == NULL)
		L.head = L.tail = node;
	else {
		node->next = L.head;
		L.head->prev = node;
		L.head = node;
	}	
}
void addTail(DList &L,Flight data){
	NODE *node = createNode(data);
	if (L.tail == NULL)
		L.head = L.tail = node;
	else{
		L.tail->next = node; 
		node->prev = L.tail;
		L.tail  = node; 
	}
}

void removeHead(DList& L){
	if (L.head == NULL)
		return;
	
	if(L.head==L.tail){
		delete L.head;
		L.head = L.tail = NULL;
		return;
	}
	NODE * temp = L.head;
	L.head = L.head->next;
	L.head->prev=NULL;
	delete temp;
}

void removeTail(DList& L){
	if (L.head == NULL)
		return;
	
	if(L.head==L.tail){
		delete L.head;
		L.head = L.tail = NULL;
		return;
	}
	NODE * temp = L.tail;
	L.tail = L.tail->prev;
	L.tail->next=NULL;
	delete temp;
}
bool compare(Flight f1, Flight f2) {
	if (f1.des != f2.des) return 0;
	if (f1.src != f2.src) return 0;
	if (f1.hour != f2.hour) return 0;
	if (f1.min != f2.min) return 0;
	return 1;
	
}
void removeBefore(DList &l, Flight fl) {
	if (l.head == NULL || l.head == l.tail) {
		return;
	}
	NODE* current = l.head;
	while (current && !compare(current->data, fl)) {
		current = current->next; // 1 2 3 
	} 
	if (current == NULL || current == l.head) {
		return;
	}
	NODE* prevCurrent = current->prev;
	if (prevCurrent == l.head) {
		removeHead(l);
		return;
	}
	current->prev = prevCurrent->prev;
	prevCurrent->prev->next = current;
	delete prevCurrent;
}
void removeAfter(DList &l,Flight fl)
{
	if (l.head == NULL || l.head == l.tail) {
		return;
	}
	for (NODE* p=l.head;p;p=p->next)
	{
		if (compare(p->data,fl))
		{
			if (p==l.tail) return;
			else 
			{
				NODE* temp=p->next;
				if (temp==l.tail)
				{
					removeTail(l);
					return;
				}
				p->next=temp->next;
				temp->next->prev=p;
				delete temp;
				return;
			}
		}
	}
}
bool addAfter(DList &L,Flight f1,Flight f2){
	NODE* head=L.head;
	while(head){
		if(compare(head->data,f1)){
			if(head->next==NULL) {
				addTail(L,f1);
				return true;
			}
			NODE* node=createNode(f2);
			NODE*  tmp=head->next;
			node->next=tmp;
			tmp->prev=node;
			head->next=node;
			node->prev=head;
			return true;
		}
		head=head->next;
	}
	return false;
}
bool addBefore(DList &L,Flight f1,Flight f2)
{
	if (L.head == NULL) {
		return false;
	}
	if(compare(L.head->data,f1))
		addHead(L,f2);
	else
	{
		NODE* curr=L.head;
		while(curr->next && !compare(curr->next->data,f1))
			curr=curr->next;
		if(!curr->next)
			return false;
		NODE* temp=createNode(f2);
		temp->prev=curr;
		temp->next=curr->next;
		curr->next=temp;
		temp->next->prev=temp;
	}
	return true;
}
bool AddPos(DList &L,Flight data,int pos)
{
	if(pos<0)
		return false;
	if(pos==0)
		addHead(L,data);
	else
	{
		NODE *q=L.head;
		int idx = 1;
		while(idx < pos)
		{
			idx++;
			q=q->next;
			if(q == NULL)
				return 0;
		}	
		NODE *temp = createNode(data);
		if(q == L.tail)
			addTail(L,data);
		else
		{
			temp->next = q->next;
			q->next->prev=temp;
			temp->prev = q;
			q->next = temp;
		}
	}
	return 1;	
}

void printAFlight(Flight fl){
	cout << fl.src << ' ' << fl.des << ' ' << fl.hour << ' ' << fl.min << '\n';
}

void printDList(DList L){
	for (NODE *p = L.head; p; p = p->next)
		printAFlight(p->data);
}


Flight getFlight(string line) {
    stringstream s(line);
    Flight f;

    string buf;
    getline(s, buf, '\"');
    getline(s, f.src, ',');
    getline(s, f.des, '\"');
    getline(s, buf, '\"');
    getline(s, buf, ' ');
    // f.hour = atoi(buf.c_str());
    f.hour = stoi(buf);

    // Check duration with 2 types
    // 1. hh hours, mm minutes
    // 2. mm minutes
    getline(s, buf, ' ');
    getline(s, buf, ' ');

	// Check if the duration string contains hours
	if (buf == "minutes\"}" || buf == "minute\"}") {
		// No hours, only minutes
		f.min = f.hour;	// Set only minutes from f.hour got from file
		f.hour = 0;	
	} else if (buf == "hours\"}" || buf == "hour\"}") {
		// Just only hours
		f.min = 0;
	} else {
		// Full 
		f.min = stoi(buf);
	    // f.min = atoi(buf.c_str());
	}

    return f;
}

vector<Flight> readFile(string fileName)
{
	ifstream is(fileName);
	vector<Flight> flight;
	string buf;
	
	while(!is.eof())
	{
		getline(is, buf, '\n');
		flight.push_back(getFlight(buf));
	}
	is.close();	
	return flight;
}

void printReverse(DList L)
{
	for (NODE *p = L.tail;p; p = p->prev)
	{
		printAFlight(p->data);
	}
}

void vector_to_list(vector<Flight>v, DList &L)
{
	
	for (int i = 0 ; i < v.size() ; i++)
	{
		addTail(L, v[i]);
	}
}

int main()
{
	const string fileName = "g1.jl";
	vector<Flight> v;
	v = readFile(fileName);
	DList L = {NULL,NULL};
	vector_to_list(v,L);
	Flight fl = {"Kazakhstan","Hong Kong", 0, 41};
	Flight f2= {"Faeroe Islands", "Ethiopia", 9, 16};
	addAfter(L,f2,fl);
	printReverse(L);
}
