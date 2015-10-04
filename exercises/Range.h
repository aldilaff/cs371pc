// ---------
// Range.c++
// ---------

#ifndef Range_h
#define Range_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            public:
                typedef input_iterator_tag iterator_category;
                typedef T                  value_type;
                typedef ptrdiff_t          difference_type;
                typedef T*                 pointer;
                typedef T&                 reference;

            private:
                T _v;

            public:
                iterator (const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                const T& operator * () {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        iterator begin () const {
            return iterator(_b);}

        iterator end () const {
            return iterator(_e);}};

#endif // Range_h
