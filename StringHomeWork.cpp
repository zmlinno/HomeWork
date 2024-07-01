#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

namespace bit {

    class string {
        friend ostream& operator<<(ostream& _cout, const bit::string& s);
        friend istream& operator>>(istream& _cin, bit::string& s);

    public:
        typedef char* iterator;

        // Constructors
        string(const char* str = "") {
            if (str == nullptr) {
                str = "";
            }
            _size = strlen(str);
            _capacity = _size + 1;
            _str = new char[_capacity];
            strcpy(_str, str);
        }

        string(const string& s) : _str(nullptr), _size(0), _capacity(0) {
            string temp(s._str);
            swap(temp);
        }

        string& operator=(const string& s) {
            if (this != &s) {
                string temp(s);
                swap(temp);
            }
            return *this;
        }

        ~string() {
            delete[] _str;
        }

        // Iterators
        iterator begin() const {
            return _str;
        }

        iterator end() const {
            return _str + _size;
        }

        // Modify
        void push_back(char c) {
            insert(_size, c);
        }

        string& operator+=(char c) {
            push_back(c);
            return *this;
        }

        void append(const char* str) {
            insert(_size, str);
        }

        string& operator+=(const char* str) {
            append(str);
            return *this;
        }

        void clear() {
            _size = 0;
            _str[0] = '\0';
        }

        void swap(string& s) {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str() const {
            return _str;
        }

        // Capacity
        size_t size() const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }

        bool empty() const {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0') {
            if (n < _size) {
                _size = n;
                _str[_size] = '\0';
            } else if (n > _size) {
                reserve(n + 1);
                for (size_t i = _size; i < n; ++i) {
                    _str[i] = c;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void reserve(size_t n) {
            if (n > _capacity) {
                char* new_str = new char[n];
                strcpy(new_str, _str);
                delete[] _str;
                _str = new_str;
                _capacity = n;
            }
        }

        // Access
        char& operator[](size_t index) {
            if (index >= _size) {
                throw out_of_range("Index out of range");
            }
            return _str[index];
        }

        const char& operator[](size_t index) const {
            if (index >= _size) {
                throw out_of_range("Index out of range");
            }
            return _str[index];
        }

        // Relational operators
        bool operator<(const string& s) const {
            return strcmp(_str, s._str) < 0;
        }

        bool operator<=(const string& s) const {
            return strcmp(_str, s._str) <= 0;
        }

        bool operator>(const string& s) const {
            return strcmp(_str, s._str) > 0;
        }

        bool operator>=(const string& s) const {
            return strcmp(_str, s._str) >= 0;
        }

        bool operator==(const string& s) const {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s) const {
            return strcmp(_str, s._str) != 0;
        }

        // Find
        size_t find(char c, size_t pos = 0) const {
            if (pos >= _size) {
                return npos;
            }
            for (size_t i = pos; i < _size; ++i) {
                if (_str[i] == c) {
                    return i;
                }
            }
            return npos;
        }

        size_t find(const char* s, size_t pos = 0) const {
            if (pos >= _size) {
                return npos;
            }
            const char* found = strstr(_str + pos, s);
            if (found != nullptr) {
                return found - _str;
            }
            return npos;
        }

        // Insert
        string& insert(size_t pos, char c) {
            if (pos > _size) {
                throw out_of_range("Index out of range");
            }
            if (_size + 1 >= _capacity) {
                reserve(_capacity * 2);
            }
            for (size_t i = _size; i > pos; --i) {
                _str[i] = _str[i - 1];
            }
            _str[pos] = c;
            ++_size;
            _str[_size] = '\0';
            return *this;
        }

        string& insert(size_t pos, const char* str) {
            size_t len = strlen(str);
            if (pos > _size) {
                throw out_of_range("Index out of range");
            }
            if (_size + len >= _capacity) {
                reserve(_capacity + len);
            }
            for (size_t i = _size; i >= pos; --i) {
                _str[i + len] = _str[i];
            }
            for (size_t i = 0; i < len; ++i) {
                _str[pos + i] = str[i];
            }
            _size += len;
            _str[_size] = '\0';
            return *this;
        }

        // Erase
        string& erase(size_t pos, size_t len) {
            if (pos >= _size) {
                throw out_of_range("Index out of range");
            }
            if (len == npos || pos + len >= _size) {
                _str[pos] = '\0';
                _size = pos;
            } else {
                for (size_t i = pos + len; i <= _size; ++i) {
                    _str[i - len] = _str[i];
                }
                _size -= len;
            }
            return *this;
        }

        static const size_t npos = -1;

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };

    ostream& operator<<(ostream& _cout, const bit::string& s) {
        _cout << s._str;
        return _cout;
    }

    istream& operator>>(istream& _cin, bit::string& s) {
        char buffer[1024];
        _cin >> buffer;
        s = buffer;
        return _cin;
    }
}