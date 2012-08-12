#include <node.h>
#include <v8.h>
#include "bea.h"
#include "opencvjs.h"

using namespace v8;


void reportError(TryCatch& try_catch){
	//if (m_logger)
		//m_logger(*v8::String::Utf8Value(try_catch.StackTrace()));
}

bea::reportExceptionCb bea::Global::reportException = reportError;

extern "C" {
    static void init (Handle<Object> target) {
        HandleScope scope;
       	opencvjs::Project::expose(target);
    }
    NODE_MODULE(addon,init);
}
