#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


#include <iostream>



using namespace std;



class X{

  public:

        X();

        template<class T> void operator()(T& value);

};



template<class T> void X::operator()(T& value)

{

    value++;

}



X::X(){}





template <class T> void mySwap(T* v1, T* v2)

{

    T tmp;

    tmp = *v2;

    *v2 = *v1;

    *v1 = tmp;

}



template <class T> void myForeach(T* tab, int len, X x)

{

    for(int i=0;i<len;i++)

    {

        x(tab[i]);

    }



}



int main()

{

    int x=1, y=5;

    mySwap(&x,&y);



    int tab[5] = {1,2,3,4,5};

    X myX;

    myForeach(tab, 5, myX);



    for(int i=0;i<5;i++)

        cout << tab[i] << " " << endl;



    cout << "\n" << x << " " << y << endl;

    return 0;

}

