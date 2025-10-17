#include "UserInterface.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

void UserInterface::clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInterface::pressEnterToContinue() {
    std::cout << "\nPresiona Enter para continuar...";
    clearInputBuffer();
}

UserInterface::UserInterface() {}

void UserInterface::run() {
    int choice;
    do {
        std::cout << "\n--- Menu Principal del Recetario ---\n"
                  << "1.  Agregar Receta\n"
                  << "2.  Eliminar Receta\n"
                  << "3.  Buscar Receta por Nombre\n"
                  << "4.  Buscar Receta por Categoria\n"
                  << "5.  Modificar Receta\n"
                  << "6.  Mostrar Todas las Recetas\n"
                  << "7.  Mostrar Recetas por Categoria\n"
                  << "8.  Ordenar Recetas\n"
                  << "9.  Guardar Recetas en Archivo\n"
                  << "10. Cargar Recetas de Archivo\n"
                  << "11. Eliminar Todas las Recetas\n"
                  << "0.  Salir\n"
                  << "Ingresa tu opcion: ";
        
        std::cin >> choice;
        if(std::cin.fail()){
            std::cin.clear();
            clearInputBuffer();
            choice = -1; // Invalida la opción para que vaya a default
        } else {
            clearInputBuffer();
        }

        switch (choice) {
            case 1: addNewRecipe(); break;
            case 2: deleteRecipe(); break;
            case 3: findRecipeByName(); break;
            case 4: findRecipeByCategory(); break;
            case 5: modifyRecipe(); break;
            case 6: showAllRecipes(); break;
            case 7: showRecipesByCategory(); break;
            case 8: sortMenu(); break;
            case 9: saveToFile(); break;
            case 10: loadFromFile(); break;
            case 11: deleteAllRecipes(); break;
            case 0: std::cout << "Saliendo del programa. Adios!\n"; break;
            default: std::cout << "Opcion invalida. Por favor intenta de nuevo.\n"; break;
        }
        if (choice != 0) {
            pressEnterToContinue();
        }

    } while (choice != 0);
}

void UserInterface::addNewRecipe() {
    Recipe newRecipe;
    std::string temp;
    
    std::cout << "Ingresa el nombre de la receta: ";
    std::getline(std::cin, temp);
    newRecipe.setName(Name(temp));

    std::cout << "Ingresa el nombre del autor: ";
    std::getline(std::cin, temp);
    newRecipe.setAuthor(Author(Name(temp)));
    
    newRecipe.setCategory(selectCategory());
    
    int h, m, s;
    std::cout << "Ingresa el tiempo de preparacion (horas minutos segundos): ";
    std::cin >> h >> m >> s;
    clearInputBuffer();
    newRecipe.setPrepTime(Duration(h, m, s));

    std::cout << "Ingresa el procedimiento (termina con una linea vacia): ";
    std::string procedureSteps, line;
    while(std::getline(std::cin, line) && !line.empty()) {
        procedureSteps += line + "\n";
    }
    newRecipe.setProcedure(Procedure(procedureSteps));

    this->myBook.addRecipe(newRecipe);
    std::cout << "Receta anadida exitosamente!\n";
}

void UserInterface::deleteRecipe() {
    std::string nameStr;
    std::cout << "Ingresa el nombre de la receta a eliminar: ";
    std::getline(std::cin, nameStr);
    this->myBook.deleteRecipeByName(Name(nameStr));
    std::cout << "Receta eliminada (si existia).\n";
}

void UserInterface::findRecipeByName() {
    std::string nameStr;
    std::cout << "Ingresa el nombre de la receta a buscar: ";
    std::getline(std::cin, nameStr);
    int index = this->myBook.findRecipeByName(Name(nameStr));
    if (index != -1) {
        std::cout << this->myBook.getRecipe(index).toString();
    } else {
        std::cout << "Receta no encontrada.\n";
    }
}

void UserInterface::findRecipeByCategory() {
    Category cat = selectCategory();
    Recipe* recipePtr = this->myBook.findRecipeByCategory(cat);
    if (recipePtr) {
        std::cout << "Primera receta encontrada en la categoria:\n";
        std::cout << recipePtr->toString();
    } else {
        std::cout << "No se encontraron recetas en esa categoria.\n";
    }
}

void UserInterface::modifyRecipe() {
    std::string nameStr;
    std::cout << "Ingresa el nombre de la receta a modificar: ";
    std::getline(std::cin, nameStr);
    int index = this->myBook.findRecipeByName(Name(nameStr));
    if (index != -1) {
        modifyRecipeMenu(this->myBook.getRecipe(index));
    } else {
        std::cout << "Receta no encontrada.\n";
    }
}

void UserInterface::showAllRecipes() {
    std::cout << "\n--- Todas las Recetas ---\n";
    if(this->myBook.getRecipes().isEmpty()){
        std::cout << "No hay recetas para mostrar.\n";
        return;
    }
    for(int i = 0; i <= this->myBook.getRecipes().getLast(); ++i) {
        std::cout << this->myBook.getRecipe(i).toString();
    }
}

