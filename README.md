<img width="1273" height="442" alt="image" src="https://github.com/user-attachments/assets/4af3b27b-b43d-4d67-9659-aab713e57786" />

**Hellbound Blackjack** é um jogo de cartas com um estética sombria em pixelart com grandes inspirações em "Resident Evil" e "Fear & Hunger: TORMENTA", desenvolvido em **C** utilizando a biblioteca gráfica **raylib**, se aventure em um jogo de cartas complexo e bem estruturado e tente sobreviver.  

---

# 📑 **Seções**

- [🎮 Visão Geral](#visão-geral)
- [🎥 Vídeo de Demonstração](#vídeo-de-demonstração)  
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

# 🎥 **Vídeo de Demonstração** <a id="vídeo-de-demonstração"></a>

Assista abaixo a uma demonstração rápida do **Hellbound Blackjack** em execução:

[![Clique para assistir ao vídeo no YouTube](https://img.youtube.com/vi/XL6lsjvSiyY/hqdefault.jpg)](https://youtu.be/XL6lsjvSiyY)

---

# 🕹️ **Itch.io** <h2 id="itchio"></h2>

Nosso jogo também está disponível para download no itch.io:  
https://gustavotorrescastro.itch.io/hellbound-blackjack

Você pode baixar um pacote já compilado para o seu sistema operacional, porém **ele ainda depende da instalação da raylib e das bibliotecas descritas na seção de [🛠️ Pré-requisitos](#pré-requisitos)**.

> ⚠️ **Importante:** antes de tentar executar o jogo baixado pelo itch.io (em qualquer sistema),  
> certifique-se de que você seguiu a seção de **Pré-requisitos** correspondente ao seu sistema operacional:
> - [Windows](#windows)  
> - [Linux](#linux)  
> - [macOS](#macos)  

Após instalar a raylib e as dependências, utilize as instruções abaixo para rodar o executável baixado do itch.io em cada plataforma.

---

<h3 id="itch-windows">🎮 Hellbound Blackjack (Windows)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com RPG desenvolvido usando a biblioteca Raylib.

> ✅ **Antes de começar:** se você ainda não instalou a raylib e o ambiente no Windows,  
> siga primeiro a seção [🛠️ Pré-requisitos → Windows](#windows).

### COMO JOGAR (itch.io)

1. **Baixar:** Acesse a página do jogo no itch.io e baixe o arquivo ZIP para Windows.  
2. **Extrair:** Descompacte (extraia) o arquivo ZIP que você baixou.  
3. **Abrir pasta:** Entre na pasta extraída (que deve conter o `jogo.exe` e algumas DLLs).  
4. **Executar:** Dê dois cliques no arquivo **`jogo.exe`** para iniciar.

### AVISO IMPORTANTE (SmartScreen)

Na primeira execução, o Windows pode exibir a tela **"O Windows protegeu o computador"**.

Isso acontece porque o aplicativo não é assinado digitalmente e ainda não é conhecido pelo SmartScreen da Microsoft.

Para prosseguir:

1. Clique em **"Mais informações"**  
2. Clique em **"Executar assim mesmo"**

O jogo é seguro.

### REQUISITOS DO SISTEMA

- **Sistema Operacional:** Windows 7 ou superior (testado em Windows 10/11)  
- Placa de vídeo compatível com **OpenGL**  
- Raylib instalada conforme [Pré-requisitos → Windows](#windows)

### CRÉDITOS

- **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra e Silva  
- **Motor:** Raylib  

---

<h3 id="itch-linux">🎮 Hellbound Blackjack (Linux)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com RPG desenvolvido usando a biblioteca Raylib.

> ✅ **Antes de começar:** siga a seção [🛠️ Pré-requisitos → Linux](#linux)  
> para instalar a raylib e as bibliotecas necessárias (OpenGL, X11, etc.).

### 🕹️ COMO JOGAR (itch.io)

1. **Baixar:** Acesse a página do jogo no itch.io e baixe o arquivo **ZIP/tar.gz** para Linux.  
2. **Extrair:** Descompacte o arquivo que você baixou.  
3. **Tornar Executável (método gráfico):**
   - Clique com o **botão direito** no arquivo do jogo (geralmente chamado **`jogo`**).  
   - Vá em **Propriedades → Permissões**.  
   - Marque **"Permitir execução do arquivo como um programa"** (ou similar).  
4. **Executar:** Dê dois cliques no arquivo executável para iniciar.

#### Opção alternativa (Terminal)

1. Abra um terminal na pasta onde você extraiu o jogo.  
2. Dê permissão de execução:
   ```bash
   chmod +x jogo
   ```
3. Execute o jogo:
   ```bash
   ./jogo
   ```

### ⚙️ REQUISITOS DO SISTEMA

- **Sistema Operacional:** Distribuição Linux moderna (Ubuntu, Fedora, Arch, etc.)  
- Bibliotecas instaladas conforme [Pré-requisitos → Linux](#linux), incluindo:
  - **raylib**
  - **OpenGL**
  - **X11**
  - **libstdc++** e demais dependências de build/runtime

### 📝 CRÉDITOS

- **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra e Silva  
- **Motor:** Raylib  

---

<h3 id="itch-macos">🎮 Hellbound Blackjack (macOS)</h3>

Bem-vindo ao Hellbound Blackjack!

Este é um jogo de cartas com RPG desenvolvido usando a biblioteca Raylib.

> ✅ **Antes de começar:** siga a seção [🛠️ Pré-requisitos → macOS](#macos)  
> para instalar a raylib via Homebrew e configurar o seu ambiente.

### 🕹️ COMO JOGAR (itch.io)

1. **Baixar:** Acesse a página do jogo no itch.io e baixe o pacote para macOS (ZIP/tar.gz).  
2. **Extrair:** Descompacte o arquivo que você baixou.  
3. **Mover:** Arraste o executável **`Hellbound`** (ou o app gerado) para a pasta **Aplicativos (Applications)** ou para qualquer pasta de sua preferência.
4. Clique 2 vezes no ícone do jogo para abrí-lo.

### AVISO IMPORTANTE

Na primeira execução, o Mac pode dar o aviso **"O item Hellbound (ou o nome do app gerado) não foi aberto"**.

Para prosseguir:

1. Clique no ícone de interrogação na parte superior do aviso, ele irá lhe redirecionar para uma página específica do Manual de Uso do Mac.
2. Clique em "Abra o ajuste 'Privacidade e Segurança' para mim".
3. Role até a aba "Segurança" na tela que abrirá após o clique anterior.
4. Você verá um aviso "O item Hellbound (ou o nome do app gerado) foi bloqueado para proteger o Mac", e ao lado dele um botão "Abrir Mesmo Assim", clique nele.
5. Outro aviso surgirá em sua tela "Abrir O item Hellbound (ou o nome do app gerado)?".
6. Clique em "Abrir mesmo assim".

O jogo é seguro.

> 🔐 Essa etapa só é necessária na primeira vez, pois o macOS não reconhece o desenvolvedor. Depois disso, basta dar dois cliques normalmente.

### ⚙️ REQUISITOS DO SISTEMA

- **Sistema Operacional:** macOS 10.9 (Mavericks) ou superior  
- Raylib instalada conforme [Pré-requisitos → macOS](#macos)  
- Suporte a **OpenGL** habilitado no sistema

### 📝 CRÉDITOS

- **Desenvolvimento e Código:** Gustavo Torres Castro, Bruno Augusto da Rocha Leite Filho e Igor Gabriel Dutra da Silva  
- **Motor:** Raylib

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
2. No terminal, instale a **raylib** com os seguintes comandos:

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
