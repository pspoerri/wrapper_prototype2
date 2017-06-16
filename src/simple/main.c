#include <wrapper.h>
#include <stdio.h>
int main()
{
    printf("Executing the simple code\n");


    // First argument
    Object* array = create_array();
    array_add(array, create_string("Hello"));
    array_add(array, create_string("World"));

    // Second argument
    Object* value = create_int(5);

    // Build argument
    Object* simple_new_arg = create_map();
    map_set(simple_new_arg, "a", array);
    map_set(simple_new_arg, "b", value);

    // Create simple object
    Object* simple = create_object("Simple", simple_new_arg);

    // Build an argument with data
    float data[] = {1.0, 2.0, 3.0, 4.0};
    Object* dataPtr = create_ptr((data));
    Object* dataLen = create_int(sizeof(data)/sizeof(float));
    Object* simple_arg = create_map();
    map_set(simple_arg, "data", dataPtr);
    map_set(simple_arg, "len", dataLen);

    object_call(simple, "doSomething", simple_arg);
}
