#include <iostream>

template <class T>
class queue {
private:
	T* m_que;
	int maxSize;
	int m_size;
	int m_head;
	int m_tail;
public:
	queue<T>(){
		m_que = NULL;
        m_head = m_tail = 0;
		m_size = maxSize = 0;
	};

	~queue<T>() {
		delete[] m_que;
	};

	bool createQueue(int len) {
		if (NULL != m_que || len < 1) {
			return false;
		} else {
			m_que = new T[len + 1];
			maxSize = len;
			m_tail = m_head = 0;
			return true;
		}
	};

	bool push(T val) {
		if (NULL == m_que) {return false;}
		if (true == full()) {return false;}
		m_que[m_tail] = val;
		m_tail = (m_tail + 1) % maxSize; 
		m_size++;
        return true;
	}

	bool pop() {
		if (NULL == m_que || true == empty()) {
			return false;
		} else {
			m_head = (m_head + 1) % maxSize;
			m_size--;
			return true;
		}
	};

	T front() {
		if (NULL == m_que || true == empty()) {
			return false;
		} else {
			return m_que[m_head];
		}
	}

	int size() { return m_size;};
	bool full () {return m_size == maxSize;}
	bool empty() {return m_size == 0;};
	bool exist() {return NULL != m_que;};
};