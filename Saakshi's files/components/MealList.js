import React from 'react';
import { View, FlatList, StyleSheet } from 'react-native';
import { withNavigation } from "react-navigation";
import { useSelector } from 'react-redux'

import MealItem from './MealItem';

const MealList = props => {
    const favouriteMeals = useSelector(state => state.meals.favouriteMeals);
    const renderMealItem = itemData => {
        const isFavourite = favouriteMeals.some(meal => meal.id === itemData.item.id);
        return (
            <MealItem
                title={itemData.item.title}
                imageUrl={itemData.item.imageUrl}
                duration={itemData.item.duration}
                complexity={itemData.item.complexity}
                affordability={itemData.item.affordability}
                onSelectMeal={() => {
                    props.navigation.navigate({
                        routeName: 'MealDetail',
                        params: {
                            mealId: itemData.item.id,
                            mealTitle: itemData.item.title,
                            isFav: isFavourite
                        }
                    })
                }}
            />);
    }

    return (
        <View style={styles.screen}>
            <FlatList
                data={props.listData}
                renderItem={renderMealItem}
                style={{ width: '100%' }}
            />
        </View>
    );
}

const styles = StyleSheet.create({
    screen: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        padding: 10,
    }
});

export default withNavigation(MealList);