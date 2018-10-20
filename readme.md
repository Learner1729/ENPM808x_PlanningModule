# ENPM808X: MidTerm Project 
*Building a path planning module for ACME Robotics*

[![Build Status](https://travis-ci.org/Learner1729/ENPM808x_PlanningModule_2.svg?branch=master)](https://travis-ci.org/Learner1729/ENPM808x_PlanningModule_2)
[![Coverage Status](https://coveralls.io/repos/github/Learner1729/ENPM808x_PlanningModule_2/badge.svg?branch=master)](https://coveralls.io/github/Learner1729/ENPM808x_PlanningModule_2?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---

## Table of Contents
- [License](#license)
- [Overview](#overview)
- [Reference Materials](#references)
- [Definitions](#define)
- [SIP Process with Sprint Plannig](#sip_process)
- [Class Diagram](#class)
- [Activity Diagram](#activity)
- [Dependencies](#packages)
- [Standard install via command-line](#implementation)
- [Building for code coverage](#code_coverage)

## <a name="license"></a> License
This project is under the [MIT License](./LICENSE)
```
Copyright (c) 2018 Ashish Patel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

```

## <a name="overview"></a> Overview 
This repo is a simple global path planning module, developed for ACME Robotics. Given an initial and final location, the module can compute shortest path using A* algorithm to reach the final location. The purpose of this project is to design a global path planning module that can be integrated to build a robotic system to navigate autonomously in a known environment. 

This repository implements a C++ A* algorithm as a global planner along with:
- cmake
- googletest

## <a name="references"></a> Reference Materials
WorkUnderProgress

## <a name="define"></a> Definitions
WorkUnderProgress

## <a name="sip_process"></a> SIP Process with Sprint Planning
Sprint Planing is provided in the google doc file, click on the link to access it: [Sprint Planning](https://docs.google.com/document/d/1hVSxTpi_4b7w9EUjY-iULoq4kF_cVz01dV_noVgrym0/edit?usp=sharing)

The SIP Process followed is detailed in a spreadsheet, click on the link to access it: [SIP](https://docs.google.com/spreadsheets/d/1qlEn87uNemp48aORazFHT43D9IT_IYHOCUPLLSN8vvQ/edit?usp=sharing)

## <a name="class"></a> Class Diagram
<p align="center">
<a target="_blank"><img src=""
alt="WorkUnderProgress" width="480" height="480" border="10" />
</a>
</p>

## <a name="activity"></a> Activity Diagram
<p align="center">
<a target="_blank"><img src=""
alt="WorkUnderProgress" width="480" height="720" border="10" />
</a>
</p>

## <a name="packages"></a> Dependencies
This module uses [SDL library](https://www.libsdl.org/), its a cross-platform development library designed to provide low level access to audio, keyboard, mouse and graphics hardware via OpenGL and Direct3D. It's written in C++ and works natively with C++. I will be using SDL version 2.0 for this project. It's license under [zlib license](https://www.libsdl.org/license.php), which unables me to use this library for any purpose, including commercial applications and can also be distributed freely. The only purpose of this library in this project is to provide visual demo of path planning algorithm.

Steps to download and install this package can be done following this simple [tutorial](http://wiki.libsdl.org/Installation).

## <a name="implementation"></a> Standard install via command-line
```
git clone --recursive https://github.com/Learner1729/enpm808x_planning_module
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## <a name="code_coverage"></a> Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.
