#include <node.h>

void Add(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();
  v8::HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  double value = args[0]->NumberValue() + args[1]->NumberValue();
  v8::Local<v8::Number> num = v8::Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void Array(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();
  v8::HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  v8::Local<v8::Array> num_array = v8::Array::New(isolate, 0);
  num_array->Set(v8::Number::New(isolate, 0), args[0]);
  num_array->Set(v8::Number::New(isolate, 1), args[1]);

  args.GetReturnValue().Set(num_array);
}

void Init(v8::Handle<v8::Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
  NODE_SET_METHOD(exports, "array", Array);
}

NODE_MODULE(addon, Init)
