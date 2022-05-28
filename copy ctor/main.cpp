#include <iostream>
using namespace std;

///stak
class myStak
{
    int* stk;
    int tos ;
    int size;

    public:
        myStak(int s){
        tos =0;
        size = s;
        stk =new int[size];
        }
        ~myStak()
        {
            cout<<"destructor \n";
            delete [] stk;
        }
        bool isEmpty(){
                return tos ==0;

         }
        bool isFull (){
                 return tos == 4 ;

         }
         void push (int n ){
             if (!isFull())
            stk[tos++] = n;
         else cout << "stk is full \n ";
         }
         int pop ()
         {
             if (isEmpty() == false)
                return stk [--tos];
                else cout<<"stk is empty \n";
         }
          int peek(){
                if (tos == 0){
                cout<< "peek"<<endl;}
                else {return stk[tos];}}


        void display (){
                if (tos == 0){
                cout<< "your stak is "<<endl;}
                else {
                    for (int i = tos ; i>=0 ;i--){
                        cout << stk[i]<<"\t";}
}
        }
        ///copy ctor
                myStak(myStak& oldS){
                tos = oldS.tos;
                size = oldS.size;
                stk = new int[size];
                for (int i = 0; i < tos ; i++)
                    stk[i] =oldS.stk[i];
                    cout <<" copy constractor \n";
                }
                friend void viewContent (myStak s);
/*myStak reverse(){
    int revers;
for (int i = stk.size()-1 ; i>=0 , --i){
    revers+=atk[i];

}

}*/
};
///std lone fun
void viewContent (myStak A){
for (int i =0 ; i< A.tos ; i++)
    cout<<A.stk[i]<<" , ";
A.stk[2] = 777;
cout<<endl;

}

int main()
{

        myStak A (3);

        A.push (0);
        A.push (22);
        A.push(33);
        A.push(55);
        A.display();
        A.pop();
        cout<<endl;
        cout <<"after pop fun"<<endl;
        A.display();
        cout<<endl;
        viewContent(A);
        cout<<endl;
        cout << "peek = "<<  A.peek()<<endl;
        cout<<"2 case for copy ctor"<<endl;
        myStak A2(A);
        viewContent(A2);
    return 0;

}
