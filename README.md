<div align="center">
  <svg width="200" height="100" xmlns="http://www.w3.org/2000/svg">
    <rect x="10" y="10" width="180" height="80" rx="20" ry="20" style="fill: #FFD1DC; stroke: #FFB6C1; stroke-width: 2;"/>
    <text x="50%" y="50%" dominant-baseline="middle" text-anchor="middle" style="font-family: 'Comic Sans MS', cursive, sans-serif; font-size: 24px; fill: #FFFFFF;">Recetario</text>
    <text x="50%" y="75%" dominant-baseline="middle" text-anchor="middle" style="font-family: 'Comic Sans MS', cursive, sans-serif; font-size: 14px; fill: #FFFFFF;">Hecho con ♡</text>
  </svg>
</div>

<h1 align="center" style="color: #FFB6C1;">
  Mi Recetario Mágico 🍳✨
</h1>
<p align="center" style="color: #FFB6C1;">
  <i>Tu pequeño asistente de cocina para guardar y organizar todas tus recetas favoritas.</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=for-the-badge&logo=cplusplus&logoColor=white&color=FFB6C1" alt="C++17">
  <img src="https://img.shields.io/badge/Estado-Finalizado-green.svg?style=for-the-badge&color=D4F0F0" alt="Estado del Proyecto">
  <img src="https://img.shields.io/badge/Mantenido-S%C3%AD-ff69b4.svg?style=for-the-badge&color=FFDAB9" alt="Mantenimiento">
  <img src="https://img.shields.io/github/last-commit/google/gemini-pro-vision?style=for-the-badge&logo=github&logoColor=white&color=C1E1C1" alt="Último Commit">
</p>

---

### 🎀 Presentación Amable

Es una aplicación de consola súper fácil de usar, desarrollada en C++, que te permite:
- **Añadir** nuevas recetas.
- **Guardar** todos los detalles: ingredientes, tiempo de preparación, autor y los pasos a seguir.
- **Organizar** tus platillos por categorías como desayuno, comida, cena y ¡hasta recetas navideñas!
- **Buscar, modificar y eliminar** recetas cuando lo necesites.
- **Guardar y cargar** tu colección completa desde un archivo.

---

### 🎨 Paleta Tecnológica

Este proyecto fue creado con utilizando las siguientes herramientas:

<div align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white&color=FFD1DC" alt="C++">
  <img src="https://img.shields.io/badge/Makefile-4298B8?style=for-the-badge&logo=gnu-make&logoColor=white&color=D4F0F0" alt="Makefile">
  <img src="https://img.shields.io/badge/Visual%20Studio%20Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white&color=C1E1C1" alt="VSCode">
</div>

---

### ✨ Joyas del Proyecto

- **🍰 Gestión Completa de Recetas:** Añade, elimina y modifica recetas con todos sus detalles.
- **👩‍🍳 Autor y Categorías:** Asigna un autor a cada receta y clasifícalas para una mejor organización.
- **📜 Listas Dinámicas:** Utiliza una clase `List` genérica para manejar colecciones de recetas e ingredientes.
- **💾 Persistencia de Datos:** Guarda todo tu recetario en un archivo de texto (`recetas.txt`) y cárgalo al iniciar.
- **🔍 Búsqueda Inteligente:** Encuentra recetas por nombre o por categoría de forma rápida y sencilla.
- **🔢 Algoritmos de Ordenamiento:** Ordena tu recetario por nombre o tiempo de preparación usando algoritmos como Burbuja, Inserción, Selección o Shell.
- **🎀 Interfaz de Usuario Amigable:** Menú de consola claro e intuitivo para interactuar con todas las funciones.

---

### 🛠️ Guía de Instalación y Uso

¡Poner en marcha este recetario es súper fácil! Solo sigue estos pasitos:

1.  **Clona el Repositorio:**
    ```bash
    git clone [https://github.com/tu-usuario/tu-repositorio.git](https://github.com/tu-usuario/tu-repositorio.git)
    cd tu-repositorio
    ```

