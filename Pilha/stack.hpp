#include <memory>

#ifndef STACK
#define STACK


using namespace std;
namespace ED{
    template<typename T>
    class Stack{
        private:
            typedef class node{
                public:
                shared_ptr<node> next;
                //shared_ptr quando destruido,
                //se nao houver outra referencia para o mesmo elemento,
                //o objeto apontado é destruido tambem; teclado sem acento:(

                T data;
            }node;

            unsigned int size;

            shared_ptr<node> StackPtr;

        public:
        Stack(){
            StackPtr = nullptr;
            size = 0;
        }

        ~Stack(){
        }

        void push_back(T obj){
            auto n = make_shared<node>();
            n->data = obj;
            n->next = StackPtr;
            StackPtr = n;
            size++;
        }

        void pop_back(){
            StackPtr = StackPtr.get()->next;
            size--;
        }

        T& top(){
            return StackPtr->data;
        }

    };
}
#endif // STACK
