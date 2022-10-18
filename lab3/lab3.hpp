#pragma once
#include <vector>
#include <type_traits>
#include <concepts>
#include <chrono>
#include <iostream>

namespace Lab3 {

    template<class T>
    class Storage final {
    public:
        struct Iterator final {
            using IterCat = std::forward_iterator_tag;
            using DiffType = std::ptrdiff_t;
            using ValueType = T;
            using Ptr = T*;
            using Ref = T&;

            Iterator(Ptr other) : mPtr(other) {}

            Ref operator*() const { return *mPtr; }

            Ptr operator->() { return mPtr; }

            Iterator& operator++() {
                mPtr++;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
                return lhs.mPtr == rhs.mPtr;
            }

            friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
                return lhs.mPtr != rhs.mPtr;
            }
        private:
            Ptr mPtr;
        };

        Iterator Begin() {
            return Iterator(&mValue[0]);
        }

        Iterator End() {
            return Iterator(&mValue[mSize]);
        }

        Storage<T>& operator=(const Storage<T>& other);

        T& operator[](const uint32_t index) { return mValue[index]; }

        Storage() = default;

        Storage(uint32_t capacity);

        Storage(const Storage<T>& other);

        void Clean();

        void Push(const T& value);

        void Pop(const uint32_t& index);

        void Pop(const uint32_t& begin, const uint32_t& end);

        uint32_t GetSize() const noexcept { return mSize; }

        uint32_t GetCapacity() const noexcept { return mCapacity; }

        ~Storage();
    private:
        void Realloc();
    private:
        T* mValue = nullptr;
        uint32_t mSize = 0;
        uint32_t mCapacity = 0;
    };

    namespace Shape {
        class IShape {};
        class RectangleShape final : IShape {};

        template<class T>
        concept BaseOfShape = std::is_base_of<IShape, T>::value;

        template<BaseOfShape T>
        using ShapeStorage = Storage<T>;
    }

}