#include <iostream>
#include <string>
#include <utility>

class Processor {
public:
    void operator()(const std::string& s) const {
        std::cout << "Processing lvalue: " << s << std::endl;
    }

    void operator()(std::string&& s) const {
        std::cout << "Processing rvalue: " << s << std::endl;
    }
};

template <typename Func, typename T>
void execute(Func&& func, T&& arg) 
{
    func(std::forward<T>(arg));
}

int main() 
{
    Processor proc;
    std::string str = "Hello";

    std::cout << "Executing with lvalue:" << std::endl;
    execute(proc, str);

    std::cout << "Executing with rvalue (std::move):" << std::endl;
    execute(proc, std::move(str));

    std::cout << "Executing with rvalue (temporary object):" << std::endl;
    execute(proc, std::string("World"));

    return 0;
}
