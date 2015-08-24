/* File : refToInternalObject.h */


class Foo {
public:
  Foo();
  ~Foo();
};

class B
{
private:
     double value;
public:
     B();
     ~B();
     void setValue(const double &_value);
     double getValue() const;
};

class A
{
private:
    B privateB;
public:
    A();
    ~A();
    B& getB();
};
