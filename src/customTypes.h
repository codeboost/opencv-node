#ifndef __CUSTOMTYPES_H__
#define __CUSTOMTYPES_H__
#include "bea.h"
#include <cv.hpp>
#include <vector>

namespace bea{
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
	};

}

#endif //__CUSTOMTYPES_H__