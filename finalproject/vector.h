#ifndef vec_h
#define vec_h

template<typename T>
class fileVector{ 
    private:
        T* data;
        int capacity;
        int size;
        void resize(int cap){
            if(cap<capacity){
                cap=capacity+50;
            }
            T tmp[cap];
            for( int i=0;i<size;i++){
                tmp[i]=data[i];
            }
            delete[] data;
            capacity=cap;
            data=tmp;
        }
    public:
        fileVector():capacity(50),size(0){
            data=new T[capacity];
        };
        T& operator[](int idx){
            return data[idx];
        }
        void push(T& value){
            if(size==capacity){
              resize(capacity+50);
            }
            data[size]=value;
            size++;
        }
        void remove(int index){
            int current=0;
            T* tmp=new T[capacity];
            for(int i=0;i<size;i++){
                if(i!=index){
                    tmp[current]=data[i];
                    current++;
                }
            }
            delete[] data;
            data=tmp;
            size--;
        }
        int length(){
            return size;
        }
};
#endif