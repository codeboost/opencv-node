cv = require './opencv'
path = require 'path'

fileName = path.resolve '../scripts/test.jpg'
console.log fileName
src = cv.imread fileName, 1
console.log src.channels # output 3

plane = []
cv.split src, plane 
console.log plane # output []
