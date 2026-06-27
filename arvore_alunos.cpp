// ============================================================
// ATIVIDADE AVALIATIVA 3 - Estrutura de Dados 2026-01
// Alunas: Lauren Marçulo e Manuella Vieira Reginato
// RA:     2767090          2767120
// Sistema de Cadastro de Alunos com Árvore Binária de Busca (ABB)
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// ESTRUTURA DO ALUNO
// Representa os dados de um aluno cadastrado no sistema
// ============================================================
struct Aluno {
    int matricula;
    string nome;
    string curso;
};

// ============================================================
// ESTRUTURA DO NÓ DA ÁRVORE
// Cada nó guarda um aluno e aponta para os filhos esquerdo e direito
// ============================================================
struct No {
    Aluno aluno;
    No* esquerdo;  // filho esquerdo (nome menor)
    No* direito;   // filho direito (nome maior)
};

// ============================================================
// FUNÇÃO: criarNo
// Cria e retorna um novo nó com os dados do aluno
// ============================================================
No* criarNo(int matricula, string nome, string curso) {
    No* novoNo = new No();          // aloca memória para o nó
    novoNo->aluno.matricula = matricula;
    novoNo->aluno.nome = nome;
    novoNo->aluno.curso = curso;
    novoNo->esquerdo = nullptr;     // começa sem filhos
    novoNo->direito = nullptr;
    return novoNo;
}

// ============================================================
// FUNÇÃO: inserir
// Insere um novo aluno na árvore usando o nome como chave.
// Nomes menores (alfabeticamente) vão para a esquerda,
// nomes maiores vão para a direita.
// ============================================================
No* inserir(No* raiz, int matricula, string nome, string curso) {
    // Caso base: encontrou posição vazia, insere aqui
    if (raiz == nullptr) {
        return criarNo(matricula, nome, curso);
    }

    // Compara o nome a inserir com o nome do nó atual
    if (nome < raiz->aluno.nome) {
        // Nome é menor: vai para a subárvore esquerda
        raiz->esquerdo = inserir(raiz->esquerdo, matricula, nome, curso);
    } else if (nome > raiz->aluno.nome) {
        // Nome é maior: vai para a subárvore direita
        raiz->direito = inserir(raiz->direito, matricula, nome, curso);
    } else {
        // Nome já existe na árvore: avisa e não insere duplicata
        cout << "Aluno com o nome '" << nome << "' ja cadastrado!" << endl;
    }

    return raiz; // retorna a raiz (sem alteração neste nível)
}

// ============================================================
// FUNÇÃO: buscar
// Busca um aluno pelo nome na árvore.
// Retorna o ponteiro para o nó encontrado, ou nullptr se não existe.
// ============================================================
No* buscar(No* raiz, string nome) {
    // Caso base: árvore vazia ou nome não encontrado
    if (raiz == nullptr) {
        return nullptr;
    }

    // Nome encontrado no nó atual
    if (nome == raiz->aluno.nome) {
        return raiz;
    }

    // Nome é menor: busca na subárvore esquerda
    if (nome < raiz->aluno.nome) {
        return buscar(raiz->esquerdo, nome);
    }

    // Nome é maior: busca na subárvore direita
    return buscar(raiz->direito, nome);
}

// ============================================================
// FUNÇÃO: exibirEmOrdem
// Percurso "in-order" (esquerda → raiz → direita).
// Visitar em ordem esquerda-raiz-direita garante que os alunos
// sejam exibidos em ordem alfabética pelo nome.
// ============================================================
void exibirEmOrdem(No* raiz) {
    if (raiz == nullptr) return; // condição de parada

    exibirEmOrdem(raiz->esquerdo);  // visita subárvore esquerda primeiro
    // Exibe os dados do aluno no nó atual
    cout << raiz->aluno.nome
         << " - Matricula: " << raiz->aluno.matricula
         << " - Curso: " << raiz->aluno.curso << endl;
    exibirEmOrdem(raiz->direito);   // depois visita subárvore direita
}

