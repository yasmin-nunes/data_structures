#include <iostream>

using namespace std;

struct coord {
    int x;
    int y;
};

int *cria_dominio(int N) {
    // int vet[N];  //alocação estática
    int *vet = new int[N];  //alocação dinâmica
    for (int i=0; i<N; i++) {
        vet[i] = i;
    }
    return vet;
}

coord soma_coordenadas_v1(coord A, coord B) {
    // passagem por valor (cópia)
    coord C;
    C.x = A.x + B.x;
    C.y = A.y + B.y;
    return C;
}

coord soma_coordenadas_v2(coord *pA, coord *pB) {
    // passagem por ponteiro (cópia apenas do ponteiro)
    coord C;
    C.x = pA->x + pB->x;
    C.y = pA->y + pB->y;
    return C;
}

coord soma_coordenadas_v3(coord &A, coord &B) {
    // passagem por referência (sem cópia)
    coord C;
    C.x = A.x + B.x;
    C.y = A.y + B.y;
    return C;
}


int main() {
    // std::cout << "Oi, mundo!" << std::endl;

    cout << "Oi, mundo!\n" << endl;

    int a;
    unsigned int b;

    short int c;
    long int d;

    char e;

    cout << sizeof(int) << ' ' << sizeof(short int) << ' ' << sizeof(long int) << ' ' << sizeof(char) << endl;

    a = 1020;
    e = 'B';

    float f;
    double g;

    bool h = true;

    // std::string h = "UFSC";
    string nome = "UFSC";

    /*
    Texto
    Texto
    Texto
    */

   if (a > 1000) {
        cout << "a maior 1000 e menor 1500\n";
   } else if (a < 1500) {
        cout << "a entre 1000 e 1500\n";
   } else {
        cout << "a maior que 1500";
   }

    switch(e) {
        case 'A':
            cout << "entrada 1\n";
            break;
        case 'B':
            cout << "entrada 2\n";
            // break;
        case 'X':
            cout << "entrada 3\n";
            break;
        case 'U':
            cout << "entrada 4\n";
            break;
        default:
            cout << "caso nenhuma anaterior\n";
    }

    a = 0;
    while (a < 10) {
        cout << a << ' ';
        a++;
    }
    cout << endl;

    a = 0;
    do {
        cout << a << ' ';
        a++;
    } while (a < 10);
    cout << endl;

    coord C1;

    C1.x = -10;
    C1.y = 5;

    cout << C1.x << ' ' << C1.y << endl;

    cout << sizeof(coord) << endl;

    coord C2;
    C2 = C1;

    cout << C2.x << ' ' << C2.y << endl;

    C2.x = 7; C2.y = -4;

    cout << C1.x << ' ' << C1.y << endl;
    cout << C2.x << ' ' << C2.y << endl;

    a = 77;

    cout << "endereço de a é " << &a << endl;

    // a = 88;

    int *ponteiro;
    ponteiro = &a;

    *ponteiro = 88;  //conteudo de 'ponteiro' recebe 88

    cout << "a = " << a << endl;

    int &apelido = a;  // compartilhamento de memória (não é cópia)

    cout << "apelido = " << apelido << endl;

    apelido = 99;

    cout << "apelido = " << apelido << endl;
    cout << "a = " << a << endl;

    cout << "endereço de a é " << &a << endl;
    cout << "endereço de apelido é " << &apelido << endl;

    coord *pc;

    pc = &C1;

    cout << "coordenada x é " << (*pc).x << endl;
    cout << "coordenada y é " << (*pc).y << endl;

    cout << "coordenada x é " << pc->x << endl;
    cout << "coordenada y é " << pc->y << endl;

    if (h) {
        int aa = 11;
        cout << aa << endl;
        coord c1; //alocação estática
        c1.x = -55;
        c1.y = 55;
    }
    // cout << aa << endl;

    coord *pc2;

    pc2 = new coord; //alocacao dinâmica
    pc2->x = -11;
    pc2->y = 11;

    pc2 = new coord;
    pc2->x = -1;
    pc2->y = 1;

    // a primeira alocação se torna incacessível ocupando memória

    delete pc2;

    int *v;
    int N = 10;
    v = cria_dominio(N);

    for (int i=0; i<N; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    for (int i=0; i<N; i++) {
        cout << *(v+i) << ' ';
    }
    cout << endl;

    coord *coordenadas = new coord[N];

    cout << coordenadas << endl;    
    cout << coordenadas+1 << endl;    
    cout << coordenadas+2 << endl;    

    delete [] v;

    coord X, Y, Z;
    X.x = 3; X.y = 5;
    Y.x = 2; Y.y = 3;

    Z = soma_coordenadas_v1(X, Y);
    cout << "Z.x = " << Z.x << " ; Z.y = " << Z.y << endl;

    Z = soma_coordenadas_v2(&X, &Y);
    cout << "Z.x = " << Z.x << " ; Z.y = " << Z.y << endl;

    Z = soma_coordenadas_v3(X, Y);
    cout << "Z.x = " << Z.x << " ; Z.y = " << Z.y << endl;

    return 0;
}