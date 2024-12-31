#include <iostream>
#include <memory>

class Base {
public:
    virtual void func() {
        std::cout << "Base::func" << std::endl;
    }
    virtual ~Base() = default;
};

class Derive : public Base {
public:
    void func() override {
        std::cout << "Derive::func" << std::endl;
    }
};

int main()
{
    auto pbase1 = std::make_unique<Base>();
    auto pbase2 = std::make_unique<Derive>();
    pbase1->func(); // Base::func
    pbase2->func(); // Derive::func
    return 0;
}
