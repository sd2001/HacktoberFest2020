import React, { useState, useEffect, useCallback } from "react";
import { View, Text, StyleSheet, Switch, Platform } from "react-native";
import { HeaderButtons, Item } from "react-navigation-header-buttons";
import { useDispatch, useSelector } from "react-redux";
import DarkSwitch from "expo-dark-mode-switch";

import { setFilters } from "../store/actions/mealsAction";
import BodyText from "../constants/BodyText";
import CustomHeaderButton from "../components/CustomHeaderButton";
import Colors from "../constants/Colors";
import { switchTheme } from "../store/actions/themeAction";
import { darkTheme, lightTheme } from "../constants/Theme";

const FiltersScreen = (props) => {
  const { navigation } = props;

  const [isGlutenFree, setIsGlutenFree] = useState(false);
  const [isLactoseFree, setIsLactoseFree] = useState(false);
  const [isVegan, setIsVegan] = useState(false);
  const [isVegetarian, setIsVegetarian] = useState(false);
  const [isDark, setIsDark] = useState(false);

  const dispatch = useDispatch();

  const saveFilters = useCallback(() => {
    const appliedFilters = {
      glutenFree: isGlutenFree,
      lactoseFree: isLactoseFree,
      vegan: isVegan,
      vegetarian: isVegetarian,
    };

    if (isDark) {
      dispatch(switchTheme(darkTheme));
    } else {
      dispatch(switchTheme(lightTheme));
    }
    dispatch(setFilters(appliedFilters));
    navigation.navigate("Categories");
  }, [isGlutenFree, isLactoseFree, isVegan, isVegetarian, isDark]);

  useEffect(() => {
    navigation.setParams({ save: saveFilters });
  }, [saveFilters]);

  const theme = useSelector((state) => state.theme.theme);

  const themeContainerStyle =
    theme.mode === "dark" ? styles.darkContainer : styles.lightContainer;
  const textColour = theme.mode === "dark" ? styles.darkText : styles.lightText;

  const FilterSwitch = (props) => {
    return (
      <View style={styles.filterContainer}>
        <BodyText style={{ ...textColour }}>{props.filterName} </BodyText>
        <Switch
          trackColor={{ true: Colors.primary, false: "#ebb978" }}
          thumbColor={Platform.OS === "android" ? Colors.primary : ""}
          value={props.filterState}
          onValueChange={props.onChange}
        />
      </View>
    );
  };
  const DarkModeSwitch = (props) => {
    return (
      <View style={styles.filterContainer}>
        <BodyText style={{ ...textColour }}>{props.filterName} </BodyText>
        <DarkSwitch value={props.darkState} onChange={props.onChange} />
      </View>
    );
  };

  return (
    <View style={{ ...styles.screen, ...themeContainerStyle }}>
      <Text style={{ ...styles.title, ...textColour }}>Available Filters:</Text>
      <FilterSwitch
        filterName="Gluten-free"
        filterState={isGlutenFree}
        onChange={(newValue) => {
          setIsGlutenFree(newValue);
        }}
      />
      <FilterSwitch
        filterName="Lactose-free"
        filterState={isLactoseFree}
        onChange={(newValue) => {
          setIsLactoseFree(newValue);
        }}
      />
      <FilterSwitch
        filterName="Vegan"
        filterState={isVegan}
        onChange={(newValue) => {
          setIsVegan(newValue);
        }}
      />
      <FilterSwitch
        filterName="Vegetarian"
        filterState={isVegetarian}
        onChange={(newValue) => {
          setIsVegetarian(newValue);
        }}
      />
      <Text style={{ ...styles.title, ...textColour }}>Your Preferences:</Text>
      <DarkModeSwitch
        filterName="Enable Dark Mode"
        darkState={isDark}
        onChange={(value) => setIsDark(value)}
      />
      {/* <View style={styles.darkSwitch}>
        <BodyText>Enable Dark Mode</BodyText>
        <DarkSwitch value={isDark} onChange={(value) => setIsDark(value)} />
      </View> */}
    </View>
  );
};

FiltersScreen.navigationOptions = (navData) => {
  return {
    headerTitle: "Filters",
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
    headerRight: () => (
      <HeaderButtons HeaderButtonComponent={CustomHeaderButton}>
        <Item
          title="Save"
          iconName="md-save"
          onPress={navData.navigation.getParam("save")}
        />
      </HeaderButtons>
    ),
  };
};

const styles = StyleSheet.create({
  screen: {
    flex: 1,
    //justifyContent: 'center',
    alignItems: "center",
  },
  filterContainer: {
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    width: "80%",
    marginVertical: 15,
  },
  title: {
    fontFamily: "open-sans-bold",
    fontSize: 22,
    margin: 20,
    textAlign: "center",
  },
  darkSwitch: {
    flexDirection: "row",
    justifyContent: "space-between",
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

export default FiltersScreen;
