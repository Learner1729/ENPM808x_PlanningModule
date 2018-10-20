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
 * @last-modified 10-20-2018
 */
 
#ifndef INCLUDE_VISUALIZEMAPSDL_H_
#define INCLUDE_VISUALIZEMAPSDL_H_

class VisualizeMapSDL {
public:
  VisualizeMapSDL(const std::string &, int width, int height);
  ~VisualizeMapSDL();
  void clear() const;
  void detectEvent();
  void callDelay() const;
  void drawPixel(int x, int y, int color);
  void updateWindow() const;

private: 
  bool init();

private:
  std::string title_;
  auto closed_{false};
  auto delay_{500};
  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
};

#endif // INCLUDE_VISUALIZEMAPSDL_H_