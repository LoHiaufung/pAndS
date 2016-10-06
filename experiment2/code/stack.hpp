#include <iostream>

template <class T>
struct node {
		node* next;
		T val;
		node(node* _next, T _val): next(_next), val(_val){};
		node(node* _next): next(_next) {};
	};

template <class T>
class stack {
private:
	int size;
	node<T>* head;
public:
	stack<T>(){
		size = 0;
		head = NULL;
	};

	~stack<T>() {
		node<T>* p = head; 
		while(NULL != head) {\
			head = head -> next;
			delete p;
			p = head;
		}
	}

	bool createStake() {
		if (NULL != head) {
			return false;
		} else {
			head = new node<T>(head);
			return true;
		}
	};

	bool push(T val) {
		if (head == NULL) {
			return false;
		} else {
			node<T>* p = new node<T>(head, val);
			head = p;
			size++;
			return true;
		}
	}

	bool pop() {
		if (true == empty()) {
			return false;
		} else {
			node<T>* p = head; 
			head = head -> next;
			delete  p;
			size--;
			return true;
		}
	};

	T top() {
		if (true == empty()) {
			// return T(0);
		} else {
			return head->val;
		}
	};

	bool empty() {return 0 == size;};
	bool exist() {return NULL != head;};
};


