#include <iostream>
#include <string>
#include <deque>
#define NUM 5

using namespace std;

// Sequential Queue
class SequentialQueue {
public:
	SequentialQueue() :front(-1), rear(-1), capacity(NUM) {
		queue = new int[NUM];
	}
	void insert_data(int);
	int delete_data();
	void double_capacity();
	void print_queue();
private:
	int front;
	int rear;
	int capacity;
	int *queue;
};

// Circular Queue
class CircularQueue {
public:
	CircularQueue() : tag(false), front(-1), rear(-1) {
		queue = new int[NUM];
	}
	void insert_data(int);
	int delete_data();
	void print_circular_queue();
private:
	int front;
	int rear;
	int *queue;
	bool tag;
};

void SequentialQueue::insert_data(int data) {
	if (rear == capacity - 1) {
		double_capacity();
		cout << "the queue is full, but there are new spaces to store data" << endl;
		cout << "the capacity of the sequential queue is " << capacity << endl;
		queue[++rear] = data;
	}else {
		queue[++rear] = data;
	}
}

int SequentialQueue::delete_data() {
	if (front == rear) {
		cout << "the queue is empty" << endl;
		return -1;
	}else {
		return queue[++front];
	}
}

void SequentialQueue::double_capacity() {
	capacity *= 2;
	int *new_queue = new int[capacity];
	int j = -1;
	for (int i = front + 1; i <= rear; i++) {
		j++;
		new_queue[j] = queue[i];
	}
	// update the data
	front = -1;
	rear = j;
	delete [] queue;
	queue = new_queue;
}

void SequentialQueue::print_queue() {
	cout << "the data in the sequential queue is : " << endl;
	for (int i = front + 1; i <= rear; i++) {
		cout << queue[i] << " ";
	}
	cout << endl;
}

void CircularQueue::insert_data(int data) {
	if (front == rear && tag == true) {
		if (rear == NUM) {
			cout << "the circular queue is full" << endl;
		}
	}else {
		rear = (rear + 1) % NUM;
		if (front == rear) {
			if (front == -1) {
				tag = true;
				cout << "the circular queue is full" << endl;
				cout << "the data didn't push in the circular queue" << endl;
			}else {
				tag = true;
				queue[rear] = data;
			}
		}else {
			queue[rear] = data;
		}
	}
}

int CircularQueue::delete_data() {
	int tmp;
	if (front == rear && tag == false) {
		cout << "the circular queue is empty" << endl;
		return -1;
	}else {
		front = (front + 1) % NUM;
		tmp = queue[front];
		queue[front] = -1;
		if (front == rear) { tag = false; }
		return tmp;
	}
}

void CircularQueue::print_circular_queue() {
	int i = 0, tmp;
	tmp = (front + 1) % NUM;
	cout << "the data in the circular queue is : " << endl;
	while (i < NUM) {
		if (queue[tmp%NUM] != -1) {
			cout << queue[tmp++%NUM] << " ";
		}
		i++;
	}
	cout << endl;
}

int main() {
	
	SequentialQueue squ;
	CircularQueue cqu;
	int answer;

	// Sequential Queue
	for (int i = 1; i <= NUM; i++) {
		squ.insert_data(i);
	}
	squ.print_queue();
	answer = squ.delete_data();
	if (answer == -1) {
		cout << "there is something wrong !" << endl;
	}else {
		cout << "delete " << answer << endl;
	}
	squ.print_queue();
	squ.insert_data(6);
	squ.insert_data(7);
	squ.print_queue();

	// Circular Queue
	for (int i = 1; i <= NUM; i++) {
		cqu.insert_data(i);
	}
	int k = 0;
	while (k < 2) {
		cqu.print_circular_queue();
		answer = cqu.delete_data();
		if (answer == -1) {
			cout << "there is something wrong !" << endl;
		}else {
			cout << "delete " << answer << endl;
		}
		k++;
	}
	cqu.print_circular_queue();
	cqu.insert_data(1);
	cout << "insert " << 1 << endl;
	cqu.print_circular_queue();

	// system("pause");
	return 0;
}
