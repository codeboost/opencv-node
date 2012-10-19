cv = require './opencv'
keypress = require 'keypress'

src = cv.imread "lena.jpg", 1
return console.log 'Error opening' if src.empty



gray = new cv.Mat src.size, src.type
eqImg = new cv.Mat src.size, src.type

cv.cvtColor src, gray, cv.CV_RGB2GRAY
cv.equalizeHist gray, eqImg
result = src.clone()


cascade = new cv.CascadeClassifier

#The 'data' folder from opencv considered to be in current directory 
if not cascade.load 'data/haarcascades/haarcascade_eye.xml'
		console.log 'Cascade load failed'
		return


faces = cascade.detectMultiScale eqImg, 1.1, 3, 0, {width: 20, height: 20}


for rect in faces
	cv.rectangle result, {x: rect.x, y: rect.y}, {x: rect.x + rect.width, y:rect.y + rect.height}, [255, 0, 0], 2

cv.imshow "result_img", result

keypress process.stdin
process.stdin.on 'keypress', (char, key) ->
	if key.name == 'escape'
		console.log 'Stopping.'
		process.exit 0

process.stdin.setRawMode true
process.stdin.resume()		
console.log 'Press ESC to stop.'

