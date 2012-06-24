_ = require('underscore')
var opencvjs = require('./build/Release/addon.node');
_.extend(this, opencvjs);

var cv = opencvjs.OpenCV

console.log(this)


function ok(expr, message){
	
	if (expr !== true)
		log("FAILED: " + message);
	else
		log("PASSED: " + message);
}

function mustThrow(name, fn){
	
	var excepted = false;
	
	try{
		fn();
	}
	catch (e){
		excepted = true; 
	}
	
	if (!excepted)
		ok(false, "Exception not thrown for '" + name + "'");
	else
		ok(true, "Exception thrown for '" + name);
}

function test(name, fnTest){
	
	log("*****");
	log(name);
	try{
		fnTest();
	} catch (e){
		ok(false, "Exception thrown for '" + name + "': " + e.message);
	}
}

function SAME_WIDTH(src, dst){return src.width === dst.width;}

function SAME_HEIGHT(src, dst){return src.height === dst.height;}

function SAME_WIDTH_HEIGHT(src, dst){return src.width === dst.width && src.height === dst.height;}
function SAME_WIDTH_HEIGHT_TYPE(src, dst){return SAME_WIDTH_HEIGHT(src, dst) && src.type === dst.type;}

function SAME_EVERYTHING(src, dst){

	return SAME_WIDTH_HEIGHT_TYPE (src, dst) 
	&& src.channels === dst.channels 
	&& src.depth === dst.depth
	&& src.total === dst.total 
	&& src.isContinuous === dst.isContinuous
	&& src.elemSize === dst.elemSize
	&& src.empty === dst.empty
}

