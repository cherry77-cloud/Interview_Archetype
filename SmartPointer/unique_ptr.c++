#include <iostream>
#include <memory>

class Test {
public:
    Test(int val) : value(val) { std::cout << "Test Constructor: " << value << std::endl; }
    ~Test() { std::cout << "Test Destructor: " << value << std::endl; }
    void show() const { std::cout << "Value: " << value << std::endl; }
private:
    int value;
};

std::unique_ptr<Test> createTest(int val) 
{
    auto ptr = std::make_unique<Test>(val);
    return ptr;
}

int main() 
{
    std::unique_ptr<Test> ptr1(new Test(100));  
    ptr1->show();

    auto ptr2 = std::make_unique<Test>(200);
    ptr2->show();

    std::unique_ptr<Test> ptr3 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is now null after std::move." << std::endl;
    }
    ptr3->show();

    ptr2.reset(new Test(300));   // Test Destructor: 200
    ptr2->show();

    Test* rawPtr = ptr3.release();
    if (!ptr3) {
        std::cout << "ptr3 is now null after release." << std::endl;
    }
    if (rawPtr) {
        std::cout << "rawPtr (from ptr3): ";
        rawPtr->show();
        delete rawPtr;  // Test Destructor: 100
        rawPtr = nullptr;
    }

    auto ptr4 = createTest(400);   // Test Destructor: 400  Test Destructor: 300
    return 0;
}
