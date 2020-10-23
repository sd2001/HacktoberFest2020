import React from "react";
import {
  View,
  StyleSheet,
  TouchableOpacity,
  TouchableNativeFeedback,
  Platform,
  ImageBackground,
} from "react-native";
import BodyText from "../constants/BodyText";

let TouchableCmp = TouchableOpacity;

if (Platform.OS === "android" && Platform.Version >= 21) {
  TouchableCmp = TouchableNativeFeedback;
}

const MealItem = (props) => {
  return (
    <View style={styles.mealItem}>
      <TouchableCmp onPress={props.onSelectMeal}>
        <View>
          <View style={{ ...styles.mealRow, ...styles.header }}>
            <ImageBackground
              source={{ uri: props.imageUrl }}
              style={styles.bgImage}
            >
              <View style={styles.titleContainer}>
                <BodyText style={styles.title} numberOfLines={1}>
                  {props.title}
                </BodyText>
              </View>
            </ImageBackground>
          </View>
          <View style={{ ...styles.mealRow, ...styles.detail }}>
            <BodyText>{props.duration}m</BodyText>
            <BodyText>{props.complexity.toUpperCase()}</BodyText>
            <BodyText>{props.affordability.toUpperCase()}</BodyText>
          </View>
        </View>
      </TouchableCmp>
    </View>
  );
};

const styles = StyleSheet.create({
  mealItem: {
    height: 250,
    width: "100%",
    backgroundColor: "rgba(230, 193, 133, 0.7)",
    borderRadius: 10,
    borderColor: "white",
    borderWidth: 1,
    overflow: "hidden",
    marginVertical: 5,
  },
  mealRow: {
    flexDirection: "row",
  },
  header: {
    height: "85%",
  },
  detail: {
    justifyContent: "space-between",
    paddingHorizontal: 10,
    alignItems: "center",
    height: "15%",
  },
  bgImage: {
    width: "100%",
    height: "100%",
    justifyContent: "flex-end",
  },
  titleContainer: {
    backgroundColor: "rgba(0,0,0,0.5)",
    paddingVertical: 5,
    paddingHorizontal: 12,
  },
  title: {
    fontFamily: "open-sans-bold",
    fontSize: 18,
    color: "white",
    textAlign: "center",
  },
});

export default MealItem;
