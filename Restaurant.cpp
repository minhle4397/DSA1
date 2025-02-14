#include "main.h"


class LinkedList_customer {
public: 
	Restaurant::customer* head;
	Restaurant::customer* tail;
	int count;

	LinkedList_customer() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void add(string name, int energy) {
		Restaurant::customer* t = new Restaurant::customer(name, energy, nullptr, nullptr);
		if (this->head == nullptr) {
			this->head = t;
			this->tail = t;
		}
		else {
			this->tail->next = t;
			this->tail = t;
		}
		count++;
	}
	void add(int index, string name, int energy) {
		Restaurant::customer* t = new Restaurant::customer(name, energy, nullptr, nullptr);
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		if (index == 0) {
			t->next = head;
			head = t;
			if (this->tail == nullptr)
				this->tail = t;

		}
		else {
			int n = 0;
			Restaurant::customer* curr = this->head;
			while (n != index - 1) {
				curr = curr->next;
				n++;
			}
			t->next = curr->next;
			curr->next = t;
			if (index == count) { tail = t; }
		}
		count++;
	}
	Restaurant::customer* get(int index) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Restaurant::customer* curr = this->head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}
	void set(int index, string name, int energy) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Restaurant::customer* curr = this->head;
		for (int i = 0; i < index; i++)
			curr = curr->next;
		curr->energy = energy;
		curr->name = name;
	}
	bool empty() {
		if (this->head == nullptr)
			return true;
		return false;
	}
	int indexOf(string name) {
		int i = 0;
		Restaurant::customer* curr = this->head;
		while (curr != nullptr) {
			if (curr->name == name) {
				return i;
			}
			curr = curr->next;
			i++;
		}
		return -1;
	}
	bool contains(string name) {
		int i = 0;
		Restaurant::customer* curr = this->head;
		while (curr != nullptr) {
			if (curr->name == name) {
				return true;
			}
			curr = curr->next;
			i++;
		}
		return false;
	}
	Restaurant::customer* removeAt(int index) {
		if (index<0 || index>count - 1)
			throw std::out_of_range("Index out of range");
		else {
			Restaurant::customer* prev = nullptr;
			Restaurant::customer* curr = this->head;
			Restaurant::customer* a;
			if (index == 0) {
				head = curr->next;
				a = new Restaurant::customer(curr->name,curr->energy, nullptr, nullptr);
				delete curr;
				count--;
				if (head == nullptr)
					tail = nullptr;
			}
			else {
				for (int i = 0; i < index; i++) {
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
				a = new Restaurant::customer(curr->name, curr->energy, nullptr, nullptr);
				delete curr;
				count--;
				if (index == count)
					tail = prev;
			}

			return a;

		}
	}
	bool removeItem(string name, int energy) {
		Restaurant::customer* curr = this->head;
		Restaurant::customer* prev = nullptr;

		while (curr != nullptr) {
			if (curr->name == name) {
				if (curr == head) {
					head = curr->next;
					delete curr;
					count--;
					if (head == nullptr)
						tail = nullptr;
					return true;
				}
				else {
					if (curr == tail) {
						tail = prev;
					}
					prev->next = curr->next;
					delete curr;
					count--;
					return true;
				}
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}
	void clear() {
		Restaurant::customer* curr = this->head;
		while (curr != nullptr) {
			Restaurant::customer* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~LinkedList_customer() {}
};
class Queue {
public:
	LinkedList_customer items;
	int count_queue;//dem so khach trong hang cho

public:
	Queue() {
		count_queue = 0;
	}
	bool isFull() {
		if (items.count == MAXSIZE)
			return true;
		return false;
	}
	bool isEmpty() {
		if (items.count==0)
			return true;
		else return false;
	}
	void Enqueue(Restaurant::customer* c) {
		if (isFull())
			cout << "Queue is full";
		else {
			items.add(c->name, c->energy);
			count_queue++;
		}
	}
	Restaurant::customer* Dequeue() {
		Restaurant::customer* e;
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return nullptr;
		}
		else {
			e = items.removeAt(0);
			count_queue--;
			return e;
		}
	}

	void display() {
		
		if (isEmpty())
			cout << endl << "Empty Queue" << endl;
		else {
			
			Restaurant::customer* queue_curr = items.head;
			while (queue_curr!=nullptr)
			{
				cout << queue_curr->name << "-" <<queue_curr->energy << "\n";
				queue_curr = queue_curr->next;
			}
				
			
		}
	}
	~Queue() {
	}
};
class Queue_STT {
public:
	LinkedList_customer items;
	int count_queue;//dem so khach trong hang cho


public:
	Queue_STT() {
		count_queue = 0;
	}
	bool isFull() {
		if (items.count==MAXSIZE*2)
			return true;
		return false;
	}
	bool isEmpty() {
		if (items.count==0)
			return true;
		else return false;
	}
	void Enqueue(Restaurant::customer* c) {
		if (isFull())
			cout << "Queue is full";
		else {
			items.add(c->name,c->energy);
			count_queue++;
			
		}
	}
	Restaurant::customer* Dequeue() {
		Restaurant::customer* e;
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return nullptr;
		}
		else {
			e = items.removeAt(0);
			count_queue--;
			return e;
		}
	}

	void display() {
		
		if (isEmpty())
			cout << endl << "Empty Queue" << endl;
		else {

			Restaurant::customer* queue_curr = items.head;
			while (queue_curr != nullptr)
			{
				cout << queue_curr->name << "-" << queue_curr->energy << "\n";
				queue_curr = queue_curr->next;
			}

		}
	}
	~Queue_STT() {}

	
};
class Data {
public:
	string name;
	int energy;
	Data* next;
	Data() {
		name = "";
		energy = 0;
		next = nullptr;
	}
	Data(string na, int en, Data* n): name(na), energy(en), next(n) { }
};

class LinkedList_data {
public:
	Data* head;
	Data* tail;
	int count;

	LinkedList_data() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void add(string name, int energy) {
		Data* t = new Data(name, energy,nullptr);
		if (this->head == nullptr) {	
			this->head = t;
			this->tail = t;
		}
		else {
			this->tail->next = t;
			this->tail = t;
		}
		count++;
	}
	void add(int index, string name, int energy) {
		Data* t = new Data(name, energy, nullptr);
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		if (index == 0) {
			t->next = head;
			head = t;
			if (this->tail == nullptr)
				this->tail = t;

		}
		else {
			int n = 0;
			Data* curr = this->head;
			while (n != index - 1) {
				curr = curr->next;
				n++;
			}
			t->next = curr->next;
			curr->next = t;
			if (index == count) { tail = t; }
		}
		count++;
	}
	Data* get(int index) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Data* curr = this->head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}
	void set(int index, string name, int energy) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Data* curr = this->head;
		for (int i = 0; i < index; i++)
			curr = curr->next;
		curr->energy = energy;
		curr->name = name;
	}
	bool empty() {
		if (this->head == nullptr)
			return true;
		return false;
	}
	int indexOf(string name) {
		int i = 0;
		Data* curr = this->head;
		while (curr != nullptr) {
			if (curr->name == name) {
				return i;
			}
			curr = curr->next;
			i++;
		}
		return -1;
	}
	bool contains(string name) {
		int i = 0;
		Data* curr = this->head;
		while (curr != nullptr) {
			if (curr->name == name) {
				return true;
			}
			curr = curr->next;
			i++;
		}
		return false;
	}
	Data* removeAt(int index) {
		if (index<0 || index>count - 1)
			throw std::out_of_range("Index out of range");
		else {
			Data* prev = nullptr;
			Data* curr = this->head;
			Data* a;
			if (index == 0) {
				head = curr->next;
				a = curr;
				delete curr;
				count--;
				if (head == nullptr)
					tail = nullptr;
			}
			else {
				for (int i = 0; i < index; i++) {
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
				a = curr;
				delete curr;
				count--;
				if (index == count)
					tail = prev;
			}

			return a;

		}
	}
	bool removeItem(string name, int energy) {
		Data* curr = this->head;
		Data* prev = nullptr;

		while (curr != nullptr) {
			if (curr->name == name) {
				if (curr == head) {
					head = curr->next;
					delete curr;
					count--;
					if (head == nullptr)
						tail = nullptr;
					return true;
				}
				else {
					if (curr == tail) {
						tail = prev;
					}
					prev->next = curr->next;
					delete curr;
					count--;
					return true;
				}
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}
	void clear() {
		Data* curr = this->head;
		while (curr != nullptr) {
			Data* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~LinkedList_data() {}
};
class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = nullptr;
	}
	Node(int d, Node* n) : data(d), next(n){}
};
class LinkedList_int {
public:
	
	Node* head;
	Node* tail;
	int count;

	LinkedList_int() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void add(int data) {
		Node* t = new Node(data,nullptr);
		if (this->head == nullptr) {
			this->head = t;
			this->tail = t;
		}
		else {
			this->tail->next = t;
			this->tail = t;
		}
		count++;
	}
	void add(int index, int data) {
		Node* t = new Node(data, nullptr);
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		if (index == 0) {
			t->next = head;
			head = t;
			if (this->tail == nullptr)
				this->tail = t;

		}
		else {
			int n = 0;
			Node* curr = this->head;
			while (n != index - 1) {
				curr = curr->next;
				n++;
			}
			t->next = curr->next;
			curr->next = t;
			if (index == count) { tail = t; }
		}
		count++;
	}
	Node* get(int index) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Node* curr = this->head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}
	void set(int index, int data) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Node* curr = this->head;
		for (int i = 0; i < index; i++)
			curr = curr->next;
		curr->data = data;
		
	}
	bool empty() {
		if (this->head == nullptr)
			return true;
		return false;
	}
	int indexOf(int data) {
		int i = 0;
		Node* curr = this->head;
		while (curr != nullptr) {
			if (curr->data == data) {
				return i;
			}
			curr = curr->next;
			i++;
		}
		return -1;
	}
	bool contains(int data) {
		int i = 0;
		Node* curr = this->head;
		while (curr != nullptr) {
			if (curr->data == data) {
				return true;
			}
			curr = curr->next;
			i++;
		}
		return false;
	}
	Node* removeAt(int index) {
		if (index<0 || index>count - 1)
			throw std::out_of_range("Index out of range");
		else {
			Node* prev = nullptr;
			Node* curr = this->head;
			Node* a;
			if (index == 0) {
				head = curr->next;
				a = curr;
				delete curr;
				count--;
				if (head == nullptr)
					tail = nullptr;
			}
			else {
				for (int i = 0; i < index; i++) {
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
				a = curr;
				delete curr;
				count--;
				if (index == count)
					tail = prev;
			}

			return a;

		}
	}
	bool removeItem(int data) {
		Node* curr = this->head;
		Node* prev = nullptr;

		while (curr != nullptr) {
			if (curr->data == data) {
				if (curr == head) {
					head = curr->next;
					delete curr;
					count--;
					if (head == nullptr)
						tail = nullptr;
					return true;
				}
				else {
					if (curr == tail) {
						tail = prev;
					}
					prev->next = curr->next;
					delete curr;
					count--;
					return true;
				}
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}
	void clear() {
		Node* curr = this->head;
		while (curr != nullptr) {
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~LinkedList_int() {}
};
class Stack {
public:
	LinkedList_data items;
	int size;
	Stack() { size = 0; }

	//Check if the stack is full
	int isFull() {
		if (items.count==MAXSIZE)
			return 1;
		else return 0;
	}
	//Check if the stack is Empty
	int isEmpty() {
		if (items.count==0)
			return 1;
		else return 0;
	}
	//Add elements into stack
	void push(Data* newitem) {
		if (isFull())
			cout << "STACK FULL";
		else {
			items.add(newitem->name, newitem->energy);
			size++;
		}
	}
	//Remove elements from stack
	void pop() {
		if (isEmpty())
			cout << "\n STACK EMPTY \n";
		else {
			cout << "Item popped = " << this->items.get(size-1)->name << " " << this->items.get(size-1)->energy;
			this->items.removeAt(size - 1);
			size--;
		}
		cout << endl;
	}
	//Print elements of stack 
	void printStack() {
		cout << "Stack: ";
		for (int i = 0; i < size; i++) {
			cout << this->items.get(i)->name << " " << this->items.get(i)->energy << endl;
		}
		cout << endl;
	}
	Data* Peel() {
		return this->items.get(size-1);
	}
};
class Stack_STT {
public:
	LinkedList_data items;
	int size;
	Stack_STT() { size = 0; }

	//Check if the stack is full
	int isFull() {
		if (items.count==MAXSIZE)
			return 1;
		else return 0;
	}
	//Check if the stack is Empty
	int isEmpty() {
		if (items.count==0)
			return 1;
		else return 0;
	}
	//Add elements into stack
	void push(Data* newitem) {
		if (isFull())
			cout << "STACK FULL";
		else {
			items.add(newitem->name, newitem->energy);
			size++;
		}
	}
	//Remove elements from stack
	void pop() {
		if (isEmpty())
			cout << "\n STACK EMPTY \n";
		else {
			cout << "Item popped = " << this->items.get(size-1)->name << " " << this->items.get(size-1)->energy;
			this->items.removeAt(size - 1);
			size--;
		}
		cout << endl;
	}
	//Print elements of stack 
	void printStack() {
		cout << "Stack: ";
		for (int i = 0; i < size; i++) {
			cout << this->items.get(i)->name << "-" << this->items.get(i)->energy << endl;
		}
		cout << endl;
	}
	Data* Peel() {
		return this->items.get(size-1);
	}
};
class Subarray_Min { //mang con co energy nho nhat
public:
	int startIndex;
	int endIndex;
	Subarray_Min* next;
	
	Subarray_Min() {
		startIndex = -1;
		endIndex = -1;
		next = nullptr;
	}
	Subarray_Min(int st, int en) : startIndex(st), endIndex(en), next(nullptr){}
};
class LinkedList_Subarray {
public:

	Subarray_Min* head;
	Subarray_Min* tail;
	int count;

	LinkedList_Subarray() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void add(Subarray_Min sub) {
		Subarray_Min* t = new Subarray_Min(sub.startIndex, sub.endIndex);
		if (this->head == nullptr) {
			this->head = t;
			this->tail = t;
		}
		else {
			this->tail->next = t;
			this->tail = t;
		}
		count++;
	}
	void add(int index, Subarray_Min sub) {
		Subarray_Min* t = new Subarray_Min(sub.startIndex, sub.endIndex);
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		if (index == 0) {
			t->next = head;
			head = t;
			if (this->tail == nullptr)
				this->tail = t;

		}
		else {
			int n = 0;
			Subarray_Min* curr = this->head;
			while (n != index - 1) {
				curr = curr->next;
				n++;
			}
			t->next = curr->next;
			curr->next = t;
			if (index == count) { tail = t; }
		}
		count++;
	}
	Subarray_Min* get(int index) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Subarray_Min* curr = this->head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}
	void set(int index, Subarray_Min sub) {
		if (index<0 || index>count)
			throw std::out_of_range("Index out of range");
		Subarray_Min* curr = this->head;
		for (int i = 0; i < index; i++)
			curr = curr->next;
		curr->startIndex = sub.startIndex;
		curr->endIndex = sub.endIndex;

	}
	bool empty() {
		if (this->head == nullptr)
			return true;
		return false;
	}
	int indexOf(Subarray_Min sub) {
		int i = 0;
		Subarray_Min* curr = this->head;
		while (curr != nullptr) {
			if (curr->startIndex == sub.startIndex && curr->endIndex == sub.endIndex) {
				return i;
			}
			curr = curr->next;
			i++;
		}
		return -1;
	}
	bool contains(Subarray_Min sub) {
		int i = 0;
		Subarray_Min* curr = this->head;
		while (curr != nullptr) {
			if (curr->startIndex == sub.startIndex && curr->endIndex == sub.endIndex) {
				return true;
			}
			curr = curr->next;
			i++;
		}
		return false;
	}
	Subarray_Min* removeAt(int index) {
		if (index<0 || index>count - 1)
			throw std::out_of_range("Index out of range");
		else {
			Subarray_Min* prev = nullptr;
			Subarray_Min* curr = this->head;
			Subarray_Min* a;
			if (index == 0) {
				head = curr->next;
				a = curr;
				delete curr;
				count--;
				if (head == nullptr)
					tail = nullptr;
			}
			else {
				for (int i = 0; i < index; i++) {
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
				a = curr;
				delete curr;
				count--;
				if (index == count)
					tail = prev;
			}

			return a;

		}
	}
	bool removeItem(Subarray_Min sub) {
		Subarray_Min* curr = this->head;
		Subarray_Min* prev = nullptr;

		while (curr != nullptr) {
			if (curr->startIndex == sub.startIndex && curr->endIndex == sub.endIndex) {
				if (curr == head) {
					head = curr->next;
					delete curr;
					count--;
					if (head == nullptr)
						tail = nullptr;
					return true;
				}
				else {
					if (curr == tail) {
						tail = prev;
					}
					prev->next = curr->next;
					delete curr;
					count--;
					return true;
				}
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}
	void clear() {
		Subarray_Min* curr = this->head;
		while (curr != nullptr) {
			Subarray_Min* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~LinkedList_Subarray() {}
};
int findMinSum_Subarrays(LinkedList_data &calc_arr, int n, LinkedList_Subarray &sub_arr_min) {
	//n la so phan tu trong mang calc_arr = count_table
	int minSum = 999999; 
	int subarrayCount = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += calc_arr.get(j)->energy;
			if (j - i + 1 >= 4 && sum < minSum) {
				minSum = sum;
				subarrayCount = 1;
				Subarray_Min s(i, j);
				sub_arr_min.add(0, s);
			}
			else if (j - i + 1 >= 4 && sum == minSum) {
				Subarray_Min s(i, j);
				sub_arr_min.add(subarrayCount,s);
				subarrayCount++;
			}
		}
	}
	return subarrayCount;
}

class imp_res : public Restaurant
{
	public:
		
		//class circular linked list
		class circular_table {
		public:
			customer* head;
			int count_table;//dem so khach trong ban tron
			int pos_x; // vi tri co su thay doi
			Queue qu; //tao hang cho
			Queue_STT stt; //so thu tu
			circular_table() {
				head = nullptr;
				count_table = 0;
				pos_x = 0;
			}
			bool isEmpty() { return head == nullptr;}

			void addCustomer(customer* cus) {
				if (cus->energy == 0) return;
				if (isEmpty()) {
					cus->next = cus;
					cus->prev = cus;
					head = cus;
					count_table++;
					stt.Enqueue(cus);
				}
				customer* cs = head; //kiem tra co trung ten trong ban tron va hang doi khong
				while (cs->next != head) {
					if (cs->name == cus->name)
						return;
					cs = cs->next;
				}
				if (cs->name == cus->name)
					return;

				customer* queue_curr = qu.items.head; //khach hang hien tai trong hang doi
				while (queue_curr != nullptr) {
					if (queue_curr->name == cus->name)
						return;
					queue_curr = queue_curr->next;
				}
				
				if (count_table == MAXSIZE) {
					if (qu.count_queue < MAXSIZE) {
						qu.Enqueue(cus);
						stt.Enqueue(cus);
					}
					else return;
				}
				else {
					if (count_table >= MAXSIZE / 2) {
						
						LinkedList_int res;
						customer* curr = head;
						for (int i = 0; i < count_table; i++) {
							res.add(abs(cus->energy - curr->energy));
							curr = curr->next;
						}
						//xử lý mảng
						int max = res.get(0)->data; //tim gia tri max trong mang
						
						for (int i = 1; i < count_table; i++)
							if (res.get(i)->data > max)
								max = res.get(i)->data;

						for(int j = 0; j < count_table ; j++)//chon vi tri max dau tien
							if (res.get(j)->data == max) {
								pos_x = j;
								break;
							}
						//them vao table
						curr = head;
						int i = 0;
						while (i < pos_x) {
							i++;
							curr = curr->next;
						}
						if ((cus->energy - curr->energy) < 0) { //nguoc chieu kim dong ho
							curr->prev->next = cus;
							cus->prev = curr->prev;
							curr->prev = cus;
							cus->next = curr;
							count_table++;
							stt.Enqueue(cus);
							//pos_x giu nguyen
						}
						else { //thuan chieu kim dong ho
							curr->next->prev = cus;
							cus->next = curr->next;
							curr->next = cus;
							cus->prev = curr;
							pos_x++;
							count_table++;
							stt.Enqueue(cus);
						}

					}
					else
					{
						customer* curr = head;
						int n = 0;
						while (n < pos_x)
						{
							curr = curr->next;
							n++;
						}
						if (cus->energy >= curr->energy) {//them vao node thuan chieu kim dong ho
							curr->next->prev = cus;
							cus->next = curr->next;
							curr->next = cus;
							cus->prev = curr;
							pos_x++;
							count_table++;
							stt.Enqueue(cus);
						}
						else //them vao node nguoc chieu kim dong ho
						{
							curr->prev->next = cus;
							cus->prev = curr->prev;
							curr->prev = cus;
							cus->next = curr;
							count_table++;
							stt.Enqueue(cus);
							//pos_x giu nguyen
						}
					}
					
				}
			}
			void deleteCustomer(int num) {
				if (head == nullptr)
					return;
				if (num >= count_table || num > MAXSIZE) {
					while (count_table>0) {
						customer* tmp = head;
						
						if (count_table > 1) {
							head->prev->next = head->next;
							head->next->prev = head->prev;
						}
						head = head->next;
						delete tmp;
						count_table--;
						if (count_table == 1) {
							head->next = head;
							head->prev = head;
						}
						stt.Dequeue();
					}
					head = nullptr;
					stt.Dequeue();
					count_table = 0;
					pos_x = 0;
				}
				else {
					int num_del = 0;
					for (int i = 0; i < num; i++) {
						customer* curr = head->next;
						int n = 1;
						
						while (curr != head)
						{
							if (curr->name == stt.items.get(0)->name) { //xoa node trung ten trong stt
								if (num_del == num)
									break;
								customer* tmp = curr;
								curr = curr->next;
								curr->prev = tmp->prev;
								tmp->prev->next = curr;
								if (tmp->energy > 0)
									pos_x = n;
								else { pos_x = n - 1; }
								delete tmp;
								count_table--;
								num_del++;
								stt.Dequeue();
								
							}
							curr = curr->next; 
							n++;
							
						}
						if (head!= nullptr && head->name == stt.items.get(0)->name) { //xoa node dau tien
							if (num_del == num) {
								break;
							}
							if (head == head->next) {
								head = nullptr;
							}
							else {
								head->prev->next = head->next;
								head->next->prev = head->prev;
								head = head->next;
							}
							if (curr->energy > 0)
								pos_x = 0;
							else { pos_x = n - 2; }
						
							delete curr;
							count_table--;
							if (count_table == 1) {
								head->next = head;
								head->prev = head;
							}
							num_del++;
							stt.Dequeue();
							
						}

						
					}
					
				}
				if (qu.isEmpty())
					return;
				else {
					if (qu.count_queue >= num) {
						int n = 0;
						while (n < num) {
							customer* c = qu.Dequeue();
							addCustomer(c);
							
							n++;
						}
					}
					else {
						int n = 0;
						while (n < qu.count_queue) {
							customer* c = qu.Dequeue();
							addCustomer(c);
							
							n++;
						}
					}
				}
			}
			void swap_customer(Queue &qu, int i, int j) {
				int en = qu.items.get(i)->energy;
				string na = qu.items.get(i)->name;
				qu.items.set(i, qu.items.get(j)->name, qu.items.get(j)->energy);
				qu.items.set(j,na,en);
			}
			void swap_energy(LinkedList_int &ll, int i, int j) {
				int tmp = ll.get(i)->data;
				ll.set(i,ll.get(j)->data);
				ll.set(j,tmp);
			}
			void inssort(LinkedList_int &ll, int stran, int n, int incr, int &k) {
				for (int i = incr; i < n; i += incr) {
					for (int j = i+stran; (j >= incr) && (ll.get(j)->data > ll.get(j - incr)->data); j -= incr) {
						swap_energy(ll, j, (j - incr));
						k++;
					}
				}
			}
			void shellsort(LinkedList_int &ll, int n, int& k) {
				for (int i = n / 2; i > 2; i /= 2)	
					for (int j = 0; j < i; j++) 
						inssort(ll, j, n - j, i, k);
				inssort(ll,0, n, 1, k);
			}
			int de_sortingEnergy() {
				if (qu.isEmpty())
					return 0;
				else{
				int n = 0; //so lan sap xep mang
				int q = 0; //vi tri absolute Energy tim duoc trong queue
				int max = abs(qu.items.get(qu.count_queue-1)->energy);
				int dem = 0; //dem so phan tu chi dinh
				
				for (int i = qu.count_queue - 1; i >= 0; i--) {
					if (max < abs(qu.items.get(i)->energy)) {
						max = abs(qu.items.get(i)->energy);
						q = i;
					}
				}
				
				//tim dc vi tri co energy lon nhat sau cung
				
				LinkedList_int arr;
				for (int i = q; i >= 0; i--) {
					arr.add(abs(qu.items.get(i)->energy));
				}
				
				shellsort(arr,arr.count, n);


				for (int i = 0; i <= q; i++) {
					for (int j = i; j <= q; j++) {
						if (abs(qu.items.get(j)->energy) == arr.get(i)->data) {
							swap_customer(qu, i, j);
							break;
						}
					}
					
				}
				return n;
				}
			}

			//reversal
			void reversion_by_two_stack() {
				if (count_table<=1)
					return;
				LinkedList_data arr_tmp; //luu tru tam thoi du lieu customer
				
				int n = 0;
				customer* curr = head;
				while( n < pos_x){
					curr = curr->next;
					n++;
				}
				//curr o vi tri pos_x
				Data tmp;
				tmp.energy = curr->energy;
				tmp.name = curr->name;
				customer* save = curr;
				
				do{
					arr_tmp.add(save->name,save->energy);
					save = save->prev;
				}while (save != curr);
				
				Stack neg_energy, posi_energy;

				for (int j = 0; j < arr_tmp.count ; j++) {
					if (arr_tmp.get(j)->energy < 0) { neg_energy.push(arr_tmp.get(j)); }
					else posi_energy.push(arr_tmp.get(j));
				}
				for (int j = 0; j < arr_tmp.count; j++) {
					Data* t;
					if (save->energy < 0) {
						t = neg_energy.Peel();
						neg_energy.pop();
						save->energy = t->energy;
						save->name = t->name;
					}
					else {
						t = posi_energy.Peel();
						posi_energy.pop();
						save->energy = t->energy;
						save->name = t->name;
					}
					save = save->prev;
				}
				if (tmp.energy == curr->energy && tmp.name == curr->name) {
					pos_x = 0;
				}
				else {
					n = 1;
					curr = head->next;
					while (curr != head) {
						if (tmp.energy == curr->energy && tmp.name == curr->name) {
							break;
						}
						n++;
						curr = curr->next;
					}
					pos_x = n;
				}
			}
			void vo_luong_khong_xu() {
				if (count_table < 4)
					return;
				int n = 0;
				customer* curr = head; 
				while (n<pos_x)
				{
					curr = curr->next;
					n++;
				}
				//curr tai vi tri x
				LinkedList_data calc_arr;
				customer* p_x = curr; //node tai vi tri pos_x
				do{
					calc_arr.add(curr->name,curr->energy);
					curr = curr->next;
				}while (curr!= p_x);
				//co duoc mang Data theo thu tu kim dong ho
				LinkedList_Subarray sub_arr_min;
				int num_subarr = findMinSum_Subarrays(calc_arr, count_table, sub_arr_min); //so luong mang con co min =  nhau
				if (num_subarr == 0)
					return;
				else {
					Subarray_Min* last_one = sub_arr_min.get(num_subarr - 1);
					int min = calc_arr.get(last_one->startIndex)->energy;
					int min_index = 0;
					LinkedList_data sub_arr;
					for (int i = last_one->startIndex; i != (last_one->endIndex + 1) % count_table; i = (i + 1) % count_table) {
						sub_arr.add(calc_arr.get(i)->name, calc_arr.get(i)->energy);
					}
					for (int i = last_one->startIndex; i != (last_one->endIndex + 1) % count_table; i = (i + 1) % count_table) {
						if (min > calc_arr.get(i)->energy) {
							min = calc_arr.get(i)->energy;
							min_index = i;
						}
					}
					//co duoc vi tri co energy nho nhat trong day con
					for (int i = min_index; i < sub_arr.count; i++) {
						cout << sub_arr.get(i)->name << "-" << sub_arr.get(i)->energy << endl;
					}
					for (int i = 0; i != min_index; i++) {
						cout << sub_arr.get(i)->name << "-" << sub_arr.get(i)->energy << endl;
					}
					
				}
			}
			
			void banh_truong_lanh_dia(){
				if (count_table <= 1)
					return;
				int sum_nega = 0;
				int sum_posi = 0;
				customer* curr = head;
				do{
					if (curr->energy < 0)
						sum_nega += curr->energy;
					else sum_posi += curr->energy;
					curr = curr->next;
				} while (curr != head);

				customer* queue_curr = qu.items.head;
				while (queue_curr != nullptr) {
					if (queue_curr->energy < 0)
						sum_nega += queue_curr->energy;
					else sum_posi += queue_curr->energy;
					queue_curr = queue_curr->next;
				}
				
				if (sum_posi >= abs(sum_nega)) {
					int n = 0;
					while (n < pos_x)
					{
						curr = curr->next;
						n++;
					}
					if (curr->energy < 0) {
						while (curr->energy < 0) {
							curr = curr->prev;
							n--;
						}
						if (n < 0)
							n += count_table;
					}
					pos_x = n; //thay doi pos_x den vi tri duong neu pos_x ban dau am
					Stack_STT stack_stt_print;
					while (head->energy < 0) {
						customer* tmp = head;
						head->prev->next = head->next;
						head->next->prev = head->prev;
						head = head->next;
						Data* d = new Data(tmp->name, tmp->energy, nullptr);
						stack_stt_print.push(d);
						delete tmp;
						count_table--;
					}

					curr = head;
					do {
						if (curr->energy < 0) {
							customer* tmp = curr;
							curr->prev->next = curr->next;
							curr->next->prev = curr->prev;
							curr = curr->next;
							Data* d = new Data(tmp->name, tmp->energy, nullptr);
							stack_stt_print.push(d);
							delete tmp;
							count_table--;
						}
					} while (curr != head); //xoa het node co energy am trong ban tron
					Queue qu_new;
					queue_curr = qu.items.head;
					while (queue_curr != nullptr) {
						if (queue_curr->energy > 0)
							qu_new.Enqueue(queue_curr);
						queue_curr = queue_curr->next;
					}
					qu.items.clear();
					qu.count_queue = 0;
					queue_curr = qu_new.items.head;
					while (queue_curr!=nullptr)
					{
						qu.Enqueue(queue_curr);
						queue_curr = queue_curr->next;
					}
					//hang doi moi chi toan energy > 0
					while (count_table < MAXSIZE && !qu.isEmpty()) {
						customer* c = qu.Dequeue();
						addCustomer(c);
					}
					
					Queue_STT stt_new;
					queue_curr = stt.items.head;
					while (queue_curr!=nullptr)
					{
						if (queue_curr->energy < 0) {
							Data* d = new Data(queue_curr->name, queue_curr->energy,nullptr);
							stack_stt_print.push(d);
						}
						if (queue_curr->energy > 0)
							stt_new.Enqueue(queue_curr);
						queue_curr = queue_curr->next;
					}
					
					stt.items.clear();
					stt.count_queue = 0;
					queue_curr = stt_new.items.head;
					while (queue_curr != nullptr) {
						stt.Enqueue(queue_curr);
						queue_curr = queue_curr->next;
					}
					
					stack_stt_print.printStack();

				}
				else {
					int n = 0;
					while (n < pos_x)
					{
						curr = curr->next;
						n++;
					}
					if (curr->energy > 0) {
						while (curr->energy > 0) {
							curr = curr->next;
							n++;
						}
						if (n >= count_table)
							n -= count_table;
					}
					pos_x = n; //thay doi pos_x den vi tri am neu pos_x ban dau duong
					Stack_STT stack_stt_print;
					while (head->energy > 0) {
						customer* tmp = head;
						head->prev->next = head->next;
						head->next->prev = head->prev;
						head = head->next;
						Data* d = new Data(tmp->name, tmp->energy,nullptr);
						stack_stt_print.push(d);
						delete tmp;
						count_table--;
					}
					curr = head;
					do {
						if (curr->energy > 0) {
							customer* tmp = curr;
							curr->prev->next = curr->next;
							curr->next->prev = curr->prev;
							curr = curr->next;
							Data* d = new Data(tmp->name, tmp->energy,nullptr);
							stack_stt_print.push(d);
							delete tmp;
							count_table--;
						}
					} while (curr != head); //xoa het node co energy duong trong ban tron
					Queue qu_new;
					customer* queue_curr = qu.items.head;
					while (queue_curr!=nullptr)
					{
						if (queue_curr->energy < 0) {
							qu_new.Enqueue(queue_curr);
						}
						queue_curr = queue_curr->next;
					}
					
					qu.items.clear();
					qu.count_queue = 0;
					//hang doi moi chi toan energy < 0
					while (count_table < MAXSIZE && !qu.isEmpty()) {
						customer* c = qu.Dequeue();
						addCustomer(c);
					}

					Queue_STT stt_new;
					queue_curr = stt.items.head;
					while (queue_curr!=nullptr)
					{
						if (queue_curr->energy > 0) {
							Data* d = new Data(queue_curr->name, queue_curr->energy,nullptr);
							stack_stt_print.push(d);
						}
						if (queue_curr->energy < 0) {
							stt_new.Enqueue(queue_curr);
						}
						queue_curr = queue_curr->next;
					}
					
					stt.items.clear();
					stt.count_queue = 0;
					queue_curr = stt_new.items.head;
					while (queue_curr!=nullptr)
					{
						stt.Enqueue(queue_curr);
						queue_curr = queue_curr->next;
					}
					
					stack_stt_print.printStack();

				}
			}
			void printer(int num) {
				if (count_table == 0 && qu.isEmpty())
					return;
				int n = 0;
				customer* curr = head;
				
				while (n < pos_x) {
					n++;
					curr = curr->next;
				}
				if (num > 0) {
					customer* traver = curr;
					do {
						traver->print();
						traver = traver->next;
					} while (traver!= curr);
				}
				else if (num < 0) {
					customer* traver = curr;
					do {
						traver->print();
						traver = traver->prev;
					} while (traver!=curr);
				}
				else {
					qu.display();
				}
			}

		};
		circular_table* ct; //ban tron
		
		// tạo constructor để tạo circular linked list
		imp_res() {
			ct = new circular_table(); // tao ra cai ban tron
			
		}
		
		~imp_res() {
			if (ct->head != nullptr) {
				customer* curr = ct->head->next;
				while (curr != ct->head) {
					customer* tmp = curr;
					curr = curr->next;
					delete tmp;
				}
				delete ct->head;
			}
		}
		
		
		void RED(string name, int energy)
		{
			//cout << name << " " << energy << endl;
			customer *cus = new customer (name, energy, nullptr, nullptr);
			ct->addCustomer(cus);
		}
		void BLUE(int num)
		{
			//cout << "blue "<< num << endl;
			ct->deleteCustomer(num);
		}
		void PURPLE()
		{
			//cout << "purple"<< endl;
			int n = ct->de_sortingEnergy();
			if (n == 0)
				return;
			BLUE(n % MAXSIZE);
		}
		void REVERSAL()
		{
			//cout << "reversal" << endl;
			ct->reversion_by_two_stack();
		}
		void UNLIMITED_VOID()
		{
			//cout << "unlimited_void" << endl;
			ct->vo_luong_khong_xu();
		}
		void DOMAIN_EXPANSION()
		{
			//cout << "domain_expansion" << endl;
			ct->banh_truong_lanh_dia();
		}
		void LIGHT(int num)
		{
			//cout << "light " << num << endl;
			ct->printer(num);
		}
};
