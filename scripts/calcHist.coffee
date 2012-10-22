#Adaptation of the example found here:
#http://opencv.willowgarage.com/documentation/cpp/imgproc_histograms.html?highlight=calchist#calcHist
cv = require './opencv'
keypress = require 'keypress'

src = cv.imread "test.jpg", 1
return console.log 'Error opening file' if src.empty


hsv = new cv.Mat 
cv.cvtColor src, hsv, cv.CV_BGR2HSV

#quantize hue to 30 levels and saturation to 32 levels
hbins = 30
sbins = 32

histSize = [hbins, sbins]
hranges = [0, 180]
sranges = [0, 256]

ranges = [hranges, sranges]

channels = [0, 1]

mask = new cv.Mat
hist = new cv.Mat

console.log 'Here'

cv.calcHist [hsv], channels, mask, hist, 2, histSize, ranges, true, false
console.log 'Computed'


console.log hist.rows + 'x' + hist.cols

minMax = cv.minMaxLoc hist

tmp = new Mat
scale = 10

histImg = tmp.zeros sbins * scale, hbins * 10, cv.CV_8UC3

console.log 'Looping...'
for h in [0..hbins - 1]
	for s in [0..sbins - 1]
		binVal = hist.at h, s
		
		intensity = Math.round(binVal * 255 / maxVal)
		cv.rectangle histImg, {x: h*scale, y: s*scale}, {x: (h+1)*scale - 1, y: (s+1)*scale - 1}, [255, 0, 0], cv.CV_FILLED

namedWindow "source", 1
imshow "source", src

namedWindow "H-S Histogram", 1
imshow "H-S Histogram", histImg

keypress process.stdin
process.stdin.on 'keypress', (char, key) ->
	if key.name == 'escape'
		console.log 'Stopping.'
		process.exit 0

process.stdin.setRawMode true
process.stdin.resume()		
console.log 'Press ESC to stop.'