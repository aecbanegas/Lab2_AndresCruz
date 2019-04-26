#include <iostream>
#include <string>
#include <stdlib.h>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void Captcha();
bool validacioncaptcha(string);
void numperf();
bool valnumperf(int);
void permutas();
bool valperm(string);
void permpal(string);

int main(){
	int opcm=0;
	while(opcm!=4){
		cout<<"Menu Principal"<<endl
			<<"1. Captcha"<<endl
			<<"2. Numeros Perfectos"<<endl
			<<"3. Permutaciones"<<endl
			<<"4. Salir"<<endl
			<<"Ingrese una opcion: "<<endl;
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
		if(opcm==2){
			numperf();
		}
		if(opcm==3){
			permutas();
		}
	}//fin while menu
	return 0;
}

void Captcha(){
	//Ejercicio numero 1 Captcha
	int opcm=0;
	while(opcm!=3){
	cout<<"Menu Ejercicio"<<endl
                        <<"1. Suma"<<endl
                        <<"2. Pasos"<<endl
                        <<"3. Salir"<<endl
			<<"Ingrese una opcion: "<<endl;
                cin>>opcm;
		while(opcm<1||opcm>3){
                        cout<<"Menu Ejercicio"<<endl
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
			string captcha;
                        cout<<"Ingrese una serie captcha: "<<endl;
                        cin>>captcha;
                        cout<<"Es verdad: "<<(captcha.length()%2==0)<<endl;
			while(bool noes=validacioncaptcha(captcha)&&(captcha.length()%2!=0)){
                                cout<<"Ingrese una serie captcha de manera correcta y que sea par: "<<endl;
                                cin>>captcha;
                        }//fin validacion
                        int suma=0;
			int mitad=captcha.length()/2;
			int inicio=0;
                        for(int i=0;i<captcha.length();i++){
                                if(i<mitad){
                                        if(captcha[i]==captcha[i+mitad]){
                                                suma+=captcha[i]-48;
					//	cout << "indice " << i << " numero " << captcha[i] << " suma " << suma << "SUMO"  << endl;					
                                        }
					//cout << "indice " << i << " numero " << captcha[i] << " suma " << suma << " NO SUMO"<<endl;
                                }else{
                                        if(captcha[i]==captcha[inicio]){
                                                suma+=captcha[i]-48;
					//	cout << "indice " << i << " numero " << captcha[i] << " suma " << suma << " SUMO" << endl;
                                        }
					//cout << "indice " << i << " numero " << captcha[i] << " suma " << suma << " NO SUMO" << endl;
					inicio++;
                                }
                        }//fin for
                        cout<<"La suma es: "<<suma<<endl;

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
void numperf(){
	int num;
	cout<<"Ingrese un numero para verificar si este es un numero perfecto: "<<endl;
	cin>>num;
	while(!isdigit(num)&&num<1){
		cout<<"Ingrese un numero para verificar si este es un numero perfecto: "<<endl;
	        cin>>num;
	}
	if(num==1){
		cout<<"EL numero es perfecto! "<<"Factor= 1 "<<endl;
	}else{
		if(valnumperf(num)){
			cout<<"El numero es perfecto! "<<endl;
		}else{
			cout<<"El numero no es perfecto! "<<endl;
			if(num<6){
				cout<<"No existe un numero perfecto anterior. "<<endl;
			}else{
				for(int i=num;i>0;i--){
					if(valnumperf(i)){
						cout<<"El anterior numero perfecto es: "<<i<<endl;
					}
				}
			}
		}
		
	}
}
bool valnumperf(int num){
	int arreglo[num];
                for(int i=1;i<num;i++){
                        if(num%i==0){
                                arreglo[i-1]=i;
                        }else{
                                arreglo[i-1]=-1;
                        }
                }//fin for
		arreglo[num-1]=-1;
		int suma=0;
	//	cout<<"Factores: "<<endl;
		for(int i=0;i<num;i++){
			if(arreglo[i]!=-1)
			{
	//			cout<<arreglo[i]<<" ;  ";
				suma+=arreglo[i];
			}
		}
	//	cout<<endl<<"la suma de los factores es: "<<suma<<endl;
		if(num==suma){
			int suma=0;
	                cout<<"Factores: "<<endl;
        	        for(int i=0;i<num;i++){
                        if(arreglo[i]!=-1)
                        {
                                cout<<arreglo[i]<<" ;  ";
                                suma+=arreglo[i];
                        }
               		 }
	                cout<<endl<<"la suma de los factores es: "<<suma<<endl;

			return true;
		}else{
			return false;
		}
}
void permutas(){
	string pal;
	cout<<"Ingrese una frase o combinacion de letras sin repetirlas :"<<endl;	
	cin>>pal;
	while(valperm(pal)==false){
		cout<<"Ingrese una frase o combinacion de letras sin repetirlas :"<<endl;
	        cin>>pal;
	}
	cout<<"Las combinaciones posibles son: "<<endl;
	permpal(pal);
}
bool valperm(string pal){
	for(int i=0;i<pal.length();i++){
		for(int j=i;j<pal.length();j++){
			if(pal[i]==pal[j]){
				return false;
			}
		}
	}
	return true;
}
void permpal(string pal){
	for(int i=0;i<pal.length();i++){
		for(int h=0;h<pal.length();j++){
			for(int j=0;j<pal.length();j++){
				if(j==0){
					cout<<pal[i];
				}
				if(pal[i]!=pal[j]){
					cout<<pal[j];
				}
			}
			cout<<endl;
		}
		/*for(int j=pal.length()-1;j>=0;j--){
                        if(j==pal.length()-1){
                                cout<<pal[i];
                        }
                        if(pal[i]!=pal[j]){
                                cout<<pal[j];
                        }
                }

		cout<<endl;*/
	}
}
