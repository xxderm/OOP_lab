#include "lab2.hpp"
#include <memory>

using namespace Graphics::Shapes;

int main() {
    {
        auto rectangleShape = std::make_shared<RectangleShape>();
        rectangleShape->Render();
        rectangleShape->PrintPosition();
    }
    std::cout << "\n\n";
    {
        auto rectangleShape = std::make_shared<RectangleShape>();
        rectangleShape->SetPosition(2);
        auto rectangleShape2 = std::make_shared<RectangleShape>(*rectangleShape);
        rectangleShape2->PrintPosition();
    }
    std::cout << "\n\n";
    {
        auto border = std::make_shared<Border>();
    }
    std::cout << "\n\n";
    {
        auto box = std::make_shared<Box>();
    }
    std::system("pause");
    return 0;
}
