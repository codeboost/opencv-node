#ifndef OPENCVJS_H
#define OPENCVJS_H
#include <v8.h>
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
			static v8::Handle<v8::Value> cvSmooth(const v8::Arguments& args);
			static v8::Handle<v8::Value> discardMats(const v8::Arguments& args);
			static v8::Handle<v8::Value> fillPoly(const v8::Arguments& args);
			static v8::Handle<v8::Value> getTextSize(const v8::Arguments& args);
			static v8::Handle<v8::Value> polylines(const v8::Arguments& args);
			static v8::Handle<v8::Value> kmeans(const v8::Arguments& args);
			static v8::Handle<v8::Value> calcHist(const v8::Arguments& args);
			static v8::Handle<v8::Value> calcBackProject(const v8::Arguments& args);
			static v8::Handle<v8::Value> detectObject(const v8::Arguments& args);
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