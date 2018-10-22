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
 * @file VisualizeMapSDL.h
 * @version 1.0
 * @author Ashish Patel
 * @brief This header file is used to Visualize the Map of an environment.
 *
 * VisualizeMapSDL class is used to Visualize the 2D map of an environment.
 * Given a Occupancy matrix, and dimensions of the map it draws the 2D map 
 * of an environment. It doesn't have any role in implementing planning
 * algorithm. It is only used for showing visual demo of AStar algorithm.
 * 
 * @last-modified 10-22-2018
 */
 
#ifndef INCLUDE_VISUALIZEMAPSDL_H_
#define INCLUDE_VISUALIZEMAPSDL_H_

// C++ header file
#include <string>

// Including externally dependent library file used to create
// window for visualizing map of an environment
#include <SDL.h>

class VisualizeMapSDL {
public:
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
  VisualizeMapSDL();
  
  /**
   * @brief VisualizeMapSDL parameterized constructor
   *
   * Used in a case when different values are needed to be assigned to member 
   * variables. Internally, calls default constructor which in turn calls init
   * member function to initialize the properties used to create and update
   * window screen.
   *
   * @param width: used to set the width of the window
   * @param height: used to set the height of the window
   * @return none
   */
  VisualizeMapSDL(int width, int height);

  /**
   * @brief VisualizeMapSDL destructor
   *
   * Used to destroy SDL objects created.
   *
   * @param none
   * @return none
   */
  ~VisualizeMapSDL();

  /**
   * @brief function to detect window events like mouse click & key press
   * @param none
   * @return none
   */
  void detectEvent();

  /**
   * @brief function which is used to put things on the screen
   * @param none
   * @return none
   */
  void clear() const;
  
  /**
   * @brief function to delay the window update speed
   * @param none
   * @return none
   */
  void callDelay() const;
  
  /**
   * @brief 
   * @param xPos, integer type, denotes x coordinates of the screen
   * @param yPos, integer type, denotes y coordinates of the screen
   * @param color, integer type, value: 1,2,3
   *        1: To select color for start position (GREEN)
   *        2: To select color for end position (RED)
   *        3: To select color to draw path (BLUE)
   *        Default: Obstacle, color for obstacles (BLACK)
   * @return none
   */
  void drawPixel(int xPos, int yPos, int color);

  /**
   * @brief function to update the screen
   * @param none
   * @return none
   */
  void updateWindow() const;

  /**
   * @brief Function used to set the update rate at which windows should be 
   *        updated.
   * @param delayMilliSeconds, integer type, stores the delay time
   * @return none
   */
  void setDelay(int delay);

  /**
   * @brief Function used to get the status of the window
   * @param none
   * @return bool, status of closed_ member variable
   */
  inline bool isClosed() const { 
    return closed_;
  }

private:
  /**
   * @brief Initialize SDL properties used to create and update window screen. 
   * @param none
   * @return none
   */
  bool init();

private:
  // variable used to give the title to our window
  std::string title_{"Environment"};

  // variable to define screen width, unit: number of pixels 
  int screenWidth_{640};
  
  // variable to define screen height, unit: number of pixels
  int screenHeight_{480}; 
  
  // variable used to keep track of whether the window is closed or not 
  bool closed_{false};
  
  // variable used to define the update rate at which window is to be updated
  // unit: milliseconds
  int delay_{1000};
  
  // SDL Window object is used to set all the properties related to window,
  // it's initialize to nullptr. It's property will be set using init
  // member function
  SDL_Window *window_{nullptr};

  // SDL Renderer is basically used to draw things on to the window
  SDL_Renderer *renderer_{nullptr};
};

#endif // INCLUDE_VISUALIZEMAPSDL_H_