<img width="1273" height="442" alt="image" src="https://github.com/user-attachments/assets/4af3b27b-b43d-4d67-9659-aab713e57786" />



**Hellbound Blackjack** é um jogo de cartas com um estética sombria em pixelart com grandes inspirações em "Resident Evil" e "Fear & Hunger: TORMENTA", desenvolvido em **C** utilizando a biblioteca gráfica **raylib**, se aventure em um jogo de cartas complexo e bem estruturado e tente sobreviver.  

---

# 📑 **Índice**

- [🎮 Visão Geral](#-visão-geral)  
- [🛠️ Pré-requisitos](#️-pré-requisitos)  
  - [Windows](#-windows)  
  - [Linux](#-linux)  
  - [macOS](#-macos)  
- [🏗️ Uso do Makefile](#️-uso-do-makefile)  
- [🎮 Controles do Jogo](#-controles-do-jogo)  
- [📷 Participantes](#participantes)  

---


# 🎮 **Visão Geral**
<img width="1270" height="69" alt="image" src="https://github.com/user-attachments/assets/8be431e5-013e-4b01-ae11-885a5d66b5ae" />

O projeto foi construído com uma combinação leve e poderosa de ferramentas:

- 🧠 Linguagem C
- 🎨 raylib 
- 🛠️ make 
- 🧩 gcc / clang 

---

# 🛠️ **Pré-requisitos**

## 🪟 **Windows**

1. Instale o **MSYS2**  
2. No terminal *MSYS2 MinGW 64-bit* execute:
```bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
pacman -S mingw-w64-x86_64-raylib
```

3. Compile usando:

```bash
mingw32-make
```

---

## 🐧 **Linux**

Instale as dependências:

```bash
sudo apt update
sudo apt install build-essential make gcc libraylib-dev
```

Compile com:

```bash
make
```

---

## 🍎 **macOS**

Instale:

```bash
brew install raylib
```

Compile:

```bash
make
```

---

# 🏗️ **Uso do Makefile**

### 🔹 Compilar o projeto

```bash
make
```

### 🔹 Executar o jogo

```bash
make run
```

### 🔹 Limpar arquivos de build

```bash
make clean
```

### 🔹 Instalar dependências automaticamente (quando suportado)

```bash
make deps
```

---

# 🎮 **Controles do Jogo**

### **Menu Inicial**

- ↓ / S → próximo item  
- ↑ / W → item anterior  
- **Enter** → confirma  

### **Tela de Opções**

- → / D → aumenta a dificuldade  
- ← / A → reduz a dificuldade  
- **Esc / Enter** → volta  

---

# 👨‍👩‍👧‍👦 **Participantes** <h2 id="participantes"></h2>

| <img src="https://avatars.githubusercontent.com/u/107767224?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/200817151?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/211526755?v=4" width="120" height="120"> |
|---------------------------------|---------------------------------|---------------------------------|
| **Igor Gabriel** | **Bruno Augusto** | **Gustavo Torres** |
| Desenvolvedor • Designer | Desenvolvedor | Desenvolvedor |


---

