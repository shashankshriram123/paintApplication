#ifndef CANVAS_H
#define CANVAS_H

#include "Toolbar.h"
#include "Rectangle.h"
#include "Scribble.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "ColorPicker.h"
#include <iostream>
using namespace std; 


struct Canvas {
    Rectangle area;
    ColorPicker colorPicker;

    Shape* shapes[1000];
    int shapeCounter;
    int selectedShape;

    float offsetX;
    float offsetY;



    Canvas(){
        area = Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, Color(1.0f, 1.0f, 1.0f));
        shapeCounter = 0;
        selectedShape = -1;
    }

    void handleMouseClick(float x, float y, Tool tool, Color color){
        if (tool == PENCIL){
            shapes[shapeCounter] = new Scribble();
            shapeCounter++;
            ((Scribble*)shapes[shapeCounter - 1])->addPoint(x, y, color);
        }
        else if (tool == ERASER){
            //
        }
        else if (tool == SQUARE){
            shapes[shapeCounter] = new Rectangle(x, y, 0.2f, 0.2f, color);
            shapeCounter++;
        }
        else if(tool == CIRCLE){
            shapes[shapeCounter] = new Circle(x,y, 0.1, color);
            shapeCounter++;
        }
        else if(tool == TRIANGLE){
            shapes[shapeCounter] = new Triangle(x,y,0.2f, color);
            shapeCounter++;
        }
        else if(tool == RHOMBUS){
            shapes[shapeCounter] = new Rhombus(x,y, 0.2f, color);
            shapeCounter++;
        }
        

    
        else if (tool == MOUSE) {
           
            for (int i = 0; i < shapeCounter; i++) {
                shapes[i]->deselect();
            }

            selectedShape = -1;
            for (int i = shapeCounter - 1; i >= 0; i--) {
                if (shapes[i]->contains(x, y)) {
                    shapes[i]->select();
                    selectedShape = i;
                    offsetX = x - shapes[i]->getX();
                    offsetY = shapes[i]->getY() - y;
                    
                    std::cerr << "CHANGE COlOR !!!" << std::endl;
                }
            }
        }
    }

    void handleMouseMotion(float x, float y, Tool tool, Color color) {
        if (tool == PENCIL){
            ((Scribble*)shapes[shapeCounter - 1])->addPoint(x, y, color);
        }
        else if (tool == ERASER){
            //
        }
        if (tool == MOUSE) {
            if (selectedShape != -1) {
                shapes[selectedShape]->setX(x - offsetX);
                shapes[selectedShape]->setY(y + offsetY);
                
                
            }
        }
    
    }
    void clearScreen(){
        
        shapeCounter = 0;
        area.draw();
    }
    void clearScreen(Tool tool){
        if(tool == MOUSE && selectedShape != -1){
            shapes[selectedShape]->shunku(Color(1.0f,1.0f,1.0f));
        }
        shapeCounter = 0;
        area.draw();
    }

    void draw(){
        area.draw();

        for (int i = 0; i < shapeCounter; i++) {
            shapes[i]->draw();
        }
       

    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }



    void moveAndChange(Tool tool, Color color, bool forward, bool backward){
    //
    if (tool == MOUSE){
    if (forward && selectedShape != 0){
        Shape* temp = shapes[selectedShape-1];
        shapes[selectedShape-1] = shapes[selectedShape];
        shapes[selectedShape] = temp;
        selectedShape = selectedShape-1;
    } 
    else if(backward && selectedShape != (shapeCounter -1)){
        Shape* temp = shapes[selectedShape+1];
        shapes[selectedShape+1] = shapes[selectedShape];
        shapes[selectedShape] = temp;
        selectedShape = selectedShape+1;
    }
    }
    }
};

#endif