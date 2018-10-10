# ENPM808X: MidTerm Project 
*Building a path planning module for ACME Robotics*

[![Build Status](https://travis-ci.org/Learner1729/enpm808x_planning_module.svg?branch=master)](https://travis-ci.org/Learner1729/enpm808x_planning_module)
[![Coverage Status](https://coveralls.io/repos/github/Learner1729/enpm808x_planning_module/badge.svg?branch=master)](https://coveralls.io/github/Learner1729/enpm808x_planning_module?branch=master)
---

## Table of Contents
- [License](#license)
- [Overview](#overview)
- [SIP Process with Sprint Plannig](#sip_process)
- [Class Diagram](#class)
- [Activity Diagram](#activity)
- [Dependencies](#packages)
- [Standard install via command-line](#implementation)
- [Building for code coverage](#code_coverage)

## <a name="license"></a> License
This project is under the [MIT License](./LICENSE)

## <a name="overview"></a> Overview 
This repo is a simple global path planning module, developed for ACME Robotics. Given an initial and final location, the module can compute shortest path using A* algorithm to reach the final location. The purpose of this project is to design a global path planning module that can be integrated to build a robotic system to navigate autonomously in a known environment. 

This repository implements a C++ A* algorithm as a global planner along with:
- cmake
- googletest

## <a name="sip_process"></a> SIP Process with Sprint Planning
Sprint Planing is provided in the google doc file, click on the link to access it:[Sprint Planning](https://docs.google.com/document/d/1hVSxTpi_4b7w9EUjY-iULoq4kF_cVz01dV_noVgrym0/edit?usp=sharing)

The SIP Process followed is detailed in a spreadsheet, click on the link to access it: [SIP](https://docs.google.com/spreadsheets/d/1vbUJpGiJZkUpezit9MyrZPyYVbuz8s5lXPCnxyJcH2M/edit?usp=sharing)

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
