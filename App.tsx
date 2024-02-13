import React from 'react';
import { SafeAreaView, ScrollView, StatusBar } from 'react-native';
import { SampleText } from './src/components/SampleText';

function App(): React.JSX.Element {
  return (
    <SafeAreaView>
      <StatusBar barStyle={'dark-content'} />
      <ScrollView contentInsetAdjustmentBehavior="automatic">
        <SampleText />
      </ScrollView>
    </SafeAreaView>
  );
}

export default App;
