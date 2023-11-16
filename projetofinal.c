#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICOS 100
#define MAX_CLIENTES 100
#define MAX_PRESTADORES 100


typedef struct {
    char detalhamento[100];
    char data[20];
    double preco;
    char uf[3];
} Servico;

typedef struct {
    char nome[50];
    int idade;
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
} Consumidor;

typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
} Prestador;


void listarServicos(Servico servicos[], int count);
void listarClientes(Consumidor clientes[], int count);
void listarPrestadores(Prestador prestadores[], int count);
void listarClientesPorEstado(Consumidor clientes[], int count, char estado[]);
void listarPrestadoresPorServico(Prestador prestadores[], int count, char tipoServico[]);
void estadoServicoMaisCaro(Servico servicos[], int count, char estado[]);
void listarServicosOrdenadosPorValor(Servico servicos[], int count);
void listarClientesOrdenadosPorNome(Consumidor clientes[], int count);

int main() {
    
    Servico servicos[MAX_SERVICOS];
    servicos[0].preco = 350.0;
    strcpy(servicos[0].detalhamento, "internacao");
    strcpy(servicos[0].data, "2023-11-15");
    strcpy(servicos[0].uf, "RJ");
    
    servicos[1].preco = 150.0;
    strcpy(servicos[1].detalhamento, "coleta de sangue");
    strcpy(servicos[1].data, "2023-10-17");
    strcpy(servicos[1].uf, "RJ");
    
    servicos[2].preco = 1000.0;
    strcpy(servicos[2].detalhamento, "cirurgia");
    strcpy(servicos[2].data, "2023-11-19");
    strcpy(servicos[2].uf, "SP");
    
    Consumidor clientes[MAX_CLIENTES];
    strcpy(clientes[0].nome, "Joao Silva");
    clientes[0].idade = 30;
    strcpy(clientes[0].email, "joao@email.com");
    strcpy(clientes[0].telefone, "123456789");
    strcpy(clientes[0].endereco, "Rua A, 123");
    strcpy(clientes[0].uf, "SP");
    
    strcpy(clientes[1].nome, "Julia Pereira");
    clientes[1].idade = 20;
    strcpy(clientes[1].email, "julia@email.com");
    strcpy(clientes[1].telefone, "234567891");
    strcpy(clientes[1].endereco, "Rua B, 123");
    strcpy(clientes[1].uf, "RJ");
    
    strcpy(clientes[2].nome, "Severina Maria");
    clientes[2].idade = 65;
    strcpy(clientes[2].email, "severina@outlook.com");
    strcpy(clientes[2].telefone, "234678951");
    strcpy(clientes[2].endereco, "Rua B, 123");
    strcpy(clientes[2].uf, "RJ");

    Prestador prestadores[MAX_PRESTADORES];
    strcpy(prestadores[0].nome, "Medico jose");
    strcpy(prestadores[0].email, "hospital@email.com");
    strcpy(prestadores[0].telefone, "987654321");
    strcpy(prestadores[0].endereco, "Avenida B, 456");
    strcpy(prestadores[0].uf, "SP");
    
    strcpy(prestadores[1].nome, "Recepcao");
    strcpy(prestadores[1].email, "pietro@email.com");
    strcpy(prestadores[1].telefone, "943215421");
    strcpy(prestadores[1].endereco, "Avenida D, 457");
    strcpy(prestadores[1].uf, "RJ");
    
    strcpy(prestadores[2].nome, "Enfermeiras");
    strcpy(prestadores[2].email, "enfermeiras@email.com");
    strcpy(prestadores[2].telefone, "757654321");
    strcpy(prestadores[2].endereco, "Avenida C, 497");
    strcpy(prestadores[2].uf, "SP");
    
    
    int opcao;
    char estado[3];
    do {
        printf("\nMenu:\n");
        printf("1. Listar todos os tipos de servicos.\n");
        printf("2. Listar todos os clientes.\n");
        printf("3. Listar todos os prestadores de servicos.\n");
        printf("4. Listar os clientes de um determinado estado.\n");
        printf("5. Listar os prestadores de servico de um determinado tipo.\n");
        printf("6. Apresentar o(s) estado(s) onde esta registrado o servico mais caro.\n");
        printf("7. Listar todos os servicos em ordem crescente de valor.\n");
        printf("8. Listar todos os clientes em ordem crescente de nome.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarServicos(servicos, 3);
                break;
            case 2:
                listarClientes(clientes, 3);
                break;
            case 3:
                listarPrestadores(prestadores, 3);
                break;
            case 4:
                printf("Digite o estado (UF): ");
                scanf("%s", estado);
                listarClientesPorEstado(clientes, 3, estado);
                break;
            case 5:
                listarPrestadoresPorServico(prestadores, 1, "Consulta");
                break;
            case 6:
                estadoServicoMaisCaro(servicos, 3, "SP" );
                break;
            case 7:
                listarServicosOrdenadosPorValor(servicos, 3);
                break;
            case 8:
                listarClientesOrdenadosPorNome(clientes, 3);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}


void listarServicos(Servico servicos[], int count) {
	int h;
    printf("\nLista de Servicos:\n");
    for (h = 0; h < count; h++) {
        printf("Detalhamento: %s\n", servicos[h].detalhamento);
        printf("Data: %s\n", servicos[h].data);
        printf("Preco: %.2f\n", servicos[h].preco);
        printf("UF: %s\n", servicos[h].uf);
        printf("\n");
    }
}

void listarClientes(Consumidor clientes[], int count) {
	int f;
    printf("\nLista de Clientes:\n");
    for (f = 0; f < count; f++) {
        printf("Nome: %s\n", clientes[f].nome);
        printf("Idade: %d\n", clientes[f].idade);
        printf("Email: %s\n", clientes[f].email);
        printf("Telefone: %s\n", clientes[f].telefone);
        printf("Endereco: %s\n", clientes[f].endereco);
        printf("UF: %s\n", clientes[f].uf);
        printf("\n");
    }
}

void listarPrestadores(Prestador prestadores[], int count) {
    printf("\nLista de Prestadores de Servicos:\n");
    int e;
    for (e = 0; e < count; e++) {
        printf("Nome: %s\n", prestadores[e].nome);
        printf("Email: %s\n", prestadores[e].email);
        printf("Telefone: %s\n", prestadores[e].telefone);
        printf("Endereco: %s\n", prestadores[e].endereco);
        printf("UF: %s\n", prestadores[e].uf);
        printf("\n");
    }
}

void listarClientesPorEstado(Consumidor clientes[], int count, char estado[]) {
    int d;
    printf("\nClientes do Estado %s:\n", estado);
    for (d = 0; d < count; d++) {
        if (strcmp(clientes[d].uf, estado) == 0) {
            printf("Nome: %s\n", clientes[d].nome);
            printf("Idade: %d\n", clientes[d].idade);
            printf("Email: %s\n", clientes[d].email);
            printf("Telefone: %s\n", clientes[d].telefone);
            printf("Endereco: %s\n", clientes[d].endereco);
            printf("UF: %s\n", clientes[d].uf);
            printf("\n");
        }
    }
}

void listarPrestadoresPorServico(Prestador prestadores[], int count, char tipoServico[]) {
	int b;
    printf("\nPrestadores de Servico para %s:\n", tipoServico);
    for ( b = 0; b < count; b++) {
        printf("Nome: %s\n", prestadores[b].nome);
        printf("Email: %s\n", prestadores[b].email);
        printf("Telefone: %s\n", prestadores[b].telefone);
        printf("Endereco: %s\n", prestadores[b].endereco);
        printf("UF: %s\n", prestadores[b].uf);
        printf("\n");
    }
}

void estadoServicoMaisCaro(Servico servicos[], int count, char estado[]) {
    double maxPreco = -1.0;
    int a;
    printf("\nEstado(s) onde esta registrado o servico mais caro:\n");

    for (a = 0; a < count; a++) {
        if (servicos[a].preco > maxPreco) {
            maxPreco = servicos[a].preco;
        }
    }

    for (a = 0; a < count; a++) {
        if (servicos[a].preco == maxPreco) {
            printf("Detalhamento: %s\n", servicos[a].detalhamento);
            printf("Data: %s\n", servicos[a].data);
            printf("Preco: %.2f\n", servicos[a].preco);
            printf("UF: %s\n", servicos[a].uf);
            printf("\n");
        }
    }
}

void listarServicosOrdenadosPorValor(Servico servicos[], int count) {
	int c, j;
    for (c = 0; c < count - 1; c++) {
        for (j = 0; j < count - c - 1; j++) {
            if (servicos[j].preco > servicos[j + 1].preco) {
                // Trocar
                Servico temp = servicos[j];
                servicos[j] = servicos[j + 1];
                servicos[j + 1] = temp;
            }
        }
    }

    printf("\nLista de Servicos em Ordem Crescente de Valor:\n");
    for (c = 0; c < count; c++) {
        printf("Detalhamento: %s\n", servicos[c].detalhamento);
        printf("Data: %s\n", servicos[c].data);
        printf("Preco: %.2f\n", servicos[c].preco);
        printf("UF: %s\n", servicos[c].uf);
        printf("\n");
    }
}

void listarClientesOrdenadosPorNome(Consumidor clientes[], int count) {
    
    int l, j;
    for (l = 0; l < count - 1; l++) {
        for (j = 0; j < count - l - 1; j++) {
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                // Trocar
                Consumidor temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }

    printf("\nLista de Clientes em Ordem Crescente de Nome:\n");
    for (l = 0; l < count; l++) {
        printf("Nome: %s\n", clientes[l].nome);
        printf("Idade: %d\n", clientes[l].idade);
        printf("Email: %s\n", clientes[l].email);
        printf("Telefone: %s\n", clientes[l].telefone);
        printf("Endereço: %s\n", clientes[l].endereco);
        printf("UF: %s\n", clientes[l].uf);
        printf("\n");
    }
    
}
