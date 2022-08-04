#include<stdio.h>
#include<stdlib.h>

// Definición de la estructura nodo, con su lado izquierdo y derecho.
typedef struct nodo {
    int dataContainer;
    struct nodo *left;
    struct nodo *right;
};

void Insert_(int);
void Print_Before(struct nodo *data);
void Print_In(struct nodo *data);
void Print_After(struct nodo *data);
void Erase_(struct nodo *data);

struct nodo *root = NULL;

int main(){
	
    Insert_(64);
    Insert_(8);
	Insert_(112);
	
    printf("Mostrando antes: ");
    Print_Before(root);
    printf("\n\n");
    
    printf("Mostrando entre ellos: ");
    Print_in(root);
    printf("\n\n");
    
    printf("Mostrando despues: ");
    Print_after(root);
    Erase_(raiz);
    
    system("pause");
    return 0;
}
void Insert_(int Data){
	struct nodo *aux;
	aux = malloc(sizeof(struct nodo));
	aux->dataContainer = Data;
    aux->left = NULL;
    aux->right = NULL;
    
    if(root == NULL){
        root = aux;
    }else{
    	struct nodo *before, *dataHelper;
        before = NULL;
        dataHelper = root;
        while(dataHelper != NULL){
        	
            before = dataHelper;
            
        if(Data<dataHelper->dataContainer){
        	
            dataHelper = dataHelper->left;
            
        }else{
        	
            dataHelper = dataHelper->right;
            
        }
        
        if (Data < before->dataContainer){
        	
            before->left = aux;
            
        }else{
        	
        before->right = aux;
        
      	}
   	}
  }
}
 
void Print_Before(struct nodo *data){
    if(data != NULL){
        printf(" %i -",data->dataContainer);
        Print_Before(data->left);
        Print_Before(data->right);
    }
}
void Print_In(struct nodo *data){
    if (data != NULL){
        Print_in(data->left);
        printf(" %i -",data->left);
        Print_in(data->right);
    }
}
void Print_After(struct nodo *data){
    if(data != NULL){
        Print_After(data->left);
        Print_After(data->right);
        printf(" %i -",data->dataContainer);
    }
}
void Erase_(struct nodo *data){
	if(data != NULL){
        Erase_(data->left);
        borrar(data->right);
        free(data);
    }
}


