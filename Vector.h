template<typename T>
class Vector {
private:
    T* array;
    int size;
    int capacity;

public:
    Vector() : size(0), capacity(10) {
        array = new T[capacity];
    }

    ~Vector() {
        delete[] array;
    }

    T* push_back(T element) {
        if (size >= capacity) {
            capacity *= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = element;
        return &array[size - 1]; 
    }
    
    T& operator[](int index) {
        return array[index];
    }

    int getSize() const {
        return size;
    }

    T* begin() {
        return array;
    }

    T* end() {
        return array + size;
    }

    T* erase(T* position) {
        if (position >= array && position < array + size) {
            for (T* ptr = position; ptr < array + size - 1; ++ptr) {
                *ptr = *(ptr + 1);
            }
            --size;
            return position; 
        }
        return nullptr; 
    }
};