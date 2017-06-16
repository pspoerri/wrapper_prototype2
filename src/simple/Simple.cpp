#include "Simple.h"

Simple::Simple(std::vector<std::string> a, int b):
    m_a(a), m_b(b)
{
    std::cout << "Hello from simple\n";
    std::cout << "Arguments:\n a: \n";
    for (auto& v: m_a) {
        std::cout << "   " << v << "\n";
    }
    std::cout << "  b: " << std::to_string(b) << std::endl;
}

float Simple::doSomething(float* data, int len) {
    std::cout << "Simple: Do Something\n  {";
    for (int i=0; i<len; ++i) {
        std::cout << std::to_string(data[i]) << " ";
    }
    std::cout << "}" << std::endl;
    return 1.0;
}

static Object* doSomething(Object* obj, Object *args) {
    auto* simple = (Simple*)obj;
    auto* argsMap = (MapObject*)args;
    auto* dataObj = ((PtrObject*)argsMap->get("data"));
    float* data = (float*)dataObj->getValue();

    auto* lenObj = ((IntObject*)argsMap->get("len"));
    int len = lenObj->getValue();

    return create_float(simple->doSomething(data, len));
}

static std::vector<std::string> expand_vector(Object* vector) {
    std::vector<std::string> vec;
    auto* array = (ArrayObject*)vector;
    int length = array->length();
    for (int i=0; i<length; ++i) {
        auto* mobj = (StringObject*)array->get(i);

        vec.push_back((mobj->getValue()));
    }
    return vec;
}

static Object* create_simple(Object* args) {
    auto* argsMap = (MapObject*)args;
    auto a = expand_vector(argsMap->get("a"));
    int b = ((IntObject*)argsMap->get("b"))->getValue();
    return new Simple(a, b);
}

static bool simple_registered = register_object_factory("Simple", create_simple);
static bool simple_register_doSomething = register_object_function("Simple", "doSomething", doSomething);
