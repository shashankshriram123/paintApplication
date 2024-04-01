#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"

#include "Button.h"

enum Tool {PENCIL, ERASER, SQUARE, MOUSE, TRASH, CIRCLE, TRIANGLE, RHOMBUS};

class Toolbar {

    Rectangle area;
    Texture mouseButton;
    Texture pencilButton;
    Texture eraserButton;
    Texture squareButton;
    Tool selectedTool;
    Texture trashButton;
    Texture circleButton;
    Texture triangleButton;
    Texture rhombusButton;
    Button forward;
    Button backward;
    

    bool sendforward;
    bool sendbackward;

    void setSendBackward(bool value){
        sendbackward = value;
    }
    void setSendForward(bool value){
        sendforward = value;
    }
    



    void deselectAll(){
        mouseButton.deselect();
        pencilButton.deselect();
        eraserButton.deselect();
        squareButton.deselect();
        trashButton.deselect();
        circleButton.deselect();
        triangleButton.deselect();
        rhombusButton.deselect();
        forward.release();
        backward.release();

    }

public:
    Toolbar(){
        area = Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, Color(0.8f, 0.8f, 0.8f));
        mouseButton = Texture("assets/mouse.png", -1.0f, 1.0f, 0.2f, 0.2f);
        pencilButton = Texture("assets/pencil.png", -1.0f, 0.8f, 0.2f, 0.2f);
        eraserButton = Texture("assets/eraser.png", -1.0f, 0.6f, 0.2f, 0.2f);
        squareButton = Texture("assets/square.png", -1.0f, 0.2f, 0.2f, 0.2f);
        trashButton = Texture("assets/trash.png", -1.0f, 0.4f, 0.2f,0.2f);
        circleButton = Texture("assets/circle.png", -1.0f, 0.0f, 0.2f,0.2f);
        triangleButton = Texture("assets/triangle.png", -1.0f, -0.2f, 0.2f, 0.2f);
        rhombusButton = Texture("assets/rhombus.png", -1.0f, -0.4f, 0.2f, 0.2f);
//   clearButton = Button("Clear", 0.6f, -0.8f);
        forward = Button(" < ", -1.0f, -0.6f);
        backward = Button(" > ", -1.0f, -0.8f);

        selectedTool = PENCIL;
        pencilButton.select();
    }

    // getters
    Tool getSelectedTool() {
        return selectedTool;
    }

    bool getForward(){return sendforward;}
    bool getBackward(){return sendbackward;}

    // setters
    void selectMouse() {
        deselectAll();
        mouseButton.select();
        selectedTool = MOUSE;
    }

    void selectPencil() {
        deselectAll();
        pencilButton.select();
        selectedTool = PENCIL;
    }

    void selectEraser() {
        deselectAll();
        eraserButton.select();
        selectedTool = ERASER;
    }

    void selectSquare() {
        deselectAll();
        squareButton.select();
        selectedTool = SQUARE;
    }

    void selectTrash(){
        deselectAll();
        trashButton.select();
        selectedTool = TRASH;    
    }

    void selectCircle(){
        deselectAll();
        circleButton.select();
        selectedTool = CIRCLE;
    }
    void selectTriangle(){
        deselectAll();
        triangleButton.select();
        selectedTool = TRIANGLE;
    }
    void selectRhombus(){
        deselectAll();
        rhombusButton.select();
        selectedTool = RHOMBUS;
    }

    void handleMouseClick(float x, float y){
        if (mouseButton.contains(x, y)){
            selectMouse();
        }
        else if (pencilButton.contains(x, y)){
            selectPencil();
        }
        else if (eraserButton.contains(x, y)){
            selectEraser();
        }
        else if (squareButton.contains(x, y)){
            selectSquare();
        }
        else if (trashButton.contains(x,y)){
            selectTrash();
        }
        else if(circleButton.contains(x,y)){
            selectCircle();
        }
        else if(triangleButton.contains(x,y)){
            selectTriangle();
        }
        else if(rhombusButton.contains(x,y)){
            selectRhombus();
        }
        else if(forward.isClicked(x,y)){
            forward.press();
            setSendForward(true);
        }
        else if(backward.isClicked(x,y)){
            backward.press();
            setSendBackward(true);
        }
    }

    void draw(){
        area.draw();
        mouseButton.draw();
        pencilButton.draw();
        eraserButton.draw();
        squareButton.draw();
        trashButton.draw();
        circleButton.draw();
        triangleButton.draw();
        rhombusButton.draw();
        forward.draw();
        backward.draw();
        
        forward.release();
        setSendForward(false);
        backward.release();
        setSendBackward(false);
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif