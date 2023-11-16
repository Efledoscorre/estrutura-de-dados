#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct servico {
    char nome[50];
    char detalhes[100];
    float preco;
};

struct cliente {
    char nome[50];
    char email[100];
    int idade;
    char endereco[100];
    char estado[3];
    struct servico servicos[3];
};

struct prestadorServico {
    char nome[50];
    char estado[3];
    char tipoServico[20];
    char especializacao[50];
};

struct hospital {
    char nome[50];
    char estado[3];
    struct servico servicos[3][3];
    struct prestadorServico prestadores[5];
};

void exibirDetalhesDoServico(struct servico servico);
void ordenarServicos(struct hospital *hosp);
void exibirPrestadoresPorTipo(struct prestadorServico prestadores[], int numPrestadores, char tipo[]);
int escolherPrestadorDeServico(struct prestadorServico prestadores[], int numPrestadores, char tipo[]);
void ordenarServicosPorPreco(struct servico servicos[], int numServicos);

void exibirDetalhesDoServico(struct servico servico) {
    printf("Detalhes do serviço:\n");
    printf("Nome: %s\n", servico.nome);
    printf("Detalhes: %s\n", servico.detalhes);
    printf("Preço: %.2f R$\n", servico.preco);
}

int escolherPrestadorDeServico(struct prestadorServico prestadores[], int numPrestadores, char tipo[]) {
    printf("Escolha um prestador de serviço para %s:\n", tipo);
    exibirPrestadoresPorTipo(prestadores, numPrestadores, tipo);

    int escolhaPrestador;
    printf("Digite o número do prestador escolhido: ");
    scanf("%d", &escolhaPrestador);

    while (escolhaPrestador < 1 || escolhaPrestador > numPrestadores) {
        printf("Escolha inválida. Digite novamente: ");
        scanf("%d", &escolhaPrestador);
    }

    return escolhaPrestador - 1;
}

void ordenarServicos(struct hospital *hosp) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (hosp->servicos[0][i].preco > hosp->servicos[0][j].preco) {
                struct servico temp = hosp->servicos[0][i];
                hosp->servicos[0][i] = hosp->servicos[0][j];
                hosp->servicos[0][j] = temp;
            }
        }
    }
}

void exibirPrestadoresPorTipo(struct prestadorServico prestadores[], int numPrestadores, char tipo[]) {
    printf("Prestadores de serviço disponíveis para %s:\n", tipo);
    for (int indicePrestador = 0; indicePrestador < numPrestadores; indicePrestador++) {
        if (strcmp(prestadores[indicePrestador].tipoServico, tipo) == 0) {
            printf("[%d] %s - %s\n", indicePrestador + 1, prestadores[indicePrestador].nome, prestadores[indicePrestador].estado);
        }
    }
}

