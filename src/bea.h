#ifndef __BEA_H__
#define __BEA_H__

#include <v8.h>
#include <vector>
#include <sstream>
#include <map>
#include <assert.h>
#include <memory>

namespace bea{
	class Exception{
	protected:
		v8::Handle<v8::Value> m_exception; 

	public:
		Exception(){}
		Exception(const char* message){
			m_exception = v8::ThrowException(v8::Exception::TypeError(v8::String::NewSymbol(message)));
		}
		inline v8::Handle<v8::Value> v8exception(){
			return m_exception;
		}
	};

	class ArgConvertException : public Exception{
	public:
		ArgConvertException(int arg, const char* message){
			std::stringstream s; 
			s << "Argument " << arg << ": " << message; 
			m_exception = v8::ThrowException(v8::Exception::TypeError(v8::String::NewSymbol(s.str().c_str())));
		}
	};

//////////////////////////////////////////////////////////////////////////

#define BEATHROW() throw bea::ArgConvertException(nArg, msg)

	class Indexable{
	public:
		void setPtr(void* ptr, int size, int type){}
	};

	class BeaBuffer{
		char* m_buffer;
		int m_size;
		int m_type;
	public:
		inline BeaBuffer(int size, int type){
			m_buffer = new char[size];
			m_size = size;
			m_type = type;
		}
		inline ~BeaBuffer(){
			delete[] m_buffer;
		}

		inline void* ptr(){
			return m_buffer;
		}

		inline int size(){
			return m_size;
		}

		inline int type(){
			return m_type;
		}


	};


	template<class T>
	class vector : public std::vector<T>
	{
	public:
		operator T* (){
			return &(this->operator[](0));
		}
	};


	class string: public std::string{
	public:
		string(){}
		string(const char* s): std::string(s){}
		
		operator const char* (){
			return this->c_str();
		}
	};

	template<class T>
	class external{
	protected:
		external(){}
	public:
		void* ptr;
		external(T* p): ptr(p){

		}
		operator T*(){
			return (T*)ptr;
		}
	};


	template <class T>
	struct Convert{
		static bool Is(v8::Handle<v8::Value> v);
		static T FromJS(v8::Handle<v8::Value> v, int nArg);
		static v8::Handle<v8::Value> ToJS(const T& val);
	};
	
	template<class T>
	struct Optional{

		static inline T FromJS(const v8::Arguments& args, int nArg, const T& def){
			if (args.Length() > nArg)
				return Convert<T>::FromJS(args[nArg], nArg);
			return def;
		}

		static inline bool Is(const v8::Arguments& args, int nArg){
			if (args.Length() > nArg)
				return Convert<T>::Is(args[nArg]);
			return true;
		}
	};	

	//Int
	template<>
	struct Convert<int> {
		
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsInt32();
		}

