#pragma once
#include <iostream>
#include <string>

// ============================================================
//  ABSTRACTION: Lớp trừu tượng - không thể khởi tạo trực tiếp
//  Định nghĩa giao diện chung cho tất cả thành phần game
// ============================================================
class GameComponent {
protected:
    std::string componentName;  // Tên thành phần (dùng chung)

public:
    GameComponent(const std::string& name = "GameComponent")
        : componentName(name) {}

    // ABSTRACTION: Pure virtual - các class con BẮT BUỘC phải override
    virtual void info() const = 0;

    // Virtual display - có thể override để hiển thị khác nhau (Polymorphism)
    virtual void display() const {
        std::cout << "[" << componentName << "]" << std::endl;
    }

    // Getter cho componentName (Encapsulation)
    std::string getName() const { return componentName; }

    // OPERATOR OVERLOADING: << để in thông tin component ra ostream
    friend std::ostream& operator<<(std::ostream& os, const GameComponent& gc) {
        os << "[Component: " << gc.componentName << "]";
        return os;
    }

    // Virtual destructor đảm bảo giải phóng bộ nhớ đúng
    virtual ~GameComponent() {}
};