/*
here is another program for cs301 Data Strcuture Queue Implementation with 
array related to assignment of the subject.
Please Don't copy it read it and learn from it
feel free to tell me my mistakes i will be glad to here from you.

*/





#include <iostream>
#include <string.h>

#define arrLength 5
using namespace std;


struct Student {
	string userVUID;
	string userDetail;
	};
class ArrQue {
private:
	Student arr[arrLength];
	int size;
	int front;
	int rear;
public:
	void enQue(Student);
	void deQue();
	void showQue();
	bool isFull();
	bool isEmpty();
	ArrQue();
	//~ArrQue();
};
int main()
{
	Student new_student[arrLength];
	ArrQue queue;

	new_student[0].userDetail = "NAME PROGRAM";
	new_student[0].userVUID = "BCxxxxxxxxxx1";

	new_student[1].userDetail = "NAME PROGRAM";
	new_student[1].userVUID = "BCxxxxxxxxxx2";

	new_student[2].userDetail = "NAME PROGRAM";
	new_student[2].userVUID = "BCxxxxxxxxxx3";

	new_student[3].userDetail = "NAME PROGRAM";
	new_student[3].userVUID = "BCxxxxxxxxxx4";

	new_student[4].userDetail = "NAME PROGRAM";
	new_student[4].userVUID = "BCxxxxxxxxxx5";
	for (int i = 0; i < arrLength; i++) {
		queue.enQue(new_student[i]);
	}
	cout << "\n--------------------------------------------------\n";
	cout << "|		After Adding Data		|\n";
	cout << "\n--------------------------------------------------\n";
	queue.showQue();

	cout << "\n--------------------------------------------------\n";
	cout << "|		After Removing Data		|\n";
	cout << "\n--------------------------------------------------\n";
	queue.deQue();
	
	queue.showQue();
	cout << "\n--------------------------------------------------\n";
	cout << "|		After Adding Data		|\n";
	cout << "\n--------------------------------------------------\n";
	new_student[0].userDetail = "First";
	new_student[0].userVUID = "BCxxxxxxxxxx5";
	queue.enQue(new_student[0]);
	queue.showQue();





	


}

void ArrQue::enQue(Student newStudent)
{
	if (isFull()) {
		cout << "\n\n\nQueue is Full...!\n\n";
	}
	else {
		rear = (rear + 1) % arrLength;
		arr[rear].userDetail = newStudent.userDetail;
		arr[rear].userVUID = newStudent.userVUID;
		size++;

	}
}
void ArrQue::deQue()
{
	if (!isEmpty()) {
		cout << "\nQueue is Empty...!\n";
	}
	else {
		for (int i = 0; i < size-1; i++) {
			this->arr[i].userDetail = this->arr[i + 1].userDetail;
			this->arr[i].userVUID = this->arr[i + 1].userVUID;
		}
		this->arr[size - 1].userDetail = "";
		this->arr[size - 1].userVUID = "";

		rear = (rear - 1) % 5;
		size--;
	}
}
void ArrQue::showQue()
{
	cout << "\n\n\nDisplaying Queue\n";

	for (int i = 0; i < size ; i++) {
		cout <<i+1<<".	"<< this->arr[i].userDetail << " " << this->arr[i].userVUID;
		cout << "\n";
	}
}
bool ArrQue::isFull()
{
	if(size==arrLength) return true;
	return false;
}
bool ArrQue::isEmpty()
{
	if(size != arrLength)	return false;
	return true;
}
//Default constructor 
ArrQue::ArrQue()
{
	front = 0;
	rear = arrLength - 1;
	size = 0;
}
