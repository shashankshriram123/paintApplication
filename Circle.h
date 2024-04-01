#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include <iostream>


class Circle : public Shape{

    float radius;
    Color color;
    

public:
    Circle() {
        x = 0.0f;
        y = 0.0f;
        radius = 0.1f;
        selected = false;

        
    }

    Circle(float x, float y, float radius, Color color) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->color = color;
        selected = false;
    }
    // getters
    float getRadius(){
        return radius;
    }



    // setters
    void setRadius(float radius){
        this->radius = radius;
    }
    void setColor(Color color) {
        this->color = color;
    }




    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());

        float inc = ( 2 * M_PI) / 60;
        glBegin(GL_POLYGON);
            for (float theta = 0; theta < 2*M_PI; theta += inc){
                glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
            }
        glEnd();

        if (selected) {
            Circle outer(x, y, radius - 0.02f, Color(1.0f, 1.0f, 1.0f));
            Circle inner(x, y, radius - 0.04f, color);
            outer.draw();
            inner.draw();
            

        }
    }
 
 
 
    bool contains(float mx, float my) {
        if (radius >= sqrt((pow((mx - x), 2) + pow((my - y), 2)))) {
            std::cerr << "PRESSED" << std::endl;
            return true;
        } else {
            return false;
        }
    }


    bool isClicked(float mx, float my){
        //if(mx<=x+radius && mx >= x-radius && my <= y+radius && my >= y-radius){
        //    return true;
        //}
        float distance = sqrt((mx - x) * (mx - x) + (my - y) * (my - y));
        return distance <= radius;
        //return false;
    }
};

#endif