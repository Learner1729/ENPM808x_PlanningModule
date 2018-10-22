/**
 * MIT License
 *
 * Copyright (c) 2018 Ashish Patel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the 
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE
 */

/**
 * @file VisualizeMapSDL.cpp
 * @version 1.0
 * @author Ashish Patel
 * @brief This file is used define member functions of VisualizeMapSDL class.
 *
 * VisualizeMapSDL class is used to Visualize the 2D map of an environment.
 * Given a Occupancy matrix, and dimensions of the map it draws the 2D map 
 * of an environment. It doesn't have any role in implementing planning
 * algorithm. It is only used for showing visual demo of AStar algorithm.
 *
 * @last-modified 10-22-2018
 */

// C++ header file
#include <iostream>

// User-defined header file
#include "VisualizeMapSDL.h"

/**
 * @brief VisualizeMapSDL default constructor
 *
 * Used when object of the class doesn't need to assign values to member
 * variables. Internally, calls init member function to initialize the 
 * properties used to create and update window screen.
 *
 * @param none
 * @return none
 */
 VisualizeMapSDL::VisualizeMapSDL() {
  std::cout << "[LOG]:Initializing VisualizeMapSDL object using default ";
  std::cout << "constructor" << std::endl;
  // Here, the variable closed_ is flag which determines whether the window is 
  // closed or not. If init() functions return true that means it's able to 
  // create window or renderer or both then closed_ will be equal to false and
  // if it fails to initialize closed_ will be equal to true.
  closed_ = !init();
 }

/**
 * @brief VisualizeMapSDL parameterized constructor
 *
 * Used in a case when different values are needed to be assigned to member 
 * variables. Internally, calls init member function to initialize the 
 * properties used to create and update window screen.
 *
 * @param width: used to set the width of the window
 * @param height: used to set the height of the window
 * @return none
 */
VisualizeMapSDL::VisualizeMapSDL(int width, int height) : 
  screenWidth_(width), screenHeight_(height) {
    std::cout << "[LOG]:Initializing VisualizeMapSDL object using ";
    std::cout << "parameterized constructor" << std::endl;
    closed_ = !init();
}

/**
 * @brief VisualizeMapSDL destructor 
 *
 * Used to destroy SDL objects created.
 *
 * @param none
 * @return none
 */
VisualizeMapSDL::~VisualizeMapSDL() {
  std::cout << "[LOG]:Destroying SDL object" << std::endl;
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

/**
 * @brief Initialize SDL properties to create and update window screen.
 * @param none
 * @return none
 */
bool VisualizeMapSDL::init() {
  std::cout << "[LOG]:SDL init process started..." << std::endl;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "[FAILED]:To initialize SDL." << std::endl;
    return false;
  }

  window_ = SDL_CreateWindow(
    // SDL library is return in a C language So, we need to use c_str() 
    // function to convert character array into string
    title_.c_str(),
    // position of the screen... x cooridinate 
    SDL_WINDOWPOS_CENTERED,
    // position of the screen... y cooridinate
    SDL_WINDOWPOS_CENTERED,
    screenWidth_,
    screenHeight_,
    // SDL flags... like SDL_WINDOW_RESIZEABLE
    // I haven't used any flag 
    0
  );

  // contion to check whether window is created successfully or not
  if(window_ == nullptr) {
    std::cout << "[FAILED]:To create window." << std::endl;
    return false;
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  if(renderer_ == nullptr) {
    std::cout << "[FAILED]:To create renderer." << std::endl;
    return false;
  }

  clear();
  
  return true;
}

/**
 * @brief function to detect window events like mouse click & key press
 * @param none
 * @return none
 */
void VisualizeMapSDL::detectEvent() {
  std::cout << "[LOG]:Detect Event" << std::endl;
  // declaring event variable of SDL_Event type to detect any event on the
  // window
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      // SDL_QUIT event is called when we click on the close button of the 
      // window
      case SDL_QUIT:
        // flag to update to close the window
        closed_ = true;
        break;
      default:
        break;
    }
  }
}

/**
 * @brief function which is used to put things on the screen
 * @param none
 * @return none
 */
void VisualizeMapSDL::clear() const {
  std::cout << "[LOG]:Clear function" << std::endl;
  // set the color
  // Parameter 1: renderer_ object
  // Parameter 2,3,4,5: R,G,B,Alpa respectively: value range from 0-255
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255); // set black background
  // clear the entire screen to our selected color
  SDL_RenderClear(renderer_);
  // updateWindow();
}

/**
 * @brief function to delay the window update speed
 * @param none
 * @return none
 */
void VisualizeMapSDL::callDelay() const {
  std::cout << "[LOG]:Delay" << std::endl;
  SDL_Delay(delay_);
}

/**
 * @brief function used to draw point on the window
 * @param xPos, integer type, denotes x coordinates of a pixel on the window
 * @param yPos, integer type, denotes y coordinates of a pixel on the window
 * @param selectColor, integer type, value: 1,2,3
 *        1: To select color GREEN (Used for Start point)
 *        2: To select color RED (Used for End point)
 *        3: To select color BLUE (Used to draw path)
 *        Default: default color WHITE (Used for obstacles)
 * @return none
 */
void VisualizeMapSDL::drawPixel(int xPos, int yPos, int selectColor) {
  std::cout << "[LOG]:Pixel Manipulation" << std::endl;
  switch (selectColor) {
    case 1:
      SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
      break;
    case 2:
      SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
      break;    
    case 3:
      SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255);
      break;
    default:
      SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
      break;  
  }
  SDL_RenderDrawPoint(renderer_, xPos, yPos);
}

/**
 * @brief function to update the screen
 * @param none
 * @return none
 */
void VisualizeMapSDL::updateWindow() const {
  std::cout << "[LOG]:Update Window" << std::endl;
  // Up until now everything was drawn behind the scenes.
  // This will show the new contents of the window.
  SDL_RenderPresent(renderer_);
}

/**
 * @brief Function used to set the update rate at which windows should be 
 *        updated.
 * @param delayMilliSeconds, integer type, stores the delay time
 * @return none
 */
void VisualizeMapSDL::setDelay(int delay) {
  delay_ = delay;
}