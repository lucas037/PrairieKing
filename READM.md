# Prairie King

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
* **`Level2`**: Implementa a lógica e os elementos do segundo nível do jogo (atualmente com funcionalidades limitadas).
* **`Object`**: Classe base para todos os objetos do jogo.
* **`Player`**: Implementa a lógica e os controles do personagem do jogador.
* **`Pivot`**: Pontos de referência no cenário para movimentação de certos objetos.
* **`Scene`**: Gerencia a atualização, desenho e detecção de colisões dos objetos na cena.
* **`ShieldEnemy`**: Um tipo de inimigo que possui um escudo.
* **`Victory`**: Tela exibida quando o jogador vence.

---

## Requisitos de Compilação

Este projeto foi desenvolvido e compilado com **Visual C++ 2022**. Certifique-se de ter o ambiente de desenvolvimento configurado corretamente.