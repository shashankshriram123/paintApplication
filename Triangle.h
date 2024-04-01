#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include <iostream>
#include "Shape.h"

class Triangle : public Shape{
    float base;
    Color color;


public:
    Triangle(){
        x = 0.0f;
        y = 0.0f;
        base = 0.2f;
        selected = false;
    }
    Triangle(float x, float y, float base, Color color){
        this->x = x;
        this->y = y;
        this->base = base;
        this->color = color;
        selected = false;
    }


    float getBase(){
        return base;
    }


    void setBase(float base){
        this->base = base;
    }
    void setColor(Color color) {
        this->color = color;
    }


    void draw(){
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
            glVertex2f(x,y+(base/2));
            glVertex2f(x-(base/2), y-(base/2));
            glVertex2f(x+(base/2), y-(base/2));
        glEnd();

        if(selected){


            Triangle outer(x,y, base-0.03f, Color(1.0f, 1.0f, 1.0f));
            Triangle inner(x,y, base-0.06f, color);

            outer.draw();
            inner.draw();

        }

    }
  
    bool contains(float mx, float my){
        if(mx >= x-(base/2) && mx <= x+(base/2) && my <= y+(base/2) && y-(base/2) ){
            std::cerr << "TRI PRESSED" << std::endl;

            return true;
        }
        else{return false;}
        
    }
};

#endif