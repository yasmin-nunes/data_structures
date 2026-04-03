
#include <string>

class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor --> quando fazemos alocação de memória no construtor, usamos o destrutor para desalocar 
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
