#include <stdio.h>
#include <stdlib.h>
#include "my_class.h"

#ifndef M_PI
#define M_PI 3.1415
#endif

MyClass *my_class_create()
{
    MyClass *obj = (MyClass *)malloc(sizeof(MyClass));
    if(obj)
    {
        obj->data = 42;
        obj->private.id = 1;
        return obj;
    }
    return NULL;
}

Private *get_private(MyClass *obj)
{
    return &obj->private;
}

void my_class_do_something(Private *obj)
{
    printf("Object id is: %d\n", obj->id);
}

void my_class_delete(MyClass *obj)
{
    if(obj)
    {
        free(obj);
    }
    else
    {
        printf("Object is NULL.\n");
    }
}

double calculate_circle_area(void *shape)
{
    Circle *circle = (Circle *)shape;
    // Abstraction: area calculation hidden behind function pointer
    return M_PI * circle->radius * circle->radius;
}

double calculate_rectangle_area(void *shape)
{
    Rectangle *rectangle = (Rectangle *)shape;
    // Abstraction: area calculation hidden behind function pointer
    return rectangle->height * rectangle->width;
}

// Abstraction: Factory function to create a Circle (details hidden)
Circle *create_circle(double radius)
{
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    if(circle)
    {
        circle->shape.calculate_area = calculate_circle_area;
        circle->radius = radius;
        return circle;
    }
    return NULL;
}

// Abstraction: Factory function to create a Rectangle (details hidden)
Rectangle *create_rectangle(double height, double width)
{
    Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    if(rectangle)
    {
        rectangle->shape.calculate_area = calculate_rectangle_area;
        rectangle->height = height;
        rectangle->width = width;
        return rectangle;
    }
    return NULL;
}

void print_shapes(Shape *shape, const char *shape_type)
{
    printf("Shape: %s, area: %.2f\n", shape_type, shape->calculate_area(shape));
}

void free_shapes(Shape *shape1, Shape *shape2)
{
    if(shape1 && shape2)
    {
        free(shape1);
        free(shape2);
    }
    else
    {
        printf("Invalid shapes.\n");
    }
}