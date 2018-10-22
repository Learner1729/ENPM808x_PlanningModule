/**
 * MIT License
 *
 * Copyright (c) 2018 Ashish Patel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 */

/**
 * @file main.cpp
 * @version 1.0
 * @author Ashish Patel
 * @brief Initial file for path finding demo module
 *
 * This file is used to demonstrate the AStar algorithm.
 *
 * @last-modified 10-22-2018
 */

// C++ header file
#include <iostream>

// User-defined header file
#include "AStar.h"

int main() {
  std::cout << "======================================" << std::endl;
  std::cout << "Implementing A* path finding algorithm" << std::endl;
  std::cout << "======================================" << std::endl;
  std::cout << std::endl;

  // Update it, according to the MAP you want to use
  // std::string filePath = "../input/Map_2.txt";
  // AStar pathFinding(filePath);

  AStar pathFinding;
  pathFinding.generateMap();
  while(!pathFinding.inloop()) {
  }
  return 0;
}
