#pragma once

#include "RecipeBook.hpp"

class UserInterface {
private:
    RecipeBook myBook;
    void clearInputBuffer();
    void pressEnterToContinue();

    // Métodos para cada opción del menú
    void addNewRecipe();
    void deleteRecipe();
    void findRecipeByName();
    void findRecipeByCategory();
    void modifyRecipe();
    void showAllRecipes();
    void showRecipesByCategory();
    void sortMenu();
    void saveToFile();
    void loadFromFile();
    void deleteAllRecipes();
    void modifyRecipeMenu(Recipe& recipe);
    Category selectCategory();

public:
    UserInterface();
    void run();
};