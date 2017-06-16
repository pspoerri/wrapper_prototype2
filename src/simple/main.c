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
    Object* Simple = create_object("Simple", simple_new_arg);

    // Build argument for doSomething
    float data[] = {1.0, 2.0, 3.0, 4.0};
    Object* dataPtr = create_ptr((data));
    Object* dataLen = create_int(sizeof(data)/sizeof(float));
    Object* simple_arg = create_map();
    map_set(simple_arg, "data", dataPtr);
    map_set(simple_arg, "len", dataLen);

    // Call doSomething
    object_call(Simple, "doSomething", simple_arg);

}

/* Output of the code:

    Registering object factory for Simple
    Executing the simple code
    Hello from simple
    Arguments:
     a:
       Hello
       World
      b: 5
    Simple: Do Something
      {1.000000 2.000000 3.000000 4.000000 }

*/
