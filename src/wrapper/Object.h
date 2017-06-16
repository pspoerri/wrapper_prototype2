#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

class Object
{
public:
    virtual bool sameType(Object* other) {
        return typeString() == other->typeString();
    }

    void printType() {
        std::cout << "Hey I am a " << typeString() << "!" << std::endl;
    }

    virtual std::string typeString() {
        return "Object";
    }

protected:
};

class MapObject: public Object
{
public:
    virtual void set(const char* name, Object* object) {
        m_objects[name] = object;
    }

    virtual Object* get(const char* name) {
        if (m_objects.find(name) == m_objects.end()) {
            return NULL;
        }

        return m_objects[name];
    }

    virtual bool has(const char* name) const{
        return m_objects.find(name) != m_objects.end();
    }

    virtual std::string typeString() override{
        return "MapObject";
    }

private:
    std::map<std::string, Object*> m_objects;
};

class ArrayObject: public Object
{
public:
    void add(Object* object) {
        m_items.push_back(object);
    }

    Object* get(int idx) const {
        if (idx < 0 || (size_t)idx > m_items.size()) {
            return NULL;
        }
        return m_items[idx];
    }

    int length() {
        return (int)m_items.size();
    }

    virtual std::string typeString() override {
        return "ArrayObject";
    }
private:
    std::vector<Object*> m_items;
};

template<typename T>
class SimpleObject: public Object
{
public:
    SimpleObject(T value): m_value(value) {
        // Do nothing
    }

    T getValue() {
        return m_value;
    }

    virtual std::string typeString();
private:
    T m_value;
};

template class SimpleObject<int>;
template class SimpleObject<float>;
template class SimpleObject<double>;
template class SimpleObject<std::string>;
template class SimpleObject<void*>;

typedef SimpleObject<int> IntObject;
typedef SimpleObject<float> FloatObject;
typedef SimpleObject<double> DoubleObject;
typedef SimpleObject<std::string> StringObject;
typedef SimpleObject<void*> PtrObject;
