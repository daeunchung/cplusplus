class Position
{
private:
     int x,y;
     char ch;

public:
     Position(int ax, int ay, char ach) { x=ax;y=ay;ch=ach; }
     void OutPosition() const {  }
     void MoveTo(int ax, int ay) { x=ax; y=ay; }
};

int main()
{
     Position Here(1,2,'A');
     Here.MoveTo(20,5);
     Here.OutPosition();

     const Position There(3,4,'B');
     There.MoveTo(40,10);           // 에러 발생
     There.OutPosition();
     
     return 0;
}
