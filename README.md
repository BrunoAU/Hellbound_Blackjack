<img width="1273" height="442" alt="image" src="https://github.com/user-attachments/assets/4af3b27b-b43d-4d67-9659-aab713e57786" />

**Hellbound Blackjack** é um jogo de cartas com um estética sombria em pixelart com grandes inspirações em "Resident Evil" e "Fear & Hunger: TORMENTA", desenvolvido em **C** utilizando a biblioteca gráfica **raylib**, se aventure em um jogo de cartas complexo e bem estruturado e tente sobreviver.  

---

# 📑 **Seções**

- [🎮 Visão Geral](#visão-geral)  
- [🕹️ Itch.io](#itchio)  
  - [Windows](#itch-windows)  
  - [Linux](#itch-linux)  
  - [macOS](#itch-macos)  
- [🛠️ Pré-requisitos](#pré-requisitos)  
  - [Windows](#windows)  
  - [Linux](#linux)  
  - [macOS](#macos)  
- [🏗️ Uso do Makefile](#uso-do-makefile)  
- [📷 Participantes](#participantes)  

---

# 🎮 **Visão Geral**

<img width="1270" height="69" alt="image" src="https://github.com/user-attachments/assets/8be431e5-013e-4b01-ae11-885a5d66b5ae" />

O projeto foi construído com uma combinação leve e poderosa de ferramentas:

- Linguagem C
- raylib 
- make 
- gcc / clang 

---

# 🕹️ **Itch.io** <h2 id="itchio"></h2>

Nosso jogo está disponível para download no itch.io: https://gustavotorrescastro.itch.io/hellbound-blackjack

Selecione o Sistema operacional desejado, baixe, extraia a pasta e acesse o readme presente nela para o resto
das instruções de instalação.

Abaixo estão as instruções completas para rodar o **Hellbound Blackjack** a partir da versão distribuída no **itch.io**, já compilada e pronta para uso em cada sistema operacional.

---

<h3 id="itch-windows">🎮 Hellbound Blackjack (Windows)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com rpg desenvolvido usando a biblioteca Raylib.

### COMO JOGAR

1.  **Extrair:** Descompacte (extraia) o arquivo ZIP que você baixou.
2.  **Abrir:** Entre na pasta extraída (que deve conter o `jogo.exe` e algumas DLLs).
3.  **Executar:** Dê dois cliques no arquivo **jogo.exe** para iniciar.

### AVISO IMPORTANTE (SmartScreen)

Se esta for a primeira vez que você executa o jogo, o Windows pode exibir uma tela azul chamada **"O Windows protegeu o computador"**.

Isso acontece porque o aplicativo é um software independente e ainda não é reconhecido pelo SmartScreen da Microsoft.

**Para prosseguir, basta clicar em:**

1.  **"Mais informações"**
2.  **"Executar assim mesmo"**

O jogo é seguro!

### REQUISITOS DO SISTEMA

* **Sistema Operacional:** Windows 7 ou superior (testado em Windows 10/11)
* (Opcional) Placa de vídeo compatível com **OpenGL**

### CRÉDITOS

* **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra e Silva
* **Motor:** Raylib

---

<h3 id="itch-linux">🎮 Hellbound Blackjack (Linux)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com rpg desenvolvido usando a biblioteca Raylib.

### 🕹️ COMO JOGAR

1.  **Extrair:** Descompacte (extraia) o arquivo ZIP/tar.gz que você baixou.
2.  **Tornar Executável (Método Gráfico):**
    * Clique com o **botão direito** no arquivo executável do jogo (que se chama **jogo**).
    * Vá em **Propriedades** > **Permissões**.
    * Marque a caixa **"Permitir execução do arquivo como um programa"** (ou similar).
3.  **Executar:** Dê dois cliques no arquivo executável para iniciar.

#### Opção Alternativa (Usando o Terminal)

1.  Abra o Terminal na pasta onde você extraiu o jogo.
2.  Use o comando para dar permissão de execução:
    ```bash
    chmod +x jogo
    ```
3.  Execute o jogo com o seguinte comando:
    ```bash
    ./jogo
    ```

### ⚙️ REQUISITOS DO SISTEMA

* **Sistema Operacional:** Qualquer distribuição Linux moderna (Ubuntu, Fedora, Arch, etc.).
* **Dependências:** Seu sistema precisa ter as bibliotecas padrões do C/C++ (libstdc++) e, possivelmente, as bibliotecas **X11** e **OpenGL** instaladas para a Raylib funcionar.

### 📝 CRÉDITOS

* **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra e Silva
* **Motor:** Raylib

---

<h3 id="itch-macos">🎮 Hellbound Blackjack (macOS)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com rpg desenvolvido usando a biblioteca Raylib.

### 🕹️ COMO JOGAR

1.  **Extrair:** Descompacte (extraia) o arquivo ZIP/tar.gz que você baixou.
2.  **Copiar:** Arraste o arquivo **jogo** para a sua pasta **Aplicativos** (Applications).
3.  **Executar (Primeira Vez):**
    * Clique no ícone do jogo com o **botão direito** (ou Control + Clique).
    * Selecione **"Abrir"** no menu.
    * Na janela de aviso de segurança, clique em **"Abrir"** novamente.

**⚠️ Nota:** Esta etapa de "clique direito > Abrir" é necessária apenas na primeira execução, pois o macOS não reconhece o desenvolvedor. Depois disso, basta dar dois cliques normalmente.

### ⚙️ REQUISITOS DO SISTEMA

* **Sistema Operacional:** macOS 10.9 (Mavericks) ou superior.
* (Opcional) Placa de vídeo compatível com **OpenGL**

### 📝 CRÉDITOS

* **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra e Silva
* **Motor:** Raylib

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
sudo apt install build-essential gcc make pkg-config git     libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
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

# 🏗️ **Uso do Makefile**

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

# 📷 **Participantes** <h2 id="participantes"></h2>

| <img src="https://avatars.githubusercontent.com/u/107767224?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/200817151?v=4" width="120" height="120"> | <img src="https://avatars.githubusercontent.com/u/211526755?v=4" width="120" height="120"> |
|---------------------------------|---------------------------------|---------------------------------|
| **Igor Gabriel** | **Bruno Augusto** | **Gustavo Torres** |
| Desenvolvedor • Artista | Desenvolvedor | Desenvolvedor |
