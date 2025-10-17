#include "RecipeBook.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

const List<Recipe>& RecipeBook::getRecipes() const {
    return this->recipes;
}

void RecipeBook::setRecipes(const List<Recipe>& recipes) {
    this->recipes = recipes;
}

void RecipeBook::addRecipe(const Recipe& recipe) {
    this->recipes.insert(this->recipes.getLast() + 1, recipe);
}

int RecipeBook::findRecipeByName(const Name& name) {
    for (int i = 0; i <= this->recipes.getLast(); ++i) {
        if (this->recipes.get(i).getName().getValue() == name.getValue()) {
            return i;
        }
    }
    return -1; 
}

Recipe* RecipeBook::findRecipeByCategory(Category category) {
    for (int i = 0; i <= this->recipes.getLast(); ++i) {
        if (this->recipes.get(i).getCategory() == category) {
            return &this->getRecipe(i);
        }
    }
    return nullptr;
}

void RecipeBook::deleteRecipeByName(const Name& name) {
    int pos = this->findRecipeByName(name);
    if (pos != -1) {
        this->recipes.remove(pos);
    }
}

void RecipeBook::deleteAllRecipes() {
    this->recipes.clear();
}

void RecipeBook::sortRecipes(int criteria, int algorithm) {
    auto comparator = (criteria == 1) ? Recipe::compareByName : Recipe::compareByPrepTime;

    switch(algorithm) {
        case 1:
            this->recipes.sortBubble(comparator);
            break;
        case 2:
            this->recipes.sortInsert(comparator);
            break;
        case 3:
            this->recipes.sortSelect(comparator);
            break;
        case 4:
            this->recipes.sortShell(comparator);
            break;
        default:
            throw std::invalid_argument("Algoritmo de ordenamiento no valido.");
    }
}

Recipe& RecipeBook::getRecipe(int index) {
    return this->recipes.get(index);
}

void RecipeBook::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar." << std::endl;
        return;
    }

    file << this->recipes.getLast() + 1 << std::endl; 
    for (int i = 0; i <= this->recipes.getLast(); ++i) {
        const auto& recipe = this->recipes.get(i);
        file << recipe.getName() << std::endl;
        file << recipe.getAuthor();
        file << static_cast<int>(recipe.getCategory()) << std::endl;
        file << recipe.getPrepTime() << std::endl;
        file << recipe.getProcedure();
        
        const auto& ingredients = recipe.getIngredients();
        file << ingredients.getLast() + 1 << std::endl; 
        for (int j = 0; j <= ingredients.getLast(); ++j) {
            file << ingredients.get(j);
        }
    }
    file.close();
}

void RecipeBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se encontro el archivo. Se creara uno nuevo al guardar." << std::endl;
        return;
    }

    this->deleteAllRecipes();
    int recipeCount;
    file >> recipeCount;
    file.ignore(); 

    for (int i = 0; i < recipeCount; ++i) {
        Recipe recipe;
        Name recipeName;
        Author author;
        Procedure procedure;
        Duration prepTime;
        int categoryEnum;

        file >> recipeName;
        recipe.setName(recipeName);
        file >> author;
        recipe.setAuthor(author);
        file >> categoryEnum;
        recipe.setCategory(static_cast<Category>(categoryEnum));
        file >> prepTime;
        file.ignore(); 
        recipe.setPrepTime(prepTime);
        file >> procedure;
        recipe.setProcedure(procedure);
        
        int ingredientCount;
        file >> ingredientCount;
        file.ignore();

        for (int j = 0; j < ingredientCount; ++j) {
            Ingredient ingredient;
            file >> ingredient;
            recipe.addIngredient(ingredient);
        }
        this->addRecipe(recipe);
    }
    file.close();
}