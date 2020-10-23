import React from 'react';
import { Text, StyleSheet } from 'react-native';

const BodyText = props => (
<Text style ={{...styles.body,...props.style}}>{props.children}</Text>
);

const styles=StyleSheet.create({
    body: {
        fontFamily:'open-sans'
    }
});

export default BodyText;