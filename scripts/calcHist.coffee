#Adaptation of the example found here:
#http://opencv.willowgarage.com/documentation/cpp/imgproc_histograms.html?highlight=calchist#calcHist
cv = require './opencv'
keypress = require 'keypress'
path = require 'path'

fullpath = path.resolve 'lena.jpg'

console.log 'Opening ', fullpath
src = cv.imread fullpath, 1
return console.log 'Error opening file' if src.empty

console.log src.size

cv.namedWindow "org", 0
cv.imshow "org", src


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

tmp = new cv.Mat
scale = 10

histImg = tmp.zeros sbins * scale, hbins * 10, cv.CV_8UC3

for h in [0..hbins - 1]
	for s in [0..sbins - 1]
		binVal = hist.at h, s
		intensity = Math.round(binVal * 255 / minMax.maxVal)
		cv.rectangle histImg, {x: h*scale, y: s*scale}, {x: (h+1)*scale - 1, y: (s+1)*scale - 1}, [intensity, intensity, intensity, intensity], -1

cv.namedWindow "H-S Histogram", 1
cv.imshow "H-S Histogram", histImg

doATick = ->
	cv.doTick();
	process.nextTick doATick

doATick()

setTimeout ->
	process.exit -1
, 1000

