#include <DefaultComponentsRegistry.h>
#include <DefaultTurboModuleManagerDelegate.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <rncore.h>
#include <RTNBase64HelperModule.h>
#ifdef REACT_NATIVE_APP_CODEGEN_HEADER
#include REACT_NATIVE_APP_CODEGEN_HEADER
#endif
#ifdef REACT_NATIVE_APP_COMPONENT_DESCRIPTORS_HEADER
#include REACT_NATIVE_APP_COMPONENT_DESCRIPTORS_HEADER
#endif

namespace facebook::react {

    void registerComponents(
            std::shared_ptr<const ComponentDescriptorProviderRegistry> registry) {
#ifdef REACT_NATIVE_APP_COMPONENT_REGISTRATION
        REACT_NATIVE_APP_COMPONENT_REGISTRATION(registry);
#endif
    }

    std::shared_ptr<TurboModule> cxxModuleProvider(
            const std::string &name,
            const std::shared_ptr<CallInvoker> &jsInvoker) {
        if (name == "RTNBase64Helper"){
            return std::make_shared<facebook::react::RTNBase64HelperModule>(jsInvoker);
        }
        return nullptr;
    }

    std::shared_ptr<TurboModule> javaModuleProvider(
            const std::string &name,
            const JavaTurboModule::InitParams &params) {
#ifdef REACT_NATIVE_APP_MODULE_PROVIDER
        auto module = REACT_NATIVE_APP_MODULE_PROVIDER(name, params);
  if (module != nullptr) {
    return module;
  }
#endif
        if (auto module = rncore_ModuleProvider(name, params)) {
            return module;
        }
        return nullptr;
    }

} // namespace facebook::react

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
    return facebook::jni::initialize(vm, [] {
        facebook::react::DefaultTurboModuleManagerDelegate::cxxModuleProvider =
                &facebook::react::cxxModuleProvider;
        facebook::react::DefaultTurboModuleManagerDelegate::javaModuleProvider =
                &facebook::react::javaModuleProvider;
        facebook::react::DefaultComponentsRegistry::
        registerComponentDescriptorsFromEntryPoint =
                &facebook::react::registerComponents;
    });
}