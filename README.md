Opencvjs

Purpose 
=======
Expose opencv to the node environment.

Features
======
	
	- cv::Point, cv::Size, cv::Rect, etc replaced by object notation:
		Point -> {x: 0, y:0}, Size -> {width: 33, height: 33}

	- Checks the types of parameters as well as ranges of values on each native call (harder to crash app from script)
	- Friendly exception messages on invalid parameters 
	

Installation
============

	npm install opencv

Example
=======

	cv = require 'opencv'


Building on MacOS X
====================

	$ brew install opencv --build32
	$ npm install -g opencv-node
	$ coffee scripts/tests


Building on Windows:
	1. OpenCV must be installed. Download latest version from http://sourceforge.net/projects/opencvlibrary/files/latest/download
	2. Extract to a folder, eg C:\OpenCV
	3. Open a command prompt and set the environment variable OPENCV_ROOT:

			set OPENCV_ROOT=C:/OpenCV

	4. Install opencv-node with npm:

			npm install -g opencv-node


API Differences

Some functions have a more js-friendly API/syntax. 
The void functions which return their output in an argument passed by reference, return the result directly:

	cv::split returns an Array and takes only 1 argument
	cv::HoughCircles returns an Array
	cv::HoughLines returns an Array
	cv::cornerSubPix returns an Array

	* others?