#include <iostream>

int main(){
    int n;
    int k;
    std::cin>>n>>k;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k;j++){
            if((i==0||i==n-1) && (j==0 || j==k-1)){
                std::cout<<"+";
            }
            else if(i==0||i==n-1){
                std::cout<<"-";
            }
            else if(j==0 || j==k-1){
                std::cout<<"|";
            }
            else{
                std::cout<<" ";
            }
            
        }
        std::cout<<std::endl;
    }
}