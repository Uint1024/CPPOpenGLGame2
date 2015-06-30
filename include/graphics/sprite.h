#ifndef SPRITE_H
#define SPRITE_H
class Sprite
{
  private:
    int mX;
    int mY;
    int mW;
    int mH;
  public:
    Sprite(int x, int y, int w, int h);
    int getX(){
      return mX;
    }
    int getY(){
      return mY;
    }
    int getW(){
      return mW;
    }
    int getH(){
      return mH;
    }

};

#endif
