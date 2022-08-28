//AEDII             Gabriel Mossini, BCC/2,
//Atualização do Programa 01/06/22

//Alunos: RA (PK), nome, endereço, telefone, cidade, UF - Finalizado
//Editoras: código (PK), nome, endereço, telefone, cidade, UF - Finalizado
//Livros: código (PK), descrição, cod_editora, situação (E/D) (Emprestado/Disponível) - Finalizado - Necessario Revisar
//Empréstimos: código (PK), RA_aluno, código_livro, data_empréstimo, data_devolução, situação (E/D) (Emprestado/Devolvido) - Necessario Revisar

//1) Escreva funções específicas para a leitura dos dados das estruturas - Feito
//2) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de alunos. Finalizado
//3) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de editoras. Em Desenvolvimento - necessario melhorar
//4) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de livros. Não Finalizado

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct indice {
       int codigo;
       int ender;
       };

struct alunos {
       int codigo;
       int ra;
       char nome[30];
       char uf[2];
       char cidade[25];
       char endereco[35];
       char telefone[11];
       int status;
       };

struct editoras {
       int codigo;
       char nome[30];
       char uf[2];
       char cidade[25];
       char endereco[35];
       char telefone[11];
       int status;
       };

struct livros {
       int codigo;
       char descricao[30];
       char cod_editora[2];
       char situacao[1]; //situação (E/D)
       int status;
       };

struct emprestimos {
       int RA_ALUNO;
       char descricao[30];
       char cod_editora[2];
       char situacao[1]; //situação (E/D)
       int status;
       };

//leitura de dados dos Alunos
void leituraDados_Alunos (struct alunos als[], int &cont){
    int i = 0;
    for (int saida = 1; i < 3 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> als[i].codigo;
        if (als[i].codigo > 0){
            cout << "RA: ";
            cin >> als[i].ra;
            cout << "Nome: ";
            cin >> als[i].nome;
            cout << "Estado: ";
            cin >> als[i].uf;
            cout << "Cidade: ";
            cin >> als[i].cidade;
            cout << "Endereco: ";
            cin >> als[i].endereco;
            cout << "Telefone: ";
            cin >> als[i].telefone;
        }
        else saida = 0;
    }
    cont = i-1;
}

//leitura de dados dos Editoras
void leituraDados_Editoras (struct editoras edt[], int &cont){
    int i = 0;
    for (int saida = 1; i < 3 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> edt[i].codigo;
        if (edt[i].codigo > 0){
            cout << "Nome: ";
            cin >> edt[i].nome;
            cout << "Estado: ";
            cin >> edt[i].uf;
            cout << "Cidade: ";
            cin >> edt[i].cidade;
            cout << "Endereco: ";
            cin >> edt[i].endereco;
            cout << "Telefone: ";
            cin >> edt[i].telefone;
        }
        else saida = 0;
    }
    cont = i-1;
}

