#ifndef SHAPE_H
#define SHAPE_H
#include "Color.h"

class Shape {
protected:
    float x;
    float y;
    bool selected;
    Color color;

public:
    Shape() {
        //
    }

    // virtual functions
    virtual void draw() = 0;
    virtual bool contains(float, float) = 0;

    Color getColor(){
        return color;
    }

    // getters
    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    bool isSelected() {
        return selected;
    }

    // setters
    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    void select() {
        selected = true;
    }

    void deselect() {
        selected = false;
    }
    void shunku(Color newcolor){
        color.setColor(newcolor.getR(), newcolor.getG(), newcolor.getB());
    }



};

#endif