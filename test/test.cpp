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
 * @file test.cpp
 * @version 1.0
 * @author Ashish Patel
 * @brief The file contains GMocking implementation
 * @last-modified 11-30-2018
 */

// Including externally dependent library file used to create
// window for visualizing map of an environment
#include <SDL.h>

// Including google unit testing header files
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// User-defined header file
#include "VisualizeMapSDL.h"
#include "AStar.h"

// Using mock in the testing
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Ge;

// developing mock class 
class MockVisualMapSDL : public VisualizeMapSDL {
public:
  MOCK_METHOD0(init, bool());
  MOCK_CONST_METHOD0(isClosed, bool());
  MOCK_CONST_METHOD0(clear, void());
  MOCK_METHOD0(detectEvent, void());
  MOCK_CONST_METHOD0(callDelay, void());
  MOCK_METHOD3(drawPixel, void(int, int, int));
  MOCK_CONST_METHOD0(updateWindow, void());
  MOCK_METHOD1(setDelay, void(int));
};

TEST(Test, CanDrawSomething) {
  MockVisualMapSDL *visual = nullptr;
  AStar path(visual);
  //pathFinding.generateMap();
  //MockVisualMapSDL mocksdl;

  //while(!pathFinding.inloop()) {
  //}
  //return 0;
}
