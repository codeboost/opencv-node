#ifndef __CUSTOMTYPES_H__
#define __CUSTOMTYPES_H__
#include "bea.h"
#include <cv.hpp>
#include <vector>

namespace cv{

		//Helper structure used as return type for the function mixMaxLoc
		struct minMaxLocRet{
			double minVal;
			double maxVal; 
			int minIdx;
			int maxIdx;
			minMaxLocRet(){
				minVal = maxVal = 0.0;
				minIdx = maxIdx = 0; 
			}
	};
}

namespace bea{

	template<> struct Convert<cv::Vec3f>{

		static bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsArray();
		}

		static cv::Vec3f FromJS(v8::Handle<v8::Value> v, int nArg){
			const char* msg = "Array of 3 values expected (Vec3f)";
			if (!Is(v)) BEATHROW();

			v8::HandleScope scope; 

			std::vector<float> vec = Convert<std::vector<float> >::FromJS(v, nArg);

			if (vec.size() < 3)
				BEATHROW();

			cv::Vec3f ret;
			ret[0] = vec[0];
			ret[1] = vec[1];
			ret[2] = vec[2];
			return ret; 
		}

		static v8::Handle<v8::Value> ToJS(cv::Vec3f const& v){

			std::vector<float> ret;
			ret.push_back(v[0]);
			ret.push_back(v[1]);
			ret.push_back(v[2]);

			return Convert<std::vector<float> >::ToJS(ret);
		}

	};

	template<> struct Convert<cv::Vec2f>{

		static bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsArray();
		}

		static cv::Vec2f FromJS(v8::Handle<v8::Value> v, int nArg){
			const char* msg = "Array of 2 values expected (Vec3f)";
			if (!Is(v)) BEATHROW();

			v8::HandleScope scope; 

			std::vector<float> vec = Convert<std::vector<float> >::FromJS(v, nArg);

			if (vec.size() < 2)
				BEATHROW();

			cv::Vec2f ret;

			ret[0] = vec[0];
			ret[1] = vec[1];
			return ret; 
		}

		static v8::Handle<v8::Value> ToJS(cv::Vec2f const& v){
			std::vector<float> ret;
			ret.push_back(v[0]);
			ret.push_back(v[1]);
			return Convert<std::vector<float> >::ToJS(ret);
		}

	};


	template<> struct Convert<cv::Scalar> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsArray();
		}

		static cv::Scalar FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Array of 3 or 4 values expected (cv::Scalar)";
			if (!Is(v)) BEATHROW();

			v8::HandleScope scope;
			std::vector<double> vec = Convert<std::vector<double> >::FromJS(v, nArg);

			if (vec.size() < 3 || vec.size() > 4)
				BEATHROW();

			cv::Scalar ret; 

			for (int k = 0; k < (int)vec.size(); k++){
				ret[k] = vec[k];
			}
			return ret;
		}

		static v8::Handle<v8::Value> ToJS(cv::Scalar const& v) {
			v8::HandleScope scope;

			std::vector<double> retV;

			for (int k = 0; k < 4; k++)
				retV.push_back(v[k]);

			return Convert<std::vector<double> >::ToJS(retV);
		}
	};

	//////////////////////////////////////////////////////////////////////////

	//Fortunately, this is possible for cv::Mat, because of the reference 
	//counting which cv::Mat implements.
	//Converting from vector<cv::Mat*> -> vector<cv::Mat>
	template<> struct Convert<std::vector<cv::Mat> >{

		static bool Is(v8::Handle<v8::Value> v){
			return Convert<std::vector<cv::Mat*> >::Is(v);
		}

		static std::vector<cv::Mat> FromJS(v8::Handle<v8::Value> v, int nArg){
			std::vector<cv::Mat*> matV = Convert<std::vector<cv::Mat*> > ::FromJS(v, nArg);
			std::vector<cv::Mat> ret; 
			for (size_t k = 0; k < matV.size(); k++)
				ret.push_back(*matV[k]);
			return ret; 
		}

		static v8::Handle<v8::Value> ToJS(const std::vector<cv::Mat>& val){
			std::vector<cv::Mat*> retVal;
			for (size_t k = 0; k < val.size(); k++)
				retVal.push_back (new cv::Mat(val[k]));

			return Convert<std::vector<cv::Mat*> >::ToJS(retVal);
		}
	};


}

#endif //__CUSTOMTYPES_H__