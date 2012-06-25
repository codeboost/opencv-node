Opencvjs


=Purpose=
Expose opencv to the node environment.


=Building on MacOS X=
	$ brew install opencv --build32
	$ node-waf configure build
	$ coffee scripts/tests

If you want to make changes to the API:

	$ npm install -g bea
	$ cd bea 
	$ bea opencv.bea -f -o ../src
	$ cd ..
	$ node-waf configure build