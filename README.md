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
	$ node-waf configure build
	$ coffee scripts/tests

If you want to make changes to the API:

	$ npm install -g bea
	$ cd bea 
	$ bea opencv.bea -f -o ../src
	$ cd ..
	$ node-waf configure build