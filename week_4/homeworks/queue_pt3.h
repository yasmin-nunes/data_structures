// Copyright [2026] <YASMIN AVILA NUNES>
#include <string>
#include "./array_queue.h"

structures::ArrayQueue<char> editaTexto(std::string texto) {
    structures::ArrayQueue<char> fila(500);
    for (size_t i = 0; i < texto.size(); i++) {
        char caractere = texto[i];
        if (caractere == '<') {
            fila.dequeue();
        } else if (caractere == '>') {
            fila.enqueue(fila.back());
        } else {
            fila.enqueue(caractere);
        }
    }

    return fila;
}