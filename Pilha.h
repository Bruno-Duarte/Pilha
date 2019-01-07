//***********************************************************
// Autor: F. Bruno Duarte
// Em: 07/01/2019
//***********************************************************

#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <assert.h>

// definição estrutura NoPilha
template<class Type>
struct NoPilha {
	Type info;
	NoPilha<Type> *prox;
};

template<class Type>
class Pilha {
public:

	Pilha(){ topo = NULL; }
	
	void push(const Type&);
	void pop();
	Type top() const;
	bool isEmpty() const;
	const int size();
	void print();
	bool search(const Type&);
	void clear();
	
	~Pilha(){ clear(); }
private:
	NoPilha<Type> *topo;
};

// insere um elemento na pilha
template<class Type>
void Pilha<Type>::push(const Type& i){
	NoPilha<Type> *novo = new NoPilha<Type>();

	novo->info = i;
	novo->prox = topo;
	topo = novo;
}

// remove elemento da pilha
template<class Type>
void Pilha<Type>::pop(){
	NoPilha<Type> *temp;

	if(topo != NULL){
		temp = topo;
		topo = topo->prox;
		delete temp;
	} else {
		std::cout << "Impossível remover de uma pilha vazia" 
			<< std::endl;	
	}
}

// retorna elemento do topoo da pilha
template<class Type>
Type Pilha<Type>::top() const{
	assert(topo != NULL);
	return topo->info;
}

// verifica se a pilha está vazia
template<class Type>
bool Pilha<Type>::isEmpty() const{
	return topo == NULL; 
}

// retorna o tamanho da pilha
template<class Type>
const int Pilha<Type>::size(){
	Pilha<Type> temp;
	int cont = 0;

	while(!isEmpty()){
		temp.push(top());
		pop();
		cont += 1;
	}

	while(!(temp.isEmpty())){
		push(temp.top());
		temp.pop();
	}

	return cont;
}

// imprime a lista
template<class Type>
void Pilha<Type>::print(){
	Pilha<Type> temp;

	while(!isEmpty()){
		temp.push(top());
		pop();
	}

	while(!temp.isEmpty()){
		push(temp.top());
		std::cout << temp.top() << " ";
		temp.pop();
	}

	std::cout << std::endl;
}

// libera a pilha
template<class Type>
void Pilha<Type>::clear(){
	NoPilha<Type> *temp;

	while(!isEmpty()){
		temp = topo;
		topo = topo->prox;
		delete temp;
	}
}

// procura elemento na pilha
template<class Type>
bool Pilha<Type>::search(const Type& i){

	Pilha<Type> temp;
	bool resultado = false;

	while(!isEmpty()){
		if(top() == i)
			resultado = true;
		temp.push(top());
		pop();
	}

	while(temp.isEmpty()){
		push(temp.top());
		temp.pop();
	}
	return resultado;
}

#endif
