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
 * @last-modified 10-20-2018
 */

// C++ header file
#include <iostream>

// User-defined header file
#include "VisualizeMapSDL.h"

VisualizeMapSDL::VisualizeMapSDL(const std::string &title, int w, int h) {
    std::cout << "[LOG] : Initialization Process Started" << std::endl;
    closed_ = !init();
  }

VisualizeMapSDL::~VisualizeMapSDL() {
  std::cout << "[LOG] : Destroying SDL objects" << std::endl;
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

bool VisualizeMapSDL::init() {
  return true;
}

void VisualizeMapSDL::clear() const {
  std::cout << "[LOG] : Clear function" << std::endl;
}

void VisualizeMapSDL::detectEvent() {
  std::cout << "[LOG] : Detect Event" << std::endl;
  SDL_Event event;
}

void VisualizeMapSDL::callDelay() const {
  std::cout << "[LOG] : Delay" << std::endl;
}

void VisualizeMapSDL::drawPixel(int x, int y, int selectColor) {
  std::cout << "[LOG] : Pixel Manipulation" << std::endl;
}

void VisualizeMapSDL::updateWindow() const {
  std::cout << "[LOG] : Update Window" << std::endl;
}
