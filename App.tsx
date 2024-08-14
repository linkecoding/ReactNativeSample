import React, { useEffect } from 'react';
import { SafeAreaView, ScrollView, StatusBar, Text } from 'react-native';
import RTNTextHelper from 'rtn-texthelper/js/NativeRTNTextHelper';
import RTNBase64Helper from './tm/NativeRTNBase64Helper';

function App(): React.JSX.Element {
  useEffect(() => {
    const textInfo = {
      text: '测试文本',
      fontSize: 12,
    };
    const result = RTNTextHelper?.measureTextSync(textInfo);
    console.log('===RTNTextHelper.measureTextSync==', JSON.stringify(result));

    RTNTextHelper?.measureTextAsync(textInfo)
      .then(res => {
        console.log('===RTNTextHelper.measureTextAsync==', JSON.stringify(res));
      })
      .catch(() => {
        // ignore
      });
    const result2 = RTNBase64Helper.base64EncodeSync(
      'abcdennkkdjededkedjkdjekj',
    );
    console.log('===base64 result===', result2);
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