2.  **Compila el Proyecto:**
    Abre tu terminal en la carpeta `preliminar` y usa el `Makefile` incluido.
    ```bash
    make
    ```
    Esto compilará todo el código fuente y creará un ejecutable en la carpeta `output`.

3.  **¡Ejecuta la Aplicación!**
    ```bash
    ./output/main.exe
    ```

4.  **Disfruta tu Recetario:**
    ¡Y listo! Se desplegará un menú interactivo en tu consola para que comiences a añadir tus recetas.

---

### 🖼️ Galería Visual

<details>
  <summary style="cursor: pointer; color: #FFB6C1;"><strong>💖 ¡Haz clic para ver cómo luce la app! 💖</strong></summary>
  <br>
  <p align="center">
    <i>Aquí puedes añadir capturas de pantalla del menú principal, la vista de una receta, el proceso de añadir un ingrediente, ¡y más!</i>
    <br><br>
    </p>
</details>

---

### 🏛️ Diagrama de Arquitectura (UML)

Aquí tienes un vistazo a cómo se conectan todas las piezas de este proyecto.

```mermaid
classDiagram
    direction TD

    class Name {
        -std::string value
        +Name()
        +Name(const std_string& value)
        +getValue() std_string
        +setValue(const std_string& value) void
        +toString() std_string
    }

    class Author {
        -Name authorName
        +Author()
        +Author(const Name& name)
        +getName() Name
        +setName(const Name& name) void
        +toString() std_string
    }

    class Quantity {
        -std::string value
        +Quantity()
        +Quantity(const std_string& value)
        +getValue() std_string
        +setValue(const std_string& value) void
        +toString() std_string
    }

    class Duration {
        -int hours
        -int minutes
        -int seconds
        -normalize() void
        +Duration()
        +Duration(int h, int m, int s)
        +getHours() int
        +setHours(int h) void
        +getMinutes() int
        +setMinutes(int m) void
        +getSeconds() int
        +setSeconds(int s) void
        +getTotalInSeconds() int
        +toString() std_string
    }

    class Procedure {
        -std::string steps
        +Procedure()
        +Procedure(const std_string& steps)
        +getSteps() std_string
        +setSteps(const std_string& steps) void
        +toString() std_string
    }

    class Ingredient {
        -Name ingredientName
        -Quantity quantity
        +getName() Name
        +setName(const Name& name) void
        +getQuantity() Quantity
        +setQuantity(const Quantity& quantity) void
        +toString() std_string
    }

    class Category {
        <<enumeration>>
        DESAYUNO
        COMIDA
        CENA
        NAVIDENO
        NONE
    }

    class ListT {
        <<template>>
        -T** data
        -int lastPos
        -int capacity
        -isValidPos(int pos) bool
        -copyAll(const ListT& other) void
        -swapData(T*& a, T*& b) void
        +List()
        +List(const List& other)
        +~List()
        +operator_assign(const ListT& other) ListT&
        +initialize() void
        +isEmpty() bool
        +isFull() bool
        +insert(int pos, const T& element) void
        +remove(int pos) void
        +get(int pos) T
        +get_ref(int pos) T&
        +getFirst() int
        +getLast() int
        +clear() void
        +toString() std_string
        +sortBubble(int cmp) void
        +sortInsert(int cmp) void
        +sortSelect(int cmp) void
        +sortShell(int cmp) void
    }

    class Recipe {
        -Name recipeName
        -Author author
        -Category category
        -Duration prepTime
        -Procedure procedure
        -ListT~Ingredient~ ingredients
        +getName() Name
        +setName(const Name& name) void
        +getAuthor() Author
        +setAuthor(const Author& author) void
        +getCategory() Category
        +setCategory(Category category) void
        +getPrepTime() Duration
        +setPrepTime(const Duration& prepTime) void
        +getProcedure() Procedure
        +setProcedure(const Procedure& procedure) void
        +getIngredients() ListT~Ingredient~&
        +getIngredients_const() const ListT~Ingredient~&
        +setIngredients(const ListT~Ingredient~& ingredients) void
        +addIngredient(const Ingredient& ingredient) void
        +deleteIngredient(const Name& ingredientName) bool
        +deleteAllIngredients() void
        +modifyIngredientQuantity(const Name& name, const Quantity& qty) bool
        +categoryToString() std_string
        +toString() std_string
        +compareByName(const Recipe& a, const Recipe& b)$ int
        +compareByPrepTime(const Recipe& a, const Recipe& b)$ int
    }

    class RecipeBook {
        -ListT~Recipe~ recipes
        +getRecipes() const ListT~Recipe~&
        +setRecipes(const ListT~Recipe~& recipes) void
        +addRecipe(const Recipe& recipe) void
        +findRecipeByName(const Name& name) int
        +findRecipeByCategory(Category category) Recipe*
        +deleteRecipeByName(const Name& name) void
        +deleteAllRecipes() void
        +sortRecipes(int criteria, int algorithm) void
        +getRecipe(int index) Recipe&
        +saveToFile(const std_string& filename) void
        +loadFromFile(const std_string& filename) void
    }

    class UserInterface {
        -RecipeBook myBook
        -clearInputBuffer() void
        -pressEnterToContinue() void
        -addNewRecipe() void
        -deleteRecipe() void
        -findRecipeByName() void
        -findRecipeByCategory() void
        -modifyRecipe() void
        -showAllRecipes() void
        -showRecipesByCategory() void
        -sortMenu() void
        -saveToFile() void
        -loadFromFile() void
        -deleteAllRecipes() void
        -modifyRecipeMenu(Recipe& recipe) void
        -selectCategory() Category
        +UserInterface()
        +run() void
    }

    class std_string {
        <<library>>
    }

    class std_ostream {
        <<library>>
    }

    class std_istream {
        <<library>>
    }

    Author *-- Name
    Ingredient *-- Name
    Ingredient *-- Quantity
    Recipe *-- Name
    Recipe *-- Author
    Recipe *-- Duration
    Recipe *-- Procedure
    Recipe *-- ListT
    Recipe --> Category
    RecipeBook *-- ListT
    UserInterface *-- RecipeBook

    Name *-- std_string
    Quantity *-- std_string
    Procedure *-- std_string
    Duration ..> std_string
    Author ..> std_string
    Ingredient ..> std_string
    Recipe ..> std_string
    ListT ..> std_string

    Name ..> std_ostream
    Name ..> std_istream
    Author ..> std_ostream
    Author ..> std_istream
    Quantity ..> std_ostream
    Quantity ..> std_istream
    Duration ..> std_ostream
    Duration ..> std_istream
    Procedure ..> std_ostream
    Procedure ..> std_istream
    Ingredient ..> std_ostream
    Ingredient ..> std_istream
    RecipeBook ..> std_string

    style Recipe fill:#e1f5ff,stroke:#01579b,stroke-width:2px,color:#000
    style RecipeBook fill:#e1f5ff,stroke:#01579b,stroke-width:2px,color:#000
    style Name fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style Quantity fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style Duration fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style Procedure fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style Author fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style Ingredient fill:#fff9c4,stroke:#f57f17,stroke-width:2px,color:#000
    style ListT fill:#f3e5f5,stroke:#4a148c,stroke-width:2px,color:#000
    style Category fill:#ffccbc,stroke:#bf360c,stroke-width:2px,color:#000
    style std_string fill:#e0e0e0,stroke:#616161,stroke-width:1px,color:#000
    style std_ostream fill:#e0e0e0,stroke:#616161,stroke-width:1px,color:#000
    style std_istream fill:#e0e0e0,stroke:#616161,stroke-width:1px,color:#000
    style UserInterface fill:#c8e6c9,stroke:#1b5e20,stroke-width:2px,color:#000
```
