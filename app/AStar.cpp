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
 * @file AStar.cpp
 * @version 1.0
 * @author Ashish Patel
 * @brief This file is used to define the member functions to implement AStar 
 * algorithm.
 *
 * Given a occupancy matrix of an environment in form of a txt file, along with
 * start point and end point, this class can compute a smallest path avoiding 
 * the static obstacles to reach the desired location. The output generated is 
 * a path, from start point to end point, or a message stating that the 
 * "Failed! Path can't be found."
 *
 * @last-modified 10-22-2018
 */

// C++ header files
#include <vector>
#include <string>
#include <fstream> // for reading file
#include <cstdlib> // for call system to stop
#include <iostream>

// User-defined header file
#include "AStar.h"

/**
 * @brief AStar default constructor
 * @param none
 * @return none
 */
AStar::AStar() : visualize_(std::make_unique<VisualizeMapSDL>()) {
  std::cout << "[LOG]:Initializing A* object using default constructor";
  std::cout << std::endl;
  // Since we are reading occupancyMatrix from a file which is basically a 
  // matrix who's size is given by width_ & height_ variable defined above,
  // this help's us in pre-sizing the vector.
  // pre-sizing a 2D Matrix of default size width_ x height_  
  occupancyMatrix_.resize(height_,std::vector<int>(width_));
}

/**
 * @brief AStar parameterized constructor
 * @param reference to a string variable named mapFile, to provide path to
 *        input file
 * @return none
 */
AStar::AStar(std::string &mapFile) : mapFileName_(mapFile), 
  visualize_(std::make_unique<VisualizeMapSDL>()) {
  std::cout << "[LOG]:Initializing A* object using parameterized constructor";
  std::cout << std::endl;
  occupancyMatrix_.resize(width_,std::vector<int>(height_));
}

/**
 * @brief AStar parameterized constructor
 * @param reference to a string variable named mapFile, to provide path to
 *        input file
 * @param w, integer type, provide width_ dimension of the map
 * @param h, integer type, provide height_ dimension of the map
 * @return none
 */
AStar::AStar(int w, int h, std::string &mapFile) : 
  width_(w), height_(h), mapFileName_(mapFile), 
  visualize_(std::make_unique<VisualizeMapSDL>(w, h)) {
  std::cout << "[LOG]:Initializing A* object using parameterized constructor";
  std::cout << std::endl;
  occupancyMatrix_.resize(width_,std::vector<int>(height_)); 
}

/**
 * @brief AStar destructor
 * @param none
 * @return none
 */
AStar::~AStar() {
  std::cout << "[LOG]:A* destructor called" << std::endl;
}

/**
 * @brief Member function used to generate Occupancy Matrix
 *
 * Reading a occupancy matrix from a txt file and storing it in the 2D Vector
 *
 * @param none
 * @return none
 */
void AStar::generateMap() {
  std::cout << "[LOG]:Generating occupancy matrix by reading input text file"; 
  std::cout << std::endl;
  // ifstream is used for reading files
  // we will read from a file stored in mapFileName_ 
  std::ifstream inFile; 

  // temporary variable to store int value
  auto temp = 0;

  // open the file stream
  inFile.open(mapFileName_);

  // if we couldn't open the input file stream for reading
  if(!inFile) {
    std::cout << "[FAILED]: Couldn't open the file" << std::endl;
    exit(EXIT_FAILURE); // call system to stop
  }
  else {
    // while there's still stuff to read
    while(inFile) {
      // read occupancy matrix from the file into a 2D vector
      for(auto i=0; i<height_; i++) {
        for(auto j=0; j<width_; j++) {
          inFile >> temp;
          occupancyMatrix_[i][j] = temp;
          if(!temp) {
            visualize_-> drawPixel(j, i, 0);
          }
        }
      }
    }
  }

  // draw start location
  visualize_ -> drawPixel(xStart_, yStart_, 1);
  // draw goal location
  visualize_ -> drawPixel(xGoal_, yGoal_, 2);
  // update the screen
  visualize_ -> updateWindow();
  
  // std::cout << "Printing the occupancy Matrix:" << std::endl;
  //  for(auto i=0; i<width_; i++) {
  //    for(auto j=0; j<height_; j++) { 
  //      std::cout << occupancyMatrix_[i][j] << std::flush;
  //    }
  //  std::cout << std::endl;
  //  }
}

/**
 * @brief Function used to get the status of the window
 * @param none
 * @return bool, status of closed_ member variable of VisualizeMapSDL class
 *         if return true, window gets closed
 *         if return false, window remains open
 */
bool AStar::inloop() const {
  visualize_->detectEvent();
  return visualize_->isClosed();
}

void AStar::computePath() {
}

bool AStar::sort(const Nodes &, const Nodes &) {
  return true;
}

bool AStar::checkNodeID() const {
  return true;
}