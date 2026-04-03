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
    int matr;
    matr = t[i].devolveMatricula();

    for (int i = 0; i < N; i++) {
        matr = t[i].devolveMatricula();
        if (matr > menor_matr) {
            tf[i] = t[i];
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
    g = new Aluno*[26];  // vetor de ponteiros;
                         // cada posição aponta para um vetor de alunos;
                         // g deve ser alocado com o seguinte:
                         //   g[0] é um ponteiro para alunos com letra 'A'
                         //   g[1] é um ponteiro para alunos com letra 'B'
                         //   ...
                         //   g[25] é um ponteiro para alunos com letra 'Z'

    // DICA: utilize a função 'turma_conta' (implementada no execício 5) para
    //       definir o tamanho de cada um dos 26 vetores
    // int *c = turma_conta(t, N);



    return g;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/