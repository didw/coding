### AI Game

#### Block Game

*Algorithm*
1. Generate 10 random position
2. Select best position from random 10 position using scoring
3. Go to target position unless target position is occupied by other player
4. Select best route between vetical and horizontal way
5. Go to 1

- Scoring
Score = number of empty cell / total cell (in area from current position to target position) * ratio
ratio = total cell / (400 - filled cell) (0.5 ~ 1.5)

- Find best route
Best route means there are more empty cell than other route keep in shortest path.

*To Do*
The purpose of this game is not painting but drawing boxes. So it is necessary to calculate how to calculate big box to get more score.

#### The Great Escape

*Algorithm*
1. When player is three just search shortest path and go.
2. When player is two block other player first and go

- How to block?
Block the other player vertically first, and if it is possible to block horizontally then block horizontally.

- How to search shortest path
Full search by simpl dynamic programming
 



