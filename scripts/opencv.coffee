#This should be done in the C++ addon ?
opencvjs = require '../build/Release/addon.node'
_ = require 'underscore'
cv = opencvjs.OpenCV
Mat = opencvjs.Mat

_.extend module.exports, opencvjs
delete module.exports.OpenCV

_.extend module.exports, opencvjs.OpenCV