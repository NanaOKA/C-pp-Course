struct Inner 
{
   Inner(int){}
   // Ways of fixing
   //1. Delete Inner(int){} so default used
   //2. Inner(){}
   //3. Give int default value = Inner(int=1)

};

struct Outer 
{
   Inner i;
   // Ways of fixing
   //1. Delete Inner i
   //2. Add, Outer(): i(3){}
};

int main() 
{
  Outer o;
}