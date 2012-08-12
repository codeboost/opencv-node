{
	'targets': [{
		'target_name': 'addon',
		'sources': [ 
			'src/addon.cpp',
			'src/opencv_manual.cpp', 
			'src/opencvjs.cpp'
		],
		'cflags!': [ '-fno-exceptions' ],
		'cflags_cc!': [ '-fno-exceptions' ],
		'conditions': [
        ['OS=="mac"', {
        	'include_dirs':['/usr/local/include/opencv'],
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          },
          'libraries':[
						'-lopencv_core', 
						'-lopencv_imgproc', 
						'-lopencv_calib3d',
						'-lopencv_features2d', 
						'-lopencv_objdetect', 
						'-lopencv_video', 
						'-lopencv_highgui', 
						'-lopencv_contrib', 
						'-lopencv_flann', 
						'-lopencv_ml', 
						'-lopencv_gpu', 
						'-lopencv_legacy'
          ]
        }]
      ]
	}]
}