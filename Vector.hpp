/**
 * \file Vector.hpp
 * \brief Implementaci&oacute;n de un vector algebraico.
 * \author Amado Rosas Archiveque
 * \date 2013-01-31
*/

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <cmath>


class Vector { 
    /**
     * \brief Operador de multiplicaci&oacute;n de escalar por vector.
     * \param scalar Escalar por el que se multiplicar&aacute; el vector.
     * \param v Vector que se multiplicar&aacute; por el escalar.
     * \return Vector resultante de la multiplicaci&oacute;n.
     * 
     * \code
     * Vector v(3),w(3);
     * double scalar = 2;
     * w = 2 * v;
     * cout << w;
     * \endcode
     * */

    friend Vector operator*(double scalar, const Vector &v); // Producto escalar de dos vectores

    /**
     * \brief Operador de inserci&oacute;n de flujo.
     * \param out Flujo de salida.
     * \param v Vector que se imprimir&aacute; en el flujo de salida.
     * \return Flujo de salida.
     * 
     * \code
     * cout << v;
     * \endcode
     */

    friend std::ostream& operator<<(std::ostream &out, const Vector &v); // Imprimir el vector en la salida estándar

    /**
     * \brief Operador de extracci&oacute;n de flujo.
     * \param in Flujo de entrada.
     * \param v Vector que se leer&aacute; del flujo de entrada.
     * \return Flujo de entrada.
     * 
     * \code
     * cout >> v;
     * \endcode
     */

    friend std::istream& operator>>(std::istream &in, Vector &v); // Ingresar valores al vector desde la entrada estándar

public: // accessible to all
    
    /** 
     * \brief Constructor de la clase Vector.
     * \param dim Dimensi&oacute;n del vector.
     * \return Vector de dimensi&oacute;n dim.
     * \throw std::string si dim es menor que 1.
     * \throw std::bad_alloc si no es posible construir el vector.
     *
     * \code
     * Vector v(3);
     * \endcode
     */
    
    explicit Vector(int dim = 3); // Constructor con dimensión especificada

    /**
     * \brief Constructor de copia.
     * \param v Vector que se copiar&aacute;.
     * \return Vector copiado.
     * \throw std::bad_alloc si no es posible construir el vector.
     */

    Vector(const Vector &v); // Constructor de copia

    /**
     * \brief Operador de asignaci&oacute;n.
     * \param v Vector que se asignar&aacute;.
     * \return Vector asignado.
     * \throw std::string si no es posible asignar el vector.
     * 
     * \code
     * Vector v(3),w(3);
     * cin >> v;
     * v = w;
     * cout << w;
     * \endcode
     */

    Vector & operator=(const Vector &v); // Operador de asignación

    /**
     * \brief Destructor de la clase Vector.
     * 
     * \code
     * Vector v(3);
     * cin >> v;
     * cout << v;
     * ~v;
     * cout << v;
     * \endcode
     */

    ~Vector(); // Destructor

    /**
     * \brief Obtener la dimensi&oacute;n del vector.
     * \return Dimensi&oacute;n del vector.
     * 
     * \code
     * Vector v(3);
     * v.GetDim();
     * cout << "La dimension es: " << dim;
     * \endcode
     */
    int GetDim() const; // Obtener la dimensión del vector
    
    /**
     * \brief Ingresar valores al vector desde la entrada explicita.
     * \return void
     * 
     * \code
     * Vector v(3);
     * v.InputVector();
     * cout << v;
     * \endcode
     */

    void InputVector(); // Ingresar valores al vector desde la entrada estándar
    
    /**
     * \brief Imprimir el vector en la salida explicita.
     * \return void
     * 
     * \code
     * Vector v(3);
     * cin >> v;
     * v.PrintVector();
     * \endcode
     */
    void PrintVector() const; // Imprimir el vector en la salida estándar
    
    /**
     * \brief Sumar dos vectores y devolver el resultado.
     * \param v Vector que se sumar&aacute; al vector que llama al m&eacute;todo.
     * \return Vector resultante de la suma.
     * 
     * \code
     * Vector v(3),w(3),sum;
     * cin >> v;
     * cin >> w;
     * sum = v.SumVector(w);
     * cout << sum;
     * \endcode
     */

    Vector SubstractVector(const Vector &v) const; // Restar dos vectores y devolver el resultado
    
    /**
     * \brief Norma de un vector.
     * \return Norma del vector.
     * 
     * \code
     * Vector v(3),norm;
     * cin >> v;
     * norm = v.NormVector();
     * cout << norm;
     * \endcode
     */
    double NormVector() const; // Norma de un vector
    
    /**
     * \brief Sumar dos vectores y devolver el resultado.
     * \param v Vector que se sumar&aacute; al vector que llama al m&eacute;todo.
     * \return Vector resultante de la suma.
     * 
     * \code
     * Vector v(3),w(3),sum;
     * cin >> v;
     * cin >> w;
     * sum = v + w;
     * cout << sum;
     * \endcode
     */
    Vector operator+(const Vector &v) const; // Sumar dos vectores y devolver el resultado

    /**
     * \brief Multiplicar un vector por un escalar.
     * \param scalar Escalar por el que se multiplicar&aacute; el vector.
     * \return Vector resultante de la multiplicaci&oacute;n.
     * 
     * \code
     * Vector v(3),w(3);
     * double scalar = 2;
     * w = v * scalar;
     * cout << w;
     * \endcode
     */

    Vector operator*(double scalar) const; // Producto escalar de dos vectores
    
    /**
     * \brief Restar dos vectores y devolver el resultado.
     * \param v Vector que se restar&aacute; al vector que llama al m&eacute;todo.
     * \return Vector resultante de la resta.
     * 
     * \code
     * Vector v(3),w(3),sub;
     * cin >> v;
     * cin >> w;
     * sub = v - w;
     * cout << sub;
     * \endcode
     */

    Vector operator-(const Vector &v) const; // Restar dos vectores y devolver el resultado

    /**
     * \brief Producto punto de dos vectores.
     * \param v Vector que se multiplicar&aacute; al vector que llama al m&eacute;todo.
     * \return Escalar resultante del producto punto.
     * 
     * \code
     * Vector v(3),w(3);
     * double dot;
     * cin >> v;
     * cin >> w;
     * dot = v * w;
     * cout << dot;
     * \endcode
     */

    Vector operator*(const Vector &v) const; // Producto punto de dos vectores

protected: // accessible to derived classes and this class
private: // accessible only within this class
    
    /**
     * \brief Establecer la dimensi&oacute;n del vector.
     * \param dim Dimensi&oacute;n del vector.
     * \return void
     * \throw std::string si dim es menor que 1.
     * 
     * \code
     * Vector v(2);
     * double dim = 3;
     * v.SetDimension(dim);
     * cin >> v;
     * cout << v;
     * \endcode
     */

    void SetDimension(int dim); // Establecer la dimensión del vector

    // Datos miembro

    /**
     * \brief Dimensi&oacute;n del vector.
     */

    int dim;

    /**
     * \brief Componentes del vector.
     */

    double *component;
};

#endif // VECTOR_HPP_INCLUDED
