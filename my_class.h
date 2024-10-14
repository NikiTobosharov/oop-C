#include <stdio.h>
#include <stdlib.h>

#ifndef MY_CLASS_H
#define MY_CLASS_H

// Polymorphism: Function pointer allows different implementations of the area calculation
typedef double (*calculate_area_func)(void *);

typedef struct Private Private;
typedef struct MyClass MyClass;
typedef struct Shape Shape;
typedef struct Circle Circle;
typedef struct Rectangle Rectangle;

// Encapsulation: Private struct with restricted access outside MyClass
struct Private
{
    int id; // This is a private member, only accessible through controlled functions.
};

struct MyClass
{
    Private private;
    int data;
};

// Abstraction: Shape is an abstract base structure with a function pointer for calculating area
struct Shape
{
    calculate_area_func calculate_area;
};

struct Circle
{
    Shape shape; // Inheritance: Circle is a subclass of Shape
    double radius;
};

struct Rectangle
{
    Shape shape; // Inheritance: Rectangle is a subclass of Shape
    double height;
    double width;
};

MyClass *my_class_create();
Private *get_private(MyClass *obj);
void my_class_do_something(Private *obj);
void my_class_delete(MyClass *obj);

// Abstraction: function pointers allow different implementations for calculating area
double calculate_circle_area(void *shape);
double calculate_rectangle_area(void *shape);

Circle *create_circle(double radius);
Rectangle *create_rectangle(double height, double width);
void print_shapes(Shape *shape, const char *shape_type);
void free_shapes(Shape *shape1, Shape *shape2);

#endif