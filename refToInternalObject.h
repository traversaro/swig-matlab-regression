/* File : refToInternalObject.h */


class B
{
private:
     double value;
public:
     B();
     void setValue(const double &_value);
     double getValue() const;
};

class A
{
private:
    B privateB;
public:
    B& getB();
};
