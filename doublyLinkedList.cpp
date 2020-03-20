// Node for doubly link list
template<typename T>
class Node {
public:
	T data;
	Node<T> *Next;
	Node<T> *Prev;
	Node() {
		Next = NULL;
		Prev = NULL;
	}
};

// implementation of the doubly link list
template<class T>
class list {
private:
	Node<T> *Head;
	Node<T> *Tail;
	int size;
public:
	list() {
		Head = NULL;
		Tail = NULL;
		size = 1;
	}
	Node<T>* getHead() const {
		return Head;
	}
	Node<T>* getTail() const {
		return Tail;
	}
	bool isEmpty() {
		if (Head == NULL)
			return true;
		else
			return false;
	}
	// inserts the data item at specific index
	void insertAt(const T &newDataItem, int index) {
		Node<T> *newNode = new Node<T>;
		newNode->data = newDataItem;
		if (index > 1 && isEmpty())
			cout << "index out of range";
		else {
			Node<T> *currNode = Head;
			int currIndex = 2;
			while (currNode && index > currIndex) {
				currNode = currNode->Next;
				currIndex++;
			}
			if (index > currIndex - 1 && !currNode)
				cout << "index out of range";
			else {
				if (index == 1 && isEmpty()) {
					newNode->Next = NULL;
					newNode->Prev = NULL;
					Head = newNode;
					Tail = newNode;
				} else if (index == 1) {
					newNode->Next = currNode;
					Head = newNode;
					if (!currNode->Next)
						Tail = currNode;
				} else if (currNode->Next == NULL) {
					newNode->Next = currNode->Next;
					newNode->Prev = currNode;
					currNode->Next = newNode;
					currNode = currNode->Next;
					Tail = currNode;
				} else {
					newNode->Next = currNode->Next;
					currNode->Next = newNode;
					newNode->Next->Prev = newNode;
					newNode->Prev = currNode;
				}
				size++;
			}
		}
	}
	// removes data item from the specific index
	void removeAt(int index) {
		if (index <= 0)
			return;
		int currIdx = 1;
		Node<T>*current = Head;
		while (current->Next && index > currIdx) {
			current = current->Next;
			currIdx++;
		}
		if (index > currIdx) {
			cout << "index out of range" << endl;
			return;
		}
		if (current) {
			if (current->Prev && index == currIdx) {
				Node<T>*oldNode = current;
				oldNode->Prev->Next = oldNode->Next;
				if (oldNode->Next) {
					oldNode->Next->Prev = oldNode->Prev;
				}
				current = oldNode->Prev;
				if (!current->Next)
					Tail = current;
				delete oldNode;
			} else {
				if (current->Next) {
					Head = current->Next;
					Head->Prev = NULL;
					if (!Head->Next)
						Tail = current;
					delete current;
				} else {
					Head = NULL;
					Tail = NULL;
				}
			}
		}
		this->size--;
	}
	// removes data item from the end
	void remove() {
		Node<T>*current = Head;
		while (current->Next) {
			current = current->Next;
		}
		if (current) {
			if (current->Prev) {
				Node<T>*oldNode = current;
				oldNode->Prev->Next = oldNode->Next;
				current = oldNode->Prev;
				Tail = current;
				delete oldNode;
			} else {
				if (current->Next) {
					Head = current->Next;
					Head->Prev = NULL;
					delete current;
					Tail = Head;
				} else {
					Head = NULL;
					Tail = NULL;
				}
			}
		}
		size--;
	}
	// inserts data item at the end
	void insert(T newDataItem) {
		if (!Head) {
			Head = new Node<T>;
			Head->data = newDataItem;
			Head->Next = NULL;
			Head->Prev = NULL;
			Tail = Head;
			return;
		} else {
			Node<T>*current = Head;
			while (current->Next) {
				current = current->Next;
			}
			Node<T>*newNode = new Node<T>;
			newNode->data = newDataItem;
			newNode->Prev = current;
			newNode->Next = current->Next;
			newNode->Prev->Next = newNode;
			current = newNode;
			Tail = current;
		}
		size++;
	}
	// returns size 
	int getSize() {
		return size;
	}
	// displays link list
	void displayList() {
		if (!isEmpty()) {
			Node<T> *currNode = Head;
			while (currNode) {
				currNode->data.display();
				currNode = currNode->Next;
			}
		} else
			cout << "List is already Empty";
	}
};
