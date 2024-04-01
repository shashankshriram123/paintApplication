#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Circle.h"
#include "Rectangle.h"
#include <iostream>



class ColorPicker{

    float redValue = 0.0f;
    float greenValue = 0.0f;
    float blueValue = 0.0f;


    Rectangle area;



    Circle red;
    Circle green;
    Circle blue;
    

    Rectangle redSliderLine;
    Rectangle greenSliderLine;
    Rectangle blueSliderLine;
    Rectangle currentColorDisplay;


    Color currentColor;

    void deselectAll(){
        red.deselect();
        green.deselect();
        blue.deselect();
    }


public:
    ColorPicker(){

// Circle(float x, float y, float radius, Color color) {
    //float x1, float y1, float x2, float y2, float thickness){

         area = Rectangle(-0.8f, -0.75f, 1.8f, 0.25f, Color(0.8f, 0.8f, 0.8f));
         red = Circle(-0.7f, -0.79,0.04f, Color(1.0f, 0.0f, 0.0f) );
         green = Circle(-0.7f, -0.870,0.04f, Color(0.0f, 1.0f, 0.0f) );
         blue = Circle(-0.7f, -0.95,0.04f, Color(0.0f, 0.0f, 1.0f) );
        

         //redSliderLine = Line(-0.7f, -0.79f, 0.5f, -0.79, .2);
        redSliderLine = Rectangle(-0.7f,-0.79, 0.5f, 0.01f, Color(0.0f,0.0f,0.0f)); 
        greenSliderLine = Rectangle(-0.7f,-0.870f, 0.5f, 0.01f, Color(0.0f,0.0f,0.0f)); 
        blueSliderLine = Rectangle(-0.7f,-0.95, 0.5f, 0.01f, Color(0.0f,0.0f,0.0f)); 

        currentColorDisplay = Rectangle(.8f, -0.75f, 0.25f, 0.25f, getCurrentColor());


    }


    Color getCurrentColor(){
        redValue = (((red.getX() - (-0.7)) / (-0.2 - (-0.7))));
        greenValue = (((green.getX() - (-0.7)) / (-0.2 - (-0.7))));
        blueValue = (((blue.getX() - (-0.7)) / (-0.2 - (-0.7))));

        currentColor = Color(redValue, greenValue,blueValue);
        
        return currentColor;
    }
    
    void handleMouseClick(float x, float y){
        if (red.isClicked(x, y) && x >= -0.7 && x <= -0.2) {
            red.setX(x);
            getCurrentColor();
            redValue = (((red.getX() - (-0.7)) / (-0.2 - (-0.7))));
            
        }
        else if (green.isClicked(x, y) && x >= -0.7 && x <= -0.2) {
            green.setX(x);
            greenValue = (((green.getX() - (-0.7)) / (-0.2 - (-0.7))));
        }
        else if (blue.isClicked(x, y) && x >= -0.7 && x <= -0.2) {
            blue.setX(x);
            blueValue = (((blue.getX() - (-0.7)) / (-0.2 - (-0.7))));
        }
        currentColorDisplay.setColor(Color(redValue, greenValue, blueValue));
        
    }
    ///MAKE PRIVATE



    void draw(){
        area.draw();

        redSliderLine.draw();
        greenSliderLine.draw();
        blueSliderLine.draw();
        
        red.draw();
        green.draw();
        blue.draw();

        currentColorDisplay.draw();



    }



    bool contains(float x, float y){
        return area.contains(x, y);
    }





};


/*.   
    Your code goes here
*/

#endif