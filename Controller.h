#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GL/gl.h>
#include "AppController.h"
#include "ColorSelector.h"
#include "Toolbar.h"
#include "Canvas.h"
#include "ColorPicker.h"


struct Controller : public AppController {
    Toolbar toolbar;
    Canvas canvas;
    ColorPicker colorPicker;

    Controller(){
       
        //
    }

    void leftMouseDown( float x, float y ){
        if (toolbar.contains(x, y)){
            
            toolbar.handleMouseClick(x, y);
            canvas.moveAndChange(toolbar.getSelectedTool(), colorPicker.getCurrentColor(), toolbar.getForward(), toolbar.getBackward());
            if(toolbar.getSelectedTool() == TRASH){
                canvas.clearScreen();
                canvas.clearScreen(toolbar.getSelectedTool());
            }
        }
        else if (canvas.contains(x, y)){
            canvas.handleMouseClick(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
        }
        else if (colorPicker.contains(x, y)){
            colorPicker.handleMouseClick(x, y);
        }
     
        //canvas.handleMouseMotion(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
    }

    void mouseMotion( float x, float y ) {
       // canvas.handleMouseMotion(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
        if (canvas.contains(x, y)){

            canvas.handleMouseMotion(x, y, toolbar.getSelectedTool(), colorPicker.getCurrentColor());
   
        }
        else if (colorPicker.contains(x, y)){

            colorPicker.handleMouseClick(x, y);
        }
    }

    void render(){
        canvas.draw();
        toolbar.draw();
        colorPicker.draw();
    }
};

#endif