		static inline int FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer expected";
			if (!Is(v)) 
				BEATHROW();
			return v->Int32Value();
		}

		static v8::Handle<v8::Value> ToJS(const int& val){
			return v8::Integer::New(val);
		}
	};

	//Double
	template<>
	struct Convert<double>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return (!v.IsEmpty() && v->IsNumber());
		}

		static inline double FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Number expected";

			if (!Is(v))
				BEATHROW();

			return v->NumberValue();
		}

		static inline v8::Handle<v8::Value> ToJS(const double& val){
			return v8::Number::New(val);
		}
	};

	//Float
	template<>
	struct Convert<float>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return Convert<double>::Is(v);
		}
		static inline float FromJS(v8::Handle<v8::Value> v, int nArg){
			return (float)Convert<double>::FromJS(v, nArg);
		}
		static inline v8::Handle<v8::Value> ToJS(const float& val){
			return Convert<double>::ToJS(val);
		}
	};


	//Bool
	template<>
	struct Convert<bool>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsBoolean();
		}
		static inline bool FromJS(v8::Handle<v8::Value> v, int nArg){

			static const char* msg = "Boolean value expected";
			if (!Is(v)) BEATHROW();

			return v->BooleanValue();
		}

		static inline v8::Handle<v8::Value> ToJS(const bool& val){
			return v8::Boolean::New(val);
		}
	};

	//bea::string
	template<>
	struct Convert<bea::string>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsString();
		}

		static inline bea::string FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "v8::String expected";

			if (!Is(v))	
				BEATHROW();

			return  *v8::String::AsciiValue(v->ToString());
		}

		static inline v8::Handle<v8::Value> ToJS(const bea::string& val){
			return v8::String::New (val.c_str());
		}
	};

	//std::string
	template<>
	struct Convert<std::string>{
		static bool Is(v8::Handle<v8::Value> v){
			return Convert<bea::string>::Is(v);
		}

		static inline std::string FromJS(v8::Handle<v8::Value> v, int nArg){
			return Convert<bea::string>::FromJS(v, nArg);
		}

		static inline v8::Handle<v8::Value> ToJS(const std::string& val){
			return Convert<bea::string>::ToJS((const bea::string&)val);
		}
	};

	//bea::vector<T>
	template<class T>
	struct Convert<bea::vector<T> >{

		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsArray();
		}

		static inline bea::vector<T> FromJS(v8::Handle<v8::Value> v, int nArg){

			static const char* msg = "Array expected";

			if (!Is(v)) BEATHROW();

			bea::vector<T> ret;

			v8::Local<v8::Array> array = v8::Array::Cast(*v);

			size_t len = (size_t)array->Length() ;

			for (size_t k = 0; k < len; k++)
			{
				ret.push_back(Convert<T>::FromJS(array->Get((int32_t)k), nArg));
			}

			return ret; 
		}

		static inline v8::Handle<v8::Value> ToJS(const bea::vector<T>& val){

			v8::HandleScope scope; 
			int len = (int)val.size();
			v8::Local<v8::Array> jsArray = v8::Array::New(len);

			for (int i = 0; i < len; i++)
				jsArray->Set(i, Convert<T>::ToJS(val[i]));

			return scope.Close(jsArray);

		}
	};
	
	//std::vector<T>
	template<class T>
	struct Convert<std::vector<T> >{
		static bool Is(v8::Handle<v8::Value> v){
			return Convert<bea::vector<T> >::Is(v);
		}

		static inline std::vector<T> FromJS(v8::Handle<v8::Value> v, int nArg){
			return Convert<bea::vector<T> >::FromJS(v, nArg);
		}

		static inline v8::Handle<v8::Value> ToJS(const std::vector<T>& val){
			return Convert<bea::vector<T> >::ToJS((const bea::vector<T>&)val);
		}
	};
	
	///???
	template<>
	struct Convert<char>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsInt32();
		}

		static inline char FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer(byte) value expected";
			if (!Is(v)) BEATHROW();

			return (char)v->Int32Value();
		}

		static inline v8::Handle<v8::Value> ToJS(const char& val){
			return v8::Int32::New(val);
		}
	};	
	//unsigned char
	template<>
	struct Convert<unsigned char>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsUint32();
		}

		static inline unsigned char FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer(byte) value expected";
			if (!Is(v)) BEATHROW();

			return (unsigned char)v->Uint32Value();
		}

		static inline v8::Handle<v8::Value> ToJS(const unsigned char& val){
			return v8::Uint32::New(val);
		}
	};
	//short
	template <>
	struct Convert<short>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsInt32();
		}
		static inline short FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer(byte) value expected";
			if (!Is(v)) BEATHROW();
			return v->Int32Value() & 0xffff;
		}

		static inline v8::Handle<v8::Value> ToJS(const short& val){
			return v8::Int32::New(val);
		}
	};
	//unsigned short
	template <>
	struct Convert<unsigned short>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsUint32();
		}
		static inline unsigned short FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer(byte) value expected";
			if (!Is(v)) BEATHROW();
			return v->Uint32Value() & 0xffff;
		}

		static inline v8::Handle<v8::Value> ToJS(const unsigned short& val){
			return v8::Uint32::New(val);
		}
	};

	template <>
	struct Convert<unsigned int>{
		static inline bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsUint32();
		}
		static inline unsigned int FromJS(v8::Handle<v8::Value> v, int nArg){
			static const char* msg = "Integer(byte) value expected";
			if (!Is(v)) BEATHROW();
			return v->Uint32Value();
		}

		static inline v8::Handle<v8::Value> ToJS(const unsigned int& val){
			return v8::Uint32::New(val);
		}
	};

	template<> struct Convert<unsigned long> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::Convert<unsigned int>::Is(v);
		}

		static unsigned long FromJS(v8::Handle<v8::Value> v, int nArg) {
			return (unsigned long)bea::Convert<unsigned int>::FromJS(v, nArg);
		}

		static v8::Handle<v8::Value> ToJS(unsigned long const& v) {
			return bea::Convert<unsigned int>::ToJS(v);
		}

	};

	template<> struct Convert<long> {
		static bool Is(v8::Handle<v8::Value> v) {
			return bea::Convert<int>::Is(v);
		}

		static unsigned long FromJS(v8::Handle<v8::Value> v, int nArg) {
			return (long)bea::Convert<int>::FromJS(v, nArg);
		}

		static v8::Handle<v8::Value> ToJS(long const& v) {
			return bea::Convert<int>::ToJS((int const&)v);
		}

	};


	typedef void (*reportExceptionCb)(v8::TryCatch&);

	struct Global{
		static v8::Persistent<v8::ObjectTemplate> externalTemplate; 
		static std::string scriptDir;
		static reportExceptionCb reportException;

		static void InitExternalTemplate(){
			v8::HandleScope scope; 
			v8::Handle<v8::ObjectTemplate> otmpl = v8::ObjectTemplate::New();
			otmpl->SetInternalFieldCount(2);
			externalTemplate = v8::Persistent<v8::ObjectTemplate>::New(otmpl);
		}
	};

	template <class T>
	struct IndexType{
		enum {Value = 0};
	};

	template<> struct IndexType<unsigned char>{
		enum  {Value = v8::kExternalUnsignedByteArray};
	};
	template<> struct IndexType<char>{
		enum {Value = v8::kExternalByteArray};
	};
	template<> struct IndexType<short>{
		enum {Value = v8::kExternalShortArray};
	};
	template<> struct IndexType<unsigned short>{
		enum {Value = v8::kExternalUnsignedShortArray};
	};
	template<> struct IndexType<int>{
		enum {Value = v8::kExternalIntArray};
	};
	template<> struct IndexType<unsigned int>{
		enum {Value = v8::kExternalUnsignedIntArray};
	};
	template<> struct IndexType<float>{
		enum {Value = v8::kExternalFloatArray};
	};


	template<class T>
	struct Convert<external<T> >{
		static bool Is(v8::Handle<v8::Value> v){
			return !v.IsEmpty() && v->IsExternal();
		}

		static external<T> FromJS(v8::Handle<v8::Value> v, int nArg){
			const char* msg = "Externally allocated buffer expected";
			if (!Is(v)) BEATHROW();
			v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(v);

			return external<T>(static_cast<T*>(ext->Value()));
		}

		static v8::Handle<v8::Value> ToJS(const external<T>& val){
			return v8::External::New(val.ptr);
		}
	};

