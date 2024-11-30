# Trabalho de Algoritmos e Estruturas de Dados 1

## Estrutura de pastas

Nem toda a estrutura foi implementada ainda, mas a intenção é que ao fim do trabalho o projeto se pareça com isto:

- `bin/`: Arquivos binários resultantes da compilação do projeto.
- `include/`: Contém os arquivos de cabeçalho do projeto.
  - `include/data-structures/`
  - `include/algorithms/`
- `src/`: Contém os arquivos .c que lidam com a lógica do projeto.
  - `src/data-structures/`
  - `src/algorithms/`
  - `src/main.c`
- `test/`: Arquivos de testes automatizados, caso o nosso QA (Antônio) faça os testes bem feitos.
- `Makefile`: Arquivo com alguns scripts pra automatizar a compilação e execução do código.
- `.gitignore`: Espero não ter que explicar pra marmanjo o que é um gitignore.

## Instalação

1. **Clonar o repositório**

```bash
git clone https://github.com/AdrianoCLeao/TrabalhoAED1.git
```

2. **Compilar o código**
   
O arquivo Makefile executará diversos comandos para compilar o código e deixar o executável na pasta bin.

```bash
make
```

3. **Rodar o código**

Agora, ainda usando o Makefile, vamos rodar o executavél criado na compilação

```bash
make run
```
