#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;
class Vector3D
{
public:
    float x, y, z;
    Vector3D()  //constructor
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3D(float x1, float y1, float z1 = 0)     //initializing object with values.
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector3D(const Vector3D& vec);    //copy constructor
    Vector3D operator+(const Vector3D& vec) ;    //addition
    Vector3D& operator+=(const Vector3D& vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D& vec);    //substraction
    Vector3D& operator-=(const Vector3D& vec);  //assigning new result to the vector
    Vector3D operator*(float value);    //multiplication
    Vector3D& operator*=(float value);  //assigning new result to the vector.
    Vector3D operator/(float value);    //division
    Vector3D& operator/=(float value);  //assigning new result to the vector
    Vector3D& operator=(const Vector3D& vec);
    float dot_product(const Vector3D& vec); //scalar dot_product
    Vector3D cross_product(const Vector3D& vec);    //cross_product
    float magnitude();  //magnitude ofloatthe vector
    Vector3D normalization();   //nor,malized vector
    float square(); //gives square ofloatthe vector

    float distance(const Vector3D& vec);    //gives distance between two vectors
    float show_X(); //return x
    float show_Y(); //return y
    float show_Z(); //return z
    void disp();    //display value ofloatvectors
};

#endif // _VECTOR3D_H_