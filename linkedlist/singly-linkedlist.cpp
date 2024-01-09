#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node {

	public:
		int data;
		Node* next;

// 		constructor
		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}

//   	destructor
		~Node(){
			// memory free
			int value = this -> data;
			if(this -> next != NULL){
				delete next;
				this -> next = NULL;
			}
		}
};

void insertAtHead(Node* &head, int d){ // head ka ref liya kyuki we dont to make a copy of node, we want to alter the original ll

//	new node create
	Node* temp = new Node(d);
	temp -> next = head;
	head = temp;
}

void insertAtTail(Node* &tail, int d){ // head ka ref liya kyuki we dont to make a copy of node, we want to alter the original ll

//	new node create
	Node* temp = new Node(d);
	tail -> next = temp;
	tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int idx){

	if(idx == 1){
		insertAtHead(head, d);
		return;
	}

	Node* temp = head;
	int count = 1;

	while(count < idx - 1){
		temp = temp -> next;
		count++;
	}

	if(temp -> next == NULL){
		insertAtTail(tail, d);
		return;
	}

//	new node create at idx
	Node* nodeToInsert = new Node(d);
	nodeToInsert -> next = temp -> next;
	temp -> next = nodeToInsert;
}

void deleteAtPosition(Node* &head, Node* &tail, int idx){

	if(idx == 1){
		Node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
		return;
	}
	else{
		Node* curr = head;
		Node* prev = NULL;
		int count = 1;

		if(count < idx){
			prev = curr;
			curr = curr -> next;
			count++;
		}

		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}

void printLL(Node* &head){
	Node* temp = head;

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	cout << endl;
}

int main(){

//	created a node
	Node* node1 = new Node(10);

//	head pointed to new node
	Node* head = node1;
	Node* tail = node1;

	printLL(head);

	insertAtHead(head, 12);

	printLL(head);

	insertAtTail(tail, 9);

	printLL(head);

	insertAtPosition(head, tail, 2, 4);

	printLL(head);

	deleteAtPosition(head, tail, 4);

	printLL(head);

	cout << tail -> data << endl;

	return 0;
}

