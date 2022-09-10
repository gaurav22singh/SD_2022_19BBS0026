# SD_2022_19BBS0026
# CHESS GAME

#PROBLEM STATEMENT

There are 2 players playing it


● The game is played on a square grid of 5 by 5 blocks

● Each player has a team of 5 characters that start from their end

● Move commands:
  L - left move
  R - right move
  F - front move
  B - back move

These moves are relative to the player.

● Characters:
    Pawn: In one move, it moves 1 block straight in any direction (L, R, F, B)
    More characters maybe added subsequently

● The opponent player’s character dies, i.e removed from the grid when a player’s
character is moved to the opponent character’s position


#Game

Each player can arrange their characters on their end in any order. They will have 5
pawns to start with and will need to deploy all of them at the start of the game.

● The input for initial character positions will be taken as a list of character names, placing
them from left to right on the starting lanes. Once this process is complete for both the
players, they can start making moves.

● The application then takes move inputs from the players, alternating between the
players, updating the game state in the process.

● Input move format: <character_name>:<move> (e.g. P1:L, P2:R, P3:F, P3:B)

  ● An invalid input move should be handled and prompted to the user(Invalid input format)
and make the player retry their turn.

  Invalid moves for a player:

  a. Input command on a character that does not exist
  b. Character going out of grid bounds.
  c. Invalid move presented for a given character.
  d. Targeting a friendly character, i.e a character from our own team.

  ● After every turn a 5 by 5 grid is displayed populated by characters.

  ● Prefix character names with player names upon displaying the grid. (Player A’s
characters should be prefixed by A-, ex:- A-P1, A-P3)

  ● The game ends when one player (winner) manages to kill all characters of their
opponent. The winner is prompted. The players can then choose to play another game.


#APPROACH
 The following game of chess was designed from scratch for the task of HitWicket_Software Engineering Role wherein all the OOP concepts and design paradigms were followed for the code build and quality.

The fundamental concept is that Game/Board/etc. merely store the game's state. If that's what you want, you can control them to, say, set up a position. My IGameRules interface is implemented by a class that is in charge of:

deciding which moves, such as castling and en passant, are legal.
determining the legality of a particular move.
identifying a player's check, checkmate, or stalemate.
executing actions

By separating the rules from the game/board classes, variants can be implemented rather quickly. Every method of the rules interface accepts a Game object, which may be examined to find out which movements are legal.

The game flow is designed by restricting the type of chess characters to pawns and restricting the board size to 5*5.

The application then takes move inputs from the players, alternating between the players, updating the game state in the process


  
![image](https://user-images.githubusercontent.com/61469874/189486857-68cb2a7d-1876-47fe-aa7b-e261d9693eb3.png)
Flowchart Diagram depicting the game flow and the control statements which helps in the loop sturcture of the game of Chess

![image](https://user-images.githubusercontent.com/61469874/189487135-de48ce4f-90d4-49b3-841f-fa8bf3ea4367.png)
UML Class Diagram depicting Functionalities and Methods


## OUTPUT
![image](https://user-images.githubusercontent.com/61469874/189484877-530112bf-35b8-4cb2-a994-2150fa9e1857.png)

![image](https://user-images.githubusercontent.com/61469874/189485072-4f9db0b6-e810-4133-a7e6-615a8448337f.png)


