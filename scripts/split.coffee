cv = require './opencv'

src = cv.imread 'scripts/test.jpg', 1
console.log src.channels # output 3

plane = []
cv.split src, plane 
console.log plane # output []
