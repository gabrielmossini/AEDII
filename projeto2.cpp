//AEDII             Gabriel Mossini, BCC/2,
//Atualização do Programa 01/06/22

//Alunos: RA (PK), nome, endereço, telefone, cidade, UF
//1) Escreva funções específicas para a leitura dos dados das estruturas
//2) Escreva uma função para permitir a inclusão e a exclusão de registros na tabela de alunos.

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
       char nome[30];
       char uf[2];
       char cidade[25];
       char endereco[35];
       char telefone[11];
       };

//leitura de dados dos Alunos
void leitura_dados (struct alunos als[], int &cont){
    int i = 0;
    for (int saida = 1; i < 3 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> als[i].codigo;
        if (als[i].codigo > 0){
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

//Leitura do indice
leitura_indice (struct indice idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

//Inclusão de Registros
void inclusao (struct indice idx[], struct alunos als[], int &cont, int cod){
    cont++;
    // inclusao do novo registro na area de dados
    als[cont].codigo = cod;
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


//busca aleatoria
void buscaaleat (struct indice idx[], struct alunos als[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
        cout << "\n\n Cliente ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Cliente: " << als[i].codigo;
        cout << "\tNome: " << als[i].nome;
        cout << "\tEstado: " << als[i].uf;
        cout << "\tCidade: " << als[i].cidade;
        cout << "\tEndereco: " << als[i].endereco;
        cout << "\tTelefone: " << als[i].telefone;
    }
    else
        inclusao (idx, als, cont, cod);
    getch();
}



int main(){

    struct indice ind[20];
    struct alunos dados[20];
    int contador, menu = 1;

    while(menu != 0){

        system("cls");
        cout << "\n\tGabriel Mossini\t";
        cout << "\tRA: 2111600174";
        cout << "\t\tAEDII";
        cout << "\t\tBegosso";
        cout << "\n\n\n\tExercicio 2 - Arquivos Indexados";

        cout << "\n\n\tMenu";
        cout << "\n\t1. Leitura da Area de Dados";
        cout << "\n\t2. Leitura da Area de Indice(Não sei se mantenho)";
        cout << "\n\t3. Incluo de Registros";
        cout << "\n\t4. Busca Aleatoria";
        cout << "\n\t0. Sair";

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
                leitura_dados (dados,contador);
                break;

            // Leitura de Indice
            case 2:
                system("cls");
                cout << "\n\nLeitura do Indice";
                leitura_indice (ind,contador);
                break;

            //Inclusao de Registros
            case 3:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo do Cliente a ser Incluido (0 para Sair): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        buscaaleat (ind, dados, contador, codpesq);
                }
                break;

            //Busca Aleatoria
            case 4:
                system("cls");
                for (int codpesq = 9; codpesq != 0;){
                cout << "\n\nInforme o Codigo do Cliente a ser Buscado (0 para Sair): ";
                cin >> codpesq;
                    if (codpesq != 0)
                        buscaaleat (ind, dados, contador, codpesq);
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
