/* File : refToInternalObject.cxx */

#include "refToInternalObject.h"

B::B()
{
    value = 0.0;
}

void B::setValue(const double& _value)
{
    value = _value;
}

double B::getValue() const
{
    return value;
}

B& A::getB()
{
    return privateB;
}
