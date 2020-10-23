import React from "react";
import { useSelector } from "react-redux";
import { View, Text, StyleSheet } from "react-native";
import { CATEGORIES } from "../data/dummy-data";

import BodyText from "../constants/BodyText";
import MealList from "../components/MealList";

const CategoryMealsScreen = (props) => {
  const theme = useSelector((state) => state.theme.theme);

  const themeContainerStyle =
    theme.mode === "dark" ? styles.darkContainer : styles.lightContainer;
  const textColour = theme.mode === "dark" ? styles.darkText : styles.lightText;

  const catId = props.navigation.getParam("categoryId");

  const availableMeals = useSelector((state) => state.meals.filteredMeals);

  const displayedMeals = availableMeals.filter(
    (meal) => meal.categoryIds.indexOf(catId) >= 0
  );

  const selectedCategory = CATEGORIES.find((cat) => cat.id === catId);
  if (displayedMeals.length == 0) {
    return (
      <View style={{ ...styles.screen, ...themeContainerStyle }}>
        <BodyText style={{ ...textColour }}>
          No meals found! Check your filters maybe?
        </BodyText>
      </View>
    );
  }

  return (
    <View style={{ ...styles.screen, ...themeContainerStyle }}>
      <MealList listData={displayedMeals} navigation={props.navigation} />
    </View>
  );
};

CategoryMealsScreen.navigationOptions = (navigationData) => {
  const catId = navigationData.navigation.getParam("categoryId");
  const selectedCategory = CATEGORIES.find((cat) => cat.id === catId);

  return {
    headerTitle: selectedCategory.title,
    headerTitleStyle: { fontFamily: "open-sans" },
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

export default CategoryMealsScreen;
