struct Inner 
{
   Inner(int){}
};

struct Outer 
{
   Inner i;
};

int main() 
{
  Outer o;
}