void UserInterface::showRecipesByCategory() {
    Category cat = selectCategory();
    bool found = false;
    Recipe tempRecipe;
    tempRecipe.setCategory(cat);
    std::cout << "\n--- Recetas en Categoria: " << tempRecipe.categoryToString() << " ---\n";

    for (int i = 0; i <= this->myBook.getRecipes().getLast(); ++i) {
        if (this->myBook.getRecipe(i).getCategory() == cat) {
            std::cout << this->myBook.getRecipe(i).toString();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No se encontraron recetas en esta categoria.\n";
    }
}

void UserInterface::sortMenu() {
    int criteria, algorithm;
    std::cout << "Ordenar por (1: Nombre, 2: Tiempo de Preparacion): ";
    std::cin >> criteria;
    std::cout << "Algoritmo (1: Burbuja, 2: Insercion, 3: Seleccion, 4: Shell): ";
    std::cin >> algorithm;
    clearInputBuffer();

    try {
        this->myBook.sortRecipes(criteria, algorithm);
        std::cout << "Recetas ordenadas.\n";
    } catch(const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void UserInterface::saveToFile() {
    this->myBook.saveToFile("recetas.txt");
    std::cout << "Recetas guardadas en recetas.txt.\n";
}

void UserInterface::loadFromFile() {
    this->myBook.loadFromFile("recetas.txt");
    std::cout << "Recetas cargadas de recetas.txt.\n";
}

void UserInterface::deleteAllRecipes() {
    this->myBook.deleteAllRecipes();
    std::cout << "Todas las recetas han sido eliminadas.\n";
}

Category UserInterface::selectCategory() {
    int catChoice;
    std::cout << "Selecciona Categoria (1:Desayuno, 2:Comida, 3:Cena, 4:Navideno): ";
    std::cin >> catChoice;
    clearInputBuffer();
    switch (catChoice) {
        case 1: return Category::DESAYUNO;
        case 2: return Category::COMIDA;
        case 3: return Category::CENA;
        case 4: return Category::NAVIDENO;
        default: return Category::NONE;
    }
}

void UserInterface::modifyRecipeMenu(Recipe& recipe) {
    int choice;
    do {
        std::cout << "\n--- Modificar Receta: " << recipe.getName().toString() << " ---\n"
                << "1. Modificar Procedimiento\n"
                << "2. Anadir Ingrediente\n"
                << "3. Eliminar Ingrediente\n"
                << "4. Modificar Cantidad de Ingrediente\n"
                << "5. Eliminar Todos los Ingredientes\n"
                << "0. Volver al Menu Principal\n"
                << "Ingresa tu opcion: ";
        std::cin >> choice;
        clearInputBuffer();

        std::string tempName;
        switch(choice) {
            case 1: {
                std::string newSteps, line;
                std::cout << "Ingresa el nuevo procedimiento (termina con una linea vacia): ";
                while(std::getline(std::cin, line) && !line.empty()) {
                    newSteps += line + "\n";
                }
                recipe.setProcedure(Procedure(newSteps));
                std::cout << "Procediminto actualizado.\n";
                break;
            }
            case 2: {
                std::string quantityValue;
                std::cout << "Ingresa el nombre del ingrediente: ";
                std::getline(std::cin, tempName);
                std::cout << "Ingresa la cantidad: ";
                std::getline(std::cin, quantityValue);
                Ingredient newIngredient;
                newIngredient.setName(Name(tempName));
                newIngredient.setQuantity(Quantity(quantityValue));
                recipe.addIngredient(newIngredient);
                std::cout << "Ingrediente anadido.\n";
                break;
            }
            case 3: {
                std::cout << "Ingresa el nombre del ingrediente a eliminar: ";
                std::getline(std::cin, tempName);
                if(recipe.deleteIngredient(Name(tempName))) {
                    std::cout << "Ingrediente eliminado.\n";
                } else {
                    std::cout << "Ingrediente no encontrado.\n";
                }
                break;
            }
            case 4: {
                std::string newQuantityValue;
                std::cout << "Ingresa el nombre del ingrediente a modificar: ";
                std::getline(std::cin, tempName);
                std::cout << "Ingresa la nueva cantidad: ";
                std::getline(std::cin, newQuantityValue);
                if(recipe.modifyIngredientQuantity(Name(tempName), Quantity(newQuantityValue))) {
                    std::cout << "Cantidad actualizada.\n";
                } else {
                    std::cout << "Ingrediente no encontrado.\n";
                }
                break;
            }
            case 5: {
                recipe.deleteAllIngredients();
                std::cout << "Todos los ingredientes han sido eliminados.\n";
                break;
            }
        }
        if (choice != 0) {
            pressEnterToContinue();
        }
    } while (choice != 0);
}