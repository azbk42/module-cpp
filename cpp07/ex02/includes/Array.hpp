#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array 
{
    public:

        Array() : _array(NULL), _size(0) {}

        Array(unsigned int n) : _array(NULL), _size(n) {

            if (_size > 0) {
                _array = new T[_size];
                for (size_t i = 0; i < _size; ++i) {
                    _array[i] = T();
                }
            }
        }

        Array(const Array& rhs) : _array(NULL), _size(rhs._size) {
            if (_size > 0) {
                _array = new T[_size];
                for (size_t i = 0; i < _size; ++i) {
                    _array[i] = rhs._array[i];
                }
            }
        }

        ~Array() {
            delete[] _array;
        }

        Array& operator=(const Array& rhs) {
            if (this != &rhs) {
                delete[] _array;
                _size = rhs._size;
                if (_size > 0){
                    _array = new T[_size];
                } else { 
                    _array = NULL;
                }
    
                for (unsigned int i = 0; i < _size; ++i) {
                    _array[i] = rhs._array[i];
                }
            }
            return *this;
        }

        const T& operator[](unsigned int index) const {
            if (index >= _size) {
                throw OutOfBounds();
            }
            return _array[index];
        }

        T& operator[](unsigned int index) {
            if (index >= _size) {
                throw OutOfBounds();
            }
            return _array[index];
        }

        unsigned int size() const {
            return _size;
        }

        void setIndex(unsigned int n, T value) {
            if (n >= _size) {
                throw OutOfBounds();
            }
            _array[n] = value;
        }

        T getValue(unsigned int n) const {
            if (n >= _size) {
                throw OutOfBounds();
            }
            return _array[n];
        }

        class OutOfBounds : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Index out of bounds";
            }
        };

    private:
        T* _array;
        unsigned int _size;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    for (unsigned int i = 0; i < arr.size(); ++i) {
        os << "["<< arr.getValue(i) << "] ";
    }
    return os;
}