#if 0
	template<class T>
	struct Convert<external<T> >{
		static bool Is(v8::Handle<v8::Value> v){
			v8::Handle<v8::Object> obj = v->ToObject();
			return !v.IsEmpty() && 
					v->IsObject() && 
					obj->InternalFieldCount() == 2 && 
					(int)obj->GetPointerFromInternalField(1) == (int)IndexType<T>::Value;
		}

		static external<T> FromJS(v8::Handle<v8::Value> v, int nArg){
			const char* msg = "Externally allocated buffer expected";
			if (!Is(v)) BEATHROW();
			v8::Handle<v8::Object> thisObj = v->ToObject();

			void* ptr = thisObj->GetPointerFromInternalField(0); 

			return external<T>(static_cast<T*>(ptr));
		}

		static v8::Handle<v8::Value> ToJS(const external<T>& val){
			//return v8::External::New(val.ptr);

			v8::HandleScope scope; 
			v8::Handle<v8::Object> obj = Global::externalTemplate->NewInstance();

			obj->SetPointerInInternalField(0, val.ptr);
			obj->SetPointerInInternalField(1, (void*)(int)IndexType<T>::Value);
			return scope.Close(obj);
		}
	};
#endif




	

	//////////////////////////////////////////////////////////////////////////


	template<class T>
	class ExposedClass {
	private:
		v8::Persistent<v8::FunctionTemplate> function_template;
		std::string m_objectName;
		v8::InvocationCallback m_constructor;
		v8::InvocationCallback m_postAlloc;
		typedef void (*DestructorCallback)(v8::Handle<v8::Value> val);

		DestructorCallback m_destructor;

	public:
		static ExposedClass<T> * Instance; 

		//Constructor: objectName is the name in Javascript
		inline ExposedClass( const char* objectName ) {
			v8::HandleScope scope; 
			m_objectName = objectName; 
			v8::Local<v8::Value> vData = v8::External::New(this);
			v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(New, vData);
			function_template = v8::Persistent<v8::FunctionTemplate>::New(t);
			function_template->InstanceTemplate()->SetInternalFieldCount(2);
			function_template->SetClassName(v8::String::NewSymbol(objectName));
			m_constructor = NULL; 
			m_postAlloc = NULL; 
			m_destructor = NULL; 
		}
		inline ~ExposedClass(){
		}

		//Expose a method to Javascript.
		inline void exposeMethod( const char* name, v8::InvocationCallback cb ) {
			v8::HandleScope scope;
			v8::Local<v8::FunctionTemplate> fn = v8::FunctionTemplate::New(cb);
			function_template->PrototypeTemplate()->Set(v8::String::NewSymbol(name), fn);
		}

		//Expose a property to javascript
		inline void exposeProperty(const char* name, v8::AccessorGetter get, v8::AccessorSetter set){
			function_template->InstanceTemplate()->SetAccessor(v8::String::New(name), get, set);
		}

		inline void exposeTo( v8::Handle<v8::Object> target ){
			target->Set(v8::String::NewSymbol(m_objectName.c_str()), function_template->GetFunction());
		}

		//Called when the garbage collector decides to dispose of value
		static inline void WeakCallback (v8::Persistent<v8::Value> value, void *data) {
			ExposedClass<T>* _this = static_cast<ExposedClass<T>*>(data);
			v8::HandleScope scope;
			v8::Local<v8::Object> o = value->ToObject();
			void* p = o->GetPointerFromInternalField(0);

			if (p != NULL){
				if (_this->m_destructor)
					_this->m_destructor(value);
				else{
					delete static_cast<T*>(p);
				}

			}
			value.Dispose();
		}

		//Called by javascript when issuing a 'new MyObject' or by a NewInstance() issued by ToJS()
		
		inline v8::Handle<v8::Value> createNew( const v8::Arguments& args ) {
			v8::HandleScope scope; 

			v8::Handle<v8::External> ext;
			v8::Handle<v8::Value> res;

			if (args[0]->IsExternal())
				ext = v8::Handle<v8::External>::Cast(args[0]);
			else
			{
				assert(m_constructor != NULL && "Constructor not set!");

				res = m_constructor(args);

				if (res->IsExternal())
					ext = v8::Handle<v8::External>::Cast(res);
				else
					res = ThrowException(v8::Exception::TypeError(v8::String::NewSymbol("Invalid constructor parameters")));
					
			}

			if (!ext.IsEmpty()){
				args.This()->SetInternalField(0, ext);
				
				if (m_destructor){
					v8::Persistent<v8::Object> persObj = v8::Persistent<v8::Object>::New(args.This()); 
					persObj.MakeWeak(this, WeakCallback);
				}

				if (m_postAlloc)
					m_postAlloc(args);

				return scope.Close(args.This());
			}

			return scope.Close(res);
		}

		static inline v8::Handle<v8::Value> New( const v8::Arguments& args ) {
			v8::HandleScope scope; 
			v8::Local<v8::External> edata = v8::Local<v8::External>::Cast(args.Data()); 
			ExposedClass* that = static_cast<ExposedClass*>(edata->Value()); 
			return that->createNew(args);
		}

		static inline bool Is( v8::Handle<v8::Value> v ) {
			if (v.IsEmpty() || !v->IsObject())
				return false; 

			v8::Local<v8::Object> o = v->ToObject();

			int nField = o->InternalFieldCount();
			bool isExt = v->IsExternal();

			if (o->InternalFieldCount() < 2)
				return false; 

			void* p = o->GetPointerFromInternalField(1);
			return true;
		}

		static inline v8::Handle<v8::Value> ToJS( T* value ){
			ExposedClass<T>* inst = ExposedClass<T>::Instance;
			v8::HandleScope scope;
			v8::Handle<v8::Function> cons = inst->function_template->GetFunction();
			v8::Handle<v8::External> ext = v8::External::New(value);
			
			v8::Handle<v8::Value> argv[1] = {ext};

			v8::Handle<v8::Value> res = cons->NewInstance(1, argv);

			return scope.Close(res);
		}

		void inline setConstructor( v8::InvocationCallback cb ) {
			m_constructor = cb; 
		}

		void inline setPostAllocator(v8::InvocationCallback cb){
			m_postAlloc = cb;
		}

		void inline setDestructor(DestructorCallback cb){
			m_destructor = cb; 
		}

		static inline T* FromJS(v8::Handle<v8::Value> v, int nArg)	{
			const char* msg  = "Wrapped object expected";

			if (!Is(v))
				throw bea::ArgConvertException(nArg, msg); 

			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject(); 
			void * p = obj->GetPointerFromInternalField(0); 

			return static_cast<T*>(p);
		}

	};

	template <class T>
	class ExposedStatic{
		static v8::Persistent<v8::ObjectTemplate> oTemplate; 
		v8::Handle<v8::Object> m_obj;
		std::string m_objName; 
	public:

		static inline void Init(){
			v8::HandleScope handle_scope;
			v8::Handle<v8::ObjectTemplate> obj_templ = v8::ObjectTemplate::New();
			obj_templ->SetInternalFieldCount(1);
			oTemplate = v8::Persistent<v8::ObjectTemplate>::New(obj_templ);
		}

		static inline ExposedStatic<T>* Create(T* ptr, const char* objectName){
			
			if (oTemplate.IsEmpty())
				Init();

			return new ExposedStatic<T>(ptr, objectName);
		}

		inline ExposedStatic(T* ptr, const char* objectName){
			m_obj = oTemplate->NewInstance();
			m_obj->SetInternalField(0, v8::External::New(ptr));
			m_objName = objectName;
		}

		inline void exposeMethod(const char* name, v8::InvocationCallback cb){
			m_obj->Set(v8::String::NewSymbol(name), v8::FunctionTemplate::New(cb)->GetFunction());
		}

		inline void exposeTo(v8::Handle<v8::Object> target){
			target->Set(v8::String::NewSymbol(m_objName.c_str()), m_obj);
		}
	};
}


