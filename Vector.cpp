#include "Vector.hpp"

Vector::Vector(int dim /* = 3*/) { // Constructor con dimensión especificada
    SetDimension(dim);

    try{
        component = new double[dim];
        for (int i = 0; i < dim; ++i) {
            component[i] = 0; }
    } catch (std::bad_alloc& ) {
        std::cerr << "No es posible construir un vector: " << '\n';
    } 
}

Vector::Vector(const  Vector &v) : component (NULL) { // Constructor de copia
    *this = v;
}

Vector & Vector::operator=(const Vector &v) { // Operador de asignación
    if(this == &v) return *this; // Evitar autoasignación
    try
    {
        delete[] component;
        dim = v.dim;
        component = new double[dim];

        for (int i = 0; i < dim; ++i) {
            component[i] = v.component[i];
        }
    }
    catch(const std::bad_alloc&) {
        throw std::string("No es posible asignar el vector");
    }
    return *this;
}

Vector::~Vector() { // Destructor
    delete[] component;
}

void Vector::SetDimension(int dim) {
    if (dim < 1) 
        throw std::string("Valor fuera de rango");
    this->dim = dim;
}

int Vector::GetDim() const{
    return dim;
}

void Vector::InputVector() {
    for (int i = 0; i < dim; ++i) {
        std::cin >> component[i];
    }
}

void Vector::PrintVector() const{
    std::cout << "<";
    for (int i = 0; i < dim; ++i) {
        std::cout << component[i] << ", ";
    }
    std::cout << "\b\b>" << std::endl;
}

Vector Vector::operator+(const Vector &v) const{
    if (dim != v.dim)
        throw std::string("Dimensiones incompatibles");

    Vector resultSum(dim);
    for (int i = 0; i < dim; ++i) {
        resultSum.component[i] = component[i] + v.component[i];
    }
    return resultSum;
}

Vector Vector::operator-(const Vector &v) const{
    if (dim != v.dim)
        throw std::string("Dimensiones incompatibles");

    Vector resultSub(dim);
    for (int i = 0; i < dim; ++i) {
        resultSub.component[i] = component[i] - v.component[i];
    }
    return resultSub;
}

Vector Vector::SubstractVector(const Vector &v) const{
    if (dim != v.dim)
        throw std::string("Dimensiones incompatibles");

    Vector resultSub(dim);
    for (int i = 0; i < dim; ++i) {
        resultSub.component[i] = component[i] - v.component[i];
    }
    return resultSub;
}

Vector Vector::operator*(double scalar) const{
    Vector resultScalar(dim);
    for (int i = 0; i < dim; ++i) {
        resultScalar.component[i] = component[i] * scalar;
    }
    return resultScalar;
}

Vector Vector::operator*(const Vector &v) const{
    if (dim != v.dim)
        throw std::string("Dimensiones incompatibles");

    Vector resultDot(dim);
    for (int i = 0; i < dim; ++i) {
        resultDot.component[i] = component[i] * v.component[i];
    }
    return resultDot;
}

double Vector::NormVector() const{
    double resultNorm = 0;
    for (int i = 0; i < dim; ++i) {
        resultNorm += component[i] * component[i];
    }
    
    resultNorm = sqrt(resultNorm);
    return resultNorm;
}

// Funciones friend

Vector operator*(double scalar, const Vector &v) {
    Vector resultScalar(v.dim);
    for (int i = 0; i < resultScalar.dim; i++)
    {
        resultScalar.component[i] = scalar * v.component[i];
    }   
return resultScalar;
}

std::ostream & operator<<(std::ostream &out, const Vector &v) {
    out << "<";
    for (int i = 0; i < v.dim; ++i) {
        out << v.component[i] << ", ";
    }
    out << "\b\b>";
    return out;
}

std::istream & operator>>(std::istream &in, Vector &v) {
    for (int i = 0; i < v.dim; ++i) {
        in >> v.component[i];
    }
    return in;
}