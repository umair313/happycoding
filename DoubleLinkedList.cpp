//Read First
// this is the double linked list implementation for course cs301 Data structure 
// this is for idea dont copy it for submiting your assignments learn from it and make your own
// if you use it and you get 0 marks i am not responsible
//if you find any thing wrong in this program please Email me at : umairapi1995@gmail.com i will be glad to here my mistake 
// Thank you .. Happy Codding :) 

#include <iostream>
using namespace std;
//struct for student details
struct StudentDetail
{
	string name;
	string vuid;
};
class Node {
private:
	StudentDetail newStd;
	Node* next;// next node
	Node* pre; // preview node // node before
public:
	//setter functions for Nodes
	void set(StudentDetail details);
	void setNext(Node* n);
	void setPre(Node* p);
	//getter functions for Nodes
	StudentDetail get();
	Node* getnext();
	Node* getpre();

};
class DoubleLinkdedList {
private:
	int size;
	Node* headPtr; // head of list
	Node* curPtr; // pointer to point in the list to control
public:
	void addAtBegining(StudentDetail student);
	void addAtEnd(StudentDetail student);
	void delNode();
	void display();
	DoubleLinkdedList();
	//~DoubleLinkdedList();
};
int main()
{
	DoubleLinkdedList list;
	StudentDetail newStudent;
	
	cout << "Add you VUID and name at the first position"<<endl << "-------------------------------------------------------------\n" << endl;
	newStudent.name = "UMAIR";
	newStudent.vuid = "BCxxxxxxx";
	list.addAtBegining(newStudent);
	list.display();


	cout << "\nInsertion at Begining in Double linked list" << endl << "-----------------------------------------------------------\n" << endl;
	newStudent.name = "Basit";
	newStudent.vuid = "bx12345678";
	list.addAtBegining(newStudent);
	list.display();

	cout << "\nInsertion at End of Double linked list" << endl << "-----------------------------------------------------------\n" << endl;
	newStudent.name = "Agha";
	newStudent.vuid = "bx987654321";
	list.addAtEnd(newStudent);
	list.display();
	cout << "\nDeletion of current Node < Last Node> " << endl << "-----------------------------------------------------------\n" << endl;
	list.delNode();
	list.display();











}

//Node Class implementations

void Node::set(StudentDetail details)
{
	newStd.name = details.name;
	newStd.vuid = details.vuid;
}

void Node::setNext(Node* n)
{
	next = n; //set next pointer
}

void Node::setPre(Node* p)
{
	pre = p;// set previous pointer
}

StudentDetail Node::get()
{
	
	return newStd; //return student data
}

Node* Node::getnext()
{
	return next; // return pointer to next
}
Node* Node::getpre() 
{
	return pre; // return pointer to pre
} 
void DoubleLinkdedList::addAtBegining(StudentDetail student)
{
	Node* add = new Node();
	add->set(student);
	//in case of there is no node (0 students in the list) in the list.
	if (curPtr == NULL) {
		headPtr->setNext(add); // point head next to new node
		headPtr->setPre(NULL); // set head previous pointer to NULL
		// new node next and previous pointers to NULL
		add->setNext(NULL);
		add->setPre(NULL);
		//move current pointer to new node
		curPtr = add;
	}
	else {
		add->setPre(NULL);// set pre of new node to NULL bacause this is first node 
		add->setNext(headPtr->getnext()); // set next pointer to where head is pointing 
		headPtr->setNext(add);//now head is pointing to new(first Node)
	}
	size++;
	
}
void DoubleLinkdedList::addAtEnd(StudentDetail student)
{
	Node* add = new Node();
	add->set(student);
	//in case of there is no node (0 students in the list) in the list.
	if (curPtr == NULL) {
		headPtr->setNext(add); // point head next to new node
		headPtr->setPre(NULL); // set head previous pointer to NULL
		// new node next and previous pointers to NULL
		add->setNext(NULL); 
		add->setPre(NULL);
		//move current pointer to new node
		curPtr = add;
	}
	else {
		add->setPre(curPtr);// set pre pointer of new node to current Node 
		add->setNext(NULL); // set next pointer to null becouse there is node at the end
		curPtr->setNext(add); // nexr pointer of current Node point to new Node
		curPtr = add;//current pointer move to new node
	}
	size++;
}
void DoubleLinkdedList::delNode()
{
	if (curPtr != NULL) {
		Node* del = new Node();
		curPtr = curPtr->getpre();
		delete del;
		size--;
	}

}

void DoubleLinkdedList::display()
{
	// this block will run if there is any node
	if (curPtr != NULL) {
		StudentDetail curstudent;

		curPtr = headPtr->getnext(); // move current pointer to first Node
		// loop for moving current pointer next untill it gets at end
		for (int i = size; i > 0; i--) {
				curstudent = curPtr->get();
				cout << curstudent.vuid << "  " << curstudent.name<< "--->"; //display data at current point
				if (curPtr->getnext() == NULL) break; // break the loop if next of current is NUll its means we are at the end
				curPtr = curPtr->getnext();
			}


		cout << endl;
		
	}

}


//implementation of double linked list class
//overwriting default constructor
DoubleLinkdedList::DoubleLinkdedList(){
	size = 0;// setting size to 0 
	headPtr = new Node();
	// setting head to NULL when their is no node
	headPtr->setNext(NULL);
	headPtr->setPre(NULL);
	curPtr = NULL;// setting current pointer to NUll when there is no node
}