namespace bea{
	class DerivedClass{
	protected:
		v8::Persistent<v8::Object> __jsInstance;
		~DerivedClass(){
			__jsInstance.Dispose();
		}

		v8::Handle<v8::Value> bea_derived_callJS(const char* name, int nargs, v8::Handle<v8::Value> args[]){

			//Enter the javascript context - this is a call from native code
			//v8::Context::Scope contextScope(Handle<Context>::Cast(Global::context));
			//Global::context->Enter();
			 

			v8::HandleScope scope; 
			v8::Handle<v8::Value> result;
			v8::Handle<v8::Value> oFn = __jsInstance->Get(v8::String::New(name));

			if (!oFn.IsEmpty() && oFn->IsFunction()){
				v8::Handle<v8::Function> fn	 = v8::Handle<v8::Function>::Cast(oFn);
				v8::TryCatch try_catch; 
				result = fn->Call(__jsInstance, nargs, args);
				if (result.IsEmpty())
						bea::Global::reportException(try_catch);
			}

			//Global::context->Exit();
			
			return scope.Close(result);
		}

		bool bea_derived_hasOverride(const char* name){
			return __jsInstance->HasRealNamedProperty(v8::String::NewSymbol(name));
		}
	public:
		void bea_derived_setInstance(v8::Handle<v8::Object> obj){
			__jsInstance = v8::Persistent<v8::Object>::New(obj);
		}
	};
}

