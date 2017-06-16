#pragma once
#include <wrapper.h>
#include <vector>
#include <string>
class Simple: public Object
{
public:
    Simple(Object* args);
    Simple(std::vector<std::string> a, int b);

    float doSomething(float* data, int len);
    virtual std::string typeString() override {
        return "Simple";
    }
private:
    std::vector<std::string> m_a;
    const int m_b;
};
