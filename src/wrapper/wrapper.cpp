#include "wrapper.h"
#include <map>


void delete_object(Object* object) {
    delete object;
}


std::map<std::string, std::function<Object*(Object*)> >& get_object_factories() {
    static std::map<std::string, std::function<Object*(Object*)> > map;
    return map;
}
std::map<std::string, std::map<std::string, std::function<Object*(Object*, Object*)> > >& get_object_functions() {
    static std::map<std::string, std::map<std::string, std::function<Object*(Object*, Object*)> > > map;
    return map;
}

bool foo() {
    return true;
}

bool register_object_factory(std::string name, std::function<Object*(Object *)> func) {
    std::cout << "Registering object factory for " << name << std::endl;
    auto& factories = get_object_factories();
    if (factories.find(name) != factories.end()) {
        throw std::runtime_error("Cannot register object factory: Factory with name "+name+" already found");
    }
    factories[name] = func;
    get_object_functions()[name] = std::map<std::string, std::function<Object*(Object*,Object*)> >();
    return true;
}

bool register_object_function(std::string name, std::string function, std::function<Object*(Object*, Object *)> func) {
    auto& functions = get_object_functions();
    if (functions.find(name) == functions.end()) {
        throw std::runtime_error("Cannot register function "+function+": Object with "+name+" is not registered!");
    }
    auto& object = functions[name];
    if (object.find(function) != object.end()) {
        throw std::runtime_error("Cannot register function "+function+" on object "+name+": Function already exists");
    }
    functions[name][function] = func;
    return true;
}

Object* create_object(const char* name, Object* arg) {
    auto& factories = get_object_factories();
    if (factories.find(name) == factories.end()) {
        throw std::runtime_error("Object factory for "+std::string(name)+" does not exist");
    }
    return factories[name](arg);
}


Object* object_call(Object* obj, const char* function, Object* arg) {
    auto& object = get_object_functions();
    auto name = obj->typeString();
    auto funcstr = std::string(function);
    if (object.find(name) == object.end()) {
        throw std::runtime_error("Cannot call "+name+"->"+funcstr+": "+name+" the object is not registered");
    }
    auto& functions = object[name];
    if (functions.find(function) == functions.end()) {
        throw std::runtime_error("Cannot call "+name+"->"+funcstr+": "+funcstr+" the function is not registered");
    }
    return functions[function](obj, arg);
}
