#include <stdlib.h>
#include <stdio.h>

//  struttura del nodo dell'albero binario
struct Node
{
    int key;
    struct Node *left, *right, *parent;
};

//  creare un nuovo nodo
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

//  inserimento di un nodo nell'albero
struct Node* insert(struct Node* node, int key){
    if (node == NULL)
        return newNode(key);
    if (key < node->key) {
        struct Node* leftChild = insert(node->left, key);
        node->left = leftChild;
        leftChild->parent = node;
    } else if (key > node->key){
        struct Node* rightChild = insert(node->right, key);
        node->right = rightChild;
        rightChild->parent = node;
    }
    return node;
}

//  Funzione di ricerca di un nodo nell'albero
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

//  trova il nodo con il valore minimo
struct Node* minimum(struct Node* node){
    while(node && node->left != NULL)
        node = node-> left;
    return node;
}

//  trova il nodo con il valore massimo
struct Node* maximum(struct Node* node){
    while(node && node->right != NULL)
        node = node->right;
    return node;
}

//  trova il successore di un nodo
struct Node* successor(struct Node* node){
    if (node->right != NULL)
        return minimum(node->right);
    
    struct Node* p = node->parent;
    while (p != NULL && node == p->right){
        node = p;
        p = p->parent;
    }
    return p;
}

//  trova il predecessore di un nodo
struct Node* predecessor(struct Node* node){
    if (node->left != NULL)
        return maximum(node->left);
    struct Node* p = node->parent;
    while (p != NULL && node == p->left){
        node = p;
        p = p->parent;
    }
    return p;
}

//  Cancellazione di un nodo dall'albero
struct Node* deleteNode(struct Node* root, int key){
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minimum(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

//  stampa in ordine l'albero
void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main (){
    int n, ele;

    printf("inserire la lunghezza dell'albero: ");
    scanf("%d",&n);

    //  Alloca dinamicamente l'array in base alla dimensione inserita
    struct Node* root = NULL;

    printf("Inserire gli elementi:\n");
    for (int i=0;i<n;i++){   
        scanf("%d",&ele);
        root = insert(root,ele);
    }

    printf("Albero: ");
    inorder(root);
    printf("\n");

    printf("Minimo: %d\n", minimum(root)->key);
    printf("massimo: %d\n", maximum(root)->key);

    printf("inserire l'elemento da ricercare: ");
    scanf("%d", &ele);
    struct Node* node = search(root, ele);
    if (node != NULL) {
        struct Node* suc = successor(node);
        struct Node* pred = predecessor(node);
        printf("successore di %d: %d\n", node->key, suc ? suc->key : -1);
        printf("predecessore di %d: %d\n", node->key, pred ? pred->key : -1);
    }

    printf("inserire l'elemento da eliminare: ");
    scanf("%d", &ele);
    root = deleteNode(root, ele);
    printf("Albero dopo la eliminazione di un elemento: ");
    inorder(root);
    printf("\n");

    return 0;
}