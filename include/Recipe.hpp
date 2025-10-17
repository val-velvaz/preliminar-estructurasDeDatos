#pragma once

#include "List.hpp"
#include "Ingredient.hpp"
#include "Author.hpp"
#include "Duration.hpp"
#include "Procedure.hpp"
#include "Name.hpp"

enum class Category { DESAYUNO, COMIDA, CENA, NAVIDENO, NONE };

class Recipe {
private:
    Name recipeName;
    Author author;
    Category category;
    Duration prepTime; 
    Procedure procedure;
    List<Ingredient> ingredients;

public:
    Name getName() const;
    void setName(const Name& name);

    Author getAuthor() const;
    void setAuthor(const Author& author);

    Category getCategory() const;
    void setCategory(Category category);

    Duration getPrepTime() const;
    void setPrepTime(const Duration& prepTime);

    Procedure getProcedure() const;
    void setProcedure(const Procedure& procedure);

    const List<Ingredient>& getIngredients() const;
    List<Ingredient>& getIngredients();
    void setIngredients(const List<Ingredient>& ingredients);

    void addIngredient(const Ingredient& ingredient);
    bool deleteIngredient(const Name& ingredientName);
    void deleteAllIngredients();
    bool modifyIngredientQuantity(const Name& ingredientName, const Quantity& newQuantity);

    std::string categoryToString() const;
    std::string toString() const;

    static int compareByName(const Recipe& a, const Recipe& b);
    static int compareByPrepTime(const Recipe& a, const Recipe& b);
};