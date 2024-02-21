#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
#include <iostream>


/**
 * \class Pila
 * \brief Clase que representa una pila
 * \tparam T Tipo de dato que se almacenará en la pila
 *
 */
template<typename T>

class Pila{


public:
  Pila(unsigned int cap = 15); // Constructor
  ~Pila(); // Destructor
  Pila(const Pila &p); // Constructor de copia
  void operator=(const Pila &p); // Operador de asignación
  void Agregar(T valor); // Agrega un elemento a la pila
  void Eliminar(); // Elimina un elemento de la pila
  T ObtenerTope() const; // Obtiene el elemento del tope de la pila
  void Vaciar(); // Elimina todos los elementos de la pila
  int ObtenerTam() const; // Obtiene el tamaño de la pila
  unsigned int ObtenerCap() const; // Obtiene la capacidad de la pila
  bool EstaVacia() const; // Verifica si la pila está vacía
  void Imprimir() const; // Imprime los elementos de la pila

private:
  int tope; // Tope de la pila
  int cap; // Capacidad de la pila
  T* elementos; // Elementos de la pila
  bool EstaLlena() const; // Verifica si la pila está llena
  void Redimensionar(); // Redimensiona la pila

};

#include "Pila.tpp"

#endif // !PILA_HPP_INCLUDED
