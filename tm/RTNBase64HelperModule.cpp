#include <string>
#include <vector>
#include "RTNBase64HelperModule.h"

namespace facebook::react {

    RTNBase64HelperModule::RTNBase64HelperModule(std::shared_ptr<CallInvoker> jsInvoker)
            : NativeRTNBase64HelperCxxSpec(std::move(jsInvoker)) {}

    jsi::String RTNBase64HelperModule::base64EncodeSync(jsi::Runtime &rt, jsi::String str) {
        auto data = str.utf8(rt);
        auto result = base64_encode(data);
        return jsi::String::createFromUtf8(rt, result);
    }

    std::string RTNBase64HelperModule::base64_encode(const std::string &input) {
        static const std::string base64_chars =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz"
                "0123456789+/";

        std::string ret;
        int val = 0, valb = -6;

        for (unsigned char c: input) {
            val = (val << 8) + c;
            valb += 8;

            while (valb >= 0) {
                ret.push_back(base64_chars[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }

        if (valb > -6) {
            ret.push_back('=');
            if (valb > -4) ret.push_back('=');
        }

        return ret;
    }

} // namespace facebook::react