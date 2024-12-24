#include <iostream>
#include <string>
#include <utility>

class Resource {
public:
    std::string data;
    Resource(const std::string& d) : data(d) {
        std::cout << "Resource constructed with data: " << data << std::endl;
    }
    Resource(Resource&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Resource moved. New data: " << data << std::endl;
        other.data = "";
    }
    Resource& operator=(Resource&& other) noexcept {
        std::cout << "Resource move assigned. Old data: " << data;
        data = std::move(other.data);
        std::cout << ", New data: " << data << std::endl;
        other.data = "";
        return *this;
    }
    void display() const {
        std::cout << "Resource data: " << data << std::endl;
    }
};

class Manager {
public:
    Resource res;
    Manager(std::string d) : res(d) {
        std::cout << "Manager constructed.\n";
    }
    Manager(Manager&& other) noexcept : res(std::move(other.res)) {
        std::cout << "Manager moved.\n";
    }
    Manager& operator=(Manager&& other) noexcept {
        std::cout << "Manager move assigned.\n";
        if (this != &other) {
            res = std::move(other.res);
        }
        return *this;
    }
    void display() const {
        res.display();
    }
};

template <typename T>
void transfer(T&& obj) 
{
    Manager m = std::forward<T>(obj);
    m.display();
}

int main() 
{
    Manager m1("Initial Data");
    m1.display();

    transfer(std::move(m1));
    m1.display();

    Manager m2("Another Data");
    m2.display();

    m2 = std::move(m1);
    m2.display();
    m1.display();

    return 0;
}
