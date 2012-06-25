srcdir = 'src'
blddir = 'build'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  bld.env.append_value('LINKFLAGS', '-lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_features2d -lopencv_objdetect -lopencv_video -lopencv_highgui -lopencv_contrib -lopencv_flann -lopencv_ml -lopencv_gpu -lopencv_legacy'.split()) 
  obj.includes = ["/usr/local/include/opencv"]
  obj.target = 'addon'
  obj.source = 'src/addon.cpp src/opencvjs.cpp src/opencv_manual.cpp'