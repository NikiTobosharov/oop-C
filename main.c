#include <stdio.h>
#include <stdlib.h>
#include "my_class.h"

int main() 
{
    MyClass *obj = my_class_create();

    // Accessing private data. Encapsulation: get_private()
    Private *private = get_private(obj);
    my_class_do_something(private);

    // Creating different types of shapes using abstraction and inheritance
    Shape *circle = (Shape *)create_circle(5.0);
    Shape *rectangle = (Shape *)create_rectangle(2.0, 4.0);

    // Polymorphism: The same function can handle different types of shapes
    print_shapes(circle, "Circle");
    print_shapes(rectangle, "Rectangle");
  
    free_shapes(circle, rectangle);
    my_class_delete(obj);
    return 0;      
}
