#include <iostream>

struct Base1
{
    virtual void foo () = 0;
    virtual ~Base1 () = default;
};

struct Base2
{
    virtual void foo () = 0;
    virtual ~Base2 () = default;
};

struct Intermediate1 : public Base1
{
    virtual void foo () override
    {
        std::cout << "Here we use Base1::foo()" << std::endl;
    }

    virtual ~Intermediate1 () = default;
};

struct Intermediate2 : public Base2
{
    virtual void foo () override
    {
        std::cout << "Here we use Base2::foo()" << std::endl;
    }

    virtual ~Intermediate2 () = default;
};

struct Derived final : public Intermediate1, public Intermediate2
{};

int main ()
{
    Derived obj;

    obj.Intermediate1::foo ();
    obj.Intermediate2::foo ();
}

