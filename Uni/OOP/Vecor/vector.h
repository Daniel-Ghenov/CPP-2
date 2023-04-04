
template <class T>
class Vector{
private:
    T* data;
    size_t size;
    size_t maxSize;
    
    void resize(size_t size);
    void copyFrom(const Vector<T>& other);
public:
    Vector();
    Vector(size_t size, const T& fill);
    ~Vector();
    Vector& operator=(const Vector<T>& other);
    Vector(const Vector<T>& other);
    void app(T newData);
    void popback();
    void clear();


};