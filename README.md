
# Opus Finance

Sistema de cadastro e análise de ativos financeiros desenvolvido em linguagem C como projeto acadêmico.

## Sobre o projeto

O Opus Finance é um programa de terminal que permite cadastrar um ativo financeiro e analisar seu desempenho com base no preço de compra, no preço atual e na quantidade informada pelo usuário.

O projeto tem como objetivo aplicar conceitos fundamentais de programação em C por meio de um sistema interativo.

## Funcionalidades

- **Cadastro de ativos:** registra nome, categoria, quantidade, preço de compra e preço atual.
- **Visualização da rentabilidade:** calcula a variação percentual do preço do ativo.
- **Cálculo de lucro ou prejuízo:** determina o resultado financeiro considerando a quantidade cadastrada.
- **Classificação de risco:** apresenta um alerta quando a rentabilidade é inferior a 10%.
- **Menu interativo:** permite selecionar as funcionalidades ou encerrar o programa.
- **Validação de dados:** verifica campos obrigatórios e valores positivos durante o cadastro.

## Tecnologias utilizadas

- Linguagem C
- Embarcadero Dev-C++
- Compilador GCC (TDM-GCC)

## Estrutura do projeto

| Arquivo | Descrição |
|---|---|
| `main.c` | Ponto de entrada do programa. |
| `funcoes.c` | Implementação do menu e das funções do sistema. |
| `funcoes.h` | Declarações das funções utilizadas no projeto. |
| `README.md` | Documentação do projeto. |

> Os nomes dos arquivos podem variar conforme a organização utilizada no Dev-C++.

## Como executar

1. Clone ou baixe este repositório.
2. Abra o projeto no Embarcadero Dev-C++.
3. Verifique se os arquivos `.c` e `.h` estão incluídos corretamente no projeto.
4. Compile o programa utilizando a opção **Execute → Rebuild All**.
5. Execute o programa e utilize o menu apresentado no terminal.

## Exemplo de utilização

Considere o cadastro de um ativo com os seguintes dados:

- **Nome:** PETR4
- **Categoria:** Ação
- **Quantidade:** 10
- **Preço de compra:** R$ 30,00
- **Preço atual:** R$ 36,00

### Resultado esperado

- **Rentabilidade:** 20,00%
- **Lucro total:** R$ 60,00
- **Classificação:** rentabilidade dentro do esperado.

## Fórmulas utilizadas

### Rentabilidade percentual

A rentabilidade é calculada pela diferença entre o preço atual e o preço de compra, dividida pelo preço de compra e multiplicada por 100.

```text
Rentabilidade = ((Preço atual - Preço de compra) / Preço de compra) * 100
```

### Lucro ou prejuízo

O resultado financeiro considera a diferença entre os preços multiplicada pela quantidade de unidades.

```text
Resultado = (Preço atual - Preço de compra) * Quantidade
```

- Resultado positivo: lucro.
- Resultado negativo: prejuízo.
- Resultado igual a zero: não houve lucro nem prejuízo.

## Conceitos de programação aplicados

- Variáveis e tipos de dados.
- Funções e parâmetros.
- Ponteiros.
- Estruturas condicionais (`if`, `else` e `switch`).
- Laços de repetição (`do...while`).
- Entrada e saída de dados (`scanf`, `fgets` e `printf`).
- Validação de entradas.
- Organização do código em arquivos `.c` e `.h`.

## Limitações atuais

- O sistema permite cadastrar um ativo por vez.
- Os dados não são armazenados permanentemente.
- A classificação utiliza um limite simplificado de rentabilidade inferior a 10%.
- Os cálculos não consideram taxas, impostos, dividendos ou outros custos.
- A classificação apresentada não representa uma avaliação completa do risco de investimento.

## Objetivo acadêmico

O Opus Finance foi desenvolvido para consolidar conhecimentos iniciais de programação em C por meio da criação de um sistema funcional de cadastro e análise de ativos financeiros.

---

**Opus Finance** — Projeto acadêmico desenvolvido em linguagem C.
