#ifndef OPENCVJS_H
#define OPENCVJS_H
#include <v8.h>
#include "cvcheck.h"
#include <cv.hpp>
#include <highgui.h>
#include "bea.h"
#include "customTypes.h"
namespace bea {
	template<> struct Convert<cv::TermCriteria> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::TermCriteria FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: type, maxCount, epsilon. This will be cast to 'cv::TermCriteria'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::TermCriteria ret;
			ret.type = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("type")), nArg);
			ret.maxCount = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("maxCount")), nArg);
			ret.epsilon = bea::Convert<double>::FromJS(obj->Get(v8::String::NewSymbol("epsilon")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::TermCriteria const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("type"), bea::Convert<int>::ToJS(v.type));
			obj->Set(v8::String::NewSymbol("maxCount"), bea::Convert<int>::ToJS(v.maxCount));
			obj->Set(v8::String::NewSymbol("epsilon"), bea::Convert<double>::ToJS(v.epsilon));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Point> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Point FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: x, y. This will be cast to 'cv::Point'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Point ret;
			ret.x = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("x")), nArg);
			ret.y = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("y")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Point const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("x"), bea::Convert<int>::ToJS(v.x));
			obj->Set(v8::String::NewSymbol("y"), bea::Convert<int>::ToJS(v.y));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Point2f> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Point2f FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: x, y. This will be cast to 'cv::Point2f'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Point2f ret;
			ret.x = bea::Convert<float>::FromJS(obj->Get(v8::String::NewSymbol("x")), nArg);
			ret.y = bea::Convert<float>::FromJS(obj->Get(v8::String::NewSymbol("y")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Point2f const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("x"), bea::Convert<float>::ToJS(v.x));
			obj->Set(v8::String::NewSymbol("y"), bea::Convert<float>::ToJS(v.y));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Size> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Size FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: width, height. This will be cast to 'cv::Size'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Size ret;
			ret.width = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("width")), nArg);
			ret.height = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("height")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Size const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("width"), bea::Convert<int>::ToJS(v.width));
			obj->Set(v8::String::NewSymbol("height"), bea::Convert<int>::ToJS(v.height));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Size2f> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Size2f FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: width, height. This will be cast to 'cv::Size2f'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Size2f ret;
			ret.width = bea::Convert<float>::FromJS(obj->Get(v8::String::NewSymbol("width")), nArg);
			ret.height = bea::Convert<float>::FromJS(obj->Get(v8::String::NewSymbol("height")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Size2f const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("width"), bea::Convert<float>::ToJS(v.width));
			obj->Set(v8::String::NewSymbol("height"), bea::Convert<float>::ToJS(v.height));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Rect> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Rect FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: x, y, width, height. This will be cast to 'cv::Rect'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Rect ret;
			ret.x = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("x")), nArg);
			ret.y = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("y")), nArg);
			ret.width = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("width")), nArg);
			ret.height = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("height")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Rect const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("x"), bea::Convert<int>::ToJS(v.x));
			obj->Set(v8::String::NewSymbol("y"), bea::Convert<int>::ToJS(v.y));
			obj->Set(v8::String::NewSymbol("width"), bea::Convert<int>::ToJS(v.width));
			obj->Set(v8::String::NewSymbol("height"), bea::Convert<int>::ToJS(v.height));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Range> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::Range FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: start, end. This will be cast to 'cv::Range'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::Range ret;
			ret.start = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("start")), nArg);
			ret.end = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("end")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Range const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("start"), bea::Convert<int>::ToJS(v.start));
			obj->Set(v8::String::NewSymbol("end"), bea::Convert<int>::ToJS(v.end));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::RotatedRect> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::RotatedRect FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: center, size, angle. This will be cast to 'cv::RotatedRect'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::RotatedRect ret;
			ret.center = bea::Convert<cv::Point2f>::FromJS(obj->Get(v8::String::NewSymbol("center")), nArg);
			ret.size = bea::Convert<cv::Size2f>::FromJS(obj->Get(v8::String::NewSymbol("size")), nArg);
			ret.angle = bea::Convert<float>::FromJS(obj->Get(v8::String::NewSymbol("angle")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::RotatedRect const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("center"), bea::Convert<cv::Point2f>::ToJS(v.center));
			obj->Set(v8::String::NewSymbol("size"), bea::Convert<cv::Size2f>::ToJS(v.size));
			obj->Set(v8::String::NewSymbol("angle"), bea::Convert<float>::ToJS(v.angle));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::minMaxLocRet> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static cv::minMaxLocRet FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: minVal, maxVal, minIdx, maxIdx. This will be cast to 'cv::minMaxLocRet'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			cv::minMaxLocRet ret;
			ret.minVal = bea::Convert<double>::FromJS(obj->Get(v8::String::NewSymbol("minVal")), nArg);
			ret.maxVal = bea::Convert<double>::FromJS(obj->Get(v8::String::NewSymbol("maxVal")), nArg);
			ret.minIdx = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("minIdx")), nArg);
			ret.maxIdx = bea::Convert<int>::FromJS(obj->Get(v8::String::NewSymbol("maxIdx")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(cv::minMaxLocRet const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("minVal"), bea::Convert<double>::ToJS(v.minVal));
			obj->Set(v8::String::NewSymbol("maxVal"), bea::Convert<double>::ToJS(v.maxVal));
			obj->Set(v8::String::NewSymbol("minIdx"), bea::Convert<int>::ToJS(v.minIdx));
			obj->Set(v8::String::NewSymbol("maxIdx"), bea::Convert<int>::ToJS(v.maxIdx));
			return scope.Close(obj);
		}
		
	};
	
	template<> struct Convert<cv::Mat*> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::ExposedClass<cv::Mat>::Is(v);
		}
		
		static cv::Mat* FromJS(v8::Handle<v8::Value> v, int nArg) {
			return bea::ExposedClass<cv::Mat>::FromJS(v, nArg);
		}
		
		static v8::Handle<v8::Value> ToJS(cv::Mat* const& v) {
			return bea::ExposedClass<cv::Mat>::ToJS(v);
		}
		
	};
	
	template<> struct Convert<cv::VideoCapture*> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::ExposedClass<cv::VideoCapture>::Is(v);
		}
		
		static cv::VideoCapture* FromJS(v8::Handle<v8::Value> v, int nArg) {
			return bea::ExposedClass<cv::VideoCapture>::FromJS(v, nArg);
		}
		
		static v8::Handle<v8::Value> ToJS(cv::VideoCapture* const& v) {
			return bea::ExposedClass<cv::VideoCapture>::ToJS(v);
		}
		
	};
	
	template<> struct Convert<cv::VideoWriter*> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::ExposedClass<cv::VideoWriter>::Is(v);
		}
		
		static cv::VideoWriter* FromJS(v8::Handle<v8::Value> v, int nArg) {
			return bea::ExposedClass<cv::VideoWriter>::FromJS(v, nArg);
		}
		
		static v8::Handle<v8::Value> ToJS(cv::VideoWriter* const& v) {
			return bea::ExposedClass<cv::VideoWriter>::ToJS(v);
		}
		
	};
	
	template<> struct Convert<cv::SparseMat*> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::ExposedClass<cv::SparseMat>::Is(v);
		}
		
		static cv::SparseMat* FromJS(v8::Handle<v8::Value> v, int nArg) {
			return bea::ExposedClass<cv::SparseMat>::FromJS(v, nArg);
		}
		
		static v8::Handle<v8::Value> ToJS(cv::SparseMat* const& v) {
			return bea::ExposedClass<cv::SparseMat>::ToJS(v);
		}
		
	};
	
	template<> struct Convert<cv::CascadeClassifier*> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::ExposedClass<cv::CascadeClassifier>::Is(v);
		}
		
		static cv::CascadeClassifier* FromJS(v8::Handle<v8::Value> v, int nArg) {
			return bea::ExposedClass<cv::CascadeClassifier>::FromJS(v, nArg);
		}
		
		static v8::Handle<v8::Value> ToJS(cv::CascadeClassifier* const& v) {
			return bea::ExposedClass<cv::CascadeClassifier>::ToJS(v);
		}
		
	};
	
}