void ordenarServicosPorPreco(struct servico servicos[], int numServicos) {
    for (int i = 0; i < numServicos - 1; i++) {
        for (int j = 0; j < numServicos - i - 1; j++) {
            if (servicos[j].preco > servicos[j + 1].preco) {
                struct servico temp = servicos[j];
                servicos[j] = servicos[j + 1];
                servicos[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    struct cliente clientes[3];
    struct hospital hospitais[3] = {
        {"Santa Lucia", "RJ", {{"Consulta", "", 500.0}, {"Exame", "", 800.0}, {"Cirurgia", "", 3000.0}}},
        {"Ordem do Carmo", "RJ", {{"Consulta", "", 500.0}, {"Exame", "", 800.0}, {"Cirurgia", "", 3000.0}}},
        {"São Lucas", "MG", {{"Consulta", "", 500.0}, {"Exame", "", 800.0}, {"Cirurgia", "", 3000.0}}}
    };

    struct prestadorServico prestadores[5] = {
        {"Dr. Silva", "DF", "Consulta", "Clínica Geral"},
        {"Dra. Santos", "RJ", "Consulta", "Pediatria"},
        {"Dr. Souza", "MG", "Cirurgia", "Ortopedia"},
        {"Dr. Lucas", "SP", "Exame", "Radiologia"},
        {"Dr. Matheus", "RJ", "Exame", "Cardiologia"}
    };

    int opcao;
    int numClientes = 0;
    int maisClientes;

    do {
    	system("color f4");
        printf("\n1 - Entrar como cliente\n");
        printf("2 - Entrar como ADM\n");
        printf("3 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nEntrou como cliente\n\n");

                do {
                    numClientes++;
                    printf("\nDigite os dados do cliente %d:\n", numClientes);
                    printf("Nome do cliente: ");
                    scanf("%s", clientes[numClientes - 1].nome);
                    printf("E-mail do cliente: ");
                    scanf("%s", clientes[numClientes - 1].email);
                    printf("Idade do cliente: ");
                    scanf("%d", &clientes[numClientes - 1].idade);
                    printf("Endereço do cliente: ");
                    scanf("%s", clientes[numClientes - 1].endereco);
                    printf("Estado do cliente (ex.: SP): ");
                    scanf("%s", clientes[numClientes - 1].estado);

                    int escolhaConsulta = escolherPrestadorDeServico(prestadores, 5, "Consulta");
                    strcpy(clientes[numClientes - 1].servicos[0].nome, prestadores[escolhaConsulta].nome);
                    strcpy(clientes[numClientes - 1].servicos[0].detalhes, prestadores[escolhaConsulta].especializacao);
                    clientes[numClientes - 1].servicos[0].preco = 300.0;

                    int escolhaExame = escolherPrestadorDeServico(prestadores, 5, "Exame");
                    strcpy(clientes[numClientes - 1].servicos[1].nome, prestadores[escolhaExame].nome);
                    strcpy(clientes[numClientes - 1].servicos[1].detalhes, prestadores[escolhaExame].especializacao);
                    clientes[numClientes - 1].servicos[1].preco = 800.0;

                    int escolhaCirurgia = escolherPrestadorDeServico(prestadores, 5, "Cirurgia");
                    strcpy(clientes[numClientes - 1].servicos[2].nome, prestadores[escolhaCirurgia].nome);
                    strcpy(clientes[numClientes - 1].servicos[2].detalhes, prestadores[escolhaCirurgia].especializacao);
                    clientes[numClientes - 1].servicos[2].preco = 3000.0;

                    for (int i = 0; i < 3; i++) {
                        int dia = rand() % 28 + 1;
                        int mes = rand() % 12 + 1;
                        int ano = 2024;

                        sprintf(clientes[numClientes - 1].servicos[i].detalhes, "%02d/%02d/%04d", dia, mes, ano);
                    }

                    printf("\nServiços escolhidos:\n");
                    for (int i = 0; i < 3; i++) {
                        exibirDetalhesDoServico(clientes[numClientes - 1].servicos[i]);
                    }

                    printf("\nDeseja adicionar mais clientes? (1 - Sim, 0 - Não): ");
                    scanf("%d", &maisClientes);

                } while (maisClientes == 1);

                for (int l = 0; l < numClientes; l++) {
                    printf("\nCliente %d: %s\n", l + 1, clientes[l].nome);
                    printf("E-mail: %s\n", clientes[l].email);
                    printf("Idade: %d\n", clientes[l].idade);
                    printf("Endereço: %s\n", clientes[l].endereco);
                    printf("Estado: %s\n", clientes[l].estado);
                    for (int i = 0; i < 3; i++) {
                        printf("Serviço %d: %s - %.2f R$\n", i + 1, clientes[l].servicos[i].nome, clientes[l].servicos[i].preco);
                    }
                }

                break;

            case 2:
                printf("\nEntrou como ADM\n\n");

                int opcaoADM;
                do {
                    printf("MENU ADM\n");
                    printf("1 - Listar todos os prestadores de serviços\n");
                    printf("2 - Listar todos os tipos de serviços em ordem crescente de valor\n");
                    printf("3 - Listar os prestadores de serviço de um determinado tipo\n");
                    printf("4 - Listar todos os clientes em ordem crescente\n");
                    printf("5 - Listar os clientes de um determinado estado\n");
                    printf("6 - Apresentar o(s) estado(s) onde está registrado o serviço mais caro\n");
                    printf("7 - Listar todos os clientes em ordem alfabética\n");
                    printf("8 - Sair\n");
                    printf("Digite uma opção: ");
                    scanf("%d", &opcaoADM);

                    switch (opcaoADM) {
                        case 1:
                            printf("\nListar todos os prestadores de serviços:\n");
                            for (int i = 0; i < 5; i++) {
                                printf("Prestador %d: %s, Estado: %s\n", i + 1, prestadores[i].nome, prestadores[i].estado);
                            }
                            break;

                        case 2:
                            printf("\nListar todos os tipos de serviços em ordem crescente de valor:\n");
                            for (int i = 0; i < 3; i++) {
                                printf("%s\n", hospitais[i].nome);
                                for (int j = 0; j < 3; j++) {
                                    ordenarServicosPorPreco(hospitais[i].servicos[j], 3);
                                    for (int k = 0; k < 3; k++) {
                                        if (hospitais[i].servicos[j][k].preco > 0.0)
                                            printf("%s - %.2f R$\n", hospitais[i].servicos[j][k].nome, hospitais[i].servicos[j][k].preco);
                                    }
                                }
                                printf("\n");
                            }
                            break;

                        case 3:
                            printf("\nListar os prestadores de serviço de um determinado tipo:\n");
                            printf("\nConsulta\n");
                            exibirPrestadoresPorTipo(prestadores, 5, "Consulta");
                            printf("\nExame\n");
                            exibirPrestadoresPorTipo(prestadores, 5, "Exame");
                            printf("\nCirurgia\n");
                            exibirPrestadoresPorTipo(prestadores, 5, "Cirurgia");
                            break;

                        case 4:
                            printf("\nListar todos os clientes em ordem crescente:\n");
                            for (int i = 0; i < numClientes; i++) {
                                printf("Cliente %d: %s, Estado: %s\n", i + 1, clientes[i].nome, clientes[i].estado);
                            }
                            break;

                        case 5:
                            printf("\nListar os clientes de um determinado estado:\n");
                            char estadoDesejado[3];
                            printf("Digite o estado desejado (ex.: SP): ");
                            scanf("%s", estadoDesejado);
                            for (int i = 0; i < numClientes; i++) {
                                if (strcmp(clientes[i].estado, estadoDesejado) == 0) {
                                    printf("Cliente %d: %s, Estado: %s\n", i + 1, clientes[i].nome, clientes[i].estado);
                                }
                            }
                            break;

                        case 6:
                            printf("\nApresentar o(s) estado(s) onde está registrado o serviço mais caro:\n");
                            float maxPrice = 0.0;
                            for (int i = 0; i < numClientes; i++) {
                                if (clientes[i].servicos[0].preco > maxPrice) {
                                    maxPrice = clientes[i].servicos[0].preco;
                                }
                            }
                            printf("Estado(s) onde está registrado o serviço mais caro:\n");
                            for (int i = 0; i < numClientes; i++) {
                                if (clientes[i].servicos[0].preco == maxPrice) {
                                    printf("%s\n", clientes[i].estado);
                                }
                            }
                            break;
                    }
                } while (opcaoADM != 7);
                break;
        }
    } while (opcao != 3);

    return 0;
}


