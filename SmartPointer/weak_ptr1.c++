// 双向关联导致循环引用
#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> ptrB;
    A() { std::cout << "A Constructor" << std::endl; }
    ~A() { std::cout << "A Destructor" << std::endl; }
};

class B {
public:
    std::shared_ptr<A> ptrA;
    B() { std::cout << "B Constructor" << std::endl; }
    ~B() { std::cout << "B Destructor" << std::endl; }
};

int main() 
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->ptrB = b;
    b->ptrA = a;
    
    std::cout << "Exiting main..." << std::endl;
    return 0;
}
