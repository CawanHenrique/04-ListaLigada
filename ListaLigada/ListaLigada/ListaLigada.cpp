#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar()
{
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos()
{
    int nElementos = 0;
    NO* aux = primeiro;

    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }

    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }

    cout << "Elementos: \n";
    NO* aux = primeiro;

    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento()
{
    int valor;
    cout << "Digite o elemento: ";
    cin >> valor;

    // 🔴 TAREFA 1: impedir duplicados
    if (posicaoElemento(valor) != NULL) {
        cout << "Elemento ja existe!" << endl;
        return;
    }

    // aloca memoria
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;

    novo->valor = valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
    }
    else {
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    cout << "Elemento inserido com sucesso!" << endl;
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
        return;
    }

    int valor;
    cout << "Digite o valor que deseja excluir: ";
    cin >> valor;

    // 🔴 verifica se existe (usando função exigida)
    if (posicaoElemento(valor) == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
        return;
    }

    NO* atual = primeiro;
    NO* anterior = NULL;

    // Caso A: primeiro elemento
    if (atual->valor == valor) {
        primeiro = atual->prox;
        free(atual);
        cout << "Elemento removido com sucesso!" << endl;
        return;
    }

    // Caso B: meio ou fim
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = atual->prox;
    free(atual);

    cout << "Elemento removido com sucesso!" << endl;
}

void buscarElemento()
{
    int valor;
    cout << "Digite o valor que deseja buscar: ";
    cin >> valor;

    // 🔴 TAREFA 2: usar função e mensagens corretas
    if (posicaoElemento(valor) != NULL) {
        cout << "ENCONTRADO" << endl;
    }
    else {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
    }
}

// retorna ponteiro ou NULL
NO* posicaoElemento(int numero)
{
    NO* aux = primeiro;

    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}