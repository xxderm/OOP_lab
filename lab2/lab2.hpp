#pragma once
#include <iostream>

namespace Graphics::Shapes {

    class IShape {
    public:
        IShape();
        IShape(const IShape& other);
        virtual void Render() = 0;
        void PrintPosition() const noexcept;
        void SetPosition(const uint32_t& pos) noexcept;
        virtual ~IShape();
    protected:
        uint32_t mPosition{};
    };

    class RectangleShape final : public IShape {
    public:
        RectangleShape();
        RectangleShape(const RectangleShape& other) : IShape(other) { }
        void Render() override;
        ~RectangleShape();
    };

    class Border final {
    public:
        Border() = default;
        ~Border() = default;
    private:
        RectangleShape mRectangle{};
    };

    class Box final {
    public:
        Box() : mRectangle(std::make_shared<RectangleShape>()) {}
    private:
        std::shared_ptr<RectangleShape> mRectangle;
    };

}