//Leitura do indice
void leituraIndice (struct indice idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

//Inclusão de Registros na Tabela Alunos
void inclusao_Alunos (struct indice idx[], struct alunos als[], int &cont, int cod){
    cont++;
    // inclusao do novo registro na area de dados
    als[cont].codigo = cod;
    cout << "RA: ";
    cin >> als[cont].ra;
    cout << "Nome: ";
    cin >> als[cont].nome;
    cout << "Endereco: ";
    cin >> als[cont].endereco;
    cout << "Cidade: ";
    cin >> als[cont].cidade;
    cout << "Estado: ";
    cin >> als[cont].uf;
    cout << "Telefone: ";
    cin >> als[cont].telefone;

// inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

//Inclusão de Registros na Tabela Editoras
void inclusao_Editoras (struct indice idx[], struct editoras edt[], int &cont, int cod){
    cont++;
    // inclusao do novo registro na area de dados
    edt[cont].codigo = cod;
    cout << "Nome: ";
    cin >> edt[cont].nome;
    cout << "Endereco: ";
    cin >> edt[cont].endereco;
    cout << "Cidade: ";
    cin >> edt[cont].cidade;
    cout << "Estado: ";
    cin >> edt[cont].uf;
    cout << "Telefone: ";
    cin >> edt[cont].telefone;

// inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}


//Inclusao de Registros na Tabela Alunos
void inclusaoReg_Alunos (struct indice idx[], struct alunos als[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
        cout << "\t\n Cliente ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Aluno: " << als[i].codigo;
        cout << "\nRA do Aluno: " << als[i].ra;
        cout << "\tNome: " << als[i].nome;
        cout << "\tEstado: " << als[i].uf;
        cout << "\tCidade: " << als[i].cidade;
        cout << "\tEndereco: " << als[i].endereco;
        cout << "\tTelefone: " << als[i].telefone;

    }
    else
        inclusaoReg_Alunos (idx, als, cont, cod);

    if ((cod == idx[m].codigo) && als[i].status == 0){
        als[i].status = 1;
        cout << "\t\nCliente Excluido com Sucesso";
    }
    else
        cout << "\t\nCliente nao cadastrado";
    getch();
}

//Inclusao de Registros na Tabela Editoras
void inclusaoReg_Editoras (struct indice idx[], struct editoras edt[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
        cout << "\t\n Livro ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Livro: " << edt[i].codigo;
        cout << "\tNome: " << edt[i].nome;
        cout << "\tEstado: " << edt[i].uf;
        cout << "\tCidade: " << edt[i].cidade;
        cout << "\tEndereco: " << edt[i].endereco;
        cout << "\tTelefone: " << edt[i].telefone;

    }
    else
        inclusaoReg_Editoras (idx, edt, cont, cod);

    if ((cod == idx[m].codigo) && edt[i].status == 0){
        edt[i].status = 1;
        cout << "\t\nLivro Excluido com Sucesso";
    }
    else
        cout << "\t\nLivro nao cadastrado";
    getch();
}

// Exclusao de Alunos
void exclusao_Alunos (struct indice idx[], struct alunos edt[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if ((cod == idx[m].codigo) && edt[i].status == 0){
        edt[i].status = 1;
        cout << "\t\n Cliente Excluido com Sucesso";
    }
    else
        cout << "\t\nCliente nao cadastrado";
    getch();
}

// Exclusao de Editoras
void exclusao_Editoras (struct indice idx[], struct editoras edt[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if ((cod == idx[m].codigo) && edt[i].status == 0){
        edt[i].status = 1;
        cout << "\t\n Editora Excluido com Sucesso";
    }
    else
        cout << "\t\nEditoras nao cadastrado";
    getch();
}

int main(){

    struct indice ind[20];
    struct alunos dadosAls[20];
    struct editoras dadosEdt[20];
    int contador, menu = 1;

    while(menu != 0){

        system("cls");
        cout << "\n\tGabriel Mossini\t";
        cout << "\tRA: 2111600174";
        cout << "\t\tAEDII";
        cout << "\t\tBegosso";
        cout << "\n\n\n\tExercicio 2 - Arquivos Indexados";

        cout << "\n\n\tMenu";
        cout << "\n\n\tAlunos";
        cout << "\n\t1. Leitura da Area de Dados(Alunos)";
        cout << "\n\t2. Leitura da Area de Indice";
        cout << "\n\t3. Inclusao de Registros(Alunos)";
        cout << "\n\t4. Exclusao de Registros(Alunos)";
        cout << "\n\n\tEditoras";
        cout << "\n\t5. Leitura da Area de Dados(Editoras)";
        cout << "\n\t6. Inclusao de Registros(Editoras)";
        cout << "\n\t7. Exclusao de Registros(Editoras)";
        cout << "\n\n\t0. Sair";

        cout << "\n\n\tInsira uma Opcao: ";
        fflush(stdin);
        cin >> menu;
        fflush(stdin);
        menu = toupper(menu);

        switch(menu){
            // Leitura de Dados
            case 1:
                system("cls");
                cout << "\n\nLeitura da Area de Dados";
                leituraDados_Alunos (dadosAls,contador);
                break;

            // Leitura de Indice
            case 2:
                system("cls");
                cout << "\n\nLeitura do Indice";
                leituraIndice (ind,contador);
                break;

            //Inclusao de Registros
            case 3:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo do Aluno a ser Incluido (0 para Sair): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        inclusaoReg_Alunos (ind, dadosAls, contador, codpesq);
                }
                break;

            case 4:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo do Aluno a ser Excluido (0 para Encerrar): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        exclusao_Alunos (ind, dadosAls, contador, codpesq);
                }
                break;

            //Editoras
            //Inclusao de Registros

            case 5:
                system("cls");
                cout << "\n\nLeitura da Area de Dados";
                leituraDados_Editoras (dadosEdt,contador);
                break;

            case 6:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo da Editora a ser Incluido (0 para Sair): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        inclusaoReg_Editoras (ind, dadosEdt, contador, codpesq);
                }
                break;

            case 7:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo do Cliente a ser Excluido (0 para Encerrar): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        exclusao_Editoras (ind, dadosEdt, contador, codpesq);
                }
                break;

            //Sair
            case 0:
                cout << "\n\n\tObrigado por usar o programa\n";
                exit(0);

            //Mensagem Padrão
            default:
                cout << "Opção invalida, por favor escolha entre(1-3)";
            break;

            }
            cout << endl << "\t";
            system("pause");
    }

}
