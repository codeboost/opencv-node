_ = require 'underscore'
cv = require './opencv'
keypress = require 'keypress'

hsvFrame = null
thresholded = null
thresholded2 = null
Mat = cv.Mat

#Base class for effects
class Effect
	name: "Untitled"
	constructor: ->
	runEffect: (frameIn, frameOut) ->
		@run frameIn, frameOut
		cv.putText(frameOut, @name, {x: 0, y: 50}, 	cv.FONT_HERSHEY_SIMPLEX , 1, [128, 255, 128], 2, 1);

#Apply 'negative' effect to the image
class Negative extends Effect
	name: "Negative"
	run: (frameIn, frameOut) ->	cv.bitwise_not frameIn, frameOut

#Make image black and white
class BlackAndWhite extends Effect
	name: "Black and white"
	constructor: (size, format) ->
		@tmp = new Mat size, cv.CV_8U
		@rgb = new Mat size, cv.CV_8UC3
		
	run: (frameIn, frameOut) -> 
		cv.cvtColor frameIn, @tmp, cv.CV_RGBA2GRAY
		cv.cvtColor @tmp, @rgb, cv.CV_GRAY2RGB
		cv.cvtColor @rgb, frameOut, cv.CV_RGB2RGBA

#Create a 'ghost' effect from the image
class EffectGhost extends Effect
	name: "Ghost"
	run: (frameIn, frameOut) ->
		cv.cvtColor frameIn, frameOut, cv.CV_RGBA2GRAY
		cv.bitwise_not frameIn, frameOut

#Detect the edges		
class Edges extends Effect
	name: "Edges"
	constructor: (size, format) ->
		@tmp = new Mat size, format
		@rgb = new Mat size, cv.CV_8UC3
	run: (frameIn, frameOut) ->
		cv
		.cvtColor(frameIn, @tmp, cv.CV_BGRA2GRAY)
		.GaussianBlur(@tmp, @tmp, {width: 7, height: 7}, 1.5, 1.5)
		.Canny(@tmp, @tmp, 3, 7);	
		
		cv.cvtColor @tmp, @rgb, cv.CV_GRAY2RGB
		cv.cvtColor @rgb, frameOut, cv.CV_RGB2RGBA

#Make image look old		
class Sepia extends Effect
	name: "Sepia"
	constructor: (size, format) ->
		@hsvImage = new Mat size, cv.CV_8U
		@tmp = new Mat size, cv.CV_8UC3
	run: (frameIn, frameOut) ->
		defaultH = 22;
		defaultS = 90;
		cv.cvtColor  frameIn, @hsvImage, cv.CV_BGR2HSV 
		components = cv.split @hsvImage
		components[0].setTo [defaultH, 0, 0]
		components[1].setTo [defaultS, 0, 0]
		cv.merge(components, @hsvImage);
		cv.cvtColor @hsvImage, @tmp, cv.CV_HSV2BGR
		cv.cvtColor @tmp, frameOut, cv.CV_RGB2RGBA
		
class Binarize extends Effect
	name: "Binarize"
	constructor: (size, format)->
		@binaryImage = null
		@tmpImage = new Mat
		@rgb = new Mat size, cv.CV_8UC3
	run: (frameIn, frameOut) ->
		#frameIn.copyTo frameOut
		cv.cvtColor frameIn, @tmpImage, cv.CV_RGBA2GRAY 
	
		if (!@binaryImage)
			@binaryImage = @tmpImage.clone();
			
		cv.threshold @tmpImage, @binaryImage, 50, 255, cv.CV_THRESH_BINARY
		cv.cvtColor @binaryImage, @rgb, cv.CV_GRAY2RGB
		cv.cvtColor @rgb, frameOut, cv.CV_RGB2RGBA
		
#This shows how to directly access the Mat pixels
class Mirror extends Effect
	constructor: (@size) ->
		@tmp = new Mat @size, cv.CV_8UC3
	name: "Mirror"
	run: (frameIn, frameOut) ->
		cv.cvtColor frameIn, @tmp, cv.CV_RGBA2RGB
		frame = @tmp
		frame.indexable();	#Note this call. Makes it possible to access the frame bytes with []
		bpp = 3
		frameWidth = frame.width
		frameHeight = frame.height
		
		halfsizes = frameWidth / 2
		frameBytes = frameWidth * bpp  - 1
		
		i = 0
		while i++ < frameHeight
			offset = i * frameWidth * bpp
			j = 0
			while j++ < halfsizes
				jBytes = offset + frameBytes - (j * 3)
				ojBytes = offset + (j * 3)
				  
				frame[jBytes - 2] = frame[ojBytes]
				frame[jBytes - 1] = frame[ojBytes+1]
				frame[jBytes] = frame[ojBytes+2]
				
		cv.cvtColor @tmp, frameOut, cv.CV_RGB2RGBA
		true

#detect an orange ball in the image and draw a circle around it.
#works, but accuracy is terrible
class DetectOrangeBall extends Effect
	name: "Orange ball"
	constructor: (@size) ->
		@hsvMin = [0, 50, 170]
		@hsvMax = [10, 180, 256]

		@hsvMin2 = [170, 50, 170]
		@hsvMax2 = [256, 180, 256]
		@hsvFrame = new Mat size, cv.CV_8U
		@thresholded = new Mat size, cv.CV_8U
		@thresholded2 = new Mat size, cv.CV_8U
		
	run: (frameIn, frameOut) ->
		frameIn.copyTo frameOut
		cv.cvtColor frameIn, @hsvFrame, cv.CV_BGR2HSV
		
		cv.inRange @hsvFrame, @hsvMin, @hsvMax, @thresholded
		cv.inRange @hsvFrame, @hsvMin2, @hsvMax2, @thresholded2
		
		cv.bitwise_or @thresholded, @thresholded2, @thresholded
		
		circles = cv.HoughCircles @thresholded, cv.CV_HOUGH_GRADIENT, 2, @thresholded.height/4, 100, 40, 20, 50
		@drawCircles circles, frameOut
	
	drawCircles: (circles, frameOut) ->
		_.each circles, (circle, i) ->
			center =
				x: Math.round circle[0]
				y: Math.round circle[1]
			cv.circle frameOut, center, Math.round(circle[2]), [255, 0, 0], 3, 8
			
			
