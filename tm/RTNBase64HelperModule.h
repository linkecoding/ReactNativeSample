#pragma once

#if __has_include(<React-Codegen/RTNBase64HelperSpecJSI.h>) // CocoaPod headers on Apple
#include <React-Codegen/RTNBase64HelperSpecJSI.h>
#elif __has_include("RTNBase64HelperSpecJSI.h") // CMake headers on Android

#include "RTNBase64HelperSpecJSI.h"

#endif

#include <memory>
#include <string>

namespace facebook::react {

    class RTNBase64HelperModule : public NativeRTNBase64HelperCxxSpec<RTNBase64HelperModule> {
    public:
        RTNBase64HelperModule(std::shared_ptr<CallInvoker> jsInvoker);

        jsi::String base64EncodeSync(jsi::Runtime &rt, jsi::String str);

        std::string base64_encode(const std::string &input);
    };

} // namespace facebook::react