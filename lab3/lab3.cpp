#include "lab3.hpp"

namespace Lab3 {

    template<class T>
    Storage<T>::Storage(uint32_t capacity) {
        mValue = new T[capacity];
        mCapacity = capacity;
    }

    template<class T>
    Storage<T>::Storage(const Storage<T> &other) {
        *this = other;
    }

    template<class T>
    void Storage<T>::Push(const T &value) {
        if (mSize >= mCapacity)
            Realloc();
        mValue[mSize] = value;
        ++mSize;
    }

    template<class T>
    void Storage<T>::Pop(const uint32_t &index) {
        if (mSize != 0) {
            Storage<T> temp(mSize - 1);
            for (uint32_t i = 0; i < mSize; ++i) {
                if (i == index) continue;
                temp.Push(mValue[i]);
            }
            *this = temp;
        }
    }

    template<class T>
    Storage<T>::~Storage() {
        this->Clean();
    }

    template<class T>
    void Storage<T>::Clean() {
        if (nullptr != mValue) {
            delete[] mValue;
            mValue = nullptr;
        }
        mSize = 0;
        mCapacity = 0;
    }

    template<class T>
    void Storage<T>::Realloc() {
        ++mCapacity;
        auto oldValues = new T[mCapacity];
        const auto oldSize = this->mSize;
        const auto byteSize = sizeof(T) * mSize;
        memcpy_s(oldValues, byteSize, mValue, byteSize);
        *this = Storage(mCapacity);
        mSize = oldSize;
        memcpy_s(mValue, byteSize, oldValues, byteSize);
        delete[] oldValues;
    }

    template<class T>
    Storage<T> &Storage<T>::operator=(const Storage<T> &other) {
        this->Clean();
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        mValue = new T[mCapacity];
        const auto& byteSize = sizeof(T) * mSize;
        memcpy_s(mValue, byteSize, other.mValue, byteSize);
        return *this;
    }

    template<class T>
    void Storage<T>::Pop(const uint32_t &begin, const uint32_t &end) {
        for (uint32_t i = begin; i < end; ++i)
            this->Pop(i);
    }

}