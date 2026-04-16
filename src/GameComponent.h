#pragma once
#include <iostream>
#include <string>

using namespace std;

// ABSTRACTION: Lớp trừu tượng - không thể khởi tạo trực tiếp
class GameComponent {
protected:
    string componentName;  // Tên thành phần

public:
    GameComponent(const string& name = "GameComponent")
        : componentName(name) {}

    // Pure virtual
    virtual void info() const = 0;

    // Có thể override
    virtual void display() const {
        cout << "[" << componentName << "]" << endl;
    }

    // Getter
    string getName() const {
        return componentName;
    }

    // Operator <<
    friend ostream& operator<<(ostream& os, const GameComponent& gc) {
        os << "[Component: " << gc.componentName << "]";
        return os;
    }

    // Destructor
    virtual ~GameComponent() {}
};