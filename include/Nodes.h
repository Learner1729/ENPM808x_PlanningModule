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
 * @file Nodes.h
 * @version 1.0
 * @author Ashish Patel
 * @brief This header file is used to declare all the member variables of Nodes 
 * Class
 *
 * The Nodes class works as an encapsulation of all the data variables and member 
 * functions related to a particular Node, which can be used by AStar class to  
 * implement planning algorithm. The path from start position to end position 
 * is given by sets of Nodes which share below common variables and member
 * functions.
 *
 * @last-modified 10-20-2018
 */

#ifndef INCLUDE_NODES_H_
#define INCLUDE_NODES_H_

class Nodes {
public:
  Nodes();
  ~Nodes();
  void computeHeuristic();
  void computeCostToCome();
  void computeTotalCost();
  void checkNode();
  
protected:
  bool nodeID_ = false;
  int parentID_ = 0;
  double totalCost_ = 0.0;
  double costToCome_ = 0.0;
  double heuristicCost_ = 0.0;
  int xPose_ = 0 ;
  int yPose_ = 0 ;
};

#endif // INCLUDE_NODES_H_