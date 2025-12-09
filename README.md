
Brick-N-Ball 🧱⚾

   A simple 2D brick-breaking game built with C and OpenGL (GLUT). 
   Break all the bricks using a bouncing ball and control the paddle with arrow keys.


Features:

   Classic brick-breaker gameplay.

   Paddle controlled with Left and Right arrow keys.

   Ball bounces off walls, paddle, and bricks.

   Bricks disappear when hit.

   Game restarts automatically when the ball falls below the paddle.

   Colorful bricks and smooth ball movement.


Gameplay:

   Use LEFT and RIGHT arrow keys to move the paddle.

   Press an arrow key to start the ball movement.

   Destroy all the bricks by hitting them with the ball.

   If the ball falls below the paddle, the game will restart after a short delay.

   Enjoy the colorful bouncing ball and bricks!



Installation:

   1. Make sure you have OpenGL and GLUT installed on your system.

      - Ubuntu / Debian:
        ```bash
          sudo apt-get install freeglut3-dev
        ```
      - Windows:
        ```bash
          Install FreeGLUT and link it with your computer
        ```
   2. Clone this repository:
      ```bash
      git clone <repository_url>
      cd Brick-N-Ball
      ```
   3. Compile the game using gcc:
      - linux
      ```bash
      gcc main.c -lGL -lGLU -lglut -o Brick_N_Ball
      ```
      - mac
      ```bash
      gcc main.c -framework OpenGL -framework GLUT -o Brick_N_Ball
      ```
   4. Run the game:
      ```bash
      ./Brick_N_Ball
      ```

Controls:

   Key             Action

   Left Arrow	   Move paddle left / Start game
   Right Arrow	   Move paddle right / Start game


Notes:

   All work is done in main.c

   Window size is 800x800.

   The paddle cannot move beyond the window boundaries.

   The ball speed and paddle size are adjustable in the code.


License:

   This project is open-source and free to use.
