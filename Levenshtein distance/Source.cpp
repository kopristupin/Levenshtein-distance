#include <iostream>
#include<vector>

int match(char example, char text) {
    if (example == text)
        return 0;
    else
        return 1;
}

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    else
        return c;
}

int measure(std::string str, std::string ex) {
   
  const int m1 = ex.length();
  const int m2 = str.length();

  int distances[20][20];
  distances[0][0] = 0;
  for (int i = 1; i <=str.length(); i++)
      distances[i][0] = i;

      for (int u = 1; u <= ex.length(); u++)
          distances[0][u] = u;

    
      for (int i = 1; i <=str.length(); i++) {
          for (int u = 1; u <=ex.length(); u++) {
              std::cout << str[i]  <<" "<<ex[u] << ", ";
             
              int ins = distances[i - 1][u] + 1;
              int del = distances[i][u - 1] + 1;
              int rep= distances[i-1][u-1]+ match(str[i], ex[u]);

              distances[i][u] = min(ins, del, rep);
            
          }
          std::cout << "\n";


      }

   for (int i = 0; i < str.length(); i++) {
       for (int u =0; u < ex.length(); u++) {
           if(distances[i][u]/10<1)
           std::cout << distances[i][u] << "  ";
           else
               std::cout << distances[i][u] << " ";
       }
       std::cout << "\n";
   }

  
   return distances[m1-1][m2-1];
 }


int main() {
    
    std::string tex = {" Halo word" };
    std::string ex = { " Hello, world" };
  std::cout<<"Result: "<<  measure(tex, ex);

  


}