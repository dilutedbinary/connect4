
class Board{

 private:
  int height_,width_, xLocation_,yLocation_;
  int **grid;
const  char *empty_, *player1_, *player2_;

 public:
  Board();
  Board(int height, int width , int, int);
  void clear();
const  int getWidth() const;
const  int getHeight() const;
 const  char * getToken(int key, int lineNum);
  int drop(int xCoord, int token);
  void print();
  void printJumbo();
  void horizontal(int);
  void vertical(int);
  void place(int xCoord, int yCoord, int token);
  const int*operator[](int i) const;
};
