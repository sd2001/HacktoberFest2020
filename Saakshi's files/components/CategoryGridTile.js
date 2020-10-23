import React from 'react';
import { View, TouchableOpacity, StyleSheet, Text, Platform, TouchableNativeFeedback } from 'react-native';

let TouchableCmp = TouchableOpacity;

if (Platform.OS === 'android' && Platform.Version >= 21) {
    TouchableCmp = TouchableNativeFeedback
}

const CategoryGridTile = props => {
    return (
        <View style={styles.grid}>
            <TouchableCmp style={{ flex: 1 }}
                onPress={props.onSelect}>
                <View style={{ ...styles.container, ...{ backgroundColor: props.color } }}>
                    <Text numberOfLines={2} style={styles.title}>{props.title}</Text>
                </View>
            </TouchableCmp>
        </View>
    )
}

const styles = StyleSheet.create({
    grid: {
        flex: 1,
        margin: 15,
        height: 150,
        elevation: 6,
        borderRadius: 10,
        borderColor: 'grey',
        borderWidth: 1,
        overflow: Platform.OS === 'android' && Platform.Version >= 21 ? 'hidden' : 'visible',
    },
    container: {
        flex: 1,
        alignItems: 'flex-end',
        justifyContent: 'flex-end',
        padding: 10,
    },
    title: {
        fontFamily: 'open-sans-bold',
        fontSize: 18,
        textAlign: 'right',
    }
});

export default CategoryGridTile;