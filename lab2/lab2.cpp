#include "lab2.hpp"

namespace Graphics::Shapes {

    Graphics::Shapes::Shape::~Shape() {
        std::cout << "IShape Destructor\n";
    }

    Shape::Shape() {
        std::cout << "Shape Constructor\n";
    }

    Shape::Shape(const Shape &other) {
        this->mPosition = other.mPosition;
    }

    void Shape::PrintPosition() const noexcept {
        std::cout << "Shape position: " << this->mPosition << std::endl;
    }

    void Shape::SetPosition(const uint32_t& pos) noexcept {
        this->mPosition = pos;
    }

    RectangleShape::RectangleShape() {
        std::cout << "RectangleShape Constructor\n";
    }

    RectangleShape::~RectangleShape() {
        std::cout << "RectangleShape Destructor\n";
    }

    void RectangleShape::Render() {
        std::cout << "RectangleShape Render\n";
    }
}