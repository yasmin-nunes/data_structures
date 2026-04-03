// Copyright [2026] <YASMIN AVILA NUNES>
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
//! classe ArrayQueue
class ArrayQueue {
 public:
    //! construtor padrao
    ArrayQueue();
    //! construtor com parametro
    explicit ArrayQueue(std::size_t max);
    //! destrutor padrao
    ~ArrayQueue();
    //! metodo enfileirar
    void enqueue(const T& data);
    //! metodo desenfileirar
    T dequeue();
    //! metodo retorna o ultimo
    T& back();
    //! metodo limpa a fila
    void clear();
    //! metodo retorna tamanho atual
    std::size_t size();
    //! metodo retorna tamanho maximo
    std::size_t max_size();
    //! metodo verifica se vazio
    bool empty();
    //! metodo verifica se esta cheio
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    int begin_;  // indice do inicio (para fila circular)
    int end_;  // indice do fim (para fila circular)
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif

//! construtor padrao
template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

//! construtor com parametro
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

//! destrutor padrao
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
    delete [] contents;
}

/*template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    //! metodo empilha
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        top_++;
        contents[top_] = data;
    }
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    //! metodo desempilha
    if (!empty()) {
        T top_value = contents[top_];
        top_--;
        return top_value;
    } else {
        throw std::out_of_range("pilha vazia");
    }
}
    */

//! metodo enfileirar
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
    if (full()) {
        throw std::out_of_range("fila cheia");
    } else {
        size_++; 
        end_ = (end_ + 1) % max_size_;
        contents[end_] = data;
    }
}

//! metodo desenfileirar
template<typename T>
T structures::ArrayQueue<T>::dequeue() {
    // COLOQUE SEU CODIGO AQUI...
}

//! metodo retorna o ultimo
template<typename T>
T& structures::ArrayQueue<T>::back() {
    if (!empty()) {
        return contents[end_];
    }
}

//! metodo limpa a fila
template<typename T>
void structures::ArrayQueue<T>::clear() {
    for (int i = begin_; i < end_; i++) {

    }
}

//! metodo retorna tamanho atual
template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
    return begin_ - end_
}

//! metodo retorna tamanho maximo
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
    return max_size_; 
}

//! metodo verifica se vazio
template<typename T>
bool structures::ArrayQueue<T>::empty() {
    return size_ == 0;
}

//! metodo verifica se esta cheio
template<typename T>
bool structures::ArrayQueue<T>::full() {
    // a fila vai estar cheia se tamanho = maior tamanho
    return size_ == max_size;
}