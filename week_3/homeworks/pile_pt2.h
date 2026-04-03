// Copyright [2026] <YASMIN AVILA NUNES>
#include <string>
#include "./array_stack.h"

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int tamanho = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);
    for (int i = 0; i < tamanho; i++) {
        char caractere = trecho_programa[i];
        if (caractere == '{') {
            pilha.push(caractere);
        } else if (caractere == '}') {
            if (pilha.empty()) {
                resposta = false;
                break;
            } else {
                pilha.pop();
            }
        }
    }
    /* no fim a resposta ainda for true, mas a pilha NÃO estiver vazia,
    significa que sobrou algum '{' sem fechar. */
    if (resposta && !pilha.empty()) {
        resposta = false;
    }
    return resposta;
}