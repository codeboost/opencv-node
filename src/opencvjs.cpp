#include "opencvjs.h"
using namespace cv;
namespace bea {
	
}

DECLARE_EXPOSED_CLASS(cv::Mat);
namespace opencvjs {
	void JMat::__destructor(v8::Handle<v8::Value> value) {
		DESTRUCTOR_BEGIN();
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(value, 0);
		int bytes = sizeof(*_this) + (int)(_this->dataend - _this->datastart);
		v8::V8::AdjustAmountOfExternalAllocatedMemory(-bytes);
		delete _this;
		DESTRUCTOR_END();
	}
	
	v8::Handle<v8::Value> JMat::__postAllocator(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void __postAllocator()
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		int bytes = sizeof(*_this) + (int)(_this->dataend - _this->datastart);
		args.This()->SetIndexedPropertiesToExternalArrayData(_this->datastart, v8::kExternalUnsignedByteArray, bytes);
		v8::V8::AdjustAmountOfExternalAllocatedMemory(bytes);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::__constructor(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//Mat(int rows, int cols, int type, const Scalar& s)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2]) && bea::Convert<cv::Scalar>::Is(args[3])) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Convert<int>::FromJS(args[2], 2);
			cv::Scalar s = bea::Convert<cv::Scalar>::FromJS(args[3], 3);
			THROW_IF_NOT(rows > 0 && cols > 0, "Invalid values for rows/cols parameters");
			cv::Mat* fnRetVal = new cv::Mat(rows, cols, type, s);
			return v8::External::New(fnRetVal);
		}
		//Mat(Size size, int type, const Scalar& s)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<cv::Scalar>::Is(args[2])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			cv::Scalar s = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
			THROW_IF_NOT(size.height > 0 && size.width > 0, "Invalid values for size parameter");
			cv::Mat* fnRetVal = new cv::Mat(size, type, s);
			return v8::External::New(fnRetVal);
		}
		//Mat(const Mat& m, const Range& rowRange, const Range& colRange)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Range>::Is(args[1]) && bea::Convert<cv::Range>::Is(args[2])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Range rowRange = bea::Convert<cv::Range>::FromJS(args[1], 1);
			cv::Range colRange = bea::Convert<cv::Range>::FromJS(args[2], 2);
			cv::Mat* fnRetVal = new cv::Mat(*m, rowRange, colRange);
			return v8::External::New(fnRetVal);
		}
		//Mat(int rows, int cols, int type = CV_8UC3)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Optional<int>::Is(args, 2)) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Optional<int>::FromJS(args, 2,  CV_8UC3);
			THROW_IF_NOT(rows > 0 && cols > 0, "Invalid values for rows/cols parameters");
			cv::Mat* fnRetVal = new cv::Mat(rows, cols, type);
			return v8::External::New(fnRetVal);
		}
		//Mat(Size size, int type)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			THROW_IF_NOT(size.height > 0 && size.width > 0, "Invalid values for size parameter");
			cv::Mat* fnRetVal = new cv::Mat(size, type);
			return v8::External::New(fnRetVal);
		}
		//Mat(const Mat& m, const Rect& r)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Rect>::Is(args[1])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Rect r = bea::Convert<cv::Rect>::FromJS(args[1], 1);
			THROW_IF_NOT(r.width > 0 && r.height > 0, "Invalid RECT argument");
			cv::Mat* fnRetVal = new cv::Mat(*m, r);
			return v8::External::New(fnRetVal);
		}
		//Mat(const Mat& m)
		if (bea::Convert<cv::Mat*>::Is(args[0])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* fnRetVal = new cv::Mat(*m);
			return v8::External::New(fnRetVal);
		}
		//Mat()
		if (args.Length() == 0) {
			cv::Mat* fnRetVal = new cv::Mat();
			return v8::External::New(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::__constructor: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::row(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat row(int i)
		int i = bea::Convert<int>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		THROW_IF_NOT(i > 0, "Invalid row value");
		cv::Mat* fnRetVal = new cv::Mat(_this->row(i));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::col(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat col(int j)
		int j = bea::Convert<int>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		THROW_IF_NOT(j > 0, "Invalid col value");
		cv::Mat* fnRetVal = new cv::Mat(_this->col(j));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::rowRange(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat rowRange(int startrow, int endrow)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			int startrow = bea::Convert<int>::FromJS(args[0], 0);
			int endrow = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(startrow >= 0 && endrow >= startrow && endrow <= _this->rows, "Invalid values for range parameters");
			cv::Mat* fnRetVal = new cv::Mat(_this->rowRange(startrow, endrow));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		//Mat rowRange(const Range& r)
		if (bea::Convert<cv::Range>::Is(args[0])) {
			cv::Range r = bea::Convert<cv::Range>::FromJS(args[0], 0);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(_this->dims >= 2, "Matrix must have at least 2 dims");
			THROW_IF_NOT( 0 <= r.start && r.start <= r.end && r.end <= _this->rows, "Invalid range");
			cv::Mat* fnRetVal = new cv::Mat(_this->rowRange(r));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::rowRange: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::colRange(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat colRange(int startcol, int endcol)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			int startcol = bea::Convert<int>::FromJS(args[0], 0);
			int endcol = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(startcol >= 0 && endcol >= startcol && endcol <= _this->cols, "Invalid values for range parameters");
			cv::Mat* fnRetVal = new cv::Mat(_this->colRange(startcol, endcol));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		//Mat colRange(const Range& r)
		if (bea::Convert<cv::Range>::Is(args[0])) {
			cv::Range r = bea::Convert<cv::Range>::FromJS(args[0], 0);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(_this->dims >= 2, "Matrix must have at least 2 dims");
			THROW_IF_NOT(0 <= r.start && r.start <= r.end && r.end <= _this->cols, "Invalid range");
			cv::Mat* fnRetVal = new cv::Mat(_this->colRange(r));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::colRange: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::diag(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat diag(int d)
		int d = bea::Convert<int>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		cv::Mat* fnRetVal = new cv::Mat(_this->diag(d));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::clone(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//Mat clone()
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		cv::Mat* fnRetVal = new cv::Mat(_this->clone());
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::copyTo(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void copyTo(Mat& m, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			_this->copyTo(*m, *mask);
			return args.This();
		}
		//void copyTo(Mat& m )
		if (bea::Convert<cv::Mat*>::Is(args[0])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			_this->copyTo(*m);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::copyTo: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::convertTo(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void convertTo(Mat& m, int rtype, double alpha=1, double beta=0)
		cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int rtype = bea::Convert<int>::FromJS(args[1], 1);
		double alpha = bea::Optional<double>::FromJS(args, 2, 1);
		double beta = bea::Optional<double>::FromJS(args, 3, 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->convertTo(*m, rtype, alpha, beta);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::assignTo(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void assignTo(Mat& m, int type=-1)
		cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int type = bea::Optional<int>::FromJS(args, 1, -1);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->assignTo(*m, type);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::setTo(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void setTo(const Scalar& s, const Mat& mask=Mat())
		cv::Scalar s = bea::Convert<cv::Scalar>::FromJS(args[0], 0);
		Mat _t = cv::Mat();
		cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 1, &_t);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->setTo(s, *mask);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::reshape(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat reshape(int cn, int rows=0)
		int cn = bea::Convert<int>::FromJS(args[0], 0);
		int rows = bea::Optional<int>::FromJS(args, 1, 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		THROW_IF_NOT(cn >= 0, "Channels must be 0 or a positive number");
		THROW_IF_NOT(rows >= 0, "Rows must be 0 or a positive number");
		cv::Mat* fnRetVal = new cv::Mat(_this->reshape(cn, rows));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::inv(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void inv(int method=cv::DECOMP_LU)
		int method = bea::Optional<int>::FromJS(args, 0, cv::DECOMP_LU);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->inv(method);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::mul(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void mul(const Mat& m, double scale=1)
		cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double scale = bea::Optional<double>::FromJS(args, 1, 1);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		REQUIRE_SAME_SIZE_TYPE(_this, m);
		_this->mul(*m, scale);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::t(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void t()
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->t();
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::cross(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat cross(const Mat& m)
		cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		THROW_IF_NOT(_this->dims <= 2 && m->dims <= 2 && _this->size() == m->size() && _this->type() == m->type() && ((_this->rows == 3 && _this->cols == 1) || (_this->cols*_this->channels() == 3 && _this->rows == 1)), "Invalid matrix size/type");
		THROW_IF_NOT(_this->depth() == CV_32F || _this->depth() == CV_64F, "Matrices must have 32 or 64 bit float format");
		cv::Mat* fnRetVal = new cv::Mat(_this->cross(*m));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::dot(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//double dot(const Mat& m)
		cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		REQUIRE_SAME_SIZE(m, _this);
		double fnRetVal = _this->dot(*m);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::create(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void create(int rows, int cols, int type)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2])) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Convert<int>::FromJS(args[2], 2);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(rows > 0 && cols > 0, "Invalid values for rows/cols parameters");
			_this->create(rows, cols, type);
			return args.This();
		}
		//void create(Size size, int type)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(size.height > 0 && size.width > 0, "Invalid values for size parameter");
			_this->create(size, type);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::create: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::eye(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//Mat eye(int rows, int cols, int type)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2])) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Convert<int>::FromJS(args[2], 2);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(rows > 0 && cols > 0, "Invalid dimensions");
			cv::Mat* fnRetVal = new cv::Mat(_this->eye(rows, cols, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		//Mat eye(Size size, int type)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			cv::Mat* fnRetVal = new cv::Mat(_this->eye(size, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::eye: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::ones(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//Mat ones(int rows, int cols, int type)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2])) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Convert<int>::FromJS(args[2], 2);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			cv::Mat* fnRetVal = new cv::Mat(_this->ones(rows, cols, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		//Mat ones(Size size, int type)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			cv::Mat* fnRetVal = new cv::Mat(_this->ones(size, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::ones: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::zeros(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//Mat zeros(int rows, int cols, int type)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2])) {
			int rows = bea::Convert<int>::FromJS(args[0], 0);
			int cols = bea::Convert<int>::FromJS(args[1], 1);
			int type = bea::Convert<int>::FromJS(args[2], 2);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			cv::Mat* fnRetVal = new cv::Mat(_this->zeros(rows, cols, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		//Mat zeros(Size size, int type)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			cv::Size size = bea::Convert<cv::Size>::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
			cv::Mat* fnRetVal = new cv::Mat(_this->zeros(size, type));
			return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("Mat::zeros: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::resize(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void resize(size_t sz)
		size_t sz = bea::Convert<size_t>::FromJS(args[0], 0);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		THROW_IF_NOT(sz > 0, "Invalid size value");
		_this->resize(sz);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::locateROI(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void locateROI(Size& wholeSize, Point& ofs)
		cv::Size wholeSize = bea::Convert<cv::Size>::FromJS(args[0], 0);
		cv::Point ofs = bea::Convert<cv::Point>::FromJS(args[1], 1);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		_this->locateROI(wholeSize, ofs);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::adjustROI(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//Mat& adjustROI(int dtop, int dbottom, int dleft, int dright)
		int dtop = bea::Convert<int>::FromJS(args[0], 0);
		int dbottom = bea::Convert<int>::FromJS(args[1], 1);
		int dleft = bea::Convert<int>::FromJS(args[2], 2);
		int dright = bea::Convert<int>::FromJS(args[3], 3);
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		cv::Mat* fnRetVal = new cv::Mat(_this->adjustROI(dtop, dbottom, dleft, dright));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::step1(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//size_t step1()
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		size_t fnRetVal = _this->step1();
		return bea::Convert<size_t>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JMat::indexable(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void indexable()
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(args.This(), 0);
		int bytes = sizeof(*_this) + (int)(_this->dataend - _this->datastart);
		args.This()->SetIndexedPropertiesToExternalArrayData(_this->datastart, v8::kExternalUnsignedByteArray, bytes);
			
		return args.This();
		METHOD_END();
	}
	
	//Get Accessor width (int)
	v8::Handle<v8::Value> JMat::accGet_width( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->size().width);
		return scope.Close(retVal);
	}
	
	//Set Accessor width (int)
	void JMat::accSet_width(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor height (int)
	v8::Handle<v8::Value> JMat::accGet_height( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->size().height);
		return scope.Close(retVal);
	}
	
	//Set Accessor height (int)
	void JMat::accSet_height(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor size (cv::Size)
	v8::Handle<v8::Value> JMat::accGet_size( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<cv::Size>::ToJS(_this->size());
		return scope.Close(retVal);
	}
	
	//Set Accessor size (cv::Size)
	void JMat::accSet_size(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		cv::Size _accValue = bea::Convert<cv::Size>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor type (int)
	v8::Handle<v8::Value> JMat::accGet_type( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->type());
		return scope.Close(retVal);
	}
	
	//Set Accessor type (int)
	void JMat::accSet_type(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor channels (int)
	v8::Handle<v8::Value> JMat::accGet_channels( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->channels());
		return scope.Close(retVal);
	}
	
	//Set Accessor channels (int)
	void JMat::accSet_channels(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor isContinuous (bool)
	v8::Handle<v8::Value> JMat::accGet_isContinuous( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<bool>::ToJS(_this->isContinuous());
		return scope.Close(retVal);
	}
	
	//Set Accessor isContinuous (bool)
	void JMat::accSet_isContinuous(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		bool _accValue = bea::Convert<bool>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor elemSize (int)
	v8::Handle<v8::Value> JMat::accGet_elemSize( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->elemSize());
		return scope.Close(retVal);
	}
	
	//Set Accessor elemSize (int)
	void JMat::accSet_elemSize(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor empty (bool)
	v8::Handle<v8::Value> JMat::accGet_empty( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<bool>::ToJS(_this->empty());
		return scope.Close(retVal);
	}
	
	//Set Accessor empty (bool)
	void JMat::accSet_empty(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		bool _accValue = bea::Convert<bool>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor depth (int)
	v8::Handle<v8::Value> JMat::accGet_depth( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->depth());
		return scope.Close(retVal);
	}
	
	//Set Accessor depth (int)
	void JMat::accSet_depth(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor total (int)
	v8::Handle<v8::Value> JMat::accGet_total( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->total());
		return scope.Close(retVal);
	}
	
	//Set Accessor total (int)
	void JMat::accSet_total(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor rows (int)
	v8::Handle<v8::Value> JMat::accGet_rows( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->rows);
		return scope.Close(retVal);
	}
	
	//Set Accessor rows (int)
	void JMat::accSet_rows(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor cols (int)
	v8::Handle<v8::Value> JMat::accGet_cols( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->cols);
		return scope.Close(retVal);
	}
	
	//Set Accessor cols (int)
	void JMat::accSet_cols(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::Mat* _this = bea::Convert<cv::Mat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	void JMat::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedClass<cv::Mat>* obj = EXPOSE_CLASS(cv::Mat, "Mat");
		//Destructor
		obj->setDestructor(__destructor);
		//Exposed Methods
		obj->setPostAllocator(__postAllocator);
		obj->setConstructor(__constructor);
		obj->exposeMethod("row", row);
		obj->exposeMethod("col", col);
		obj->exposeMethod("rowRange", rowRange);
		obj->exposeMethod("colRange", colRange);
		obj->exposeMethod("diag", diag);
		obj->exposeMethod("clone", clone);
		obj->exposeMethod("copyTo", copyTo);
		obj->exposeMethod("convertTo", convertTo);
		obj->exposeMethod("assignTo", assignTo);
		obj->exposeMethod("setTo", setTo);
		obj->exposeMethod("reshape", reshape);
		obj->exposeMethod("inv", inv);
		obj->exposeMethod("mul", mul);
		obj->exposeMethod("t", t);
		obj->exposeMethod("cross", cross);
		obj->exposeMethod("dot", dot);
		obj->exposeMethod("create", create);
		obj->exposeMethod("eye", eye);
		obj->exposeMethod("ones", ones);
		obj->exposeMethod("zeros", zeros);
		obj->exposeMethod("resize", resize);
		obj->exposeMethod("locateROI", locateROI);
		obj->exposeMethod("adjustROI", adjustROI);
		obj->exposeMethod("step1", step1);
		obj->exposeMethod("indexable", indexable);
		obj->exposeMethod("at", at);
		//Accessors
		obj->exposeProperty("width", accGet_width, accSet_width);
		obj->exposeProperty("height", accGet_height, accSet_height);
		obj->exposeProperty("size", accGet_size, accSet_size);
		obj->exposeProperty("type", accGet_type, accSet_type);
		obj->exposeProperty("channels", accGet_channels, accSet_channels);
		obj->exposeProperty("isContinuous", accGet_isContinuous, accSet_isContinuous);
		obj->exposeProperty("elemSize", accGet_elemSize, accSet_elemSize);
		obj->exposeProperty("empty", accGet_empty, accSet_empty);
		obj->exposeProperty("depth", accGet_depth, accSet_depth);
		obj->exposeProperty("total", accGet_total, accSet_total);
		obj->exposeProperty("rows", accGet_rows, accSet_rows);
		obj->exposeProperty("cols", accGet_cols, accSet_cols);
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

DECLARE_EXPOSED_CLASS(cv::VideoCapture);
namespace opencvjs {
	v8::Handle<v8::Value> JVideoCapture::__constructor(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//VideoCapture(const std::string& filename)
		if (bea::Convert<std::string>::Is(args[0])) {
			std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
			cv::VideoCapture* fnRetVal = new cv::VideoCapture(filename);
			return v8::External::New(fnRetVal);
		}
		//VideoCapture(int device)
		if (bea::Convert<int>::Is(args[0])) {
			int device = bea::Convert<int>::FromJS(args[0], 0);
			cv::VideoCapture* fnRetVal = new cv::VideoCapture(device);
			return v8::External::New(fnRetVal);
		}
		//VideoCapture()
		if (args.Length() == 0) {
			cv::VideoCapture* fnRetVal = new cv::VideoCapture();
			return v8::External::New(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("VideoCapture::__constructor: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::open(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//bool open(const std::string& filename)
		if (bea::Convert<std::string>::Is(args[0])) {
			std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
			cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
			bool fnRetVal = _this->open(filename);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		//bool open(int device)
		if (bea::Convert<int>::Is(args[0])) {
			int device = bea::Convert<int>::FromJS(args[0], 0);
			cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
			bool fnRetVal = _this->open(device);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("VideoCapture::open: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::isOpened(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//bool isOpened()
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->isOpened();
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::release(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void release()
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		_this->release();
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::grab(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//bool grab()
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->grab();
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::retrieve(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//bool retrieve(Mat& image, int channel=0)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int channel = bea::Optional<int>::FromJS(args, 1, 0);
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->retrieve(*image, channel);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::read(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//bool read(Mat& image)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->read(*image);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::get(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//double get(int propId)
		int propId = bea::Convert<int>::FromJS(args[0], 0);
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		double fnRetVal = _this->get(propId);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::set(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//bool set(int propId, double value)
		int propId = bea::Convert<int>::FromJS(args[0], 0);
		double value = bea::Convert<double>::FromJS(args[1], 1);
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->set(propId, value);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoCapture::__postAllocator(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void __postAllocator()
		cv::VideoCapture* _this = bea::Convert<cv::VideoCapture*>::FromJS(args.This(), 0);
		return args.This();
		METHOD_END();
	}
	
	void JVideoCapture::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedClass<cv::VideoCapture>* obj = EXPOSE_CLASS(cv::VideoCapture, "VideoCapture");
		//Exposed Methods
		obj->setConstructor(__constructor);
		obj->exposeMethod("open", open);
		obj->exposeMethod("isOpened", isOpened);
		obj->exposeMethod("release", release);
		obj->exposeMethod("grab", grab);
		obj->exposeMethod("retrieve", retrieve);
		obj->exposeMethod("read", read);
		obj->exposeMethod("get", get);
		obj->exposeMethod("set", set);
		obj->setPostAllocator(__postAllocator);
		//Accessors
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

DECLARE_EXPOSED_CLASS(cv::VideoWriter);
namespace opencvjs {
	v8::Handle<v8::Value> JVideoWriter::__constructor(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//VideoWriter(const std::string& filename, int fourcc, double fps, Size frameSize, bool isColor=true)
		if (bea::Convert<std::string>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<double>::Is(args[2]) && bea::Convert<cv::Size>::Is(args[3]) && bea::Optional<bool>::Is(args, 4)) {
			std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
			int fourcc = bea::Convert<int>::FromJS(args[1], 1);
			double fps = bea::Convert<double>::FromJS(args[2], 2);
			cv::Size frameSize = bea::Convert<cv::Size>::FromJS(args[3], 3);
			bool isColor = bea::Optional<bool>::FromJS(args, 4, true);
			cv::VideoWriter* fnRetVal = new cv::VideoWriter(filename, fourcc, fps, frameSize, isColor);
			return v8::External::New(fnRetVal);
		}
		//VideoWriter()
		if (args.Length() == 0) {
			cv::VideoWriter* fnRetVal = new cv::VideoWriter();
			return v8::External::New(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("VideoWriter::__constructor: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoWriter::open(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//bool open(const std::string& filename, int fourcc, double fps, Size frameSize, bool isColor=true)
		std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
		int fourcc = bea::Convert<int>::FromJS(args[1], 1);
		double fps = bea::Convert<double>::FromJS(args[2], 2);
		cv::Size frameSize = bea::Convert<cv::Size>::FromJS(args[3], 3);
		bool isColor = bea::Optional<bool>::FromJS(args, 4, true);
		cv::VideoWriter* _this = bea::Convert<cv::VideoWriter*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->open(filename, fourcc, fps, frameSize, isColor);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoWriter::isOpened(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//bool isOpened()
		cv::VideoWriter* _this = bea::Convert<cv::VideoWriter*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->isOpened();
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoWriter::write(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void write(const Mat& image)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::VideoWriter* _this = bea::Convert<cv::VideoWriter*>::FromJS(args.This(), 0);
		_this->write(*image);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JVideoWriter::__postAllocator(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void __postAllocator()
		cv::VideoWriter* _this = bea::Convert<cv::VideoWriter*>::FromJS(args.This(), 0);
		return args.This();
		METHOD_END();
	}
	
	void JVideoWriter::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedClass<cv::VideoWriter>* obj = EXPOSE_CLASS(cv::VideoWriter, "VideoWriter");
		//Exposed Methods
		obj->setConstructor(__constructor);
		obj->exposeMethod("open", open);
		obj->exposeMethod("isOpened", isOpened);
		obj->exposeMethod("write", write);
		obj->setPostAllocator(__postAllocator);
		//Accessors
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

DECLARE_EXPOSED_CLASS(cv::SparseMat);
namespace opencvjs {
	void JSparseMat::__destructor(v8::Handle<v8::Value> value) {
		DESTRUCTOR_BEGIN();
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(value, 0);
		delete _this;
		DESTRUCTOR_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::__constructor(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//SparseMat(std::vector<int> sizes, int type)
		if (bea::Convert<std::vector<int> >::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			std::vector<int> sizes = bea::Convert<std::vector<int> >::FromJS(args[0], 0);
			int type = bea::Convert<int>::FromJS(args[1], 1);
			//@orgapi SparseMat(int dims, const int* _sizes, int _type);
			cv::SparseMat* fnRetVal = new cv::SparseMat(sizes.size(), &sizes[0], type);
				
			return bea::Convert<cv::SparseMat*>::ToJS(fnRetVal);
		}
		//SparseMat(const Mat& m)
		if (bea::Convert<cv::Mat*>::Is(args[0])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::SparseMat* fnRetVal = new cv::SparseMat(*m);
			return v8::External::New(fnRetVal);
		}
		//SparseMat()
		if (args.Length() == 0) {
			cv::SparseMat* fnRetVal = new cv::SparseMat();
			return v8::External::New(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("SparseMat::__constructor: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::clone(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//SparseMat clone()
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
		cv::SparseMat* fnRetVal = new cv::SparseMat(_this->clone());
		return bea::Convert<cv::SparseMat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::copyTo(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void copyTo(SparseMat& m)
		if (bea::Convert<cv::SparseMat*>::Is(args[0])) {
			cv::SparseMat* m = bea::Convert<cv::SparseMat*>::FromJS(args[0], 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			_this->copyTo(*m);
			return args.This();
		}
		//void copyTo(Mat& m)
		if (bea::Convert<cv::Mat*>::Is(args[0])) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			_this->copyTo(*m);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("SparseMat::copyTo: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::convertTo(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void convertTo(SparseMat& m, int rtype, double alpha = 1)
		if (bea::Convert<cv::SparseMat*>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Optional<double>::Is(args, 2)) {
			cv::SparseMat* m = bea::Convert<cv::SparseMat*>::FromJS(args[0], 0);
			int rtype = bea::Convert<int>::FromJS(args[1], 1);
			double alpha = bea::Optional<double>::FromJS(args, 2,  1);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			_this->convertTo(*m, rtype, alpha);
			return args.This();
		}
		//void convertTo(Mat& m, int rtype, double alpha=1, double beta=0)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Optional<double>::Is(args, 2) && bea::Optional<double>::Is(args, 3)) {
			cv::Mat* m = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			int rtype = bea::Convert<int>::FromJS(args[1], 1);
			double alpha = bea::Optional<double>::FromJS(args, 2, 1);
			double beta = bea::Optional<double>::FromJS(args, 3, 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			_this->convertTo(*m, rtype, alpha, beta);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("SparseMat::convertTo: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::create(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void create(std::vector<int> sizes, int type)
		std::vector<int> sizes = bea::Convert<std::vector<int> >::FromJS(args[0], 0);
		int type = bea::Convert<int>::FromJS(args[1], 1);
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
		//@orgapi void create(int dims, const int* _sizes, int _type);
		_this->create(sizes.size(), &sizes[0], type);
			
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::clear(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void clear()
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
		_this->clear();
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::hash(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//size_t hash(int i0, int i1, int i2)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<int>::Is(args[2])) {
			int i0 = bea::Convert<int>::FromJS(args[0], 0);
			int i1 = bea::Convert<int>::FromJS(args[1], 1);
			int i2 = bea::Convert<int>::FromJS(args[2], 2);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			size_t fnRetVal = _this->hash(i0, i1, i2);
			return bea::Convert<size_t>::ToJS(fnRetVal);
		}
		//size_t hash(int i0, int i1)
		if (bea::Convert<int>::Is(args[0]) && bea::Convert<int>::Is(args[1])) {
			int i0 = bea::Convert<int>::FromJS(args[0], 0);
			int i1 = bea::Convert<int>::FromJS(args[1], 1);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			size_t fnRetVal = _this->hash(i0, i1);
			return bea::Convert<size_t>::ToJS(fnRetVal);
		}
		//size_t hash(int i0)
		if (bea::Convert<int>::Is(args[0])) {
			int i0 = bea::Convert<int>::FromJS(args[0], 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			size_t fnRetVal = _this->hash(i0);
			return bea::Convert<size_t>::ToJS(fnRetVal);
		}
		//size_t hash(std::vector<int> idx)
		if (bea::Convert<std::vector<int> >::Is(args[0])) {
			std::vector<int> idx = bea::Convert<std::vector<int> >::FromJS(args[0], 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			THROW_IF_NOT(idx.size() == _this->dims(), "Input array must have size equal to dims()");
			size_t fnRetVal = _this->hash(&idx[0]);
				
			return bea::Convert<size_t>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("SparseMat::hash: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::size(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//int size(int i)
		if (bea::Convert<int>::Is(args[0])) {
			int i = bea::Convert<int>::FromJS(args[0], 0);
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			int fnRetVal = _this->size(i);
			return bea::Convert<int>::ToJS(fnRetVal);
		}
		//std::vector<int> size()
		if (args.Length() == 0) {
			cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
			//@orgapi int* size()
			const int* sizeptr = _this->size();
			std::vector<int> fnRetVal(sizeptr, sizeptr + _this->dims());
				
			return bea::Convert<std::vector<int> >::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("SparseMat::size: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JSparseMat::__postAllocator(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void __postAllocator()
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(args.This(), 0);
		return args.This();
		METHOD_END();
	}
	
	//Get Accessor elemSize (size_t)
	v8::Handle<v8::Value> JSparseMat::accGet_elemSize( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<size_t>::ToJS(_this->elemSize());
		return scope.Close(retVal);
	}
	
	//Set Accessor elemSize (size_t)
	void JSparseMat::accSet_elemSize(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		size_t _accValue = bea::Convert<size_t>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor elemSize1 (size_t)
	v8::Handle<v8::Value> JSparseMat::accGet_elemSize1( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<size_t>::ToJS(_this->elemSize1());
		return scope.Close(retVal);
	}
	
	//Set Accessor elemSize1 (size_t)
	void JSparseMat::accSet_elemSize1(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		size_t _accValue = bea::Convert<size_t>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor type (int)
	v8::Handle<v8::Value> JSparseMat::accGet_type( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->type());
		return scope.Close(retVal);
	}
	
	//Set Accessor type (int)
	void JSparseMat::accSet_type(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor depth (int)
	v8::Handle<v8::Value> JSparseMat::accGet_depth( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->depth());
		return scope.Close(retVal);
	}
	
	//Set Accessor depth (int)
	void JSparseMat::accSet_depth(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor channels (int)
	v8::Handle<v8::Value> JSparseMat::accGet_channels( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->channels());
		return scope.Close(retVal);
	}
	
	//Set Accessor channels (int)
	void JSparseMat::accSet_channels(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor dims (int)
	v8::Handle<v8::Value> JSparseMat::accGet_dims( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<int>::ToJS(_this->dims());
		return scope.Close(retVal);
	}
	
	//Set Accessor dims (int)
	void JSparseMat::accSet_dims(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		int _accValue = bea::Convert<int>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	//Get Accessor nzcount (size_t)
	v8::Handle<v8::Value> JSparseMat::accGet_nzcount( v8::Local<v8::String> prop, const v8::AccessorInfo& info) {
		v8::HandleScope scope; 
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		v8::Handle<v8::Value> retVal = bea::Convert<size_t>::ToJS(_this->nzcount());
		return scope.Close(retVal);
	}
	
	//Set Accessor nzcount (size_t)
	void JSparseMat::accSet_nzcount(v8::Local<v8::String> prop, v8::Local<v8::Value> v, const v8::AccessorInfo& info) {
		v8::HandleScope scope;
		cv::SparseMat* _this = bea::Convert<cv::SparseMat*>::FromJS(info.Holder(), 0); 
		size_t _accValue = bea::Convert<size_t>::FromJS(v, 0);
		//TODO: Set value here
	}
	
	void JSparseMat::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedClass<cv::SparseMat>* obj = EXPOSE_CLASS(cv::SparseMat, "SparseMat");
		//Destructor
		obj->setDestructor(__destructor);
		//Exposed Methods
		obj->setConstructor(__constructor);
		obj->exposeMethod("clone", clone);
		obj->exposeMethod("copyTo", copyTo);
		obj->exposeMethod("convertTo", convertTo);
		obj->exposeMethod("create", create);
		obj->exposeMethod("clear", clear);
		obj->exposeMethod("hash", hash);
		obj->exposeMethod("size", size);
		obj->setPostAllocator(__postAllocator);
		//Accessors
		obj->exposeProperty("elemSize", accGet_elemSize, accSet_elemSize);
		obj->exposeProperty("elemSize1", accGet_elemSize1, accSet_elemSize1);
		obj->exposeProperty("type", accGet_type, accSet_type);
		obj->exposeProperty("depth", accGet_depth, accSet_depth);
		obj->exposeProperty("channels", accGet_channels, accSet_channels);
		obj->exposeProperty("dims", accGet_dims, accSet_dims);
		obj->exposeProperty("nzcount", accGet_nzcount, accSet_nzcount);
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

DECLARE_STATIC(opencvjs::JOpenCV);
namespace opencvjs {
	v8::Handle<v8::Value> JOpenCV::GaussianBlur(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void GaussianBlur(const Mat& src, Mat& dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=cv::BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Size ksize = bea::Convert<cv::Size>::FromJS(args[2], 2);
		double sigmaX = bea::Convert<double>::FromJS(args[3], 3);
		double sigmaY = bea::Optional<double>::FromJS(args, 4, 0);
		int borderType = bea::Optional<int>::FromJS(args, 5, cv::BORDER_DEFAULT);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::GaussianBlur(*src, *dst, ksize, sigmaX, sigmaY, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::Canny(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void Canny(const Mat& image, Mat& edges, double threshold1, double threshold2, int apertureSize=3, bool L2gradient=false)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* edges = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		double threshold1 = bea::Convert<double>::FromJS(args[2], 2);
		double threshold2 = bea::Convert<double>::FromJS(args[3], 3);
		int apertureSize = bea::Optional<int>::FromJS(args, 4, 3);
		bool L2gradient = bea::Optional<bool>::FromJS(args, 5, false);
		apertureSize &= INT_MAX;
		REQUIRE_SAME_SIZE_TYPE(image, edges);
		THROW_IF_NOT(image->channels() == 1, "Image must have 1 channel");
		THROW_IF_NOT( !((apertureSize & 1) == 0 || apertureSize < 3 || apertureSize > 7 ), "Invalid aperture size");
		cv::Canny(*image, *edges, threshold1, threshold2, apertureSize, L2gradient);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::bilateralFilter(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		//void bilateralFilter(const Mat& src, Mat& dst, int d, double sigmaColor, double sigmaSpace, int borderType=cv::BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int d = bea::Convert<int>::FromJS(args[2], 2);
		double sigmaColor = bea::Convert<double>::FromJS(args[3], 3);
		double sigmaSpace = bea::Convert<double>::FromJS(args[4], 4);
		int borderType = bea::Optional<int>::FromJS(args, 5, cv::BORDER_DEFAULT);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::bilateralFilter(*src, *dst, d, sigmaColor, sigmaSpace, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cvtColor(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void cvtColor(const Mat& src, Mat& dst, int code, int dstCn=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int code = bea::Convert<int>::FromJS(args[2], 2);
		int dstCn = bea::Optional<int>::FromJS(args, 3, 0);
		cv::cvtColor(*src, *dst, code, dstCn);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::addWeighted(const v8::Arguments& args) {
		METHOD_BEGIN(6);
		//void addWeighted(const Mat& src1, double alpha, const Mat& src2, double beta, double gamma, Mat& dst)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double alpha = bea::Convert<double>::FromJS(args[1], 1);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		double beta = bea::Convert<double>::FromJS(args[3], 3);
		double gamma = bea::Convert<double>::FromJS(args[4], 4);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[5], 5);
		REQUIRE_SAME_SIZE_TYPE(src1, src2);
		REQUIRE_SAME_SIZE_TYPE(src1, dst);
		cv::addWeighted(*src1, alpha, *src2, beta, gamma, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::resize(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void resize(const Mat& src, Mat& dst, Size dsize, double fx=0, double fy=0, int interpolation=cv::INTER_LINEAR)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Size dsize = bea::Convert<cv::Size>::FromJS(args[2], 2);
		double fx = bea::Optional<double>::FromJS(args, 3, 0);
		double fy = bea::Optional<double>::FromJS(args, 4, 0);
		int interpolation = bea::Optional<int>::FromJS(args, 5, cv::INTER_LINEAR);
		THROW_IF_NOT((dsize.width > 0 && dsize.height > 0) || (fx > 0 && fy > 0) , "Invalid size or fx fy");
		THROW_IF_NOT(src->total() > 0 && dst->total() > 0, "One or both images are invalid");
		cv::resize(*src, *dst, dsize, fx, fy, interpolation);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::threshold(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		//double threshold(const Mat& src, Mat& dst, double thresh, double maxVal, int thresholdType)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		double thresh = bea::Convert<double>::FromJS(args[2], 2);
		double maxVal = bea::Convert<double>::FromJS(args[3], 3);
		int thresholdType = bea::Convert<int>::FromJS(args[4], 4);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		double fnRetVal = cv::threshold(*src, *dst, thresh, maxVal, thresholdType);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::warpAffine(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void warpAffine(const Mat& src, Mat& dst, const Mat& M, Size dsize, int flags=cv::INTER_LINEAR, int borderMode=cv::BORDER_CONSTANT, const Scalar& borderValue=cv::Scalar())
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* M = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Size dsize = bea::Convert<cv::Size>::FromJS(args[3], 3);
		int flags = bea::Optional<int>::FromJS(args, 4, cv::INTER_LINEAR);
		int borderMode = bea::Optional<int>::FromJS(args, 5, cv::BORDER_CONSTANT);
		cv::Scalar borderValue = bea::Optional<cv::Scalar>::FromJS(args, 6, cv::Scalar());
		REQUIRE_SAME_TYPE(src, dst);
		THROW_IF_NOT (dst->size() == dsize, "Destination matrix must have same size as size parameter");
		THROW_IF_NOT(M->rows == 2 && M->cols == 3, "M matrix must be a 2x3 matrix");
		cv::warpAffine(*src, *dst, *M, dsize, flags, borderMode, borderValue);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::getRotationMatrix2D(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//Mat getRotationMatrix2D(Point2f center, double angle, double scale)
		cv::Point2f center = bea::Convert<cv::Point2f>::FromJS(args[0], 0);
		double angle = bea::Convert<double>::FromJS(args[1], 1);
		double scale = bea::Convert<double>::FromJS(args[2], 2);
		cv::Mat* fnRetVal = new cv::Mat(cv::getRotationMatrix2D(center, angle, scale));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::namedWindow(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void namedWindow(const std::string& winname, int flags)
		std::string winname = bea::Convert<std::string>::FromJS(args[0], 0);
		int flags = bea::Convert<int>::FromJS(args[1], 1);
		cv::namedWindow(winname, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::imshow(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void imshow(const std::string& winname, const Mat& image)
		std::string winname = bea::Convert<std::string>::FromJS(args[0], 0);
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::imshow(winname, *image);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::dilate(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void dilate(const Mat& src, Mat& dst, const Mat& element, Point anchor=Point(-1, -1), int iterations=1, int borderType=cv::BORDER_CONSTANT, const Scalar& borderValue=cv::morphologyDefaultBorderValue())
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* element = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Point anchor = bea::Optional<cv::Point>::FromJS(args, 3, cv::Point(-1, -1));
		int iterations = bea::Optional<int>::FromJS(args, 4, 1);
		int borderType = bea::Optional<int>::FromJS(args, 5, cv::BORDER_CONSTANT);
		cv::Scalar borderValue = bea::Optional<cv::Scalar>::FromJS(args, 6, cv::morphologyDefaultBorderValue());
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::dilate(*src, *dst, *element, anchor, iterations, borderType, borderValue);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::erode(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void erode(const Mat& src, Mat& dst, const Mat& element, Point anchor=Point(-1, -1), int iterations=1, int borderType=cv::BORDER_CONSTANT, const Scalar& borderValue=cv::morphologyDefaultBorderValue())
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* element = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Point anchor = bea::Optional<cv::Point>::FromJS(args, 3, cv::Point(-1, -1));
		int iterations = bea::Optional<int>::FromJS(args, 4, 1);
		int borderType = bea::Optional<int>::FromJS(args, 5, cv::BORDER_CONSTANT);
		cv::Scalar borderValue = bea::Optional<cv::Scalar>::FromJS(args, 6, cv::morphologyDefaultBorderValue());
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::erode(*src, *dst, *element, anchor, iterations, borderType, borderValue);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::absdiff(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void absdiff(const Mat& src1, const Mat& src2, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::absdiff(*src1, *src2, *dst);
			return args.This();
		}
		//void absdiff(const Mat& src1, const Scalar& sc, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::absdiff(*src1, sc, *dst);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::absdiff: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::add(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void add(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Convert<cv::Mat*>::Is(args[3])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			THROW_IF_NOT(bea::Convert<cv::Mat*>::Is(args[3]) && mask->channels() == 1, "Mask must be a single-channel 8 bit matrix");
			cv::add(*src1, *src2, *dst, *mask);
			return args.This();
		}
		//void add(const Mat& src1, const Mat& src2, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::add(*src1, *src2, *dst);
			return args.This();
		}
		//void add(const Mat& src1, const Scalar& sc, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			THROW_IF_NOT(bea::Convert<cv::Mat*>::Is(args[3]) && mask->channels() == 1, "Mask must be a single-channel 8 bit matrix");
			cv::add(*src1, sc, *dst, *mask);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::add: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::bitwise_and(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void bitwise_and(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::bitwise_and(*src1, *src2, *dst, *mask);
			return args.This();
		}
		//void bitwise_and(const Mat& src1, const Scalar& sc, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::bitwise_and(*src1, sc, *dst, *mask);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::bitwise_and: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::bitwise_not(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void bitwise_not(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::bitwise_not(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::bitwise_or(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void bitwise_or(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			cv::bitwise_or(*src1, *src2, *dst, *mask);
			return args.This();
		}
		//void bitwise_or(const Mat& src1, const Scalar& sc, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			cv::bitwise_or(*src1, sc, *dst, *mask);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::bitwise_or: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::bitwise_xor(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void bitwise_xor(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			cv::bitwise_xor(*src1, *src2, *dst, *mask);
			return args.This();
		}
		//void bitwise_xor(const Mat& src1, const Scalar& sc, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			cv::bitwise_xor(*src1, sc, *dst, *mask);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::bitwise_xor: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::calcCovarMatrix(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void calcCovarMatrix(const Mat& samples, Mat& covar, Mat& mean, int flags, int ctype=CV_64F)
		cv::Mat* samples = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* covar = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* mean = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		int flags = bea::Convert<int>::FromJS(args[3], 3);
		int ctype = bea::Optional<int>::FromJS(args, 4, CV_64F);
		THROW_IF_NOT(covar->type() == ctype, "Covar matrix must have same type as ctype");
		cv::calcCovarMatrix(*samples, *covar, *mean, flags, ctype);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cartToPolar(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void cartToPolar(const Mat& x, const Mat& y, Mat& magnitude, Mat& angle, bool angleInDegrees=false)
		cv::Mat* x = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* y = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* magnitude = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Mat* angle = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		bool angleInDegrees = bea::Optional<bool>::FromJS(args, 4, false);
		REQUIRE_SAME_SIZE_TYPE(x, y);
		REQUIRE_SAME_SIZE_TYPE(x, magnitude);
		REQUIRE_SAME_SIZE_TYPE(x, angle);
		cv::cartToPolar(*x, *y, *magnitude, *angle, angleInDegrees);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::compare(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void compare(const Mat& src1, const Mat& src2, Mat& dst, int cmpop)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Convert<int>::Is(args[3])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			int cmpop = bea::Convert<int>::FromJS(args[3], 3);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE(src1, dst);
			THROW_IF_NOT(dst->type() == CV_8UC1, "Destination must have type CV_8UC1");
			cv::compare(*src1, *src2, *dst, cmpop);
			return args.This();
		}
		//void compare(const Mat& src1, double value, Mat& dst, int cmpop)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<double>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Convert<int>::Is(args[3])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			double value = bea::Convert<double>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			int cmpop = bea::Convert<int>::FromJS(args[3], 3);
			REQUIRE_SAME_SIZE(src1, dst);
			THROW_IF_NOT(dst->type() == CV_8UC1, "Destination must have type CV_8UC1");
			cv::compare(*src1, value, *dst, cmpop);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::compare: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::completeSymm(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void completeSymm(Mat& mtx, bool lowerToUpper=false)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		bool lowerToUpper = bea::Optional<bool>::FromJS(args, 1, false);
		cv::completeSymm(*mtx, lowerToUpper);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::convertScaleAbs(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void convertScaleAbs(const Mat& src, Mat& dst, double alpha=1, double beta=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		double alpha = bea::Optional<double>::FromJS(args, 2, 1);
		double beta = bea::Optional<double>::FromJS(args, 3, 0);
		cv::convertScaleAbs(*src, *dst, alpha, beta);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::countNonZero(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//int countNonZero(const Mat& mtx)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int fnRetVal = cv::countNonZero(*mtx);
		return bea::Convert<int>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cubeRoot(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//float cubeRoot(float val)
		float val = bea::Convert<float>::FromJS(args[0], 0);
		float fnRetVal = cv::cubeRoot(val);
		return bea::Convert<float>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::dct(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void dct(const Mat& src, Mat& dst, int flags=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Optional<int>::FromJS(args, 2, 0);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::dct(*src, *dst, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::dft(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void dft(const Mat& src, Mat& dst, int flags=0, int nonzeroRows=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Optional<int>::FromJS(args, 2, 0);
		int nonzeroRows = bea::Optional<int>::FromJS(args, 3, 0);
		cv::dft(*src, *dst, flags, nonzeroRows);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::divide(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void divide(double scale, const Mat& src2, Mat& dst)
		if (bea::Convert<double>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			double scale = bea::Convert<double>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src2, dst);
			cv::divide(scale, *src2, *dst);
			return args.This();
		}
		//void divide(const Mat& src1, const Mat& src2, Mat& dst, double scale=1)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<double>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			double scale = bea::Optional<double>::FromJS(args, 3, 1);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::divide(*src1, *src2, *dst, scale);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::divide: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::determinant(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//double determinant(const Mat& mtx)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		THROW_IF_NOT(mtx->type() == CV_32FC1 || mtx->type() == CV_64FC1, "Matrix must be of type CV_32FC1 or CV_64FC1 and have square size");
		double fnRetVal = cv::determinant(*mtx);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::eigen(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//bool eigen(const Mat& src, Mat& eigenvalues, Mat& eigenvectors, int lowindex=-1, int highindex=-1)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<int>::Is(args, 3) && bea::Optional<int>::Is(args, 4)) {
			cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* eigenvalues = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* eigenvectors = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			int lowindex = bea::Optional<int>::FromJS(args, 3, -1);
			int highindex = bea::Optional<int>::FromJS(args, 4, -1);
			REQUIRE_SAME_SIZE_TYPE(src, eigenvectors);
			bool fnRetVal = cv::eigen(*src, *eigenvalues, *eigenvectors, lowindex, highindex);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		//bool eigen(const Mat& src, Mat& eigenvalues, int lowindex=-1, int highindex=-1)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Optional<int>::Is(args, 2) && bea::Optional<int>::Is(args, 3)) {
			cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* eigenvalues = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			int lowindex = bea::Optional<int>::FromJS(args, 2, -1);
			int highindex = bea::Optional<int>::FromJS(args, 3, -1);
			bool fnRetVal = cv::eigen(*src, *eigenvalues, lowindex, highindex);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::eigen: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::exp(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void exp(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::exp(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::fastAtan2(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//float fastAtan2(float y, float x)
		float y = bea::Convert<float>::FromJS(args[0], 0);
		float x = bea::Convert<float>::FromJS(args[1], 1);
		float fnRetVal = cv::fastAtan2(y, x);
		return bea::Convert<float>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::flip(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void flip(const Mat& src, Mat& dst, int flipCode)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flipCode = bea::Convert<int>::FromJS(args[2], 2);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::flip(*src, *dst, flipCode);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::gemm(const v8::Arguments& args) {
		METHOD_BEGIN(6);
		//void gemm(const Mat& src1, const Mat& src2, double alpha, const Mat& src3, double beta, Mat& dst, int flags=0)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		double alpha = bea::Convert<double>::FromJS(args[2], 2);
		cv::Mat* src3 = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		double beta = bea::Convert<double>::FromJS(args[4], 4);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[5], 5);
		int flags = bea::Optional<int>::FromJS(args, 6, 0);
		THROW_IF_NOT(src1 && src2 && src3 && dst, "Invalid matrix argument");
		int type = src1->type();
		THROW_IF_NOT(type == CV_32FC1 || type == CV_64FC1 || type == CV_32FC2 || type == CV_64FC2, "Unsupported matrix type");
		REQUIRE_SAME_TYPE(src1, src2);
		REQUIRE_SAME_TYPE(src1, src3);
		REQUIRE_SAME_SIZE_TYPE(src1, dst);
		cv::gemm(*src1, *src2, alpha, *src3, beta, *dst, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::idct(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void idct(const Mat& src, Mat& dst, int flags=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Optional<int>::FromJS(args, 2, 0);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::idct(*src, *dst, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::idft(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void idft(const Mat& src, Mat& dst, int flags=0, int outputRows=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Optional<int>::FromJS(args, 2, 0);
		int outputRows = bea::Optional<int>::FromJS(args, 3, 0);
		//TODO: Check flags and determine if dst type is good
		cv::idft(*src, *dst, flags, outputRows);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::inRange(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void inRange(const Mat& src, const Mat& lowerb, const Mat& upperb, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Convert<cv::Mat*>::Is(args[3])) {
			cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* lowerb = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* upperb = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
			REQUIRE_SAME_SIZE_TYPE(src, upperb);
			REQUIRE_SAME_SIZE_TYPE(src, lowerb);
			REQUIRE_SAME_SIZE(src, dst);
			THROW_IF_NOT(dst->depth() == CV_8U, "Destination must be a CV_8U matrix");
			cv::inRange(*src, *lowerb, *upperb, *dst);
			return args.This();
		}
		//void inRange(const Mat& src, const Scalar& lowerb, const Scalar& upperb, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Scalar>::Is(args[2]) && bea::Convert<cv::Mat*>::Is(args[3])) {
			cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar lowerb = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Scalar upperb = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
			REQUIRE_SAME_SIZE(src, dst);
			THROW_IF_NOT(dst->depth() == CV_8U, "Destination must be a CV_8U matrix");
			cv::inRange(*src, lowerb, upperb, *dst);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::inRange: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::invert(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//double invert(const Mat& src, Mat& dst, int method=cv::DECOMP_LU)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int method = bea::Optional<int>::FromJS(args, 2, cv::DECOMP_LU);
		REQUIRE_SAME_TYPE(src, dst);
		double fnRetVal = cv::invert(*src, *dst, method);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::log(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void log(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		REQUIRE_SAME_SIZE_TYPE(src, dst);
		cv::log(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::LUT(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void LUT(const Mat& src, const Mat& lut, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* lut = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		//TODO: check LUT size/channels
		THROW_IF_NOT(src->channels() == dst->channels() && dst->depth() == lut->depth(), "Destination matrix must have the same size and the same number of channels as src , and the same depth as lut");
		cv::LUT(*src, *lut, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::magnitude(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void magnitude(const Mat& x, const Mat& y, Mat& magnitude)
		cv::Mat* x = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* y = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* magnitude = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		REQUIRE_SAME_SIZE(x, y);
		REQUIRE_SAME_SIZE_TYPE(x, magnitude);
		cv::magnitude(*x, *y, *magnitude);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::Mahalanobis(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//double Mahalanobis(const Mat& vec1, const Mat& vec2, const Mat& icovar)
		cv::Mat* vec1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* vec2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* icovar = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		double fnRetVal = cv::Mahalanobis(*vec1, *vec2, *icovar);
		return bea::Convert<double>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::max(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void max(const Mat& src1, double value, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<double>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			double value = bea::Convert<double>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::max(*src1, value, *dst);
			return args.This();
		}
		//void max(const Mat& src1, const Mat& src2, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			cv::max(*src1, *src2, *dst);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::max: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::mean(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Scalar mean(const Mat& mtx, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1])) {
			cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Scalar fnRetVal = cv::mean(*mtx, *mask);
			return bea::Convert<cv::Scalar>::ToJS(fnRetVal);
		}
		//Scalar mean(const Mat& mtx)
		if (bea::Convert<cv::Mat*>::Is(args[0])) {
			cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar fnRetVal = cv::mean(*mtx);
			return bea::Convert<cv::Scalar>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::mean: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::meanStdDev(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void meanStdDev(const Mat& mtx, Scalar& mean, Scalar& stddev, const Mat& mask=cv::Mat())
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar mean = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
		cv::Scalar stddev = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
		Mat _t = cv::Mat();
		cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
		//TODO: check mask type/size
		cv::meanStdDev(*mtx, mean, stddev, *mask);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::min(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void min(const Mat& src1, double value, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<double>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			double value = bea::Convert<double>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			cv::min(*src1, value, *dst);
			return args.This();
		}
		//void min(const Mat& src1, const Mat& src2, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			REQUIRE_SAME_SIZE_TYPE(src1, dst);
			REQUIRE_SAME_SIZE_TYPE(src1, src2);
			cv::min(*src1, *src2, *dst);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::min: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::mulSpectrums(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void mulSpectrums(const Mat& src1, const Mat& src2, Mat& dst, int flags, bool conj=false)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		int flags = bea::Convert<int>::FromJS(args[3], 3);
		bool conj = bea::Optional<bool>::FromJS(args, 4, false);
		cv::mulSpectrums(*src1, *src2, *dst, flags, conj);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::norm(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//double norm(const Mat& src1, const Mat& src2, int normType, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<int>::Is(args[2]) && bea::Convert<cv::Mat*>::Is(args[3])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			int normType = bea::Convert<int>::FromJS(args[2], 2);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
			double fnRetVal = cv::norm(*src1, *src2, normType, *mask);
			return bea::Convert<double>::ToJS(fnRetVal);
		}
		//double norm(const Mat& src1, int normType, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<int>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			int normType = bea::Convert<int>::FromJS(args[1], 1);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			double fnRetVal = cv::norm(*src1, normType, *mask);
			return bea::Convert<double>::ToJS(fnRetVal);
		}
		//double norm(const Mat& src1, const Mat& src2, int normType=cv::NORM_L2)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Optional<int>::Is(args, 2)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			int normType = bea::Optional<int>::FromJS(args, 2, cv::NORM_L2);
			double fnRetVal = cv::norm(*src1, *src2, normType);
			return bea::Convert<double>::ToJS(fnRetVal);
		}
		//double norm(const Mat& src1, int normType=cv::NORM_L2)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Optional<int>::Is(args, 1)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			int normType = bea::Optional<int>::FromJS(args, 1, cv::NORM_L2);
			double fnRetVal = cv::norm(*src1, normType);
			return bea::Convert<double>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::norm: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::multiply(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void multiply(const Mat& src1, const Mat& src2, Mat& dst, double scale=1)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		double scale = bea::Optional<double>::FromJS(args, 3, 1);
		cv::multiply(*src1, *src2, *dst, scale);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::mulTransposed(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void mulTransposed(const Mat& src, Mat& dst, bool aTa, const Mat& delta=cv::Mat(), double scale=1, int rtype=-1)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		bool aTa = bea::Convert<bool>::FromJS(args[2], 2);
		Mat _t = cv::Mat();
		cv::Mat* delta = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
		double scale = bea::Optional<double>::FromJS(args, 4, 1);
		int rtype = bea::Optional<int>::FromJS(args, 5, -1);
		cv::mulTransposed(*src, *dst, aTa, *delta, scale, rtype);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::normalize(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void normalize(const Mat& src, Mat& dst, double alpha=1, double beta=0, int normType=cv::NORM_L2, int rtype=-1, const Mat& mask=cv::Mat())
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		double alpha = bea::Optional<double>::FromJS(args, 2, 1);
		double beta = bea::Optional<double>::FromJS(args, 3, 0);
		int normType = bea::Optional<int>::FromJS(args, 4, cv::NORM_L2);
		int rtype = bea::Optional<int>::FromJS(args, 5, -1);
		Mat _t = cv::Mat();
		cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 6, &_t);
		cv::normalize(*src, *dst, alpha, beta, normType, rtype, *mask);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::perspectiveTransform(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void perspectiveTransform(const Mat& src, Mat& dst, const Mat& mtx)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::perspectiveTransform(*src, *dst, *mtx);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::phase(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void phase(const Mat& x, const Mat& y, Mat& angle, bool angleInDegrees=false)
		cv::Mat* x = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* y = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* angle = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		bool angleInDegrees = bea::Optional<bool>::FromJS(args, 3, false);
		cv::phase(*x, *y, *angle, angleInDegrees);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::polarToCart(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void polarToCart(const Mat& magnitude, const Mat& angle, Mat& x, Mat& y, bool angleInDegrees=false)
		cv::Mat* magnitude = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* angle = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* x = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Mat* y = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		bool angleInDegrees = bea::Optional<bool>::FromJS(args, 4, false);
		cv::polarToCart(*magnitude, *angle, *x, *y, angleInDegrees);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::pow(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void pow(const Mat& src, double p, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double p = bea::Convert<double>::FromJS(args[1], 1);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::pow(*src, p, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::randu(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void randu(Mat& mtx, const Scalar& low, const Scalar& high)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar low = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
		cv::Scalar high = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
		cv::randu(*mtx, low, high);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::randn(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void randn(Mat& mtx, const Scalar& mean, const Scalar& stddev)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar mean = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
		cv::Scalar stddev = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
		cv::randn(*mtx, mean, stddev);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::reduce(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void reduce(const Mat& mtx, Mat& vec, int dim, int reduceOp, int dtype=-1)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* vec = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int dim = bea::Convert<int>::FromJS(args[2], 2);
		int reduceOp = bea::Convert<int>::FromJS(args[3], 3);
		int dtype = bea::Optional<int>::FromJS(args, 4, -1);
		cv::reduce(*mtx, *vec, dim, reduceOp, dtype);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::repeat(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void repeat(const Mat& src, int ny, int nx, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int ny = bea::Convert<int>::FromJS(args[1], 1);
		int nx = bea::Convert<int>::FromJS(args[2], 2);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		cv::repeat(*src, ny, nx, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::scaleAdd(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void scaleAdd(const Mat& src1, double scale, const Mat& src2, Mat& dst)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double scale = bea::Convert<double>::FromJS(args[1], 1);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		cv::scaleAdd(*src1, scale, *src2, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::setIdentity(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//void setIdentity(Mat& dst, const Scalar& value=Scalar(1))
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar value = bea::Optional<cv::Scalar>::FromJS(args, 1, cv::Scalar(1));
		cv::setIdentity(*dst, value);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::solve(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//bool solve(const Mat& src1, const Mat& src2, Mat& dst, int flags=cv::DECOMP_LU)
		cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		int flags = bea::Optional<int>::FromJS(args, 3, cv::DECOMP_LU);
		bool fnRetVal = cv::solve(*src1, *src2, *dst, flags);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::solveCubic(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void solveCubic(const Mat& coeffs, Mat& roots)
		cv::Mat* coeffs = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* roots = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::solveCubic(*coeffs, *roots);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::solvePoly(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void solvePoly(const Mat& coeffs, Mat& roots, int maxIters=20)
		cv::Mat* coeffs = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* roots = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int maxIters = bea::Optional<int>::FromJS(args, 2, 20);
		cv::solvePoly(*coeffs, *roots, maxIters);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::sort(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void sort(const Mat& src, Mat& dst, int flags)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Convert<int>::FromJS(args[2], 2);
		cv::sort(*src, *dst, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::sortIdx(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void sortIdx(const Mat& src, Mat& dst, int flags)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int flags = bea::Convert<int>::FromJS(args[2], 2);
		cv::sortIdx(*src, *dst, flags);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::sqrt(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void sqrt(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::sqrt(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::subtract(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void subtract(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Convert<cv::Mat*>::Is(args[3])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
			cv::subtract(*src1, *src2, *dst, *mask);
			return args.This();
		}
		//void subtract(const Mat& src1, const Mat& src2, Mat& dst)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2])) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			cv::subtract(*src1, *src2, *dst);
			return args.This();
		}
		//void subtract(const Mat& src1, const Scalar& sc, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Scalar>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Mat* src1 = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			cv::subtract(*src1, sc, *dst, *mask);
			return args.This();
		}
		//void subtract(const Scalar& sc, const Mat& src2, Mat& dst, const Mat& mask=cv::Mat())
		if (bea::Convert<cv::Scalar>::Is(args[0]) && bea::Convert<cv::Mat*>::Is(args[1]) && bea::Convert<cv::Mat*>::Is(args[2]) && bea::Optional<cv::Mat*>::Is(args, 3)) {
			cv::Scalar sc = bea::Convert<cv::Scalar>::FromJS(args[0], 0);
			cv::Mat* src2 = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
			cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
			Mat _t = cv::Mat();
			cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 3, &_t);
			cv::subtract(sc, *src2, *dst, *mask);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::subtract: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::sum(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Scalar sum(const Mat& mtx)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar fnRetVal = cv::sum(*mtx);
		return bea::Convert<cv::Scalar>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::trace(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Scalar trace(const Mat& mtx)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Scalar fnRetVal = cv::trace(*mtx);
		return bea::Convert<cv::Scalar>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::transform(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void transform(const Mat& src, Mat& dst, const Mat& mtx)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::transform(*src, *dst, *mtx);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::transpose(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void transpose(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::transpose(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::circle(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void circle(Mat& img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Point center = bea::Convert<cv::Point>::FromJS(args[1], 1);
		int radius = bea::Convert<int>::FromJS(args[2], 2);
		cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[3], 3);
		int thickness = bea::Optional<int>::FromJS(args, 4, 1);
		int lineType = bea::Optional<int>::FromJS(args, 5, 8);
		int shift = bea::Optional<int>::FromJS(args, 6, 0);
		cv::circle(*img, center, radius, color, thickness, lineType, shift);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::clipLine(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//bool clipLine(Size imgSize, Point& pt1, Point& pt2)
		if (bea::Convert<cv::Size>::Is(args[0]) && bea::Convert<cv::Point>::Is(args[1]) && bea::Convert<cv::Point>::Is(args[2])) {
			cv::Size imgSize = bea::Convert<cv::Size>::FromJS(args[0], 0);
			cv::Point pt1 = bea::Convert<cv::Point>::FromJS(args[1], 1);
			cv::Point pt2 = bea::Convert<cv::Point>::FromJS(args[2], 2);
			bool fnRetVal = cv::clipLine(imgSize, pt1, pt2);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		//bool clipLine(Rect imgRect, Point& pt1, Point& pt2)
		if (bea::Convert<cv::Rect>::Is(args[0]) && bea::Convert<cv::Point>::Is(args[1]) && bea::Convert<cv::Point>::Is(args[2])) {
			cv::Rect imgRect = bea::Convert<cv::Rect>::FromJS(args[0], 0);
			cv::Point pt1 = bea::Convert<cv::Point>::FromJS(args[1], 1);
			cv::Point pt2 = bea::Convert<cv::Point>::FromJS(args[2], 2);
			bool fnRetVal = cv::clipLine(imgRect, pt1, pt2);
			return bea::Convert<bool>::ToJS(fnRetVal);
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::clipLine: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::ellipse(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void ellipse(Mat& img, Point center, Size axes, double angle, double startAngle, double endAngle, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::Point>::Is(args[1]) && bea::Convert<cv::Size>::Is(args[2]) && bea::Convert<double>::Is(args[3]) && bea::Convert<double>::Is(args[4]) && bea::Convert<double>::Is(args[5]) && bea::Convert<cv::Scalar>::Is(args[6]) && bea::Optional<int>::Is(args, 7) && bea::Optional<int>::Is(args, 8) && bea::Optional<int>::Is(args, 9)) {
			cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::Point center = bea::Convert<cv::Point>::FromJS(args[1], 1);
			cv::Size axes = bea::Convert<cv::Size>::FromJS(args[2], 2);
			double angle = bea::Convert<double>::FromJS(args[3], 3);
			double startAngle = bea::Convert<double>::FromJS(args[4], 4);
			double endAngle = bea::Convert<double>::FromJS(args[5], 5);
			cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[6], 6);
			int thickness = bea::Optional<int>::FromJS(args, 7, 1);
			int lineType = bea::Optional<int>::FromJS(args, 8, 8);
			int shift = bea::Optional<int>::FromJS(args, 9, 0);
			cv::ellipse(*img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift);
			return args.This();
		}
		//void ellipse(Mat& img, const RotatedRect& box, const Scalar& color, int thickness=1, int lineType=8)
		if (bea::Convert<cv::Mat*>::Is(args[0]) && bea::Convert<cv::RotatedRect>::Is(args[1]) && bea::Convert<cv::Scalar>::Is(args[2]) && bea::Optional<int>::Is(args, 3) && bea::Optional<int>::Is(args, 4)) {
			cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
			cv::RotatedRect box = bea::Convert<cv::RotatedRect>::FromJS(args[1], 1);
			cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
			int thickness = bea::Optional<int>::FromJS(args, 3, 1);
			int lineType = bea::Optional<int>::FromJS(args, 4, 8);
			cv::ellipse(*img, box, color, thickness, lineType);
			return args.This();
		}
		return v8::ThrowException(v8::Exception::Error(v8::String::New(("OpenCV::ellipse: Could not determine overload from supplied arguments"))));
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::line(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Point pt1 = bea::Convert<cv::Point>::FromJS(args[1], 1);
		cv::Point pt2 = bea::Convert<cv::Point>::FromJS(args[2], 2);
		cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[3], 3);
		int thickness = bea::Optional<int>::FromJS(args, 4, 1);
		int lineType = bea::Optional<int>::FromJS(args, 5, 8);
		int shift = bea::Optional<int>::FromJS(args, 6, 0);
		cv::line(*img, pt1, pt2, color, thickness, lineType, shift);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::rectangle(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Point pt1 = bea::Convert<cv::Point>::FromJS(args[1], 1);
		cv::Point pt2 = bea::Convert<cv::Point>::FromJS(args[2], 2);
		cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[3], 3);
		int thickness = bea::Optional<int>::FromJS(args, 4, 1);
		int lineType = bea::Optional<int>::FromJS(args, 5, 8);
		int shift = bea::Optional<int>::FromJS(args, 6, 0);
		cv::rectangle(*img, pt1, pt2, color, thickness, lineType, shift);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::putText(const v8::Arguments& args) {
		METHOD_BEGIN(6);
		//void putText(Mat& img, const std::string& text, Point org, int fontFace, double fontScale, Scalar color, int thickness=1, int lineType=8, bool bottomLeftOrigin=false)
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		std::string text = bea::Convert<std::string>::FromJS(args[1], 1);
		cv::Point org = bea::Convert<cv::Point>::FromJS(args[2], 2);
		int fontFace = bea::Convert<int>::FromJS(args[3], 3);
		double fontScale = bea::Convert<double>::FromJS(args[4], 4);
		cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[5], 5);
		int thickness = bea::Optional<int>::FromJS(args, 6, 1);
		int lineType = bea::Optional<int>::FromJS(args, 7, 8);
		bool bottomLeftOrigin = bea::Optional<bool>::FromJS(args, 8, false);
		cv::putText(*img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::equalizeHist(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void equalizeHist(const Mat& src, Mat& dst)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		cv::equalizeHist(*src, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::ellipse2Poly(const v8::Arguments& args) {
		METHOD_BEGIN(7);
		//void ellipse2Poly(Point center, Size axes, int angle, int startAngle, int endAngle, int delta, std::vector<cv::Point>& pts)
		cv::Point center = bea::Convert<cv::Point>::FromJS(args[0], 0);
		cv::Size axes = bea::Convert<cv::Size>::FromJS(args[1], 1);
		int angle = bea::Convert<int>::FromJS(args[2], 2);
		int startAngle = bea::Convert<int>::FromJS(args[3], 3);
		int endAngle = bea::Convert<int>::FromJS(args[4], 4);
		int delta = bea::Convert<int>::FromJS(args[5], 5);
		std::vector<cv::Point> pts = bea::Convert<std::vector<cv::Point> >::FromJS(args[6], 6);
		cv::ellipse2Poly(center, axes, angle, startAngle, endAngle, delta, pts);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::checkRange(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//bool checkRange(const Mat& src, bool quiet=true, std::vector<cv::Point> pos = std::vector<cv::Point>(), double minVal=-DBL_MAX, double maxVal=DBL_MAX)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		bool quiet = bea::Optional<bool>::FromJS(args, 1, true);
		std::vector<cv::Point> pos = bea::Optional<std::vector<cv::Point> >::FromJS(args, 2,  std::vector<cv::Point>());
		double minVal = bea::Optional<double>::FromJS(args, 3, -DBL_MAX);
		double maxVal = bea::Optional<double>::FromJS(args, 4, DBL_MAX);
		//bool checkRange(const Mat& src, bool quiet=true, Point* pos=0, double minVal=-DBL_MAX, double maxVal=DBL_MAX)
		bool fnRetVal = cv::checkRange(*src, quiet, pos.size() ? &pos[0] : NULL, minVal, maxVal);
			
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::merge(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void merge(std::vector<cv::Mat> mv, Mat& dst)
		std::vector<cv::Mat> mv = bea::Convert<std::vector<cv::Mat> >::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		//void merge(const Mat* mv, size_t count, Mat& dst)
		THROW_IF_NOT(mv.size() > 0, "Empty array");
		cv::merge(mv, *dst);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::split(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//std::vector<cv::Mat> split(const Mat& mtx)
		cv::Mat* mtx = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		std::vector<cv::Mat> fnRetVal;
		cv::split(*mtx, fnRetVal);
			
		return bea::Convert<std::vector<cv::Mat> >::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::fillConvexPoly(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void fillConvexPoly(Mat& img, const std::vector<cv::Point> &pts, const Scalar& color, int lineType=8, int shift=0)
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		std::vector<cv::Point> pts = bea::Convert<std::vector<cv::Point> >::FromJS(args[1], 1);
		cv::Scalar color = bea::Convert<cv::Scalar>::FromJS(args[2], 2);
		int lineType = bea::Optional<int>::FromJS(args, 3, 8);
		int shift = bea::Optional<int>::FromJS(args, 4, 0);
		//calling void fillConvexPoly(Mat& img, const Point* pts, int npts, const Scalar& color, int lineType=8, int shift=0)
		cv::fillConvexPoly(*img, &pts[0], pts.size(), color, lineType, shift);
			
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::resizeImage(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//Mat resizeImage(const Mat& src, Size dsize, double fx=0, double fy=0, int interpolation=INTER_LINEAR )
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Size dsize = bea::Convert<cv::Size>::FromJS(args[1], 1);
		double fx = bea::Optional<double>::FromJS(args, 2, 0);
		double fy = bea::Optional<double>::FromJS(args, 3, 0);
		int interpolation = bea::Optional<int>::FromJS(args, 4, INTER_LINEAR);
		cv::Mat tmp;
		cv::resize(*src, tmp, dsize, fx, fy, interpolation);
		cv::Mat* fnRetVal = new Mat(tmp);
			
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::imdecode(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//Mat imdecode(const Mat& buf, int flags)
		cv::Mat* buf = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int flags = bea::Convert<int>::FromJS(args[1], 1);
		cv::Mat* fnRetVal = new cv::Mat(cv::imdecode(*buf, flags));
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::imread(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//Mat imread(const std::string& filename, int flags=1)
		std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
		int flags = bea::Optional<int>::FromJS(args, 1, 1);
		cv::Mat tmp = cv::imread(filename, flags);
		THROW_IF_NOT(tmp.total() > 0, "Couldn't load file");
		cv::Mat* fnRetVal = new Mat(tmp);
			
		return bea::Convert<cv::Mat*>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::imwrite(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//bool imwrite(const std::string& filename, const Mat& img, const std::vector<int>& params=std::vector<int>())
		std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
		cv::Mat* img = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		std::vector<int> params = bea::Optional<std::vector<int> >::FromJS(args, 2, std::vector<int>());
		bool fnRetVal = cv::imwrite(filename, *img, params);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::waitKey(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//int waitKey(int delay = 0)
		int delay = bea::Optional<int>::FromJS(args, 0,  0);
		int fnRetVal = cv::waitKey(delay);
		return bea::Convert<int>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::HoughCircles(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//std::vector<cv::Vec3f> HoughCircles(Mat& image, int method, double dp, double minDist, double param1=100, double param2=100, int minRadius=0, int maxRadius=0)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		int method = bea::Convert<int>::FromJS(args[1], 1);
		double dp = bea::Convert<double>::FromJS(args[2], 2);
		double minDist = bea::Convert<double>::FromJS(args[3], 3);
		double param1 = bea::Optional<double>::FromJS(args, 4, 100);
		double param2 = bea::Optional<double>::FromJS(args, 5, 100);
		int minRadius = bea::Optional<int>::FromJS(args, 6, 0);
		int maxRadius = bea::Optional<int>::FromJS(args, 7, 0);
		std::vector<cv::Vec3f> fnRetVal;
		cv::HoughCircles(*image, fnRetVal, method, dp, minDist, param1, param2, minRadius, maxRadius);
			
		return bea::Convert<std::vector<cv::Vec3f> >::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::HoughLines(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//std::vector<cv::Vec2f> HoughLines(Mat& image, double rho, double theta, int threshold, double srn=0, double stn=0)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double rho = bea::Convert<double>::FromJS(args[1], 1);
		double theta = bea::Convert<double>::FromJS(args[2], 2);
		int threshold = bea::Convert<int>::FromJS(args[3], 3);
		double srn = bea::Optional<double>::FromJS(args, 4, 0);
		double stn = bea::Optional<double>::FromJS(args, 5, 0);
		std::vector<cv::Vec2f> fnRetVal;
		cv::HoughLines(*image, fnRetVal, rho, theta, threshold, srn, stn);
			
		return bea::Convert<std::vector<cv::Vec2f> >::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::preCornerDetect(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void preCornerDetect(const Mat& src, Mat& dst, int apertureSize, int borderType=BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int apertureSize = bea::Convert<int>::FromJS(args[2], 2);
		int borderType = bea::Optional<int>::FromJS(args, 3, BORDER_DEFAULT);
		cv::preCornerDetect(*src, *dst, apertureSize, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::goodFeaturesToTrack(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		//void goodFeaturesToTrack(const Mat& image, std::vector<Point2f>& corners, int maxCorners, double qualityLevel, double minDistance, const Mat& mask=Mat(), int blockSize=3, bool useHarrisDetector=false, double k=0.04)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		std::vector<Point2f> corners = bea::Convert<std::vector<Point2f> >::FromJS(args[1], 1);
		int maxCorners = bea::Convert<int>::FromJS(args[2], 2);
		double qualityLevel = bea::Convert<double>::FromJS(args[3], 3);
		double minDistance = bea::Convert<double>::FromJS(args[4], 4);
		Mat _t = cv::Mat();
		cv::Mat* mask = bea::Optional<cv::Mat*>::FromJS(args, 5, &_t);
		int blockSize = bea::Optional<int>::FromJS(args, 6, 3);
		bool useHarrisDetector = bea::Optional<bool>::FromJS(args, 7, false);
		double k = bea::Optional<double>::FromJS(args, 8, 0.04);
		cv::goodFeaturesToTrack(*image, corners, maxCorners, qualityLevel, minDistance, *mask, blockSize, useHarrisDetector, k);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cornerSubPix(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//std::vector<cv::Point2f> cornerSubPix(const Mat& image, Size winSize, Size zeroZone, TermCriteria criteria)
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Size winSize = bea::Convert<cv::Size>::FromJS(args[1], 1);
		cv::Size zeroZone = bea::Convert<cv::Size>::FromJS(args[2], 2);
		cv::TermCriteria criteria = bea::Convert<cv::TermCriteria>::FromJS(args[3], 3);
		std::vector<cv::Point2f> fnRetVal;
		cv::cornerSubPix(*image, fnRetVal, winSize, zeroZone, criteria);
			
		return bea::Convert<std::vector<cv::Point2f> >::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cornerMinEigenVal(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		//void cornerMinEigenVal(const Mat& src, Mat& dst, int blockSize, int apertureSize=3, int borderType=BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int blockSize = bea::Convert<int>::FromJS(args[2], 2);
		int apertureSize = bea::Optional<int>::FromJS(args, 3, 3);
		int borderType = bea::Optional<int>::FromJS(args, 4, BORDER_DEFAULT);
		cv::cornerMinEigenVal(*src, *dst, blockSize, apertureSize, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cornerHarris(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		//void cornerHarris(const Mat& src, Mat& dst, int blockSize, int apertureSize, double k, int borderType=BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int blockSize = bea::Convert<int>::FromJS(args[2], 2);
		int apertureSize = bea::Convert<int>::FromJS(args[3], 3);
		double k = bea::Convert<double>::FromJS(args[4], 4);
		int borderType = bea::Optional<int>::FromJS(args, 5, BORDER_DEFAULT);
		cv::cornerHarris(*src, *dst, blockSize, apertureSize, k, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::cornerEigenValsAndVecs(const v8::Arguments& args) {
		METHOD_BEGIN(4);
		//void cornerEigenValsAndVecs(const Mat& src, Mat& dst, int blockSize, int apertureSize, int borderType=BORDER_DEFAULT)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int blockSize = bea::Convert<int>::FromJS(args[2], 2);
		int apertureSize = bea::Convert<int>::FromJS(args[3], 3);
		int borderType = bea::Optional<int>::FromJS(args, 4, BORDER_DEFAULT);
		cv::cornerEigenValsAndVecs(*src, *dst, blockSize, apertureSize, borderType);
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::calcHist(const v8::Arguments& args) {
		METHOD_BEGIN(7);
		//void calcHist(std::vector<cv::Mat> arrays, std::vector<int> channels, const Mat& mask, cv::Mat& hist, int dims, std::vector<int> histSize, std::vector<std::vector<float> > ranges, bool uniform = true, bool accumulate = false)
		std::vector<cv::Mat> arrays = bea::Convert<std::vector<cv::Mat> >::FromJS(args[0], 0);
		std::vector<int> channels = bea::Convert<std::vector<int> >::FromJS(args[1], 1);
		cv::Mat* mask = bea::Convert<cv::Mat*>::FromJS(args[2], 2);
		cv::Mat* hist = bea::Convert<cv::Mat*>::FromJS(args[3], 3);
		int dims = bea::Convert<int>::FromJS(args[4], 4);
		std::vector<int> histSize = bea::Convert<std::vector<int> >::FromJS(args[5], 5);
		std::vector<std::vector<float> > ranges = bea::Convert<std::vector<std::vector<float> > >::FromJS(args[6], 6);
		bool uniform = bea::Optional<bool>::FromJS(args, 7,  true);
		bool accumulate = bea::Optional<bool>::FromJS(args, 8,  false);
		std::vector<float*> vranges = std::vector<float*>(ranges.size());
		for (int k = 0 ; k < ranges.size(); k++){
		vranges[k] = &((ranges[k])[0]);
		}
		cv::calcHist(&arrays[0], arrays.size(), &channels[0], *mask, *hist, dims, &histSize[0], (const float**)&vranges[0], uniform, accumulate);
			
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::minMaxLoc(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//minMaxLocRet minMaxLoc(const Mat& a)
		cv::Mat* a = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		minMaxLocRet fnRetVal;
		cv::minMaxLoc(*a, &fnRetVal.minVal, &fnRetVal.maxVal, NULL, NULL);
			
		return bea::Convert<cv::minMaxLocRet>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	void JOpenCV::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedStatic<JOpenCV>* obj = EXPOSE_STATIC(JOpenCV, "OpenCV");
		//Exposed Methods
		obj->exposeMethod("GaussianBlur", GaussianBlur);
		obj->exposeMethod("Canny", Canny);
		obj->exposeMethod("bilateralFilter", bilateralFilter);
		obj->exposeMethod("cvtColor", cvtColor);
		obj->exposeMethod("addWeighted", addWeighted);
		obj->exposeMethod("resize", resize);
		obj->exposeMethod("threshold", threshold);
		obj->exposeMethod("warpAffine", warpAffine);
		obj->exposeMethod("getRotationMatrix2D", getRotationMatrix2D);
		obj->exposeMethod("namedWindow", namedWindow);
		obj->exposeMethod("imshow", imshow);
		obj->exposeMethod("dilate", dilate);
		obj->exposeMethod("erode", erode);
		obj->exposeMethod("absdiff", absdiff);
		obj->exposeMethod("add", add);
		obj->exposeMethod("bitwise_and", bitwise_and);
		obj->exposeMethod("bitwise_not", bitwise_not);
		obj->exposeMethod("bitwise_or", bitwise_or);
		obj->exposeMethod("bitwise_xor", bitwise_xor);
		obj->exposeMethod("calcCovarMatrix", calcCovarMatrix);
		obj->exposeMethod("cartToPolar", cartToPolar);
		obj->exposeMethod("compare", compare);
		obj->exposeMethod("completeSymm", completeSymm);
		obj->exposeMethod("convertScaleAbs", convertScaleAbs);
		obj->exposeMethod("countNonZero", countNonZero);
		obj->exposeMethod("cubeRoot", cubeRoot);
		obj->exposeMethod("dct", dct);
		obj->exposeMethod("dft", dft);
		obj->exposeMethod("divide", divide);
		obj->exposeMethod("determinant", determinant);
		obj->exposeMethod("eigen", eigen);
		obj->exposeMethod("exp", exp);
		obj->exposeMethod("fastAtan2", fastAtan2);
		obj->exposeMethod("flip", flip);
		obj->exposeMethod("gemm", gemm);
		obj->exposeMethod("idct", idct);
		obj->exposeMethod("idft", idft);
		obj->exposeMethod("inRange", inRange);
		obj->exposeMethod("invert", invert);
		obj->exposeMethod("log", log);
		obj->exposeMethod("LUT", LUT);
		obj->exposeMethod("magnitude", magnitude);
		obj->exposeMethod("Mahalanobis", Mahalanobis);
		obj->exposeMethod("max", max);
		obj->exposeMethod("mean", mean);
		obj->exposeMethod("meanStdDev", meanStdDev);
		obj->exposeMethod("min", min);
		obj->exposeMethod("mulSpectrums", mulSpectrums);
		obj->exposeMethod("norm", norm);
		obj->exposeMethod("multiply", multiply);
		obj->exposeMethod("mulTransposed", mulTransposed);
		obj->exposeMethod("normalize", normalize);
		obj->exposeMethod("perspectiveTransform", perspectiveTransform);
		obj->exposeMethod("phase", phase);
		obj->exposeMethod("polarToCart", polarToCart);
		obj->exposeMethod("pow", pow);
		obj->exposeMethod("randu", randu);
		obj->exposeMethod("randn", randn);
		obj->exposeMethod("reduce", reduce);
		obj->exposeMethod("repeat", repeat);
		obj->exposeMethod("scaleAdd", scaleAdd);
		obj->exposeMethod("setIdentity", setIdentity);
		obj->exposeMethod("solve", solve);
		obj->exposeMethod("solveCubic", solveCubic);
		obj->exposeMethod("solvePoly", solvePoly);
		obj->exposeMethod("sort", sort);
		obj->exposeMethod("sortIdx", sortIdx);
		obj->exposeMethod("sqrt", sqrt);
		obj->exposeMethod("subtract", subtract);
		obj->exposeMethod("sum", sum);
		obj->exposeMethod("trace", trace);
		obj->exposeMethod("transform", transform);
		obj->exposeMethod("transpose", transpose);
		obj->exposeMethod("circle", circle);
		obj->exposeMethod("clipLine", clipLine);
		obj->exposeMethod("ellipse", ellipse);
		obj->exposeMethod("line", line);
		obj->exposeMethod("rectangle", rectangle);
		obj->exposeMethod("putText", putText);
		obj->exposeMethod("equalizeHist", equalizeHist);
		obj->exposeMethod("ellipse2Poly", ellipse2Poly);
		obj->exposeMethod("checkRange", checkRange);
		obj->exposeMethod("merge", merge);
		obj->exposeMethod("split", split);
		obj->exposeMethod("fillConvexPoly", fillConvexPoly);
		obj->exposeMethod("resizeImage", resizeImage);
		obj->exposeMethod("imdecode", imdecode);
		obj->exposeMethod("imread", imread);
		obj->exposeMethod("imwrite", imwrite);
		obj->exposeMethod("waitKey", waitKey);
		obj->exposeMethod("HoughCircles", HoughCircles);
		obj->exposeMethod("HoughLines", HoughLines);
		obj->exposeMethod("preCornerDetect", preCornerDetect);
		obj->exposeMethod("goodFeaturesToTrack", goodFeaturesToTrack);
		obj->exposeMethod("cornerSubPix", cornerSubPix);
		obj->exposeMethod("cornerMinEigenVal", cornerMinEigenVal);
		obj->exposeMethod("cornerHarris", cornerHarris);
		obj->exposeMethod("cornerEigenValsAndVecs", cornerEigenValsAndVecs);
		obj->exposeMethod("calcHist", calcHist);
		obj->exposeMethod("calcBackProject", calcBackProject);
		obj->exposeMethod("minMaxLoc", minMaxLoc);
		obj->exposeMethod("cvSmooth", cvSmooth);
		obj->exposeMethod("imencode", imencode);
		obj->exposeMethod("doTick", doTick);
		obj->exposeMethod("discardMats", discardMats);
		obj->exposeMethod("fillPoly", fillPoly);
		obj->exposeMethod("getTextSize", getTextSize);
		obj->exposeMethod("polylines", polylines);
		obj->exposeMethod("kmeans", kmeans);
		obj->exposeMethod("detectObject", detectObject);
		//Accessors
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

DECLARE_EXPOSED_CLASS(cv::CascadeClassifier);
namespace opencvjs {
	v8::Handle<v8::Value> JCascadeClassifier::__constructor(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//CascadeClassifier()
		cv::CascadeClassifier* fnRetVal = new cv::CascadeClassifier();
		return v8::External::New(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JCascadeClassifier::empty(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//bool empty()
		cv::CascadeClassifier* _this = bea::Convert<cv::CascadeClassifier*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->empty();
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JCascadeClassifier::load(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//bool load(const std::string& filename)
		std::string filename = bea::Convert<std::string>::FromJS(args[0], 0);
		cv::CascadeClassifier* _this = bea::Convert<cv::CascadeClassifier*>::FromJS(args.This(), 0);
		bool fnRetVal = _this->load(filename);
		return bea::Convert<bool>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JCascadeClassifier::detectMultiScale(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//std::vector<Rect> detectMultiScale(const Mat& image, double scaleFactor=1.1, int minNeighbours=3, int flags = 0, Size minSize=Size())
		cv::Mat* image = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		double scaleFactor = bea::Optional<double>::FromJS(args, 1, 1.1);
		int minNeighbours = bea::Optional<int>::FromJS(args, 2, 3);
		int flags = bea::Optional<int>::FromJS(args, 3,  0);
		cv::Size minSize = bea::Optional<cv::Size>::FromJS(args, 4, cv::Size());
		cv::CascadeClassifier* _this = bea::Convert<cv::CascadeClassifier*>::FromJS(args.This(), 0);
		std::vector<cv::Rect> fnRetVal;
		_this->detectMultiScale(*image, fnRetVal, scaleFactor, minNeighbours, flags, minSize);
			
		return bea::Convert<std::vector<Rect> >::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JCascadeClassifier::__postAllocator(const v8::Arguments& args) {
		METHOD_BEGIN(0);
		//void __postAllocator()
		cv::CascadeClassifier* _this = bea::Convert<cv::CascadeClassifier*>::FromJS(args.This(), 0);
		return args.This();
		METHOD_END();
	}
	
	void JCascadeClassifier::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedClass<cv::CascadeClassifier>* obj = EXPOSE_CLASS(cv::CascadeClassifier, "CascadeClassifier");
		//Exposed Methods
		obj->setConstructor(__constructor);
		obj->exposeMethod("empty", empty);
		obj->exposeMethod("load", load);
		obj->exposeMethod("detectMultiScale", detectMultiScale);
		obj->setPostAllocator(__postAllocator);
		//Accessors
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

namespace opencvjs {
	void ExposeConstants(v8::Handle<v8::Object> target) {
		BEA_DEFINE_CONSTANT(target, CV_8U);
		BEA_DEFINE_CONSTANT(target, CV_8S);
		BEA_DEFINE_CONSTANT(target, CV_16U);
		BEA_DEFINE_CONSTANT(target, CV_16S);
		BEA_DEFINE_CONSTANT(target, CV_32S);
		BEA_DEFINE_CONSTANT(target, CV_32F);
		BEA_DEFINE_CONSTANT(target, CV_64F);
		BEA_DEFINE_CONSTANT(target, CV_USRTYPE1);
		BEA_DEFINE_CONSTANT(target, CV_8UC1);
		BEA_DEFINE_CONSTANT(target, CV_8UC2);
		BEA_DEFINE_CONSTANT(target, CV_8UC3);
		BEA_DEFINE_CONSTANT(target, CV_8UC4);
		BEA_DEFINE_CONSTANT(target, CV_8SC1);
		BEA_DEFINE_CONSTANT(target, CV_8SC2);
		BEA_DEFINE_CONSTANT(target, CV_8SC3);
		BEA_DEFINE_CONSTANT(target, CV_8SC4);
		BEA_DEFINE_CONSTANT(target, CV_16UC1);
		BEA_DEFINE_CONSTANT(target, CV_16UC2);
		BEA_DEFINE_CONSTANT(target, CV_16UC3);
		BEA_DEFINE_CONSTANT(target, CV_16UC4);
		BEA_DEFINE_CONSTANT(target, CV_16SC1);
		BEA_DEFINE_CONSTANT(target, CV_16SC2);
		BEA_DEFINE_CONSTANT(target, CV_16SC3);
		BEA_DEFINE_CONSTANT(target, CV_16SC4);
		BEA_DEFINE_CONSTANT(target, CV_32SC1);
		BEA_DEFINE_CONSTANT(target, CV_32SC2);
		BEA_DEFINE_CONSTANT(target, CV_32SC3);
		BEA_DEFINE_CONSTANT(target, CV_32SC4);
		BEA_DEFINE_CONSTANT(target, CV_32FC1);
		BEA_DEFINE_CONSTANT(target, CV_32FC2);
		BEA_DEFINE_CONSTANT(target, CV_32FC3);
		BEA_DEFINE_CONSTANT(target, CV_32FC4);
		BEA_DEFINE_CONSTANT(target, CV_64FC1);
		BEA_DEFINE_CONSTANT(target, CV_64FC2);
		BEA_DEFINE_CONSTANT(target, CV_64FC3);
		BEA_DEFINE_CONSTANT(target, CV_64FC4);
		BEA_DEFINE_CONSTANT(target, CV_BGR2BGRA);
		BEA_DEFINE_CONSTANT(target, CV_RGB2RGBA);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2BGR);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2RGBA);
		BEA_DEFINE_CONSTANT(target, CV_RGB2BGRA);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2RGB);
		BEA_DEFINE_CONSTANT(target, CV_RGB2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2RGBA);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2BGRA);
		BEA_DEFINE_CONSTANT(target, CV_BGR2GRAY);
		BEA_DEFINE_CONSTANT(target, CV_RGB2GRAY);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2BGR);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2RGB);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2BGRA);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2RGBA);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2GRAY);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2GRAY);
		BEA_DEFINE_CONSTANT(target, CV_BGR2BGR565);
		BEA_DEFINE_CONSTANT(target, CV_RGB2BGR565);
		BEA_DEFINE_CONSTANT(target, CV_BGR5652BGR);
		BEA_DEFINE_CONSTANT(target, CV_BGR5652RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2BGR565);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2BGR565);
		BEA_DEFINE_CONSTANT(target, CV_BGR5652BGRA);
		BEA_DEFINE_CONSTANT(target, CV_BGR5652RGBA);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2BGR565);
		BEA_DEFINE_CONSTANT(target, CV_BGR5652GRAY);
		BEA_DEFINE_CONSTANT(target, CV_BGR2BGR555);
		BEA_DEFINE_CONSTANT(target, CV_RGB2BGR555);
		BEA_DEFINE_CONSTANT(target, CV_BGR5552BGR);
		BEA_DEFINE_CONSTANT(target, CV_BGR5552RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGRA2BGR555);
		BEA_DEFINE_CONSTANT(target, CV_RGBA2BGR555);
		BEA_DEFINE_CONSTANT(target, CV_BGR5552BGRA);
		BEA_DEFINE_CONSTANT(target, CV_BGR5552RGBA);
		BEA_DEFINE_CONSTANT(target, CV_GRAY2BGR555);
		BEA_DEFINE_CONSTANT(target, CV_BGR5552GRAY);
		BEA_DEFINE_CONSTANT(target, CV_BGR2XYZ);
		BEA_DEFINE_CONSTANT(target, CV_RGB2XYZ);
		BEA_DEFINE_CONSTANT(target, CV_XYZ2BGR);
		BEA_DEFINE_CONSTANT(target, CV_XYZ2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2YCrCb);
		BEA_DEFINE_CONSTANT(target, CV_RGB2YCrCb);
		BEA_DEFINE_CONSTANT(target, CV_YCrCb2BGR);
		BEA_DEFINE_CONSTANT(target, CV_YCrCb2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2HSV);
		BEA_DEFINE_CONSTANT(target, CV_RGB2HSV);
		BEA_DEFINE_CONSTANT(target, CV_BGR2Lab);
		BEA_DEFINE_CONSTANT(target, CV_RGB2Lab);
		BEA_DEFINE_CONSTANT(target, CV_BayerBG2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BayerGB2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BayerRG2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BayerGR2BGR);
		BEA_DEFINE_CONSTANT(target, CV_BayerBG2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BayerGB2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BayerRG2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BayerGR2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2Luv);
		BEA_DEFINE_CONSTANT(target, CV_RGB2Luv);
		BEA_DEFINE_CONSTANT(target, CV_BGR2HLS);
		BEA_DEFINE_CONSTANT(target, CV_RGB2HLS);
		BEA_DEFINE_CONSTANT(target, CV_HSV2BGR);
		BEA_DEFINE_CONSTANT(target, CV_HSV2RGB);
		BEA_DEFINE_CONSTANT(target, CV_Lab2BGR);
		BEA_DEFINE_CONSTANT(target, CV_Lab2RGB);
		BEA_DEFINE_CONSTANT(target, CV_Luv2BGR);
		BEA_DEFINE_CONSTANT(target, CV_Luv2RGB);
		BEA_DEFINE_CONSTANT(target, CV_HLS2BGR);
		BEA_DEFINE_CONSTANT(target, CV_HLS2RGB);
		BEA_DEFINE_CONSTANT(target, CV_BayerBG2BGR_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerGB2BGR_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerRG2BGR_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerGR2BGR_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerBG2RGB_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerGB2RGB_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerRG2RGB_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BayerGR2RGB_VNG);
		BEA_DEFINE_CONSTANT(target, CV_BGR2HSV_FULL);
		BEA_DEFINE_CONSTANT(target, CV_RGB2HSV_FULL);
		BEA_DEFINE_CONSTANT(target, CV_BGR2HLS_FULL);
		BEA_DEFINE_CONSTANT(target, CV_RGB2HLS_FULL);
		BEA_DEFINE_CONSTANT(target, CV_HSV2BGR_FULL);
		BEA_DEFINE_CONSTANT(target, CV_HSV2RGB_FULL);
		BEA_DEFINE_CONSTANT(target, CV_HLS2BGR_FULL);
		BEA_DEFINE_CONSTANT(target, CV_HLS2RGB_FULL);
		BEA_DEFINE_CONSTANT(target, CV_LBGR2Lab);
		BEA_DEFINE_CONSTANT(target, CV_LRGB2Lab);
		BEA_DEFINE_CONSTANT(target, CV_LBGR2Luv);
		BEA_DEFINE_CONSTANT(target, CV_LRGB2Luv);
		BEA_DEFINE_CONSTANT(target, CV_Lab2LBGR);
		BEA_DEFINE_CONSTANT(target, CV_Lab2LRGB);
		BEA_DEFINE_CONSTANT(target, CV_Luv2LBGR);
		BEA_DEFINE_CONSTANT(target, CV_Luv2LRGB);
		BEA_DEFINE_CONSTANT(target, CV_BGR2YUV);
		BEA_DEFINE_CONSTANT(target, CV_RGB2YUV);
		BEA_DEFINE_CONSTANT(target, CV_YUV2BGR);
		BEA_DEFINE_CONSTANT(target, CV_YUV2RGB);
		BEA_DEFINE_CONSTANT(target, THRESH_BINARY);
		BEA_DEFINE_CONSTANT(target, THRESH_BINARY_INV);
		BEA_DEFINE_CONSTANT(target, THRESH_TRUNC);
		BEA_DEFINE_CONSTANT(target, THRESH_TOZERO);
		BEA_DEFINE_CONSTANT(target, THRESH_TOZERO_INV);
		BEA_DEFINE_CONSTANT(target, THRESH_MASK);
		BEA_DEFINE_CONSTANT(target, THRESH_OTSU);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_SCRAMBLED);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_NORMAL);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_USE_AVG);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_SCALE);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_ROWS);
		BEA_DEFINE_CONSTANT(target, CV_COVAR_COLS);
		BEA_DEFINE_CONSTANT(target, DECOMP_LU);
		BEA_DEFINE_CONSTANT(target, DECOMP_SVD);
		BEA_DEFINE_CONSTANT(target, DECOMP_EIG);
		BEA_DEFINE_CONSTANT(target, DECOMP_CHOLESKY);
		BEA_DEFINE_CONSTANT(target, DECOMP_QR);
		BEA_DEFINE_CONSTANT(target, DECOMP_NORMAL);
		BEA_DEFINE_CONSTANT(target, NORM_INF);
		BEA_DEFINE_CONSTANT(target, NORM_L1);
		BEA_DEFINE_CONSTANT(target, NORM_L2);
		BEA_DEFINE_CONSTANT(target, NORM_TYPE_MASK);
		BEA_DEFINE_CONSTANT(target, NORM_RELATIVE);
		BEA_DEFINE_CONSTANT(target, NORM_MINMAX);
		BEA_DEFINE_CONSTANT(target, CMP_EQ);
		BEA_DEFINE_CONSTANT(target, CMP_GT);
		BEA_DEFINE_CONSTANT(target, CMP_GE);
		BEA_DEFINE_CONSTANT(target, CMP_LT);
		BEA_DEFINE_CONSTANT(target, CMP_LE);
		BEA_DEFINE_CONSTANT(target, CMP_NE);
		BEA_DEFINE_CONSTANT(target, GEMM_1_T);
		BEA_DEFINE_CONSTANT(target, GEMM_2_T);
		BEA_DEFINE_CONSTANT(target, GEMM_3_T);
		BEA_DEFINE_CONSTANT(target, DFT_INVERSE);
		BEA_DEFINE_CONSTANT(target, DFT_SCALE);
		BEA_DEFINE_CONSTANT(target, DFT_ROWS);
		BEA_DEFINE_CONSTANT(target, DFT_COMPLEX_OUTPUT);
		BEA_DEFINE_CONSTANT(target, DFT_REAL_OUTPUT);
		BEA_DEFINE_CONSTANT(target, DCT_INVERSE);
		BEA_DEFINE_CONSTANT(target, DCT_ROWS);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_BINARY);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_BINARY_INV);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_TRUNC);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_TOZERO);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_TOZERO_INV);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_MASK);
		BEA_DEFINE_CONSTANT(target, CV_THRESH_OTSU);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_MOUSEMOVE);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONDOWN);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONDOWN);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONDOWN);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONUP);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONUP);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONUP);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONDBLCLK);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONDBLCLK);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONDBLCLK);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_LBUTTON);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_RBUTTON);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_MBUTTON);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_CTRLKEY);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_SHIFTKEY);
		BEA_DEFINE_CONSTANT(target, CV_EVENT_FLAG_ALTKEY);
		BEA_DEFINE_CONSTANT(target, CV_INTER_NN);
		BEA_DEFINE_CONSTANT(target, CV_INTER_LINEAR);
		BEA_DEFINE_CONSTANT(target, CV_INTER_CUBIC);
		BEA_DEFINE_CONSTANT(target, CV_INTER_AREA);
		BEA_DEFINE_CONSTANT(target, CV_INTER_LANCZOS4);
		BEA_DEFINE_CONSTANT(target, CV_WARP_FILL_OUTLIERS);
		BEA_DEFINE_CONSTANT(target, CV_WARP_INVERSE_MAP);
		BEA_DEFINE_CONSTANT(target, CV_SHAPE_RECT);
		BEA_DEFINE_CONSTANT(target, CV_SHAPE_CROSS);
		BEA_DEFINE_CONSTANT(target, CV_SHAPE_ELLIPSE);
		BEA_DEFINE_CONSTANT(target, CV_SHAPE_CUSTOM);
		BEA_DEFINE_CONSTANT(target, CV_MOP_ERODE);
		BEA_DEFINE_CONSTANT(target, CV_MOP_DILATE);
		BEA_DEFINE_CONSTANT(target, CV_MOP_OPEN);
		BEA_DEFINE_CONSTANT(target, CV_MOP_CLOSE);
		BEA_DEFINE_CONSTANT(target, CV_MOP_GRADIENT);
		BEA_DEFINE_CONSTANT(target, CV_MOP_TOPHAT);
		BEA_DEFINE_CONSTANT(target, CV_MOP_BLACKHAT);
		BEA_DEFINE_CONSTANT(target, CV_TM_SQDIFF);
		BEA_DEFINE_CONSTANT(target, CV_TM_SQDIFF_NORMED);
		BEA_DEFINE_CONSTANT(target, CV_TM_CCORR);
		BEA_DEFINE_CONSTANT(target, CV_TM_CCORR_NORMED);
		BEA_DEFINE_CONSTANT(target, CV_TM_CCOEFF);
		BEA_DEFINE_CONSTANT(target, CV_TM_CCOEFF_NORMED);
		BEA_DEFINE_CONSTANT(target, CV_RETR_EXTERNAL);
		BEA_DEFINE_CONSTANT(target, CV_RETR_LIST);
		BEA_DEFINE_CONSTANT(target, CV_RETR_CCOMP);
		BEA_DEFINE_CONSTANT(target, CV_RETR_TREE);
		BEA_DEFINE_CONSTANT(target, CV_CHAIN_CODE);
		BEA_DEFINE_CONSTANT(target, CV_CHAIN_APPROX_NONE);
		BEA_DEFINE_CONSTANT(target, CV_CHAIN_APPROX_SIMPLE);
		BEA_DEFINE_CONSTANT(target, CV_CHAIN_APPROX_TC89_L1);
		BEA_DEFINE_CONSTANT(target, CV_CHAIN_APPROX_TC89_KCOS);
		BEA_DEFINE_CONSTANT(target, CV_LINK_RUNS);
		BEA_DEFINE_CONSTANT(target, CV_PTLOC_ERROR);
		BEA_DEFINE_CONSTANT(target, CV_PTLOC_OUTSIDE_RECT);
		BEA_DEFINE_CONSTANT(target, CV_PTLOC_INSIDE);
		BEA_DEFINE_CONSTANT(target, CV_PTLOC_VERTEX);
		BEA_DEFINE_CONSTANT(target, CV_PTLOC_ON_EDGE);
		BEA_DEFINE_CONSTANT(target, CV_NEXT_AROUND_ORG);
		BEA_DEFINE_CONSTANT(target, CV_NEXT_AROUND_DST);
		BEA_DEFINE_CONSTANT(target, CV_PREV_AROUND_ORG);
		BEA_DEFINE_CONSTANT(target, CV_PREV_AROUND_DST);
		BEA_DEFINE_CONSTANT(target, CV_NEXT_AROUND_LEFT);
		BEA_DEFINE_CONSTANT(target, CV_NEXT_AROUND_RIGHT);
		BEA_DEFINE_CONSTANT(target, CV_PREV_AROUND_LEFT);
		BEA_DEFINE_CONSTANT(target, CV_PREV_AROUND_RIGHT);
		BEA_DEFINE_CONSTANT(target, CV_POLY_APPROX_DP);
		BEA_DEFINE_CONSTANT(target, CV_CONTOURS_MATCH_I1);
		BEA_DEFINE_CONSTANT(target, CV_CONTOURS_MATCH_I2);
		BEA_DEFINE_CONSTANT(target, CV_CONTOURS_MATCH_I3);
		BEA_DEFINE_CONSTANT(target, CV_CLOCKWISE);
		BEA_DEFINE_CONSTANT(target, CV_COUNTER_CLOCKWISE);
		BEA_DEFINE_CONSTANT(target, CV_COMP_CORREL);
		BEA_DEFINE_CONSTANT(target, CV_COMP_CHISQR);
		BEA_DEFINE_CONSTANT(target, CV_COMP_INTERSECT);
		BEA_DEFINE_CONSTANT(target, CV_COMP_BHATTACHARYYA);
		BEA_DEFINE_CONSTANT(target, CV_DIST_MASK_3);
		BEA_DEFINE_CONSTANT(target, CV_DIST_MASK_5);
		BEA_DEFINE_CONSTANT(target, CV_DIST_MASK_PRECISE);
		BEA_DEFINE_CONSTANT(target, CV_DIST_USER);
		BEA_DEFINE_CONSTANT(target, CV_DIST_L1);
		BEA_DEFINE_CONSTANT(target, CV_DIST_L2);
		BEA_DEFINE_CONSTANT(target, CV_DIST_C);
		BEA_DEFINE_CONSTANT(target, CV_DIST_L12);
		BEA_DEFINE_CONSTANT(target, CV_DIST_FAIR);
		BEA_DEFINE_CONSTANT(target, CV_DIST_WELSCH);
		BEA_DEFINE_CONSTANT(target, CV_DIST_HUBER);
		BEA_DEFINE_CONSTANT(target, CV_ADAPTIVE_THRESH_MEAN_C);
		BEA_DEFINE_CONSTANT(target, CV_ADAPTIVE_THRESH_GAUSSIAN_C);
		BEA_DEFINE_CONSTANT(target, CV_FLOODFILL_FIXED_RANGE);
		BEA_DEFINE_CONSTANT(target, CV_FLOODFILL_MASK_ONLY);
		BEA_DEFINE_CONSTANT(target, CV_CANNY_L2_GRADIENT);
		BEA_DEFINE_CONSTANT(target, CV_HOUGH_PROBABILISTIC);
		BEA_DEFINE_CONSTANT(target, CV_HOUGH_STANDARD);
		BEA_DEFINE_CONSTANT(target, CV_HOUGH_MULTI_SCALE);
		BEA_DEFINE_CONSTANT(target, CV_HOUGH_GRADIENT);
		BEA_DEFINE_CONSTANT(target, CV_BLUR_NO_SCALE);
		BEA_DEFINE_CONSTANT(target, CV_BLUR);
		BEA_DEFINE_CONSTANT(target, CV_GAUSSIAN);
		BEA_DEFINE_CONSTANT(target, CV_MEDIAN);
		BEA_DEFINE_CONSTANT(target, CV_BILATERAL);
		BEA_DEFINE_CONSTANT(target, CV_GAUSSIAN_5x5);
		BEA_DEFINE_CONSTANT(target, CV_SCHARR);
		BEA_DEFINE_CONSTANT(target, CV_MAX_SOBEL_KSIZE);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_SIMPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_PLAIN);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_DUPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_COMPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_TRIPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_COMPLEX_SMALL);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_SCRIPT_SIMPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_HERSHEY_SCRIPT_COMPLEX);
		BEA_DEFINE_CONSTANT(target, FONT_ITALIC);
		BEA_DEFINE_CONSTANT(target, CV_FILLED);
	}
	
}

namespace opencvjs {
	void Project::expose(v8::Handle<v8::Object> target) {
		JMat::_InitJSObject(target);
		JVideoCapture::_InitJSObject(target);
		JVideoWriter::_InitJSObject(target);
		JSparseMat::_InitJSObject(target);
		JOpenCV::_InitJSObject(target);
		JCascadeClassifier::_InitJSObject(target);
		ExposeConstants(target);
	}
	
}