class RotateImage extends Effect
	name: "Rotated"
	constructor: (@size, format) ->
		@rotAngle = 0
	run: (frameIn, frameOut) ->
		rotation = cv.getRotationMatrix2D({x: frameIn.width / 2, y: frameIn.height / 2}, @rotAngle++, 1);
		cv.warpAffine(frameIn, frameOut, rotation, frameIn.size);
		@rotAngle = (@rotAngle + 10) % 360;

class CircleDetector extends Effect
	constructor: ->
		@count = 0
		@lastDetection = new Date().getTime()
	hasCircle: (frameIn, frameOut) ->
		curTime = new Date().getTime()
		if curTime - @lastDetection < 3000
			@count = 0
			return false
		gray = new Mat
		cv.cvtColor frameIn, gray, cv.CV_RGBA2GRAY
		cv.GaussianBlur( gray, gray, {width: 9, height: 9}, 2, 2 )
		circles = cv.HoughCircles(gray, cv.CV_HOUGH_GRADIENT, 2, gray.rows/4, 200, 100 );
		
		has = _.any circles, (circle) ->
			circle[2] > 60 && circle[2] < 120

		if has then @count++ else @count = 0

		if @count >= 14
			@count = 0
			@lastDetection = new Date().getTime()
			return true
			
		return false

	drawCircles: (circles, frameOut) ->
		_.each circles, (circle, i) ->
			center =
				x: Math.round circle[0]
				y: Math.round circle[1]
			cv.circle frameOut, center, Math.round(circle[2]), [255, 0, 0], 3, 8
			
#Run all effects at once				
class NineEffects extends Effect
	name: "Nine effects"
	constructor: (size, format) ->
		@n = 9
		@efSize = 
			width: Math.floor(size.width / 3)
			height: Math.floor(size.height / 3)
		
		@effects = [	
			new Mirror(@efSize, format),
			new BlackAndWhite(@efSize, format),
			new Binarize(@efSize, format),
			new Edges(@efSize, format),
			new Sepia(@efSize, format),
			new Negative,
			new Mirror(@efSize, format),
			new DetectOrangeBall(@efSize, format),
			new RotateImage(@efSize, format)
			
		]
			
		@tmp = new Mat @efSize, cv.CV_8UC4
	
	run: (frameIn, frameOut) ->
		
		sFrameIn = cv.resizeImage frameIn, @efSize
	
		i = 0
		row = 0
		while row < 3
			col = 0
			while col < 3
				
				colStart = col * @efSize.width
				colEnd = col * @efSize.width + @efSize.width
				rowStart = row * @efSize.height
				rowEnd = row * @efSize.height + @efSize.height
				part = frameOut.colRange(colStart, colEnd).rowRange(rowStart, rowEnd)
				#console.log "#{i}. x = #{colStart}, y = #{rowStart}; width=#{part.width}, height=#{part.height}"
				#console.log 'Running ', @effects[i].name
				@effects[i].run sFrameIn, part
				col = col + 1
				i = i + 1
				true
			row = row + 1
		true

class EffectRunner
	constructor: (width, height, format) ->
		console.log "Init: #{width}x#{height}:#{format}"
		
		size = 
			width: width,
			height: height
		
		cv.namedWindow "output", 0
		
		@effects = [
			new NineEffects(size, format),
			new BlackAndWhite(size, format),
			new Binarize(size, format),
			new Edges(size, format),
			new Sepia(size, format),
			new Negative,
			new Mirror(size, format),
			new DetectOrangeBall(size, format),
			new RotateImage(size, format),
		]
		
		@ei = 0	#effect index
		@circleDetector = new CircleDetector
		true

	
	processFrame: (frameIn, frameOut) ->
		if frameIn.type != cv.CV_8UC4
			tmp = new Mat
			cv.cvtColor frameIn, tmp, cv.CV_RGB2RGBA
		else
			tmp = frameIn
		
			
		@effects[@ei].runEffect(tmp, frameOut)
		
		cv.imshow "output", frameOut
		true

	nextEffect: ->
		@ei = @ei + 1 
		@ei = @ei % @effects.length
	prevEffect: ->
		@ei = @ei - 1
		if @ei < 0 then @ei = @effects.length - 1



class Capturer
	constructor: ->
	go: ->
		@cap = new cv.VideoCapture 0
		if not @cap.isOpened()
			console.log 'Couldnt open video device'
			return false
		frame = new Mat()
		@cap.read frame
		@outFrame = new Mat {width:frame.width, height:frame.height}, cv.CV_8UC4
		@effectRunner = new EffectRunner frame.width, frame.height, frame.type
		@nextFrame()

	nextFrame: =>
		frame = new Mat
		@cap.read frame
		@effectRunner.processFrame frame, @outFrame
		process.nextTick @nextFrame


capturer = new Capturer()
capturer.go()

cv.closeOnEsc()

process.stdin.on 'keypress', (char, key) ->
	if key.name == 'space' or key.name == 'right'
		capturer.effectRunner.nextEffect()
	else if key.name == 'left'
		capturer.effectRunner.prevEffect()

console.log 'Press ESC to stop.'
console.log 'Press space or right/left keys to cycle through effects'