#define DECLARE_EXPOSED_CLASS(typeName) template<> bea::ExposedClass<typeName>* bea::ExposedClass<typeName>::Instance = NULL
#define EXPOSE_CLASS(typeName, jsName) bea::ExposedClass<typeName>::Instance = new bea::ExposedClass<typeName>(jsName)

#define DECLARE_STATIC(typeName) template<> v8::Persistent<v8::ObjectTemplate> bea::ExposedStatic<typeName>::oTemplate = v8::Persistent<v8::ObjectTemplate>()
#define EXPOSE_STATIC(typeName, jsName) bea::ExposedStatic<typeName>::Create(new (typeName), jsName)

//Throw if number of arguments is smaller than n
#define REQUIRE_ARGS(args, n) if ((args).Length() < (n)) return v8::ThrowException(v8::Exception::TypeError(v8::String::NewSymbol("Wrong number of arguments")))

//Every method accessible by javascript must start with this macro
#define METHOD_BEGIN(nArgs) REQUIRE_ARGS(args, (nArgs)); try { 
#define DESTRUCTOR_BEGIN() try{
#define DESTRUCTOR_END() } catch(bea::ArgConvertException& ){ }

//Every method must end with this macro
#define METHOD_END() } catch(bea::ArgConvertException& e){ return e.v8exception();}

//Copied from NODE_DEFINE_CONSTANT in node.js
#define BEA_DEFINE_CONSTANT(target, constant)               \
	(target)->Set(v8::String::NewSymbol(#constant),          \
	v8::Integer::New(constant),                               \
	static_cast<v8::PropertyAttribute>(v8::ReadOnly|v8::DontDelete))

//Copied from NODE_SET_METHOD in node.js
#define BEA_SET_METHOD(obj, name, callback)                              \
	obj->Set(v8::String::NewSymbol(name),                                   \
	v8::FunctionTemplate::New(callback)->GetFunction())



#endif //__BEA_H__
