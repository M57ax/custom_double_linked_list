#pragma once

class List {
	private:
		struct Node {
			int data;
			Node* next;
			Node* prev;
		
			Node(int value) : data(value), next(nullptr), prev(nullptr) {}
		
		};

		Node* begin {}; // mit nichts initialisieren, nicht vergessen!
		Node* end {};
		int m_size = 0;
	
	public:


	List();

	void push_back(int value);
	void pop_back();
	void front();
	void back();

	void push_front(int value);
	void pop_front();

	void print();

	void size();

};
