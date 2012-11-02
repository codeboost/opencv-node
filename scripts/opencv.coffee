#This should be done in the C++ addon ?
opencvjs = require '../build/Release/addon.node'

_ = require 'underscore'
cv = opencvjs.OpenCV
Mat = opencvjs.Mat

_.extend module.exports, opencvjs
delete module.exports.OpenCV

_.extend module.exports, opencvjs.OpenCV

#Run the message loop on windows. This is required, otherwise the window painting will not work in Windows.
module.exports.runMessageLoop = ->
	#I doubt this is the most efficient way to do it, but it seems to do the job for the moment
	doTick = ->
		cv.doTick();	#calls GetMessage(), TranslateMessage() and DispatchMessage()
		process.nextTick doTick

	if require('os').type().toLowerCase().indexOf("windows") is 0
		doTick()


#This is used
module.exports.closeOnEsc = ->
	require('keypress') process.stdin
	process.stdin.on 'keypress', (char, key) ->
		if key.name == 'escape'
			console.log 'Stopping.'
			process.exit 0
	process.stdin.setRawMode true
	process.stdin.resume()
