import React, { useEffect } from 'react';
import { SafeAreaView, ScrollView, StatusBar, Text } from 'react-native';
import RTNBase64Helper from './tm/NativeRTNBase64Helper';

function App(): React.JSX.Element {
  useEffect(() => {
    const result = RTNBase64Helper.base64EncodeSync(
      'abcdennkkdjededkedjkdjekj',
    );
    console.log('===base64 result===', result);
  }, []);
  return (
    <SafeAreaView>
      <StatusBar barStyle={'dark-content'} />
      <ScrollView contentInsetAdjustmentBehavior="automatic">
        <Text>Sample</Text>
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
