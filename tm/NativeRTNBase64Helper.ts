import { TurboModule, TurboModuleRegistry } from "react-native";

export interface Spec extends TurboModule {
  readonly base64EncodeSync: (str: string) => string;
}

export default TurboModuleRegistry.getEnforcing<Spec>("RTNBase64Helper");