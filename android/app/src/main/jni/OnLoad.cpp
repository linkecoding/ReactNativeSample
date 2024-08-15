#include <DefaultComponentsRegistry.h>
#include <DefaultTurboModuleManagerDelegate.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <rncli.h>
#include <RTNBase64HelperModule.h>

namespace facebook::react {

    void registerComponents(
            std::shared_ptr<const ComponentDescriptorProviderRegistry> registry) {
        rncli_registerProviders(registry);
    }

    std::shared_ptr<TurboModule> cxxModuleProvider(
            const std::string &name,
            const std::shared_ptr<CallInvoker> &jsInvoker) {
        if (name == "RTNBase64Helper") {
            return std::make_shared<facebook::react::RTNBase64HelperModule>(jsInvoker);
        }
        return nullptr;
    }

    std::shared_ptr<TurboModule> javaModuleProvider(
            const std::string &name,
            const JavaTurboModule::InitParams &params) {
        return rncli_ModuleProvider(name, params);
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