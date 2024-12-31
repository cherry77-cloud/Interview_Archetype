#include <iostream>
#include <memory>

class B; // 前向声明

class A {
public:
    std::shared_ptr<B> ptrB;
    A() { std::cout << "A Constructor" << std::endl; }
    ~A() { std::cout << "A Destructor" << std::endl; }
};

class B {
public:
    std::weak_ptr<A> ptrA; // 使用 weak_ptr
    B() { std::cout << "B Constructor" << std::endl; }
    ~B() { std::cout << "B Destructor" << std::endl; }
};

int main() 
{
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        a->ptrB = b;
        b->ptrA = a;

        std::cout << "a.use_count() = " << a.use_count() << std::endl;
        std::cout << "b.use_count() = " << b.use_count() << std::endl;
    }
    std::cout << "Exiting main..." << std::endl;
    return 0;
}