namespace opencvjs {
	class JMat {
		protected:
			//Destructor
			static void __destructor(v8::Handle<v8::Value> value);
			//Exported methods
			static v8::Handle<v8::Value> __postAllocator(const v8::Arguments& args);
			static v8::Handle<v8::Value> __constructor(const v8::Arguments& args);
			static v8::Handle<v8::Value> row(const v8::Arguments& args);
			static v8::Handle<v8::Value> col(const v8::Arguments& args);
			static v8::Handle<v8::Value> rowRange(const v8::Arguments& args);
			static v8::Handle<v8::Value> colRange(const v8::Arguments& args);
			static v8::Handle<v8::Value> diag(const v8::Arguments& args);
			static v8::Handle<v8::Value> clone(const v8::Arguments& args);
			static v8::Handle<v8::Value> copyTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> convertTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> assignTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> setTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> reshape(const v8::Arguments& args);
			static v8::Handle<v8::Value> inv(const v8::Arguments& args);
			static v8::Handle<v8::Value> mul(const v8::Arguments& args);
			static v8::Handle<v8::Value> t(const v8::Arguments& args);
			static v8::Handle<v8::Value> cross(const v8::Arguments& args);
			static v8::Handle<v8::Value> dot(const v8::Arguments& args);
			static v8::Handle<v8::Value> create(const v8::Arguments& args);
			static v8::Handle<v8::Value> eye(const v8::Arguments& args);
			static v8::Handle<v8::Value> ones(const v8::Arguments& args);
			static v8::Handle<v8::Value> zeros(const v8::Arguments& args);
			static v8::Handle<v8::Value> resize(const v8::Arguments& args);
			static v8::Handle<v8::Value> locateROI(const v8::Arguments& args);
			static v8::Handle<v8::Value> adjustROI(const v8::Arguments& args);
			static v8::Handle<v8::Value> step1(const v8::Arguments& args);
			static v8::Handle<v8::Value> indexable(const v8::Arguments& args);
			static v8::Handle<v8::Value> at(const v8::Arguments& args);
			//Accessors - Getters
			static v8::Handle<v8::Value> accGet_width(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_height(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_size(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_type(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_channels(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_isContinuous(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_elemSize(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_empty(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_depth(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_total(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_rows(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_cols(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			//Accessors - Setters
			static void accSet_width(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_height(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_size(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_type(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_channels(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_isContinuous(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_elemSize(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_empty(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_depth(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_total(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_rows(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_cols(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	class JVideoCapture {
		protected:
			//Exported methods
			static v8::Handle<v8::Value> __constructor(const v8::Arguments& args);
			static v8::Handle<v8::Value> open(const v8::Arguments& args);
			static v8::Handle<v8::Value> isOpened(const v8::Arguments& args);
			static v8::Handle<v8::Value> release(const v8::Arguments& args);
			static v8::Handle<v8::Value> grab(const v8::Arguments& args);
			static v8::Handle<v8::Value> retrieve(const v8::Arguments& args);
			static v8::Handle<v8::Value> read(const v8::Arguments& args);
			static v8::Handle<v8::Value> get(const v8::Arguments& args);
			static v8::Handle<v8::Value> set(const v8::Arguments& args);
			static v8::Handle<v8::Value> __postAllocator(const v8::Arguments& args);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	class JVideoWriter {
		protected:
			//Exported methods
			static v8::Handle<v8::Value> __constructor(const v8::Arguments& args);
			static v8::Handle<v8::Value> open(const v8::Arguments& args);
			static v8::Handle<v8::Value> isOpened(const v8::Arguments& args);
			static v8::Handle<v8::Value> write(const v8::Arguments& args);
			static v8::Handle<v8::Value> __postAllocator(const v8::Arguments& args);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	class JSparseMat {
		protected:
			//Destructor
			static void __destructor(v8::Handle<v8::Value> value);
			//Exported methods
			static v8::Handle<v8::Value> __constructor(const v8::Arguments& args);
			static v8::Handle<v8::Value> clone(const v8::Arguments& args);
			static v8::Handle<v8::Value> copyTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> convertTo(const v8::Arguments& args);
			static v8::Handle<v8::Value> create(const v8::Arguments& args);
			static v8::Handle<v8::Value> clear(const v8::Arguments& args);
			static v8::Handle<v8::Value> hash(const v8::Arguments& args);
			static v8::Handle<v8::Value> size(const v8::Arguments& args);
			static v8::Handle<v8::Value> __postAllocator(const v8::Arguments& args);
			//Accessors - Getters
			static v8::Handle<v8::Value> accGet_elemSize(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_elemSize1(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_type(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_depth(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_channels(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_dims(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			static v8::Handle<v8::Value> accGet_nzcount(v8::Local<v8::String> prop, const v8::AccessorInfo& info);
			//Accessors - Setters
			static void accSet_elemSize(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_elemSize1(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_type(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_depth(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_channels(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_dims(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
			static void accSet_nzcount(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	class JOpenCV {
		protected:
			//Exported methods
			static v8::Handle<v8::Value> GaussianBlur(const v8::Arguments& args);
			static v8::Handle<v8::Value> Canny(const v8::Arguments& args);
			static v8::Handle<v8::Value> bilateralFilter(const v8::Arguments& args);
			static v8::Handle<v8::Value> cvtColor(const v8::Arguments& args);
			static v8::Handle<v8::Value> addWeighted(const v8::Arguments& args);
			static v8::Handle<v8::Value> resize(const v8::Arguments& args);
			static v8::Handle<v8::Value> threshold(const v8::Arguments& args);
			static v8::Handle<v8::Value> warpAffine(const v8::Arguments& args);
			static v8::Handle<v8::Value> getRotationMatrix2D(const v8::Arguments& args);
			static v8::Handle<v8::Value> namedWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> imshow(const v8::Arguments& args);
			static v8::Handle<v8::Value> dilate(const v8::Arguments& args);
			static v8::Handle<v8::Value> absdiff(const v8::Arguments& args);
			static v8::Handle<v8::Value> add(const v8::Arguments& args);
			static v8::Handle<v8::Value> bitwise_and(const v8::Arguments& args);
			static v8::Handle<v8::Value> bitwise_not(const v8::Arguments& args);
			static v8::Handle<v8::Value> bitwise_or(const v8::Arguments& args);
			static v8::Handle<v8::Value> bitwise_xor(const v8::Arguments& args);
			static v8::Handle<v8::Value> calcCovarMatrix(const v8::Arguments& args);
			static v8::Handle<v8::Value> cartToPolar(const v8::Arguments& args);
			static v8::Handle<v8::Value> compare(const v8::Arguments& args);
			static v8::Handle<v8::Value> completeSymm(const v8::Arguments& args);
			static v8::Handle<v8::Value> convertScaleAbs(const v8::Arguments& args);
			static v8::Handle<v8::Value> countNonZero(const v8::Arguments& args);
			static v8::Handle<v8::Value> cubeRoot(const v8::Arguments& args);
			static v8::Handle<v8::Value> dct(const v8::Arguments& args);
			static v8::Handle<v8::Value> dft(const v8::Arguments& args);
			static v8::Handle<v8::Value> divide(const v8::Arguments& args);
			static v8::Handle<v8::Value> determinant(const v8::Arguments& args);
			static v8::Handle<v8::Value> eigen(const v8::Arguments& args);
			static v8::Handle<v8::Value> exp(const v8::Arguments& args);
			static v8::Handle<v8::Value> fastAtan2(const v8::Arguments& args);
			static v8::Handle<v8::Value> flip(const v8::Arguments& args);
			static v8::Handle<v8::Value> gemm(const v8::Arguments& args);
			static v8::Handle<v8::Value> idct(const v8::Arguments& args);
			static v8::Handle<v8::Value> idft(const v8::Arguments& args);
			static v8::Handle<v8::Value> inRange(const v8::Arguments& args);
			static v8::Handle<v8::Value> invert(const v8::Arguments& args);
			static v8::Handle<v8::Value> log(const v8::Arguments& args);
			static v8::Handle<v8::Value> LUT(const v8::Arguments& args);
			static v8::Handle<v8::Value> magnitude(const v8::Arguments& args);
			static v8::Handle<v8::Value> Mahalanobis(const v8::Arguments& args);
			static v8::Handle<v8::Value> max(const v8::Arguments& args);
			static v8::Handle<v8::Value> mean(const v8::Arguments& args);
			static v8::Handle<v8::Value> meanStdDev(const v8::Arguments& args);
			static v8::Handle<v8::Value> min(const v8::Arguments& args);
			static v8::Handle<v8::Value> mulSpectrums(const v8::Arguments& args);
			static v8::Handle<v8::Value> norm(const v8::Arguments& args);
			static v8::Handle<v8::Value> multiply(const v8::Arguments& args);
			static v8::Handle<v8::Value> mulTransposed(const v8::Arguments& args);
			static v8::Handle<v8::Value> normalize(const v8::Arguments& args);
			static v8::Handle<v8::Value> perspectiveTransform(const v8::Arguments& args);
			static v8::Handle<v8::Value> phase(const v8::Arguments& args);
			static v8::Handle<v8::Value> polarToCart(const v8::Arguments& args);
			static v8::Handle<v8::Value> pow(const v8::Arguments& args);
			static v8::Handle<v8::Value> randu(const v8::Arguments& args);
			static v8::Handle<v8::Value> randn(const v8::Arguments& args);
			static v8::Handle<v8::Value> reduce(const v8::Arguments& args);
			static v8::Handle<v8::Value> repeat(const v8::Arguments& args);
			static v8::Handle<v8::Value> scaleAdd(const v8::Arguments& args);
			static v8::Handle<v8::Value> setIdentity(const v8::Arguments& args);
			static v8::Handle<v8::Value> solve(const v8::Arguments& args);
			static v8::Handle<v8::Value> solveCubic(const v8::Arguments& args);
			static v8::Handle<v8::Value> solvePoly(const v8::Arguments& args);
			static v8::Handle<v8::Value> sort(const v8::Arguments& args);
			static v8::Handle<v8::Value> sortIdx(const v8::Arguments& args);
			static v8::Handle<v8::Value> sqrt(const v8::Arguments& args);
			static v8::Handle<v8::Value> subtract(const v8::Arguments& args);
			static v8::Handle<v8::Value> sum(const v8::Arguments& args);
			static v8::Handle<v8::Value> trace(const v8::Arguments& args);
			static v8::Handle<v8::Value> transform(const v8::Arguments& args);
			static v8::Handle<v8::Value> transpose(const v8::Arguments& args);
			static v8::Handle<v8::Value> circle(const v8::Arguments& args);
			static v8::Handle<v8::Value> clipLine(const v8::Arguments& args);
			static v8::Handle<v8::Value> ellipse(const v8::Arguments& args);
			static v8::Handle<v8::Value> line(const v8::Arguments& args);
			static v8::Handle<v8::Value> rectangle(const v8::Arguments& args);
			static v8::Handle<v8::Value> putText(const v8::Arguments& args);
			static v8::Handle<v8::Value> equalizeHist(const v8::Arguments& args);
			static v8::Handle<v8::Value> ellipse2Poly(const v8::Arguments& args);
			static v8::Handle<v8::Value> checkRange(const v8::Arguments& args);
			static v8::Handle<v8::Value> merge(const v8::Arguments& args);
			static v8::Handle<v8::Value> split(const v8::Arguments& args);
			static v8::Handle<v8::Value> fillConvexPoly(const v8::Arguments& args);
			static v8::Handle<v8::Value> resizeImage(const v8::Arguments& args);
			static v8::Handle<v8::Value> imdecode(const v8::Arguments& args);
			static v8::Handle<v8::Value> imread(const v8::Arguments& args);
			static v8::Handle<v8::Value> imwrite(const v8::Arguments& args);
			static v8::Handle<v8::Value> waitKey(const v8::Arguments& args);
			static v8::Handle<v8::Value> HoughCircles(const v8::Arguments& args);
			static v8::Handle<v8::Value> HoughLines(const v8::Arguments& args);
			static v8::Handle<v8::Value> preCornerDetect(const v8::Arguments& args);
			static v8::Handle<v8::Value> goodFeaturesToTrack(const v8::Arguments& args);
			static v8::Handle<v8::Value> cornerSubPix(const v8::Arguments& args);
			static v8::Handle<v8::Value> cornerMinEigenVal(const v8::Arguments& args);
			static v8::Handle<v8::Value> cornerHarris(const v8::Arguments& args);
			static v8::Handle<v8::Value> cornerEigenValsAndVecs(const v8::Arguments& args);
			static v8::Handle<v8::Value> calcHist(const v8::Arguments& args);
			static v8::Handle<v8::Value> calcBackProject(const v8::Arguments& args);
			static v8::Handle<v8::Value> minMaxLoc(const v8::Arguments& args);
			static v8::Handle<v8::Value> cvSmooth(const v8::Arguments& args);
			static v8::Handle<v8::Value> doTick(const v8::Arguments& args);
			static v8::Handle<v8::Value> discardMats(const v8::Arguments& args);
			static v8::Handle<v8::Value> fillPoly(const v8::Arguments& args);
			static v8::Handle<v8::Value> getTextSize(const v8::Arguments& args);
			static v8::Handle<v8::Value> polylines(const v8::Arguments& args);
			static v8::Handle<v8::Value> kmeans(const v8::Arguments& args);
			static v8::Handle<v8::Value> detectObject(const v8::Arguments& args);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	class JCascadeClassifier {
		protected:
			//Exported methods
			static v8::Handle<v8::Value> __constructor(const v8::Arguments& args);
			static v8::Handle<v8::Value> empty(const v8::Arguments& args);
			static v8::Handle<v8::Value> load(const v8::Arguments& args);
			static v8::Handle<v8::Value> detectMultiScale(const v8::Arguments& args);
			static v8::Handle<v8::Value> __postAllocator(const v8::Arguments& args);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace opencvjs {
	static void ExposeConstants(v8::Handle<v8::Object> target);
}

namespace opencvjs {
	class Project {
		public:
			static void expose(v8::Handle<v8::Object> target);
	};
	
}

#endif //#ifndef OPENCVJS_H