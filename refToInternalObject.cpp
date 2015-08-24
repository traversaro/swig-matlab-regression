/* File : refToInternalObject.cxx */

#include "refToInternalObject.h"

#include <iostream>


B::B()
{
    value = 0.0;
}

B::~B()
{
}

void B::setValue(const double& _value)
{
    value = _value;
}

double B::getValue() const
{
    return value;
}

A::A()
{
    value = 0.0;
}

A::~A()
{
}

B& A::getB()
{
    return privateB;
}

Foo::Foo() {
    std::cout << "allocating a new Foo" << std::endl;
}

Foo::~Foo() {
    std::cout << "destructing Foo at address " << this << std::endl;
}