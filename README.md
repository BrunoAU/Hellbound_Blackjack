<img width="1273" height="442" alt="image" src="https://github.com/user-attachments/assets/4af3b27b-b43d-4d67-9659-aab713e57786" />



**Hellbound Blackjack** é um jogo de cartas com um estética sombria em pixelart com grandes inspirações em "Resident Evil" e "Fear & Hunger: TORMENTA", desenvolvido em **C** utilizando a biblioteca gráfica **raylib**, se aventure em um jogo de cartas complexo e bem estruturado e tente sobreviver.  

---

# **Seções**

- [🎮 Visão Geral](#-visão-geral)  
- [🛠️ Pré-requisitos](#️-pré-requisitos)  
  - [Windows](#-windows)  
  - [Linux](#-linux)  
  - [macOS](#-macos)  
- [🏗️ Uso do Makefile](#️-uso-do-makefile)  
- [🎮 Controles do Jogo](#-controles-do-jogo)  
- [📷 Participantes](#participantes)  

---


# **Visão Geral**

<img width="1270" height="69" alt="image" src="https://github.com/user-attachments/assets/8be431e5-013e-4b01-ae11-885a5d66b5ae" />

O projeto foi construído com uma combinação leve e poderosa de ferramentas:

- Linguagem C
- raylib 
- make 
- gcc / clang 

---


# **Pré-requisitos**

## **Windows**

Há duas formas principais de preparar o ambiente no Windows.  
Recomendamos utilizar o **MSYS2 MinGW 64-bit**.

### Usando o pacote pré-compilado da raylib (zip oficial)

1. Baixe o pacote **raylib 5.5 (MinGW-w64)** no site oficial.  
2. Extraia o conteúdo em `C:/raylib-5.5_win64_mingw-w64` (pasta padrão esperada pelo `Makefile`).  
3. No terminal **MSYS2 MinGW 64-bit**, dentro da pasta do projeto, compile com:

```bash
mingw32-make
```

3. Ainda no terminal *MSYS2 MinGW 64-bit*, dentro da pasta do projeto, compile informando o caminho da raylib do MSYS2:

```bash
mingw32-make RAYLIB_PATH=/mingw64
```

> Dica: se preferir, você pode editar o `Makefile` e ajustar permanentemente o valor de `RAYLIB_PATH` para `/mingw64`.

4. Depois de compilar, execute o jogo com:

```bash
./jogo.exe
```

---

## **Linux**

1. Instale as dependências de sistema:

```bash
sudo apt update
sudo apt install build-essential gcc make pkg-config git \
    libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```

2. Baixe e prepare a **raylib** (versão local em `~/dev_libs/raylib`, usada pelo Makefile):

```bash
make deps-linux
```

Esse comando irá criar a pasta `~/dev_libs/raylib` e clonar o repositório oficial da raylib.

3. Compile a **raylib** (apenas na primeira vez):

```bash
cd ~/dev_libs/raylib/src
make
```

4. Volte para a pasta do projeto e compile o jogo:

```bash
cd /caminho/para/Hellbound_Blackjack-main
make
```

5. Execute o jogo:

```bash
./jogo
```

---

## **macOS**

1. Instale o **Homebrew** (se ainda não tiver).  
2. No terminal, instale a **raylib**:

```bash
brew update
brew install raylib
```

> Opcionalmente, você pode usar também:
>
> ```bash
> make deps-macos
> ```
> 
> que chama internamente os mesmos comandos de instalação via Homebrew.

3. Com a raylib instalada, na pasta do projeto, compile o jogo:

```bash
make
```

4. Execute o jogo:

```bash
./jogo
```

---


# **Uso do Makefile**

### 🔹 Compilar o projeto

```bash
make
```

### 🔹 Executar o jogo

Após compilar, execute manualmente o binário gerado:

```bash
# Linux / macOS
./jogo

# Windows (MSYS2 MinGW 64-bit)
./jogo.exe
```

### 🔹 Limpar arquivos de build

```bash
make clean
```

### 🔹 Instalar dependências automaticamente (quando suportado)

```bash
make deps
```

> O comando `make deps` chama internamente:
> - `make deps-windows` (no Windows, para instalar pacotes via `pacman`, se configurado)  
> - `make deps-linux` (no Linux, para preparar a pasta `~/dev_libs/raylib`)  
> - `make deps-macos` (no macOS, para instalar a raylib com Homebrew)

---

# **Controles do Jogo**

### **Menu Inicial**

- ↓ / S → próximo item  
- ↑ / W → item anterior  
- **Enter** → confirma  

### **Tela de Opções**

- → / D → aumenta a dificuldade  
- ← / A → reduz a dificuldade  
- **Esc / Enter** → volta  

---

# **Participantes** <h2 id="participantes"></h2>

| <img src="https://avatars.githubusercontent.com/u/107767224?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/200817151?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/211526755?v=4" width="120" height="120"> |
|---------------------------------|---------------------------------|---------------------------------|
| **Igor Gabriel** | **Bruno Augusto** | **Gustavo Torres** |
| Desenvolvedor • Artista | Desenvolvedor | Desenvolvedor |


---
