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

¡Hola! 👋 ¿Cansada de tener tus recetas esparcidas en notas adhesivas, cuadernos viejos o en enlaces perdidos en tu navegador? ¡Este **Recetario Mágico** es la solución perfecta para ti! 💖

Es una aplicación de consola súper adorable y fácil de usar, desarrollada en C++, que te permite:
- **Añadir** nuevas y deliciosas recetas.
- **Guardar** todos los detalles: ingredientes, tiempo de preparación, autor y los pasos a seguir.
- **Organizar** tus platillos por categorías como desayuno, comida, cena y ¡hasta recetas navideñas!
- **Buscar, modificar y eliminar** recetas cuando lo necesites.
- **Guardar y cargar** tu colección completa desde un archivo para que nunca pierdas tus creaciones.

¡Es como tener tu propio libro de cocina digital, siempre listo para inspirarte en tu próxima aventura culinaria!

---

### 🎨 Paleta Tecnológica

Este proyecto fue creado con mucho cariño utilizando las siguientes herramientas:

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
    ¡Y listo! Se desplegará un menú interactivo en tu consola para que comiences a añadir tus recetas favoritas.

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

Aquí tienes un vistazo a cómo se conectan todas las piezas de este adorable proyecto, ¡compatible con Mermaid v8!

```mermaid
graph TD
    %% --- Subgraphs for Organization ---
    subgraph "Core Logic"
        UI["UserInterface<br>-myBook: RecipeBook<br>+run()"]
        Book["RecipeBook<br>-recipes: List&lt;Recipe&gt;<br>+addRecipe(const Recipe&)<br>+findRecipeByName(const Name&): int<br>+deleteRecipeByName(const Name&)<br>+saveToFile(const string&)<br>+loadFromFile(const string&)"]
        ListRecipe["List&lt;Recipe&gt;"]
        ListIngredient["List&lt;Ingredient&gt;"]
    end

    subgraph "Data Models"
        Rec["Recipe<br>-recipeName: Name<br>-author: Author<br>-category: Category<br>-prepTime: Duration<br>-procedure: Procedure<br>-ingredients: List&lt;Ingredient&gt;<br>+toString(): string"]
        Ing["Ingredient<br>-ingredientName: Name<br>-quantity: Quantity<br>+toString(): string"]
    end

    subgraph "Primitive Data Wrappers"
        Auth["Author<br>-authorName: Name<br>+toString(): string"]
        Nm["Name<br>-value: string<br>+toString(): string"]
        Dur["Duration<br>-minutes: int<br>+toString(): string"]
        Proc["Procedure<br>-steps: string<br>+toString(): string"]
        Qty["Quantity<br>-value: string<br>+toString(): string"]
    end

    subgraph "Enumerations"
        Cat["<<enumeration>><br>Category<br>DESAYUNO<br>COMIDA<br>CENA<br>NAVIDENO<br>NONE"]
    end

    %% --- Relationships (Simplified for GitHub Compatibility) ---
    UI --> Book
    Book --> ListRecipe
    ListRecipe --> Rec

    Rec --> Nm
    Rec --> Auth
    Rec --> Cat
    Rec --> Dur
    Rec --> Proc
    Rec --> ListIngredient

    ListIngredient --> Ing
    Ing --> Nm
    Ing --> Qty

    Auth --> Nm
```
