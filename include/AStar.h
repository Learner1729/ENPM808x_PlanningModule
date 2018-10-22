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
 * @file AStar.h
 * @version 1.0
 * @author Ashish Patel
 * @brief This header file is used to implement AStar algorithm
 *
 * Given a occupancy matrix of an environment in form of a txt file, along with
 * start point and end point, this class can compute a smallest path avoiding 
 * the static obstacles to reach the desired location, if it's possible. 
 * The output generated is a path, from start point to end point, or a message 
 * stating that the "Failed! Path can't be found."
 *
 * @last-modified 10-22-2018
 */

#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_

// C++ header file
#include <list> 
#include <string>
#include <vector>
#include <memory>

// User defined header file
#include "Nodes.h"
#include "VisualizeMapSDL.h"

class AStar : public Nodes {
public:
  /**
   * @brief AStar default constructor
   * @param none
   * @return none
   */
  AStar();

  /**
   * @brief AStar parameterized constructor
   * @param reference to a string variable named mapFile, to provide path to
   *        input file
   * @return none
   */
  AStar(std::string &mapFile);
  
  /**
   * @brief AStar parameterized constructor
   * @param reference to a string variable named mapFile, to provide path to
   *        input file
   * @param w, integer type, provide width_ dimension of the map
   * @param h, integer type, provide height_ dimension of the map
   * @return none
   */
  AStar(int w, int h, std::string &mapFile);
  
  /**
   * @brief AStar destructor
   * @param none
   * @return none
   */
  ~AStar();

  /**
   * @brief Member function used to generate Occupancy Matrix
   *
   * Reading a occupancy matrix from a txt file and storing it in the 2D Vector
   *
   * @param none
   * @return none
   */
  void generateMap();

  /**
   * @brief Function used to get the status of the window
   * @param none
   * @return bool, status of closed_ member variable of VisualizeMapSDL class
   *         if return true, window gets closed
   *         if return false, window remains open
   */
  bool inloop() const;
  
  void computePath();
  bool sort(const Nodes &, const Nodes &);
  bool checkNodeID() const;

private:
  // variable to define map dimensions
  int width_{640};
  int height_{640};

  // variable to define coordinates of start position
  int xStart_{10};
  int yStart_{10};

  // variable to define coordinates of goal position
  int xGoal_{620};
  int yGoal_{460};

  // variable to store file path
  std::string mapFileName_{"../input/Map_1.txt"};

  // variable to store occupancyMatrix
  std::vector< std::vector<int> > occupancyMatrix_;

  // variable to store openNodes that needs to be travelled
  std::list<Nodes> openSet_;

  // object of class VisualizeMapSDL to link VisualizeMapSDL class
  std::unique_ptr<VisualizeMapSDL> visualize_{nullptr};
};

#endif // INCLUDE_ASTAR_H_