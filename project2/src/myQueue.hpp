#ifndef MYQUEUE
#define MYQUEUE
#include <queue>
#include "plane.hpp"


enum Error_code {fail, success};
class Extended_queue {
private:
	std::queue<Plane> m_queue;
public:
    Extended_queue() {}
	int size() const {return m_queue.size();}
	bool empty() const {return m_queue.empty();}
	Error_code append(const Plane& x) {
		m_queue.push(x);
		return success;
	}
	Error_code serve() {
		if (!m_queue.empty()) {
			m_queue.pop();
			return success;
		} else {
			return fail;
		}
	}
	Error_code retrieve(Plane& x) const {
		if (m_queue.empty()) {
			return fail;
		} else {
			x = m_queue.front();
			return success;
		}
	}


}; 
#endif