#pragma once
#ifdef __cplusplus
#include "Object.h"
extern "C" {
#else
typedef struct Object {} Object;
#endif
void delete_object(Object* object);
Object* create_object(const char* name, Object* arg);
Object* object_call(Object* obj, const char* function, Object* arg);

// Map
Object* create_map();
void map_set(Object* map, const char* name, Object* object);
Object* map_get(Object* map, const char* name);
int map_has(Object* map, const char* name);
// Array
Object* create_array();
void array_add(Object* array, Object* value);
Object* array_get(Object* array, int idx);
int array_length(Object* array);

// string
Object* create_string(const char* value);
const char* get_string(Object* object);

// float
Object* create_float(float value);
float get_float(Object* object);

// double
Object* create_double(double value);
double get_double(Object* object);

//int
Object* create_int(int value);
int get_int(Object* object);

// Pointer
Object* create_ptr(void* value);
void* get_ptr(Object* object);

#ifdef __cplusplus
}
#include <string>
#include <functional>
bool register_object_factory(std::string name, std::function<Object*(Object*)> func);
bool register_object_function(std::string name, std::string function, std::function<Object*(Object*, Object *)> func);
#endif
