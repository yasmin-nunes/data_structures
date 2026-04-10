// Copyright [2026] <YASMIN AVILA NUNES>

/*
    *** Importante ***

    - É preciso anexar o código de lista em vetor (utilize o ícone '+' e, na
      sequência, o ícone 'Novo' ou Alt+N para novo arquivo). Utilize o nome:
          array_list.h
    
    - A seguinte diretriz NÃO deve ser escrita, pois já está nos testes: 
          #include "./array_list.h"  // não deve constar

*/


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


/*
(1) seleciona alunos de uma lista 'turma_entrada', cujos nomes iniciam com uma determinada 'letra', produzinda uma lista 'turma_saida' como resposta.
Exemplo:
  turma_entrada = [{'Fulano',1010}, {'Beltrano',2020}, {'Fulana',7070}, {'Cicrana':1515}, {'Beltrana',8080}]
  letra = 'F'
  turma_saida = [{'Fulano',1010}, {'Fulana',7070}]
*/

structures::ArrayList<Aluno> selecao_nome(structures::ArrayList<Aluno> &turma_entrada, char letra) {
    structures::ArrayList<Aluno> turma_saida(turma_entrada.size());
    int tamanho = turma_entrada.size();
    for (int i = 0; i < tamanho; i++) {
        char inicial = turma_entrada[i].devolveNome()[0];
        if (letra == inicial) {
            turma_saida.push_back(turma_entrada[i]);
        }
    }
    return turma_saida;
}

/*
(2) amostra alunos a cada 'k' posições de uma lista 'turma_entrada'.
Exemplo: 
  turma_entrada: [A,B,C,D,E,F,G,H]
  k = 3
  turma_saida: [C,F]
*/

structures::ArrayList<Aluno> selecao_amostra(structures::ArrayList<Aluno> &turma_entrada, int k) {
    structures::ArrayList<Aluno> turma_saida(turma_entrada.size());
    int tamanho = turma_entrada.size();
    for (int i = k - 1; i < tamanho; i += k) {
        turma_saida.push_back(turma_entrada[i]);
        }
    return turma_saida;
}