function init(width, height, format){

	log("Starting tests");
	
	var srcMat = new Mat({width: width, height: height}, format);
	
	srcMat.setTo([0, 0, 0]);
	
	test("createMat", function(){
	
		mustThrow("new Mat(156, undefined)", function(){
			new Mat(156, undefined);
		});
	
		var mat1 = new Mat(155, 156);
				
		ok(mat1.width == 156 && mat1.height == 155, "Mat1 width/height");
		ok(mat1.type == CV_8UC3, "Type of mat created with int parameters");
		
		cv.discardMats(mat1);
		
		mat1 = new Mat(srcMat);
		
		ok(mat1.width === srcMat.width && 
		   mat1.height === srcMat.height && 
		   mat1.type === srcMat.type && 
		   mat1.depth === srcMat.depth && 
		   mat1.channels === srcMat.channels, "Width/height/channels/depth of matrix created with Mat parameter"
		   );
		 
		cv.discardMats(mat1);
		mat1 = new Mat({width: 123, height: 124}, CV_8UC4);
		
		ok(mat1.width == 123 && mat1.height == 124, "Width/height of Mat created with Size param");
		ok(mat1.type == CV_8UC4, "Type of mat created with size param")
		
		cv.discardMats(mat1);
		
		mat1 = new Mat(srcMat, {x: 20, y:20, width: 100, height: 100});
		
		ok(mat1.type == srcMat.type, "Type of matrix created with Mat and RECT params");
		ok(mat1.width == 100, "Width of mat created with RECT param");
		ok(mat1.height == 100, "Height of mat created with RECT param");
		
		mustThrow("new Mat(100)", function(){
			var mat1 = new Mat(100);
		});
		
		mustThrow("new Mat(100, 0)", function(){
			var mat1 = new Mat(100, 0);
		});

		mustThrow("new Mat(-100, 100)", function(){
			var mat1 = new Mat(-100, 0);
		});
		
		mustThrow("new Mat({width: 324}, 12)", function(){
		
			var mat1 = new Mat({width: 324}, 12);
		});
		
	});

	test("range", function(){
			
		ok(srcMat.channels === 3, "3 channels");
		
		var myRange = srcMat.colRange(10, 20);
		
		mustThrow("Invalid col range", function(){
			srcMat.colRange(0, width + 1);
		});
		
		mustThrow("Invalid col range 2", function(){
			srcMat.colRange(10, 2);
		});
		
		mustThrow("Invalid col range 3", function(){
			srcMat.colRange(-21, width);
		});

		var colsMat = srcMat.colRange(0, width);
		
		ok(colsMat.width == width, "Width must be equal");
		ok(colsMat.height == height, "Height must be equal");
		
		cv.discardMats(colsMat);
		
		mustThrow("Invalid row range", function(){
			srcMat.rowRange(0, height + 1);
		});
		
		
		mustThrow("Invalid row range 2", function(){
			srcMat.rowRange(10, 2);
		});
		
		
		mustThrow("Invalid row range 3", function(){
			srcMat.rowRange(-21, width);
		});
	});
	
	test("clone", function(){
	
			var cloned = srcMat.clone(); 
			
			log("Sizes: "  + srcMat.size.width + "x" + srcMat.size.height + "-" + cloned.size.width + "x" + cloned.size.height);
			ok(SAME_EVERYTHING(srcMat, cloned), "Cloned matrix must be identical");
			
	});
	
	test("copyTo", function(){
		
		var destMat;
		
		mustThrow("Copy to undefined var", function(){
			srcMat.copyTo(destMat);
		});
		
		destMat = new Mat(100, 100, CV_8UC3);
		srcMat.copyTo(destMat);
		
		ok(SAME_EVERYTHING(srcMat, destMat), "Copy to different size matrix");
		
		cv.discardMats(destMat);
		
		destMat = new Mat(height, width, CV_8UC4);
		
		srcMat.copyTo(destMat);
		ok(SAME_EVERYTHING(srcMat, destMat), "Copy to different depth matrix");
		
		mustThrow("Copy to RECT argument", function(){
			srcMat.copyTo({width: 1090, height: 33});
		});

		cv.discardMats(destMat);
		
		destMat = new Mat(height, width, CV_8UC3);
		
		ok(srcMat.copyTo(destMat) === srcMat, "Copy to good matrix");
		
		cv.discardMats(destMat);
	});
	
	test('setTo', function(){
		
		mustThrow("setTo(undefined)", function(){
			srcMat.setTo();
		});
		
		mustThrow("setTo(1)", function(){
			srcMat.setTo(1);
		});
		
		mustThrow("setTo({width: 1900, height: 1000})", function(){
			srcMat.setTo({width: 1900, height: 1000});
		});

		mustThrow("setTo([])", function(){
			srcMat.setTo([]);
		});
		
		mustThrow("setTo([1, 2])", function(){
			srcMat.setTo([1, 2]);
		});

		mustThrow("setTo([1, 2, {one: 1}])", function(){
			srcMat.setTo([1, 2, {one: 1}]);
		});
		
		ok(srcMat == srcMat.setTo([1, 2, 2]), "srcMat == srcMat.setTo([1, 2, 2])");
		
		srcMat.setTo([0, 0, 0]);
		
		ok(srcMat[0] == 0, "mat[0] == 0");
		ok(srcMat[192] == 0, "mat[192] == 0");
		
		srcMat.setTo([123, 253, 99]);
		
		ok(srcMat[0] == 123, "mat[0] == 123");
		ok(srcMat[1] == 253, "mat[1] = 253");
		ok(srcMat[2] == 99, "mat[2] = 99");
		
		ok(srcMat[3] == 123, "mat[3] == 123");
		ok(srcMat[4] == 253, "mat[4] = 253");
		ok(srcMat[5] == 99, "mat[5] = 99");
		
		srcMat[33] = 22;
		
		ok(srcMat[33] == 22, "mat[33] == 22");
	});
	
	test('mul', function(){
	
		mustThrow("mul(undefined)", function(){
			srcMat.mul(undefined);
		});
		
		mustThrow("mul({one: 1})", function(){
			srcMat.mul({one: 1});
		});
		
		var mulMat = new Mat(100, 100);
		
		mustThrow("mul(invalid size matrix)", function(){
			srcMat.mul(mulMat);
		});
		
		cv.discardMats(mulMat);
		
		mulMat = new Mat(srcMat.height, srcMat.width, srcMat.type);
		
		var newMat = srcMat.mul(mulMat);
		
		ok(SAME_WIDTH_HEIGHT_TYPE(newMat, srcMat), "Multiplied must have same w/h/t");
		

	});
	
	test('convertTo', function(){
	
		mustThrow('convertTo(undefined)', function(){
			srcMat.convertTo(undefined, 1);
		});
		
		mustThrow('convertTo(1)', function(){
			srcMat.convertTo(1, 1);
		});
		
		var dest = new Mat(1, 1, CV_8UC2);
		
		srcMat.convertTo(dest, CV_8UC2);
		
		ok(SAME_WIDTH_HEIGHT(srcMat, dest), "Same width height after convertTo");
		
		ok(dest.depth === srcMat.depth, "dest.depth === src.depth");
		
	});
	
	
	test('reshape', function(){
		
		var src = srcMat.clone();
		
		mustThrow('reshape(-1)', function(){
			src.reshape(-1);
		});
		
		mustThrow('reshape(1, -1)', function(){
			src.reshape(0, -1);
		});
		
		var res = src.reshape(0);
		
		ok(SAME_EVERYTHING(res, src), "reshaped must be a cloned src");
		
		cv.discardMats(res);
		res = src.reshape(1, 0);
		
		ok (res.width == src.width * 3, "Result width must be 3 * src.width?");
		
		
	});
}




init (320, 200, CV_8UC3);