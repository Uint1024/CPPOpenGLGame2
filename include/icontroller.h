#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController
{
  private:
    
  public:
    virtual ~IController();
    virtual void update() =  0;
};

class IControllerPlayer : public IController
{
  private:

  public:
    IControllerPlayer();
    virtual void update();

};

class IControllerBonus : public IController {
  public:
    IControllerBonus();
    virtual void update();
};
#endif
