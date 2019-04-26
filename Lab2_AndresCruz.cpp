#include <iostream>
#include <string>
#include <stdlib.h>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void Captcha();
bool validacioncaptcha(string);

int main(){
	int opcm=0;
	while(opcm!=4){
		cout<<"Menu Principal"<<endl
			<<"1. Captcha"<<endl
			<<"2. Numeros Perfectos"<<endl
			<<"3. Permutaciones"<<endl
			<<"4. Salir"<<endl;
		cin>>opcm;
		while(opcm<1||opcm>4){
			cout<<"Menu Principal"<<endl
                        <<"1. Captcha"<<endl
                        <<"2. Numeros Perfectos"<<endl
                        <<"3. Permutaciones"<<endl
                        <<"4. Salir"<<endl
			<<"Ingrese una opcion valida: "<<endl;
	                cin>>opcm;
		}//fin while validacion
		if(opcm==1){
			Captcha();
		}
	}//fin while menu
	return 0;
}

void Captcha(){
	//Ejercicio numero 1 Captcha
	int opcm=0;
	while(opcm!=3){
	cout<<"Menu Principal"<<endl
                        <<"1. Suma"<<endl
                        <<"2. Pasos"<<endl
                        <<"3. Salir"<<endl;
                cin>>opcm;
		while(opcm<1||opcm>3){
                        cout<<"Menu Principal"<<endl
                        <<"1. Suma"<<endl
                        <<"2. Pasos"<<endl
                        <<"3. Salir"<<endl
                        <<"Ingrese una opcion valida: "<<endl;
                        cin>>opcm;
                }//fin while validacion
		if(opcm==1){
			string captcha;	
			cout<<"Ingrese una serie captcha: "<<endl;
			cin>>captcha;
			while(bool noes=validacioncaptcha(captcha)){
				cout<<"Ingrese una serie captcha de manera correcta: "<<endl;
	                        cin>>captcha;
			}//fin validacion
			int suma=0;
			for(int i=0;i<captcha.length();i++){
				if(i!=captcha.length()-1){
					if(captcha[i]==captcha[i+1]){						
						suma+=captcha[i]-48;
					}
				}else{
					if(captcha[i]==captcha[0]){
                                                suma+=captcha[i]-48;
                                        }

				}
			}//fin for
			cout<<"La suma es: "<<suma<<endl;			
		}//fin if
		if(opcm==2){
				
		}//fin if
	}//fin while
}
bool validacioncaptcha(string captcha){
	int validacion=0;
                                for(int i=0;i<captcha.length();i++){
                                        if(isdigit(captcha[i])){
                                        validacion++;
                                        }
                                }
                                if(validacion==captcha.length()){
                                        return false;
                                }else{
                                        return true;
                                }

}
