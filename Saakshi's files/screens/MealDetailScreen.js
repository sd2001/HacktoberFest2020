import React, { useEffect, useCallback } from "react";
import { View, Text, StyleSheet, ScrollView, Image } from "react-native";
import { HeaderButtons, Item } from "react-navigation-header-buttons";
import { useSelector, useDispatch } from "react-redux";

import CustomHeaderButton from "../components/CustomHeaderButton";
import BodyText from "../constants/BodyText";
import { toggleFavourite } from "../store/actions/mealsAction";

const MealDetailScreen = (props) => {
  const availableMeals = useSelector((state) => state.meals.meals);
  const mealId = props.navigation.getParam("mealId");
  const currentMealIsFav = useSelector((state) =>
    state.meals.favouriteMeals.some((meal) => meal.id === mealId)
  );

  const selectedMeal = availableMeals.find((meal) => meal.id === mealId);

  const dispatch = useDispatch();

  const toggleFavouriteHandler = useCallback(() => {
    dispatch(toggleFavourite(mealId));
  }, [dispatch, mealId]);

  useEffect(() => {
    props.navigation.setParams({ toggleFav: toggleFavouriteHandler });
  }, [toggleFavouriteHandler]);

  useEffect(() => {
    props.navigation.setParams({ isFav: currentMealIsFav });
  }, [currentMealIsFav]);

  const theme = useSelector((state) => state.theme.theme);

  const themeContainerStyle =
    theme.mode === "dark" ? styles.darkContainer : styles.lightContainer;
  const textColour = theme.mode === "dark" ? styles.darkText : styles.lightText;

  const ListItem = (props) => {
    return (
      <View style={styles.listItem}>
        <BodyText style={{ ...textColour }}>{props.children}</BodyText>
      </View>
    );
  };

  return (
    <ScrollView style={{ ...styles.screen, ...themeContainerStyle }}>
      <View style={styles.imageContainer}>
        <Image source={{ uri: selectedMeal.imageUrl }} style={styles.image} />
        <View style={styles.details}>
          <BodyText>{selectedMeal.duration}m</BodyText>
          <BodyText>{selectedMeal.complexity.toUpperCase()}</BodyText>
          <BodyText>{selectedMeal.affordability.toUpperCase()}</BodyText>
        </View>
      </View>
      <Text style={{ ...styles.title, ...textColour }}>Ingredients :</Text>
      {selectedMeal.ingredients.map((ingredient) => (
        <ListItem key={ingredient}>{ingredient}</ListItem>
      ))}
      <Text style={{ ...styles.title, ...textColour }}>Steps :</Text>
      {selectedMeal.steps.map((step) => (
        <ListItem key={step}>{step}</ListItem>
      ))}
    </ScrollView>
  );
};

MealDetailScreen.navigationOptions = (navigationData) => {
  //const mealId = navigationData.navigation.getParam('mealId');
  const mealTitle = navigationData.navigation.getParam("mealTitle");
  const toggleFavourite = navigationData.navigation.getParam("toggleFav");
  const isFavourite = navigationData.navigation.getParam("isFav");
  //const selectedMeal = MEALS.find(meal => meal.id === mealId);

  return {
    headerTitle: mealTitle,
    headerTitleStyle: { width: 260, fontFamily: "open-sans" },
    headerRight: () => (
      <HeaderButtons HeaderButtonComponent={CustomHeaderButton}>
        <Item
          title="Favourite"
          iconName={isFavourite ? "ios-star" : "ios-star-outline"}
          onPress={toggleFavourite}
        />
      </HeaderButtons>
    ),
  };
};

const styles = StyleSheet.create({
  screen: {
    flex: 1,
  },
  imageContainer: {
    padding: 10,
  },
  image: {
    width: "100%",
    height: 200,
    borderRadius: 10,
  },
  details: {
    justifyContent: "space-between",
    paddingHorizontal: 10,
    alignItems: "center",
    backgroundColor: "rgba(230, 193, 133, 0.7)",
    flexDirection: "row",
    borderRadius: 10,
    height: 35,
    borderColor: "#ccc",
    borderWidth: 1,
  },
  title: {
    textAlign: "center",
    fontFamily: "open-sans-bold",
    fontSize: 18,
  },
  listItem: {
    margin: 10,
    padding: 10,
    borderColor: "#ccc",
    borderWidth: 1,
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

export default MealDetailScreen;
