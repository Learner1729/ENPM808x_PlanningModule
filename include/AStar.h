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
 * @last-modified 10-20-2018
 */

#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_

class AStar : public Nodes {
public:
  AStar();
  ~AStar();
  void generateMap();
  void computePath();
  bool sort(const Nodes &, const Nodes &);
  bool checkNodeID() const;
private:
  auto width_{640};
  auto height_{480};
  auto xStart_{10};
  auto yStart_{10};
  auto xGoal_{620};
  auto yGoal_{460};
  std::pair<int, int> occupancyMatrix_;
  std::list<Nodes> openSet_;
};

#endif // INCLUDE_ASTAR_H_