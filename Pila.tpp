#include "Pila.hpp"

/**
 * \file Pila.tpp
 * \brief Implementación de la clase Pila
 * \author Omar Pacheco & Amado Rosas
 * \date Febrero 2024
 * 
*/

/**
 * \brief Constructor de la clase Pila
 * \details Inicializa la pila con una capacidad predeterminada
 * 
 * \param cap Capacidad de la pila
*/
template<typename T>
Pila<T>::Pila(unsigned int cap /* = 15*/){
  this->cap = cap;
  tope = -1;
  elementos = new T [cap];
}

/**
 * \brief Destructor de la clase Pila
 * \details Libera la memoria que se reservó para los elementos de la pila
 * 
*/
template<typename T>
Pila<T>::~Pila(){
  delete [] elementos;
}

/**
 * \brief Constructor de copia de la clase Pila
 * \details Copia los elementos de una pila a otra
 * 
 * \param p Pila a copiar
*/
template<typename T>
Pila<T>::Pila(const Pila &p){
  this->cap = p.cap;
  tope = p.tope;
  elementos = new T [p.cap];
  for (int i = 0; i < p.tope+1; ++i){
    elementos[i] = p.elementos[i];
  }
}

/**
 * \brief Operador de asignación de la clase Pila
 * \details Asigna los elementos de una pila a otra
 * 
 * \param p Pila a asignar
*/
template<typename T>
void Pila<T>::operator=(const Pila &p){
  this->cap = p.cap;
  tope = p.tope;
  elementos = new T [p.cap];
  for (int i = 0; i < p.cap; ++i){
    elementos[i] = p.elementos[i];
  }
}

/**
 * \brief Agrega un elemento a la pila
 * 
 * \param valor Valor a agregar
*/
template<typename T>
void Pila<T>::Agregar(T valor){
  if (EstaLlena()) Redimensionar();
  elementos[++tope] = valor;
}

/**
 * \brief Elimina un elemento de la pila
 * \details Si la pila está vacía, lanza una excepción
 * \throw "La pila esta vacía, no se pueden eliminar mas elementos"
 * 
*/
template<typename T>
void Pila<T>::Eliminar(){
  if (EstaVacia()) throw "La pila esta vacía, no se pueden eliminar mas elementos";
  --tope;
}

/**
 * \brief Obtiene el elemento del tope de la pila
 * \details El tope de la pila es el último elemento que se agregó
 * \throw "La pila esta vacía, no se puede obtener el tope"
 * 
 * \return Elemento del tope de la pila
*/
template<typename T>
T Pila<T>::ObtenerTope() const{
  return elementos[tope];
}

/**
 * \brief Elimina todos los elementos de la pila
 * 
*/
template<typename T>
void Pila<T>::Vaciar(){
  tope = -1;
}

/**
 * \brief Obtiene el tamaño de la pila
 * \details El tamaño de la pila es el número de elementos que contiene
 * 
 * \return Tamaño de la pila
*/
template<typename T>
int Pila<T>::ObtenerTam() const{
  return tope+1;
}

/**
 * \brief Obtiene la capacidad de la pila
 * \details La capacidad de la pila es el número máximo de elementos que puede contener
 * 
 * \return Capacidad de la pila
*/
template<typename T>
unsigned int Pila<T>::ObtenerCap() const{
  return cap;
}

/**
 * \brief Verifica si la pila está vacía
 * \details La pila está vacía si no contiene elementos
 * 
 * \return true si la pila está vacía, false en otro caso
*/
template<typename T>
bool Pila<T>::EstaVacia() const{
  if (tope == -1) return true;
  else return false;
}

/**
 * \brief Verifica si la pila está llena
 * \details La pila está llena si contiene el número máximo de elementos que puede contener
 * 
 * \return true si la pila está llena, false en otro caso
*/
template<typename T>
bool Pila<T>::EstaLlena() const{
  if (cap == ObtenerTam()) return true;
  else return false;
}

/**
 * \brief Imprime los elementos de la pila
 * 
*/
template<typename T>
void Pila<T>::Imprimir() const{
  std::cout << "( ";
  for (int i = 0; i <= tope; ++i){
    std::cout << elementos[i] << ", ";
  }
  std::cout << "\b\b )";
}

/**
 * \brief Redimensiona la pila
 * \details Duplica la capacidad de la pila
 * 
*/
template<typename T>
void Pila<T>::Redimensionar(){
  cap = 2 * cap;
  T* arreglo = elementos;
  elementos = new T [cap];
  for (int i = 0; i < cap; ++i){
    elementos[i] = arreglo[i];
  }
  delete [] arreglo;
}

