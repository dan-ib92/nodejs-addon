#include <napi.h>
#include <string>
#include "greeting.h"

Napi::String SayHello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string user = (std::string) info[0].ToString();
    std::string result = helloUser(user);
    
    return Napi::String::New(env, result);
}

Napi::Number SumValues(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::int32_t a = info[0].ToNumber().Uint32Value();
    std::int32_t b = info[1].ToNumber().Uint32Value();
    
    return Napi::Number::New(env, sumValues(a, b));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

    exports.Set(Napi::String::New(env, "SayHello"), Napi::Function::New(env, SayHello));

    exports.Set( Napi::String::New(env, "SumValues"), Napi::Function::New(env, SumValues));

    return exports;
}

NODE_API_MODULE(greet, Init);



