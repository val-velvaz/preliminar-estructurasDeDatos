#pragma once
#include "List.hpp"
#include "Recipe.hpp"
#include <string>

class RecipeBook {
private:
    List<Recipe> recipes;

public:
    const List<Recipe>& getRecipes() const;
    void setRecipes(const List<Recipe>& recipes);

    void addRecipe(const Recipe& recipe);
    int findRecipeByName(const Name& name);
    Recipe* findRecipeByCategory(Category category);
    void deleteRecipeByName(const Name& name);
    void deleteAllRecipes();

    void sortRecipes(int criteria, int algorithm);
    
    Recipe& getRecipe(int index);

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};