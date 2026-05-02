#ifndef LINKED_STACK_H
#define LINKED_STACK_H


namespace structures {

template<typename T>
class LinkedStack {
 public:
    LinkedStack();
    ~LinkedStack();

    void clear();  // limpa pilha
    void push(const T& data);  // empilha
    T pop();  // desempilha
    T& top() const;  // dado no topo
    bool empty() const;  // pilha vazia
    std::size_t size() const;  // tamanho da pilha

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);

        T& data();
        const T& data() const;

        Node* next();
        const Node* next() const;

        void next(Node* next);

     private:
        T data_;
        Node* next_;
    };

    Node* top_;
    std::size_t size_;
};


template<typename T>
LinkedStack<T>::Node::Node(const T& data)
    : data_(data), next_(nullptr) {}

template<typename T>
LinkedStack<T>::Node::Node(const T& data, Node* next)
    : data_(data), next_(next) {}

template<typename T>
T& LinkedStack<T>::Node::data() {
    return data_;
}

template<typename T>
const T& LinkedStack<T>::Node::data() const {
    return data_;
}

template<typename T>
typename LinkedStack<T>::Node* LinkedStack<T>::Node::next() {
    return next_;
}

template<typename T>
const typename LinkedStack<T>::Node* LinkedStack<T>::Node::next() const {
    return next_;
}

template<typename T>
void LinkedStack<T>::Node::next(Node* next) {
    next_ = next;
}

// ================= STACK =================

template<typename T>
LinkedStack<T>::LinkedStack() : top_(nullptr), size_(0u) {}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template<typename T>
void LinkedStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void LinkedStack<T>::push(const T& data) {
    top_ = new Node(data, top_);
    size_++;
}

template<typename T>
T LinkedStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }

    Node* temp = top_;
    T data = temp->data();

    top_ = temp->next();
    delete temp;

    size_--;
    return data;
}

template<typename T>
T& LinkedStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }

    return top_->data();
}

template<typename T>
bool LinkedStack<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t LinkedStack<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
