#include <iostream>
#include <memory>
#include <cstdint>

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

typedef void (*FuncPtr)(void);

int main()
{
    std::unique_ptr<Base> pbase1 = std::make_unique<Base>();
    std::unique_ptr<Base> pbase2 = std::make_unique<Derive>();

    uintptr_t* vptr1 = *(uintptr_t**)pbase1.get();
    uintptr_t* vptr2 = *(uintptr_t**)pbase2.get();

    FuncPtr f1 = reinterpret_cast<FuncPtr>(vptr1[0]);
    FuncPtr f2 = reinterpret_cast<FuncPtr>(vptr2[0]);
    
    f1();
    f2();
    return 0;
}
