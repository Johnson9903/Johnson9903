#include<iostream>
using namespace std;
//Student类及相关函数的书写
//***begin***
class Student
{
   public:
   void setNo(string);
   void setName(string);
   void setScore(float);
   float Score;
   //double getScore(Student);
   void display();
   private:
   string No;
   string Name;
   //float Score;
};
void Student::setNo(string n)
{
   No = n;
}
void Student::setName(string na)
{
   Name = na;
}
void Student::setScore(float s)
{
   Score = s;
}
/*double Student::getScore(Student s)
{
   return s.Score;
}*/
void Student::display()
{
   cout<<No<<'/'<<Name<<'/'<<Score<<endl;
}
Student max(Student *s)
{
   Student max = s[0];
   for(int i = 0;i<5;i++)
   {
      if(max.Score<s[i].Score)
      {
         max = s[i];
      }
   }
   return max;
}
//***end***
int main(int argc, char *argv[])
{
   Student stu[5];
   string name,no;
   float score;
   for(int i=0;i<5;i++)
     {
        cin>>no>>name>>score;
        stu[i].setNo(no);
        stu[i].setName(name);
        stu[i].setScore(score);
     }
  Student temp=max(stu);
  temp.display();
}