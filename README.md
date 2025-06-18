# Prairie King

This is the **Prairie King** project, an arena-style shooter game with **resource management** and **level progression** elements.

---

## About the Game

Inspired by classic arcade games, Prairie King places the player in a challenging environment where the objective is to **survive waves of enemies**, **collect resources**, and **upgrade the character** to face the formidable **final boss**.

### Features

* **Shooting Mechanics**: Shoot in **8 directions** to defeat approaching enemies.
* **Dynamic Level Generation**: Levels are procedurally generated with different block types and enemy spawn positions.
* **Varied Enemies**: Encounter different enemy types, including a challenging **final boss**.
* **Life System**: Manage your character's lives and try to survive as long as possible.
* **Resource Collection**: Collect **chests** dropped by enemies to gain bonuses.
* **Bonuses**: Obtain **extra lives** and different **temporary ammunition types** to aid your journey.
* **Final Scoreboard**: View your score based on defeated enemies and remaining lives.

---

## How to Play

### Controls

* **`W` `A` `S` `D`**: Move the character.
* **`ARROWS`**: Control shooting direction.
* **`ESC`**: Pause game / Return to main menu.
* **`SPACE`**: Start game / Advance to the next screen.

### Objectives

**Survive** enemy waves, **defeat the final boss**, and achieve the **highest possible score**!

---

## Project Structure

The project is organized into the following **main classes**:

* **`Background`**: Manages the creation and drawing of the game's environment.
* **`BgBlock`**: Represents individual blocks within the game environment.
* **`Bullet`**: Base class for all projectiles.
    * **`DefaultBullet`**: Implements the player's standard projectile.
    * **`EnemyBullet`**: Implements enemy projectiles.
    * **`PiercingBullet`**: Implements a special projectile that can pierce through enemies.
* **`Chest`**: Represents bonus chests that can be collected.
* **`CowboyBoss`**: Implements the final boss of the game.
* **`Enemy`**: Base class for normal enemies.
* **`Game`**: Base class for different game screens (Menu, Level, Game Over).
* **`GameOver`**: Screen displayed when the player loses.
* **`Home`**: Game's initial screen.
* **`Level1`**: Implements the logic and elements of the first game level.
* **`Object`**: Base class for all game objects.
* **`Player`**: Implements the logic and controls for the player character.
* **`Pivot`**: Reference points in the environment for certain object movements.
* **`Scene`**: Manages the updating, drawing, and collision detection of objects in the scene.
* **`ShieldEnemy`**: A type of enemy that possesses a shield.
* **`Victory`**: Screen displayed when the player wins.

---

## Compilation Requirements

This project was developed and compiled with **Visual C++ 2022**. Ensure your development environment is correctly configured.

---
---

# Prairie King (Português)

Este é o projeto **Prairie King**, um jogo de tiro estilo arena com elementos de **gerenciamento de recursos** e **progressão de níveis**.

---

## Sobre o Jogo

Inspirado em jogos clássicos de arcade, Prairie King coloca o jogador em um ambiente desafiador onde o objetivo é **sobreviver a ondas de inimigos**, **coletar recursos** e **aprimorar o personagem** para enfrentar o temível **chefe final**.

### Funcionalidades

* **Mecânica de Tiro**: Atire em **8 direções** para derrotar os inimigos que se aproximam.
* **Geração de Níveis Dinâmica**: Os níveis são gerados proceduralmente com diferentes tipos de blocos e posições de *spawn* de inimigos.
* **Inimigos Variados**: Enfrente diferentes tipos de inimigos, incluindo um **chefe final desafiador**.
* **Sistema de Vida**: Gerencie as vidas do seu personagem e tente sobreviver o máximo possível.
* **Coleta de Recursos**: Colete **baús** deixados pelos inimigos para obter bônus.
* **Bônus**: Obtenha **vidas extras** e diferentes tipos de **munição temporárias** para auxiliar na sua jornada.
* **Placar Final**: Veja sua pontuação baseada nos inimigos derrotados e nas vidas restantes.

---

## Como Jogar

### Controles

* **`W` `A` `S` `D`**: Movimentar o personagem.
* **`SETAS`**: Controlar a direção do tiro.
* **`ESC`**: Pausar o jogo / Voltar para o menu principal.
* **`ESPAÇO`**: Iniciar jogo / Avançar para a próxima tela.

### Objetivos

**Sobreviva** às ondas de inimigos, **derrote o chefe final** e obtenha a **melhor pontuação possível**!

---

## Estrutura do Projeto

O projeto é organizado nas seguintes **classes principais**:

* **`Background`**: Gerencia a criação e o desenho do cenário do jogo.
* **`BgBlock`**: Representa os blocos individuais do cenário.
* **`Bullet`**: Classe base para todos os projéteis.
    * **`DefaultBullet`**: Implementa o projétil padrão do jogador.
    * **`EnemyBullet`**: Implementa o projétil dos inimigos.
    * **`PiercingBullet`**: Implementa um projétil especial que atravessa inimigos.
* **`Chest`**: Representa os baús de bônus que podem ser coletados.
* **`CowboyBoss`**: Implementa o chefe final do jogo.
* **`Enemy`**: Classe base para os inimigos normais.
* **`Game`**: Classe base para as diferentes telas do jogo (Menu, Nível, Game Over).
* **`GameOver`**: Tela exibida quando o jogador perde.
* **`Home`**: Tela inicial do jogo.
* **`Level1`**: Implementa a lógica e os elementos do primeiro nível do jogo.
* **`Object`**: Classe base para todos os objetos do jogo.
* **`Player`**: Implementa a lógica e os controles do personagem do jogador.
* **`Pivot`**: Pontos de referência no cenário para movimentação de certos objetos.
* **`Scene`**: Gerencia a atualização, desenho e detecção de colisões dos objetos na cena.
* **`ShieldEnemy`**: Um tipo de inimigo que possui um escudo.
* **`Victory`**: Tela exibida quando o jogador vence.

---

## Requisitos de Compilação

Este projeto foi desenvolvido e compilado com **Visual C++ 2022**. Certifique-se de ter o ambiente de desenvolvimento configurado corretamente.