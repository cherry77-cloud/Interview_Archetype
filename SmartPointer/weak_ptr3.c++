// weak_ptr 不能直接访问对象，需要通过 lock() 方法转换为 shared_ptr，并检查对象是否仍然存在。
#include <iostream>
#include <memory>

int main() 
{
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;

    if (auto locked = wp.lock()) { // 尝试获取 shared_ptr
        std::cout << "Value: " << *locked << std::endl;
    } else {
        std::cout << "Object no longer exists." << std::endl;
    }

    sp.reset(); // 释放资源

    if (auto locked = wp.lock()) { // 再次尝试获取 shared_ptr
        std::cout << "Value: " << *locked << std::endl;
    } else {
        std::cout << "Object no longer exists." << std::endl;
    }

    return 0;
}
