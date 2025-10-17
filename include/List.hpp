#pragma once
#include <string>
#include <stdexcept>

template <class T>
class List {
private:
    T** data;
    int lastPos;
    int capacity;

    bool isValidPos(int pos) const;
    void copyAll(const List<T>& other);
    void swapData(T*& a, T*& b);

public:
    List();
    List(const List& other);
    ~List();
    List<T>& operator = (const List<T>& other);

    void initialize();
    bool isEmpty() const;
    bool isFull() const;

    void insert(int pos, const T& element);
    void remove(int pos);

    T get(int pos) const;
    T& get(int pos);

    int getFirst() const;
    int getLast() const;
    
    void clear();
    std::string toString() const;

    void sortBubble(int (*cmp)(const T&, const T&));
    void sortInsert(int (*cmp)(const T&, const T&));
    void sortSelect(int (*cmp)(const T&, const T&));
    void sortShell(int (*cmp)(const T&, const T&));
};

template <class T>
bool List<T>::isValidPos(int pos) const {
    return pos >= 0 && pos <= this->lastPos;
}

template <class T>
void List<T>::copyAll(const List<T>& other) {
    for(int i = 0; i <= other.lastPos; ++i) {
        this->data[i] = new T(*other.data[i]);
    }
    this->lastPos = other.lastPos;
    this->capacity = other.capacity;
}

template <class T>
void List<T>::swapData(T*& a, T*& b) {
    T* aux = a;
    a = b;
    b = aux;
}

template <class T>
List<T>::List(): lastPos(-1), capacity(3000) {
    this->data = new T*[this->capacity];
}

template <class T>
List<T>::List(const List<T>& other) {
    this->data = new T*[other.capacity];
    this->copyAll(other);
}

template <class T>
List<T>::~List() {
    this->clear();
    delete[] this->data;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        this->clear();
        delete[] this->data;
        this->data = new T*[other.capacity];
        this->copyAll(other);
    }
    return *this;
}

template <class T>
void List<T>::initialize() {
    this->clear();
}

template <class T>
bool List<T>::isEmpty() const {
    return this->lastPos == -1;
}

template <class T>
bool List<T>::isFull() const {
    return this->lastPos == this->capacity - 1;
}

template <class T>
void List<T>::insert(int pos, const T& element) {
    if (this->isFull()) {
        throw std::overflow_error("Lista llena, no se puede insertar.");
    }
    if (pos < 0 || pos > this->lastPos + 1) {
        throw std::out_of_range("Posicion de insercion invalida.");
    }

    for(int i = this->lastPos; i >= pos; --i) {
        this->data[i + 1] = this->data[i];
    }
    this->data[pos] = new T(element);
    this->lastPos++;
}

template <class T>
void List<T>::remove(int pos) {
    if (!this->isValidPos(pos)) {
        throw std::out_of_range("Posicion de eliminacion invalida.");
    }
    delete this->data[pos];
    for(int i = pos; i < this->lastPos; ++i) {
        this->data[i] = this->data[i + 1];
    }
    this->data[this->lastPos] = nullptr;
    this->lastPos--;
}

template <class T>
T List<T>::get(int pos) const {
    if (!this->isValidPos(pos)) {
        throw std::out_of_range("Posicion invalida.");
    }
    return *this->data[pos];
}

template <class T>
T& List<T>::get(int pos) {
    if (!this->isValidPos(pos)) {
        throw std::out_of_range("Posicion invalida.");
    }
    return *this->data[pos];
}

template <class T>
int List<T>::getFirst() const {
    return this->isEmpty() ? -1 : 0;
}

template <class T>
int List<T>::getLast() const {
    return this->lastPos;
}

template <class T>
void List<T>::clear() {
    for(int i = 0; i <= this->lastPos; ++i) {
        delete this->data[i];
        this->data[i] = nullptr;
    }
    this->lastPos = -1;
}

template <class T>
std::string List<T>::toString() const {
    std::string result = "";
    for(int i = 0; i <= this->lastPos; ++i) {
        result += "- " + this->data[i]->toString() + "\n";
    }
    return result;
}

template <class T>
void List<T>::sortBubble(int (*cmp)(const T&, const T&)) {
    for (int i = 0; i < this->lastPos; ++i) {
        for (int j = 0; j < this->lastPos - i; ++j) {
            if (cmp(*this->data[j], *this->data[j + 1]) > 0) {
                this->swapData(this->data[j], this->data[j + 1]);
            }
        }
    }
}

template <class T>
void List<T>::sortInsert(int (*cmp)(const T&, const T&)) {
    int i = 1, j;
    T* aux;
    while (i <= this->lastPos) {
        aux = this->data[i];
        j = i;
        while(j > 0 && cmp(*aux, *this->data[j - 1]) < 0) {
            this->data[j] = this->data[j-1];
            j--;
        }
        if(i != j) {
            this->data[j] = aux;
        }
        i++;
    }
}

template <class T>
void List<T>::sortSelect(int (*cmp)(const T&, const T&)) {
    int i = 0, j, m;
    while(i < this->lastPos) {
        m = i;
        j = i + 1;
        while(j <= this->lastPos) {
            if(cmp(*this->data[j], *this->data[m]) < 0) {
                m = j;
            }
            j++;
        }
        if(m != i) {
            this->swapData(this->data[i], this->data[m]);
        }
        i++;
    }
}

template <class T>
void List<T>::sortShell(int (*cmp)(const T&, const T&)) {
    float fact = 0.5f;
    int dif = (this->lastPos + 1) * fact;
    int i, j;
    while(dif > 0) {
        i = dif;
        while (i <= this->lastPos) {
            j = i;
            while(j >= dif && cmp(*this->data[j], *this->data[j - dif]) < 0) {
                this->swapData(this->data[j-dif], this->data[j]);
                j -= dif;
            }
            i++;
        }
        dif *= fact;
    }
}