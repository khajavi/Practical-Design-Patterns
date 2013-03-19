
class Client {
public:
  Client(AbstractFactory*);
  private:
    AbstractProductA* a;
    AbstractProductB* b;
};
