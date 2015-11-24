//
// Created by diego on 11/1/15.
// Implements a linked list, using template, smart_ptr
//

#include <memory>
#include <exception>


#ifndef LIST_LIST_HPP
#define LIST_LIST_HPP

using namespace std;

namespace ED{
    template <typename T>
    class list{
    private:

        struct node{
            public:

            node(T obj) : obj(obj) {
                next = nullptr;
            };

            T obj;

            shared_ptr<node> next;
        };

    private:
        uint size;

        shared_ptr<node> first, last;

        long int search(T t){
            long int ret, i;
            shared_ptr<node> temp;
            for (temp = first; ; i++, temp = temp.get()->next) {
                if(temp.get()->obj == t)
                    return i;
                if(temp.get()->next == nullptr)
                    return -1;
            }
        }

    public:

        class iterator{

        private:
            iterator(shared_ptr<node> & n):current(n){};

        public:
            iterator():current(nullptr){};

            T &operator*(){
                    return retrieve();
            }

            iterator &operator++(){
                current = current.get()->next;
                return *this;
            } //++i

            iterator &operator++(int){//i++
                auto old = *this;
                ++( *this );
                return old;
            }

            bool operator==(iterator rhs){
                return current == rhs.current;
            }

            bool operator!=(iterator rhs){
                return (current != rhs.current);
            }


        protected:
            shared_ptr<node> current;
            T & retrieve(){
                return current.get()->obj;
            }
            friend class list<T>;
        };

    public:
        list(){
            size = 0;
            first = nullptr;
            last = nullptr;
        }

        ~list(){
            //must delete all items
        }

        uint getSize() const {
            return size;
        }

        void insert(T t, uint position){
            if(position > size){
                throw "error: Posição é maior que tamanho da lista";
            }
            auto p  = make_shared<node>(node(t)); //equivalente a malloc, porem com smart pointer.
            uint i = 0;
            if(position == 0){
                p.get()->next = first;
                first = p;
                size++;
                return ;
            }

            for(auto temp = first; i <= position; i++, temp = temp.get()->next){
                if(i == position - 1){
                    p.get()->next = temp.get()->next;
                    temp.get()->next = p;
                    break;
                }
                if( i == (size - 1) ){
                    temp.get()->next = p;
                    last = p;
                }
            }
            size++;
        }

        void erase(long int position){
            if(position > size || position < 0){
                throw ;
            }
            shared_ptr<node> temp;
            long int i = 0;
            if(position == 0){
                first = first.get()->next;
                size--;
                return ;
            }
            for(temp = first; i <= position; i++, temp = temp.get()->next){
                if (i == (size-2) && position - 1 == i){
                    temp.get()->next = nullptr;
                    last = temp;
                    break;
                }
                if( i == position - 1){
                    auto a = temp.get()->next;
                    temp.get()->next= a.get()->next;
                }
            }
            size--;
        }

        void push_back(T t){
            insert(t, size);
        }

        void push_front(T t){
            insert(t, 0);
        }

        void pop_back(){
            erase(size-1);
        }

        void pop_front(){
            erase(0);
        }

        uint max_size(){
            return  size;
        }

        iterator begin(){
            if(size != 0){
                auto ret = iterator(first);
                return ret;
            }
        }

        iterator end(){
            auto ret = iterator(last);
            return ret;
        }
    };
}
#endif //LIST_LIST_HPP
