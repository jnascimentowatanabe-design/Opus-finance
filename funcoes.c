#include <stdio.h>
#include <string.h>
#include "funcoes.h"



void menu() {
	
	char nome[100] = "";
    char categoria[100] = "";
    int quantidade = 0;
    double precoCompra = 0;
    double precoAtual = 0;
    int ativoCadastrado = 0;
    int answer;
	
	do{
		printf("-----------Opus Finance-------------\n");
		printf("Qual trabalho desejas realizar?\n");
		printf("1 --> Cadastrar Ativo\n");
		printf("2 --> Visualizar a rentabilidade\n");
		printf("3 --> Calcular o lucro e prejuizo\n");
		printf("4 --> Classificar o risco\n");
		printf("0 --> Sair do Opus Finance\n");
	
		scanf("%d", &answer);
		
		if (answer < 0 || answer > 4) {
			printf("Desculpa! essa resposta nao existe, tente novamente\n");
			continue;
		}	
		
		switch(answer){
			case 1:
				cadastrarAtivo(nome, categoria, &quantidade, &precoCompra, &precoAtual);
                ativoCadastrado = 1;
                break;
			case 2:
				if (ativoCadastrado) {
				printf("\nRentabilidade de %s: %.2f%%\n", nome, calcular_rentabilidade(precoCompra, precoAtual)); 
				} else {
					printf("Cadastre o ativo primeiro!");
				}
				break;
			case 3:
				if (ativoCadastrado) {
                    exibir_resultado(nome, quantidade, precoCompra, precoAtual);
                } else {
                    printf("Cadastre um ativo primeiro!\n");
                }
                break;
			case 4: 
				if (ativoCadastrado) {
                    classificarRisco(calcular_rentabilidade(precoCompra, precoAtual));
                } else {
                    printf("Cadastre um ativo primeiro!\n");
                }
                break; 
            case 0:
				printf("Saindo do Opus Finance...\n");
                break;
			default:
				printf("escolha invalida");
		}     	
	} while (answer != 0);
}




void classificarRisco(float rentabilidade) {
	if (rentabilidade < 10.0) {
		printf("ALERTA: Rentabilidade Baixa\n");
	} else {
		printf("Rentabilidade dentro do esperado\n");
	}
}


double calcular_rentabilidade(double preco_compra, double preco_atual) {
    return (preco_atual - preco_compra) / preco_compra * 100.0;
}

double calcular_lucro_prejuizo(double preco_compra, double preco_atual, double quantidade) {
    return (preco_atual - preco_compra) * quantidade;
}

void exibir_resultado(char nome[], double quantidade, double preco_compra, double preco_atual) {
    double rentabilidade = calcular_rentabilidade(preco_compra, preco_atual);
    double lucro_prejuizo = calcular_lucro_prejuizo(preco_compra, preco_atual, quantidade);

    printf("\n--- Resultado de %s ---\n", nome);
    printf("Rentabilidade: %.2f%%\n", rentabilidade);
    if (lucro_prejuizo >= 0) {
        printf("Lucro: R$ %.2f\n", lucro_prejuizo);
    } else {
        printf("Prejuizo: R$ %.2f\n", -lucro_prejuizo);
    }
}

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void lerTexto(const char *mensagem, char destino[], int tamanho) {
    do {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0';
        if (destino[0] == '\0') {
            printf("Campo obrigatorio! Digite novamente.\n");
        }
    } while (destino[0] == '\0');
}

int lerQuantidadePositiva(void) {
    int valor;
    do {
        printf("Quantidade: ");
        if (scanf("%d", &valor) != 1) {
            valor = 0;
        }
        limparBuffer();
        if (valor <= 0) {
            printf("Valor invalido! Digite um inteiro maior que zero.\n");
        }
    } while (valor <= 0);
    return valor;
}

double lerPrecoPositivo(const char *mensagem) {
    double valor;
    do {
        printf("%s", mensagem);
        if (scanf("%lf", &valor) != 1) {
            valor = 0;
        }
        limparBuffer();
        if (valor <= 0) {
            printf("Valor invalido! Digite um numero maior que zero.\n");
        }
    } while (valor <= 0);
    return valor;
}

void cadastrarAtivo(char nome[], char categoria[], int *quantidade, double *precoCompra, double *precoAtual) {
    printf("\n--- Cadastro de ativo ---\n");

    lerTexto("Nome do ativo: ", nome, 100);
    lerTexto("Categoria (ex.: Renda Fixa, Acao, FII): ", categoria, 100);

    *quantidade  = lerQuantidadePositiva();
    *precoCompra = lerPrecoPositivo("Preco de compra: R$ ");
    *precoAtual  = lerPrecoPositivo("Preco atual: R$ ");

    printf("\nAtivo cadastrado com sucesso!\n");
}