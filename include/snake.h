#include <vector>

/**
 * @struct segment
 * @brief Represents a single block of the snake's body on the grid.
 */
struct segment{
    int x;  /**< The X coordinate of this segment. */
    int y;  /**< The Y coordinate of this segment. */
};

/**
 * @class Snake
 * @brief Manages the snake's body segments, movement, growth, and state resets.
 * 
 * This class uses a continuous vector of segments where index 0 always represents the head.
 * It handles direction-based grid movement and tail growth upon eating.
 */
class Snake{
    std::vector<segment>s;  /**< Vector container holding all segments of the snake's body. */

    public:

    /**
     * @brief Constructs a new Snake object with an initial size of 2 segments.
     * 
     * Places the head at (x+1, y) and the initial body segment at (x, y).
     * 
     * @param x The base starting X coordinate on the grid.
     * @param y The base starting Y coordinate on the grid.
     */
    Snake(int x,int y);

    /**
     * @brief Updates the position of all segments based on the given direction.
     * 
     * Moves the head according to the movement character and shifts all subsequent 
     * body segments to follow the path of the segment ahead of them.
     * 
     * @param m Direction character: 'w' (Up), 's' (Down), 'a' (Left), 'd' (Right).
     */
    void move(char m); 

    /**
     * @brief Grows the snake by appending a new segment at the current tail's position.
     * 
     * This is called when the snake successfully consumes a food item.
     */
    void eat();

    /**
     * @brief Provides read-only access to the entire body of the snake.
     * @return const std::vector<segment>& A constant reference to the vector of segments.
     */
    const std::vector<segment>& getBody() const;

    /**
     * @brief Provides read-only access to the head of the snake.
     * @return const segment& A constant reference to the first segment (index 0).
     */
    const segment& getHead() const;
};