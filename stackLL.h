

class stackLL
{
private:
	class node
	{
	public:
		int data;
        node* next;
        node(int d, node* n = nullptr) : data(d), next(n) {}
	};

	node * top;

public:

	stackLL() : top(nullptr) {}

	//Take care of memory leaks...
	~stackLL() {
        while (!empty()) pop();
	{}

	//return true if empty, false if not
	bool empty(){
		return top == nullptr;
	}

	//add item to top of stack
	void push(int x){
		top = new node(x, top);
	}

	//remove and return top item from stack
	int pop(){
		if (empty()) throw std::runtime_error("Stack underflow");
        int val = top->data;
        node* old = top;
        top = top->next;
        delete old;
        return val;
	}

	//add item x to stack, but insert it
	//right after the current ith item from the top
	//(and before the i+1 item).
	void insertAt(int x, int i){
		if (i == 0) {
            push(x);
            return;
	}

	node* cur = top;
        for (int k = 0; k < i - 1 && cur != nullptr; k++) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            // insert at end
            cur = top;
            if (!cur) { push(x); return; }
            while (cur->next) cur = cur->next;
            cur->next = new node(x);
        } else {
            cur->next = new node(x, cur->next);
        }
    }
};