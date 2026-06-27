# 🌳 Sistema de Cadastro de Alunos - Árvore Binária de Busca

> Atividade Avaliativa 3 - Estrutura de Dados 2026-01  
> Universidade Tecnológica Federal do Paraná (UTFPR)  
> Professor: Clayton Kossoski

---

## 📋 Descrição

Sistema de cadastro de alunos implementado em **C++** utilizando uma **Árvore Binária de Busca (ABB)** como estrutura de dados principal.

O sistema permite inserir, buscar e listar alunos em ordem alfabética, além de exibir informações gerais sobre a árvore.

---

## 🏗️ Estrutura de Dados Escolhida

Foi utilizada a **Árvore Binária de Busca (ABB)**, por ser a estrutura mais fundamental entre as opções disponíveis (ABB, AVL e Rubro-Negra), oferecendo boa legibilidade e clareza na implementação dos conceitos de árvores.

### Como funciona a ABB

- Cada nó armazena os dados de um aluno e possui dois ponteiros: filho **esquerdo** e filho **direito**.
- A **chave de ordenação** é o **nome do aluno** (comparação lexicográfica).
- Nomes **menores** são inseridos à **esquerda**; nomes **maiores** à **direita**.
- Isso garante que um percurso **in-order** (esquerda → raiz → direita) produza os alunos em **ordem alfabética**.

```
         João Ferreira
        /           \
  Alice Silva     Manuella Reginato
       \
    Lauren Marçulo
```

---

## ⚙️ Funcionalidades

| Funcionalidade | Descrição |
|---|---|
| Inserir aluno | Cadastra um novo aluno na árvore pelo nome |
| Buscar aluno | Localiza um aluno pelo nome completo |
| Listar em ordem alfabética | Percurso in-order na árvore |
| Informações da árvore | Exibe total de alunos e altura da árvore |

---

## 🗂️ Atributos do Aluno

Cada aluno possui:
- **Matrícula** (inteiro)
- **Nome completo** (string — chave da árvore)
- **Curso** (string)

---

## ▶️ Como compilar e executar

### Pré-requisitos
- Compilador C++ (g++)

### Compilar
```bash
g++ -o arvore_alunos arvore_alunos.cpp
```

### Executar
```bash
./arvore_alunos
```

---

## 💻 Exemplo de uso

```
===== SISTEMA DE CADASTRO DE ALUNOS =====
1. Inserir aluno
2. Buscar aluno
3. Listar alunos em ordem alfabetica
4. Informacoes da arvore
0. Sair

--- Alunos em ordem alfabetica ---
Alice Silva    - Matricula: 102 - Curso: Engenharia Computação
João Ferreira  - Matricula: 101 - Curso: Engenharia de Software
Lauren Marçulo - Matricula: 104 - Curso: ADS
Manuella Reg.  - Matricula: 103 - Curso: ADS

--- Informacoes da arvore ---
Total de alunos: 4
Altura da arvore: 3
```

---

## 📁 Estrutura do repositório

```
📦 arvore-alunos
 ┣ 📄 LICENSE             ← licença MIT
 ┣ 📄 arvore_alunos.cpp   ← código-fonte principal
 ┗ 📄 README.md           ← este arquivo

```

---

## 📄 Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

---

## 👥 Integrantes

- Lauren Marçulo
- Manuella Vieira Reginato