// ============================================================
// FUNÇÃO: calcularAltura
// Calcula a altura da árvore recursivamente.
// Altura = número de níveis da árvore (raiz até a folha mais distante)
// ============================================================
int calcularAltura(No* raiz) {
    if (raiz == nullptr) return 0; // árvore vazia tem altura 0

    int alturaEsq = calcularAltura(raiz->esquerdo); // altura subárvore esq
    int alturaDir = calcularAltura(raiz->direito);  // altura subárvore dir

    // A altura do nó atual é 1 + a maior das subárvores
    if (alturaEsq > alturaDir)
        return 1 + alturaEsq;
    else
        return 1 + alturaDir;
}

// ============================================================
// FUNÇÃO: contarAlunos
// Conta o total de nós (alunos) na árvore recursivamente.
// ============================================================
int contarAlunos(No* raiz) {
    if (raiz == nullptr) return 0;
    // Conta o nó atual + todos da esquerda + todos da direita
    return 1 + contarAlunos(raiz->esquerdo) + contarAlunos(raiz->direito);
}

// ============================================================
// FUNÇÃO: exibirMenu
// Exibe o menu de opções do sistema
// ============================================================
void exibirMenu() {
    cout << "\n===== SISTEMA DE CADASTRO DE ALUNOS =====" << endl;
    cout << "1. Inserir aluno" << endl;
    cout << "2. Buscar aluno" << endl;
    cout << "3. Listar alunos em ordem alfabetica" << endl;
    cout << "4. Informacoes da arvore" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha: ";
}

// ============================================================
// FUNÇÃO PRINCIPAL
// ============================================================
int main() {
    No* raiz = nullptr; // árvore começa vazia
    int opcao;

    // Insere os alunos do exemplo da atividade para demonstração
    raiz = inserir(raiz, 101, "João Ferreira",    "Engenharia de Software");
    raiz = inserir(raiz, 102, "Alice Silva", "Engenharia Computação");
    raiz = inserir(raiz, 103, "Manuella Reginato", "ADS");
    raiz = inserir(raiz, 104, "Lauren Marçulo",   "ADS");

    cout << "Alunos de exemplo carregados com sucesso!" << endl;

    // Loop principal do menu
    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore(); // limpa o buffer do teclado após ler o número

        if (opcao == 1) {
            // --- INSERIR ALUNO ---
            int mat;
            string nome, curso;
            cout << "Matricula: ";
            cin >> mat;
            cin.ignore();
            cout << "Nome completo: ";
            getline(cin, nome);
            cout << "Curso: ";
            getline(cin, curso);
            raiz = inserir(raiz, mat, nome, curso);
            cout << "Aluno inserido com sucesso!" << endl;

        } else if (opcao == 2) {
            // --- BUSCAR ALUNO ---
            string nome;
            cout << "Digite o nome do aluno: ";
            getline(cin, nome);
            No* encontrado = buscar(raiz, nome);
            if (encontrado != nullptr) {
                cout << "Aluno encontrado:" << endl;
                cout << "  Nome:      " << encontrado->aluno.nome << endl;
                cout << "  Matricula: " << encontrado->aluno.matricula << endl;
                cout << "  Curso:     " << encontrado->aluno.curso << endl;
            } else {
                cout << "Aluno nao encontrado." << endl;
            }

        } else if (opcao == 3) {
            // --- LISTAR EM ORDEM ALFABÉTICA ---
            cout << "\n--- Alunos em ordem alfabetica ---" << endl;
            exibirEmOrdem(raiz);

        } else if (opcao == 4) {
            // --- INFORMAÇÕES DA ÁRVORE ---
            cout << "\n--- Informacoes da arvore ---" << endl;
            cout << "Total de alunos: " << contarAlunos(raiz) << endl;
            cout << "Altura da arvore: " << calcularAltura(raiz) << endl;

        } else if (opcao != 0) {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    cout << "Encerrando o sistema. Ate logo!" << endl;
    return 0;
}
