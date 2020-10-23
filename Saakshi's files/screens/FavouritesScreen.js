import React from "react";
import { View, StyleSheet } from "react-native";
import MealList from "../components/MealList";
import { HeaderButtons, Item } from "react-navigation-header-buttons";
import { useSelector } from "react-redux";

import CustomHeaderButton from "../components/CustomHeaderButton";
import BodyText from "../constants/BodyText";

const FavouritesScreen = (props) => {
  const favMeals = useSelector((state) => state.meals.favouriteMeals);

  const theme = useSelector((state) => state.theme.theme);

  const themeContainerStyle =
    theme.mode === "dark" ? styles.darkContainer : styles.lightContainer;
  const textColour = theme.mode === "dark" ? styles.darkText : styles.lightText;

  if (favMeals.length === 0 || !favMeals) {
    return (
      <View style={{ ...styles.screen, ...themeContainerStyle }}>
        <BodyText style={{ ...textColour }}>No favourites added!</BodyText>
      </View>
    );
  }

  return (
    <View style={{ ...styles.screen, ...themeContainerStyle }}>
      <MealList listData={favMeals} navigation={props.navigation} />
    </View>
  );
};

FavouritesScreen.navigationOptions = (navData) => {
  return {
    headerTitle: "Your Favourites",
    headerTitleStyle: { fontFamily: "open-sans" },
    headerLeft: () => (
      <HeaderButtons HeaderButtonComponent={CustomHeaderButton}>
        <Item
          title="Menu"
          iconName="ios-menu"
          onPress={() => {
            navData.navigation.toggleDrawer();
          }}
        />
      </HeaderButtons>
    ),
  };
};

const styles = StyleSheet.create({
  screen: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
  },
  lightContainer: {
    backgroundColor: "white",
  },
  darkContainer: {
    backgroundColor: "#3b3937",
  },
  darkText: {
    color: "white",
  },
  lightText: {
    color: "#3b3937",
  },
});

export default FavouritesScreen;
