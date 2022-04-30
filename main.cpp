#include <iostream>
int vetor[8];
int p = 0,x = 0;
using namespace std;
template <class T, int N> class BoundedArray {
  public:
    void set(int index, T value) {
    
    if(index >= N){
        std::cout<< "Erro: indice maior que arranjo." << std::endl;
    }else{
      buf[index] = value;

    }
      
    }
    T get(int index) {

    if(index >= N){
        std::cout<< "Erro: indice maior que arranjo." << std::endl;
    }else{
      return buf[index];

    }
      
    }
  private:
    T buf[N];
};

template <class T> void testArray() {
  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action) {
  	x=0;
    int index;
    std::cin >> index;
    try {
      if (action == 's') {
        T value;
        std::cin >> value;
      
        if(index < 0) throw 1;
        
        vetor[p] = index;
        p++;
         a.set(index, value);
      } else if (action == 'g') {
        if(index < 0) throw 1;
        
        for(int i=0; i<p; i++){
        	if(index == vetor[i] && x ==0 && index<8){
        		x = 1;
        		
		  }
	  }
        if(x ==1){
        	std::cout << a.get(index) << std::endl;
	  }else{
	  	if(index<8)
	  	cout << "Erro: indice nao inicializado."<<endl;
	  }
        
      }
    } catch (int e) {
        if(e == 1)
            std::cerr << "Erro: indice negativo." << std::endl;
    }
  }

}

int main() {
  char type;
  std::cin >> type;
  switch(type) {
    case 'd':
      testArray<double>();
      break;
    case 'i':
      testArray<int>();
      break;
    case 's':
      testArray<std::string>();
      break;
  }
  return 0;
}
