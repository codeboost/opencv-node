#ifndef __CVCHECK_H__
#define __CVCHECK_H__
#define THROW_EXCEPTION(msg) return v8::ThrowException(v8::Exception::TypeError(v8::String::New(msg)))

//Throw if images have different size
#define REQUIRE_SAME_SIZE(src, dst) if (src->size() != dst->size()) THROW_EXCEPTION("Images must have the same size")

//Throws if images have different type
#define REQUIRE_SAME_TYPE(src, dst) if (src->type() != dst->type()) THROW_EXCEPTION("Images must have the same type")

//Throw if images have different size/type
#define REQUIRE_SAME_SIZE_TYPE(src, dst) if (src->size() != dst->size() || src->type() != dst->type()) THROW_EXCEPTION("Images must have same size and type")

//Throws if expression is false
#define THROW_IF_NOT(expr, msg) if (!(expr)) {return v8::ThrowException(v8::Exception::RangeError(v8::String::New((msg))));}
#endif //__CVCHECK_H__
