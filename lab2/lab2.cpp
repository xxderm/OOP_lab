#include "lab2.hpp"

namespace Graphics::Shapes {

    Graphics::Shapes::IShape::~IShape() {
        std::cout << "IShape Destructor\n";
    }

    IShape::IShape() {
        std::cout << "IShape Constructor\n";
    }

    IShape::IShape(const IShape &other) {
        this->mPosition = other.mPosition;
    }

    void IShape::PrintPosition() const noexcept {
        std::cout << "Shape position: " << this->mPosition << std::endl;
    }

    void IShape::SetPosition(const uint32_t& pos) noexcept {
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