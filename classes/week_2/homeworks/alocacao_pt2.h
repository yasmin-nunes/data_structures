// Copyright [2025] <COLOQUE SEU NOME AQUI...>
#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};


Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    Aluno *tf;
    tf = nullptr;  // retirar e alocar (com new)
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            count++;
        }
    }

    tf = new Aluno[count];

    int j = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            tf[j++] = t[i];
        }
    }

    return tf;
}

int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26]();
    char letra;
    for (int i = 0; i < N; i++) {
        letra = t[i].devolveNome()[0];
        int pos = letra - 'A';
        c[pos]++;
        }

    return c;
}


Aluno **grupos_por_iniciais(Aluno t[], int N) {
    Aluno **g;
    g = new Aluno *[26];

    int *c = turma_conta(t, N);

    for (int i = 0; i < 26; i++) {
        if (c[i] > 0) {
            g[i] = new Aluno[c[i]];
        } else {
            g[i] = nullptr;
            }
        }

    int posicoes[26] = {0};

    for (int i = 0; i < N; i++) {
        char letra = t[i].devolveNome()[0];
        int pos = letra - 'A';
        if (g[pos] != nullptr) {
            g[pos][posicoes[pos]++] = t[i];
        }
    }

  delete[] c;

  return g;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/

