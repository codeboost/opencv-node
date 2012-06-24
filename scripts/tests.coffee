cv = require './opencv'
Mat = cv.Mat

Results = 
  failed: 0
  passed: 0
  total: 0

ok = (expr, message) ->
  Results.total++
  if expr isnt true
    console.log "FAILED: " + message
    #console.log new Error().stack
    process.exit -1
    Results.failed++
  else
    console.log "PASSED: " + message
    Results.passed++
mustThrow = (name, fn) ->
  excepted = false
  try
    fn()
  catch e
    excepted = true
  unless excepted
    ok false, "Exception not thrown for '" + name + "'"
  else
    ok true, "Exception thrown for '" + name
test = (name, fnTest) ->
  console.log "*****"
  console.log name
  try
    fnTest()
  catch e
    ok false, "Exception thrown for '" + name + "': " + e.message

SAME_WIDTH = (src, dst) ->
  src.width is dst.width

SAME_HEIGHT = (src, dst) ->
  src.height is dst.height

SAME_WIDTH_HEIGHT = (src, dst) ->
  src.width is dst.width and src.height is dst.height

SAME_WIDTH_HEIGHT_TYPE = (src, dst) ->
  SAME_WIDTH_HEIGHT(src, dst) and src.type is dst.type

SAME_EVERYTHING = (src, dst) ->
  SAME_WIDTH_HEIGHT_TYPE(src, dst) and src.channels is dst.channels and src.depth is dst.depth and src.total is dst.total and src.isContinuous is dst.isContinuous and src.elemSize is dst.elemSize and src.empty is dst.empty

