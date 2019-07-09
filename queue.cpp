#include <iostream>
#include <string>
#include <deque>
#define NUM 5

using namespace std;

// Sequential Queue
void insert_queue(int);
int delete_queue();
void print_queue();
// Circular Queue
void insert_circular_queue(int);
int delete_circular_queue();
void print_circular_queue();

typedef struct queue {
	queue() : front(-1), rear(-1) {}
	int q[NUM];
	int front;
	int rear;
}Queue;

// Sequential Queue
Queue qu;
// Circular Queue
Queue cqu;
bool tag = false;

int main(int argc, char *argv[] ) {
	int answer;

	/*

	for (int i = 1; i <= NUM; i++) {
		insert_queue(i);
	}
	print_queue();
	answer = delete_queue();
	if (answer == -1) {
		cout << "there is something wrong !" << endl;
	}else {
		cout << "delete " << answer << endl;
	}
	print_queue();
	*/


	/*
	deque<int> dq;
	for (int i = 0; i < 5; i++) {
		dq.push_back(i);
	}
	if (!dq.empty()) { dq.pop_back(); }
	dq.push_front(6);
	dq.push_front(7);
	dq.push_front(8);
	dq.pop_front();
	
	while (!dq.empty()) {
		cout << "dq data = " << dq.front() << endl;
		dq.pop_front();
	}

	*/
	
	for (int i = 1; i <= NUM; i++) {
		insert_circular_queue(i);
	}
	int k = 0;
	while (k < 2) {
		print_circular_queue();
		answer = delete_circular_queue();
		if (answer == -1) {
			cout << "there is something wrong !" << endl;
		}else {
			cout << "delete " << answer << endl;
		}
		k++;
	}
	print_circular_queue();
	insert_circular_queue(1);
	cout << "insert " << 1 << endl;
	print_circular_queue();

	// system("pause");
	return 0;
}
void insert_queue(int data) {
	if (qu.rear == NUM - 1) {
		cout << "the queue is full" << endl;
	}
	else {
		qu.q[++qu.rear] = data;
	}
}
int delete_queue() {
	if (qu.front == qu.rear) {
		cout << "the queue is empty" << endl;
		return -1;
	}
	else {
		return qu.q[++qu.front];
	}
}
void print_queue() {
	cout << "the data in the queue is : " << endl;
	for (int i = qu.front + 1; i <= qu.rear; i++) {
		cout << qu.q[i] << " ";
	}
	cout << endl;
}
void insert_circular_queue(int data) {
	if (cqu.front == cqu.rear && tag == true) {
		if (cqu.rear == NUM) {
			cout << "the circular queue is full" << endl;
		}
	}else {
		cqu.rear = (cqu.rear + 1) % NUM;
		if (cqu.front == cqu.rear) {
			if (cqu.front == -1) {
				tag = true;
				cout << "the circular queue is full" << endl;
				cout << "the data didn't push in the circular queue" << endl;
			}else {
				tag = true;
				cqu.q[cqu.rear] = data;
			}
		}else {
			cqu.q[cqu.rear] = data;
		}
	}
}
int delete_circular_queue() {
	int tmp;
	if (cqu.front == cqu.rear && tag == false) {
		cout << "the circular queue is empty" << endl;
		return -1;
	}else {
		cqu.front = (cqu.front + 1) % NUM;
		tmp = cqu.q[cqu.front];
		cqu.q[cqu.front] = -1;
		if (cqu.front == cqu.rear) { tag = false; }
		return tmp;
	}
}
void print_circular_queue() {
	int i = 0, tmp;	
	tmp = (cqu.front + 1) % NUM;
	while(i < NUM){
		if(cqu.q[tmp%NUM] != -1){
			cout << cqu.q[tmp++%NUM] << " ";
		}
		i++;
	}
	cout << endl;
}
