#include<iostream>
using namespace std;

class factorial{
    private:
        float n;
        float fact =1;
        void find_fact(){
            for(int i=1;i<n+1;i++){
                fact = fact*i;
            }
        }
    public:
        void input(){
            cout<<"input the number";
            cin>>n;
        }

        void output(){
            find_fact();
            cout<<"factorial of "<<n<<" is : "<<fact<<endl;
        }
};

int main(){
    factorial f1;
    f1.input();
    f1.output();
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";
}