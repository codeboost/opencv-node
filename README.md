
Building on MacOS X:
	$ brew install opencv --build32
	$ node-waf configure build


If you want to make changes to the API, bea must be installed:

	$ npm install -g bea
	#generate the C++ glue
	$ bea bea/opencv.bea -f
	$ node-waf configure build