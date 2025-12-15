#include <stdio.h>
#include <malloc.h>

struct nod {
    struct nod *left;
    char data;
    struct nod *right;
};

typedef struct nod NOD;
typedef NOD POKOK;

NOD *NodBaru(char item) {
    NOD *n;
    n = (NOD*) malloc(sizeof(NOD));
    if(n != NULL){
        n->data = item;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void BinaPokok(POKOK **T){
    *T = NULL;
}

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

BOOL PokokKosong(POKOK *T){
    if (T == NULL)
        return TRUE;
    else
        return FALSE;
}

void TambahNod(NOD **p, char item){
    NOD *n;
    n = NodBaru(item);
    *p = n;
}

/* PREORDER */
void preOrder(POKOK *T){
    if(!PokokKosong(T)){
        printf("%c ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

/* INORDER */
void inOrder(POKOK *T){
    if(!PokokKosong(T)){
        inOrder(T->left);
        printf("%c ", T->data);
        inOrder(T->right);
    }
}

/* POSTORDER */
void postOrder(POKOK *T){
    if(!PokokKosong(T)){
        postOrder(T->left);
        postOrder(T->right);
        printf("%c ", T->data);
    }
}

int main()
{
    POKOK *kelapa;
    char buah;

    BinaPokok(&kelapa);

    TambahNod(&kelapa, buah = 'M');
    TambahNod(&kelapa->left, buah = 'E');
    TambahNod(&kelapa->left->right, buah = 'I');
    TambahNod(&kelapa->right, buah = 'L');
    TambahNod(&kelapa->right->right, buah = 'O');
    TambahNod(&kelapa->right->left, buah = 'D');

    printf("Tampilan secara PreOrder : ");
    preOrder(kelapa);

    printf("\nTampilan secara InOrder  : ");
    inOrder(kelapa);

    printf("\nTampilan secara PostOrder: ");
    postOrder(kelapa);

    printf("\n\n");
    return 0;
}
