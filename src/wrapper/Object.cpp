#include "Object.h"
#include "wrapper.h"

Object* create_object() {
    return new Object;
}

// Map
Object* create_map() {
    return new MapObject;
}
void map_set(Object* map, const char* name, Object* object) {
    ((MapObject*)map)->set(name, object);
}
Object* map_get(Object* map, const char* name) {
    return ((MapObject*)map)->get(name);
}
int map_has(Object* map, const char* name) {
    return ((MapObject*)map)->has(name);
}

// Array
Object* create_array() {
    return new ArrayObject;
}
void array_add(Object* array, Object* value) {
    ((ArrayObject*)array)->add(value);
}
Object* array_get(Object* array, int idx) {
    return ((ArrayObject*)array)->get(idx);
}
int array_length(Object* array) {
    return ((ArrayObject*)array)->length();
}

// string
Object* create_string(const char* value) {
    return new SimpleObject<std::string>(std::string(value));
}
const char* get_string(Object* object) {
    return ((SimpleObject<std::string>*)object)->getValue().c_str();
}

// float
Object* create_float(float value) {
    return new SimpleObject<float>(value);
}
float get_float(Object* object) {
    return ((SimpleObject<float>*)object)->getValue();
}

// double
Object* create_double(double value) {
    return new SimpleObject<double>(value);
}
double get_double(Object* object) {
    return ((SimpleObject<double>*)object)->getValue();
}

//int
Object* create_int(int value) {
    return new SimpleObject<int>(value);
}
int get_int(Object* object) {
    return ((SimpleObject<int>*)object)->getValue();
}

// Pointer
Object* create_ptr(void* value) {
    return new SimpleObject<void*>(value);
}
void* get_ptr(Object* object) {
    return ((SimpleObject<void*>*)object)->getValue();
}


template<>
std::string SimpleObject<std::string>::typeString() {
    return "StringObject";
}

template<>
std::string SimpleObject<float>::typeString() {
    return "FloatObject";
}

template<>
std::string SimpleObject<double>::typeString() {
    return "DoubleObject";
}

template<>
std::string SimpleObject<int>::typeString() {
    return "IntegerObject";
}

template<>
std::string SimpleObject<void*>::typeString() {
    return "PointerObject";
}
