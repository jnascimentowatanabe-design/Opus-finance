
#ifndef FUNCOES_H
#define FUNCOES_H


void menu(void);
void classificarRisco(float rentabilidade);
int lerQuantidadePositiva(void);
double lerPrecoPositivo(const char *mensagem);
void cadastrarAtivo(char nome[], char categoria[], int *quantidade, double *precoCompra, double *precoAtual);
double calcular_rentabilidade(double preco_compra, double preco_atual);
double calcular_lucro_prejuizo(double preco_compra, double preco_atual, double quantidade);
void exibir_resultado(char nome[], double quantidade, double preco_compra, double preco_atual);

#endif