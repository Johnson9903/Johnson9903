/********* Begin *********/
class Rectangle
{
    //在此处实现Rectangle类
    public:
    void Set(int h, int w);
    int GetArea();
    Rectangle GetRect(int h,int w);
    int GetRectArea(Rectangle rect);
    //private:
    int height;
    int width;
};
/********* End *********/

Rectangle GetRect(int h,int w)
{
    /********* Begin *********/
    //返回一个 h*w 的 Rectangle 对象
    Rectangle r1;
    r1.height = h;
    r1.width = w;
    return r1;
    /********* End *********/
}

int GetRectArea(Rectangle rect)
{
    /********* Begin *********/
    //返回 rect 对象的面积
    int area;
    area = rect.height*rect.width;
    return area;
    /********* End *********/
}

