import React from "react";
import { StyleSheet, FlatList, View } from "react-native";
import { HeaderButtons, Item } from "react-navigation-header-buttons";

import { CATEGORIES } from "../data/dummy-data";
import CategoryGridTile from "../components/CategoryGridTile";
import CustomHeaderButton from "../components/CustomHeaderButton";
import { useSelector } from "react-redux";

const CategoriesScreen = (props) => {
  const theme = useSelector((state) => state.theme.theme);

  const themeContainerStyle =
    theme.mode === "dark" ? styles.darkContainer : styles.lightContainer;
  const textColour = theme.mode === "dark" ? styles.darkText : styles.lightText;
  const renderGridItem = (itemData) => {
    return (
      <CategoryGridTile
        title={itemData.item.title}
        color={itemData.item.color}
        onSelect={() => {
          props.navigation.navigate({
            routeName: "CategoryMeals",
            params: {
              categoryId: itemData.item.id,
            },
          });
        }}
      />
    );
  };
  CategoriesScreen.navigationOptions = (navdata) => {
    return {
      headerTitle: "Meal Categories",
      headerTitleStyle: { fontFamily: "open-sans" },
      headerLeft: () => (
        <HeaderButtons HeaderButtonComponent={CustomHeaderButton}>
          <Item
            title="Menu"
            iconName="ios-menu"
            onPress={() => {
              navdata.navigation.toggleDrawer();
            }}
          />
        </HeaderButtons>
      ),
    };
  };

  return (
    <View style={{...styles.screen, ...themeContainerStyle}}>
      <FlatList
        keyExtractor={(item, index) => item.id}
        data={CATEGORIES}
        renderItem={renderGridItem}
        numColumns={2}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  screen: {
    flex: 1,
    
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

export default CategoriesScreen;