init = (width, height, format) ->
  console.log "Starting tests"
  srcMat = new Mat(
    width: width
    height: height
  , format)
  srcMat.setTo [ 0, 0, 0 ]
  test "createMat", ->
    mustThrow "new Mat(156, undefined)", ->
      new Mat(156, `undefined`)

    mat1 = new Mat(155, 156)
    ok mat1.width is 156 and mat1.height is 155, "Mat1 width/height"
    ok mat1.type is cv.CV_8UC3, "Type of mat created with int parameters"
    cv.discardMats mat1
    mat1 = new Mat(srcMat)
    ok mat1.width is srcMat.width and mat1.height is srcMat.height and mat1.type is srcMat.type and mat1.depth is srcMat.depth and mat1.channels is srcMat.channels, "Width/height/channels/depth of matrix created with Mat parameter"
    cv.discardMats mat1
    mat1 = new Mat(
      width: 123
      height: 124
    , cv.CV_8UC4)
    ok mat1.width is 123 and mat1.height is 124, "Width/height of Mat created with Size param"
    ok mat1.type is cv.CV_8UC4, "Type of mat created with size param"
    cv.discardMats mat1
    mat1 = new Mat(srcMat,
      x: 20
      y: 20
      width: 100
      height: 100
    )
    ok mat1.type is srcMat.type, "Type of matrix created with Mat and RECT params"
    ok mat1.width is 100, "Width of mat created with RECT param"
    ok mat1.height is 100, "Height of mat created with RECT param"
    mustThrow "new Mat(100)", ->
      mat1 = new Mat(100)

    mustThrow "new Mat(100, 0)", ->
      mat1 = new Mat(100, 0)

    mustThrow "new Mat(-100, 100)", ->
      mat1 = new Mat(-100, 0)

    mustThrow "new Mat({width: 324}, 12)", ->
      mat1 = new Mat(
        width: 324
      , 12)

  test "range", ->
    ok srcMat.channels is 3, "3 channels"
    myRange = srcMat.colRange(10, 20)
    mustThrow "Invalid col range", ->
      srcMat.colRange 0, width + 1

    mustThrow "Invalid col range 2", ->
      srcMat.colRange 10, 2

    mustThrow "Invalid col range 3", ->
      srcMat.colRange -21, width

    colsMat = srcMat.colRange(0, width)
    ok colsMat.width is width, "Width must be equal"
    ok colsMat.height is height, "Height must be equal"
    cv.discardMats colsMat
    mustThrow "Invalid row range", ->
      srcMat.rowRange 0, height + 1

    mustThrow "Invalid row range 2", ->
      srcMat.rowRange 10, 2

    mustThrow "Invalid row range 3", ->
      srcMat.rowRange -21, width

  test "clone", ->
    cloned = srcMat.clone()
    console.log "Sizes: " + srcMat.size.width + "x" + srcMat.size.height + "-" + cloned.size.width + "x" + cloned.size.height
    ok SAME_EVERYTHING(srcMat, cloned), "Cloned matrix must be identical"

  test "copyTo", ->
    destMat = undefined
    mustThrow "Copy to undefined var", ->
      srcMat.copyTo destMat

    destMat = new Mat(100, 100, cv.CV_8UC3)
    srcMat.copyTo destMat
    ok SAME_EVERYTHING(srcMat, destMat), "Copy to different size matrix"
    cv.discardMats destMat
    destMat = new Mat(height, width, cv.CV_8UC4)
    srcMat.copyTo destMat
    ok SAME_EVERYTHING(srcMat, destMat), "Copy to different depth matrix"
    mustThrow "Copy to RECT argument", ->
      srcMat.copyTo
        width: 1090
        height: 33

    cv.discardMats destMat
    destMat = new Mat(height, width, cv.CV_8UC3)
    ok srcMat.copyTo(destMat) is srcMat, "Copy to good matrix"
    cv.discardMats destMat

  test "setTo", ->
    mustThrow "setTo(undefined)", ->
      srcMat.setTo()

    mustThrow "setTo(1)", ->
      srcMat.setTo 1

    mustThrow "setTo({width: 1900, height: 1000})", ->
      srcMat.setTo
        width: 1900
        height: 1000

    mustThrow "setTo([])", ->
      srcMat.setTo []

    mustThrow "setTo([1, 2])", ->
      srcMat.setTo [ 1, 2 ]

    mustThrow "setTo([1, 2, {one: 1}])", ->
      srcMat.setTo [ 1, 2,
        one: 1
       ]

    ok srcMat is srcMat.setTo([ 1, 2, 2 ]), "srcMat == srcMat.setTo([1, 2, 2])"
    srcMat.setTo [ 0, 0, 0 ]
    ok srcMat[0] is 0, "mat[0] == 0"
    ok srcMat[192] is 0, "mat[192] == 0"
    srcMat.setTo [ 123, 253, 99 ]
    ok srcMat[0] is 123, "mat[0] == 123"
    ok srcMat[1] is 253, "mat[1] = 253"
    ok srcMat[2] is 99, "mat[2] = 99"
    ok srcMat[3] is 123, "mat[3] == 123"
    ok srcMat[4] is 253, "mat[4] = 253"
    ok srcMat[5] is 99, "mat[5] = 99"
    srcMat[33] = 22
    ok srcMat[33] is 22, "mat[33] == 22"

  test "mul", ->
    
    mustThrow "mul(undefined)", ->
      srcMat.mul `undefined`

    mustThrow "mul({one: 1})", ->
      srcMat.mul one: 1

    mulMat = new Mat(100, 100)
    
    mustThrow "mul(invalid size matrix)", ->
      srcMat.mul mulMat

    cv.discardMats mulMat

    srcMat = new Mat 100, 100

    mulMat = new Mat(srcMat.height, srcMat.width, srcMat.type)
    newMat = srcMat.mul(mulMat)
    ok SAME_WIDTH_HEIGHT_TYPE(newMat, srcMat), "Multiplied must have same w/h/t"

  test "convertTo", ->
    mustThrow "convertTo(undefined)", ->
      srcMat.convertTo `undefined`, 1

    mustThrow "convertTo(1)", ->
      srcMat.convertTo 1, 1

    srcMat = new Mat 100, 100

    dest = new Mat(1, 1, cv.CV_8UC2)
    srcMat.convertTo dest, cv.CV_8UC2
    ok SAME_WIDTH_HEIGHT(srcMat, dest), "Same width height after convertTo"
    ok dest.depth is srcMat.depth, "dest.depth === src.depth"

  test "reshape", ->
    
    src = new Mat 100, 100

    mustThrow "reshape(-1)", ->
      src.reshape -1

    mustThrow "reshape(1, -1)", ->
      src.reshape 0, -1

    res = src.reshape(0)
    ok SAME_EVERYTHING(res, src), "reshaped must be a cloned src"
    cv.discardMats res
    res = src.reshape(1, 0)
    ok res.width is src.width * 3, "Result width must be 3 * src.width?"


init 320, 200, cv.CV_8UC3

console.log '*** Finished ***'
console.log Results














