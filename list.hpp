#pragma once

class List {
	private:
		struct Node {
			int data;
			Node* next;
			Node* prev;
			Node(int value) : data(value), next(nullptr), prev(nullptr) {}
		
		};
		Node* head {}; // mit nichts initialisieren, nicht vergessen!
		Node* tail {};
		int m_size = 0;
	
	public:

		struct Iterator {
			Node* ptr {};

			Iterator(Node* p) : ptr(p) {};
			int& operator*() const {return ptr->data;}
			Iterator& operator++() {ptr = ptr->next; return *this;}
			Iterator& operator--() {ptr = ptr->prev; return *this;}

			bool operator!=(const Iterator& o) const {return ptr != o.ptr;}
			//bool operator!=(const Iterator& a, const Iterator& b) {return a.ptr != b.ptr;}
			
		};
	Iterator begin() {return head;}
	Iterator end() {return nullptr;}
	
	List();
	List(const List& other); 
	List& operator=(const List& other);
	bool operator==(const List& other) const;
	~List();

	void push_back(int value);
	void pop_back();
	void insert_at(int pos, int value);
	int front();
	int back();

	void push_front(int value);
	void pop_front();

	void print();

	void size();
	void clear();
	void copyFrom(const List& other);
	void iteration();

};
