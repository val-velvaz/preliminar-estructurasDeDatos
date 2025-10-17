#include "Recipe.hpp"

Name Recipe::getName() const {
    return this->recipeName;
}

void Recipe::setName(const Name& name) {
    this->recipeName = name;
}

Author Recipe::getAuthor() const {
    return this->author;
}

void Recipe::setAuthor(const Author& author) {
    this->author = author;
}

Category Recipe::getCategory() const {
    return this->category;
}

void Recipe::setCategory(Category category) {
    this->category = category;
}

Duration Recipe::getPrepTime() const {
    return this->prepTime;
}

void Recipe::setPrepTime(const Duration& prepTime) {
    this->prepTime = prepTime;
}

Procedure Recipe::getProcedure() const {
    return this->procedure;
}

void Recipe::setProcedure(const Procedure& procedure) {
    this->procedure = procedure;
}

const List<Ingredient>& Recipe::getIngredients() const {
    return this->ingredients;
}

List<Ingredient>& Recipe::getIngredients() {
    return this->ingredients;
}

void Recipe::setIngredients(const List<Ingredient>& ingredients) {
    this->ingredients = ingredients;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    int pos = 0;
    while (pos <= this->ingredients.getLast() && this->ingredients.get(pos).getName().getValue() < ingredient.getName().getValue()) {
        pos++;
    }
    this->ingredients.insert(pos, ingredient);
}

bool Recipe::deleteIngredient(const Name& ingredientName) {
    for (int i = 0; i <= this->ingredients.getLast(); ++i) {
        if (this->ingredients.get(i).getName().getValue() == ingredientName.getValue()) {
            this->ingredients.remove(i);
            return true;
        }
    }
    return false;
}

void Recipe::deleteAllIngredients() {
    this->ingredients.clear();
}

bool Recipe::modifyIngredientQuantity(const Name& ingredientName, const Quantity& newQuantity) {
    for (int i = 0; i <= this->ingredients.getLast(); ++i) {
        if (this->ingredients.get(i).getName().getValue() == ingredientName.getValue()) {
            this->ingredients.get(i).setQuantity(newQuantity);
            return true;
        }
    }
    return false;
}

std::string Recipe::categoryToString() const {
    switch (this->category) {
        case Category::DESAYUNO: return "Desayuno";
        case Category::COMIDA:   return "Comida";
        case Category::CENA:     return "Cena";
        case Category::NAVIDENO: return "Navideno";
        default:                 return "Sin Categoria";
    }
}

std::string Recipe::toString() const {
    std::string result = "\n>> " + this->getName().toString() + " <<\n";
    result += "Autor: " + this->getAuthor().toString() + "\n";
    result += "Categoria: " + this->categoryToString() + "\n";
    result += "Tiempo de Preparacion: " + this->getPrepTime().toString() + "\n\n";
    result += "Ingredientes:\n";
    result += this->ingredients.toString();
    result += "\nProcedimiento:\n" + this->getProcedure().toString() + "\n";
    return result;
}

int Recipe::compareByName(const Recipe& a, const Recipe& b) {
    if (a.getName().getValue() < b.getName().getValue()) return -1;
    if (a.getName().getValue() > b.getName().getValue()) return 1;
    return 0;
}

int Recipe::compareByPrepTime(const Recipe& a, const Recipe& b) {
    if (a.getPrepTime().getTotalInSeconds() < b.getPrepTime().getTotalInSeconds()) return -1;
    if (a.getPrepTime().getTotalInSeconds() > b.getPrepTime().getTotalInSeconds()) return 1;
    return 0;
}